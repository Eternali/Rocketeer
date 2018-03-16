cmake_minimum_required(VERSION 3.9)
project(Rocketeer)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_NAME "Rocketeer")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(IPC_LINK_FLAGS "-pthread")

set(headers
        ${PROJECT_INCLUDE_DIR}/Button.hpp
        ${PROJECT_INCLUDE_DIR}/MenuState.hpp
        ${PROJECT_INCLUDE_DIR}/settings.hpp
        ${PROJECT_INCLUDE_DIR}/RectButton.hpp
        ${PROJECT_INCLUDE_DIR}/GameState.hpp
        ${PROJECT_INCLUDE_DIR}/IPC.hpp)

set(sources
        ${PROJECT_SRC_DIR}/main.cpp
        ${PROJECT_SRC_DIR}/MenuState.cpp
        ${PROJECT_SRC_DIR}/RectButton.cpp
        ${PROJECT_SRC_DIR}/GameState.cpp
        ${PROJECT_SRC_DIR}/IPC.cpp)

add_subdirectory(${LIB_DIR}/Box2D)
add_subdirectory(${LIB_DIR}/GameUtils)

include_directories(${LIB_DIR})
include_directories(${PROJECT_INCLUDE_DIR})

add_definitions(${IPC_LINK_FLAGS})

add_executable(${EXECUTABLE_NAME} ${headers} ${sources})

# target_link_libraries(${EXECUTABLE_NAME} Box2D)
target_link_libraries(${EXECUTABLE_NAME} GameUtils)

find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
