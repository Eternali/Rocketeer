#include <sstream>

#include "MenuState.hpp"
#include "GameState.hpp"
#include "settings.hpp"

MenuState::MenuState(ch::GameDataRef data) : _data(data) {

}

void MenuState::init() {
    this->_data->assets.loadFont("redlight", "../assets/fonts/redlight.ttf");

    this->initButtons();

//    this->_data->assets.loadTexture("menu_state_background", MENUSCREEN_BACKGROUND_FILENAME);

//    _background.setTexture(this->_data->assets.getTexture("menu_state_background"));
}

void MenuState::initButtons() {

    // initialize handler functions
    struct OnClicks {
        static void startButton() {
            std::cout << "Starting game" << std::endl;
        }
    };

    // start button
    sf::Text startLabel;
    startLabel.setFont(this->_data->assets.getFont("redlight"));
    startLabel.setString("S T A R T");
    startLabel.setColor(sf::Color::White);
    startLabel.setStyle(sf::Text::Bold);
    startLabel.setCharacterSize(H2);

    this->_startButton.init(
        sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2),
        sf::Vector2f(200, 100),
        startLabel,
        [](ch::GameDataRef data) -> void { data->machine.addState(ch::StateRef(new GameState(data)), true); },
        sf::Color::Blue,
        sf::Color::Magenta);

}

void MenuState::handleInput() {
    sf::Event event;

    while (this->_data->window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                this->_data->window.close();
                break;
        }
    }

}

void MenuState::update(float dt) {

    if (this->_startButton.isOver(this->_data->input.getMousePosition(this->_data->window))) {
        if (!this->_startButton.state.isHovered) this->_startButton.onEnter();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (!this->_startButton.isActive) {
                this->_startButton.isActive = true;
                this->_startButton.onClick(this->_data);
            }
        } else {
            this->_startButton.isActive = false;
        }
    } else {
        if (this->_startButton.state.isHovered) this->_startButton.onLeave();
    }

}

void MenuState::draw(float dt) {
    this->_data->window.clear(CLEAR_COLOR);

    this->_startButton.draw(this->_data->window);
//    this->_data->window.draw(this->_background);

    this->_data->window.display();
}
