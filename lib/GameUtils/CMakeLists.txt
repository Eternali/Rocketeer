cmake_minimum_required(VERSION 3.9)
project(GameUtils)

set(CMAKE_CXX_STANDARD 17)

set(LIB_NAME "GameUtils")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(headers
        ${PROJECT_INCLUDE_DIR}/Animation.hpp
        ${PROJECT_INCLUDE_DIR}/AssetManager.hpp
        ${PROJECT_INCLUDE_DIR}/Game.hpp
        ${PROJECT_INCLUDE_DIR}/InputManager.hpp
        ${PROJECT_INCLUDE_DIR}/State.hpp
        ${PROJECT_INCLUDE_DIR}/StateMachine.hpp)
set(sources
        ${PROJECT_SOURCE_DIR}/Animation.cpp
        ${PROJECT_SOURCE_DIR}/AssetManager.cpp
        ${PROJECT_SOURCE_DIR}/Game.cpp
        ${PROJECT_SOURCE_DIR}/InputManager.cpp
        ${PROJECT_SOURCE_DIR}/StateMachine.cpp)

# include_directories(${PROJECT_BINARY_DIR})
include_directories(${PROJECT_INCLUDE_DIR})

add_library(${LIB_NAME} STATIC ${headers} ${sources})
set_target_properties(${LIB_NAME} PROPERTIES
        CLEAN_DIRECT_OUTPUT 1)

find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${LIB_NAME} ${SFML_LIBRARIES})
endif()
