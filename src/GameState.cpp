#include <sstream>

#include "GameState.hpp"
#include "settings.hpp"

GameState::GameState(ch::GameDataRef data) : _data(data) {

}

void GameState::init() {
    this->_data->assets.loadFont("redlight", "../assets/fonts/redlight.ttf");

    this->initButtons();
}

void GameState::initButtons() {

    // start button
    sf::Text pauseLabel;
    pauseLabel.setFont(this->_data->assets.getFont("redlight"));
    pauseLabel.setString("P A U S E");
    pauseLabel.setColor(sf::Color::Blue);
    pauseLabel.setStyle(sf::Text::Bold);
    pauseLabel.setCharacterSize(P);

    this->_pauseButton.init(
        sf::Vector2f(WINDOW_WIDTH-50, 30),
        sf::Vector2f(80, 40),
        pauseLabel,
        [](ch::GameDataRef data) -> void { std::cout << "Pausing Game" << std::endl; },
        sf::Color::White,
        sf::Color::Green);

}

void GameState::handleInput() {
    sf::Event event;

    while (this->_data->window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                this->_data->window.close();
                break;
        }
    }

}

void GameState::update(float dt) {

    if (this->_pauseButton.isOver(this->_data->input.getMousePosition(this->_data->window))) {
        if (!this->_pauseButton.state.isHovered) this->_pauseButton.onEnter();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (!this->_pauseButton.isActive) {
                this->_pauseButton.isActive = true;
                this->_pauseButton.onClick(this->_data);
            }
        } else {
            this->_pauseButton.isActive = false;
        }
    } else {
        if (this->_pauseButton.state.isHovered) this->_pauseButton.onLeave();
    }

}

void GameState::draw(float dt) {
    this->_data->window.clear(CLEAR_COLOR);

    this->_pauseButton.draw(this->_data->window);

    this->_data->window.display();
}
