#include <sstream>

#include "GameState.hpp"
#include "settings.hpp"

GameState::GameState(ch::GameDataRef data) : _data(data) {

}

void GameState::init() {
    this->_data->assets.loadFont("redlight", "../assets/fonts/redlight.ttf");
    this->initButtons();
    this->initPlayers();
}

void GameState::initButtons() {

    // pause button
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

void GameState::initPlayers() {

    std::vector<sf::Keyboard::Key> p1inputs = { sf::Keyboard::Key::A, sf::Keyboard::Key::D, sf::Keyboard::Key::W };
    std::vector<sf::Keyboard::Key> p2inputs = { sf::Keyboard::Key::Left, sf::Keyboard::Key::Right, sf::Keyboard::Key::Up };
    this->player1.init(this->_data, "../assets/textures/ship.png", sf::Vector2i(200, 200), p1inputs);
    this->player2.init(this->_data, "../assets/textures/ship2.png", sf::Vector2i(400, 400), p2inputs);

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

    this->player1.handleInput();
    this->player2.handleInput();

}

void GameState::update(float dt) {

    this->player1.update(dt);
    this->player2.update(dt);

}

void GameState::draw(float dt) {
    this->_data->window.clear(CLEAR_COLOR);

    this->_pauseButton.draw(this->_data->window);
    
    this->player1.draw();
    this->player2.draw();

    this->_data->window.display();
}
