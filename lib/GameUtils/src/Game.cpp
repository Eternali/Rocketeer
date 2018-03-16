#include "Game.hpp"

namespace ch {

    Game::Game(int width, int height, std::string title) {
        this->_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    }

    GameDataRef Game::getData() {
        return this->_data;
    }

    void Game::run() {
        float newTime, frameTime, interpolation;
        float curTime = this->_clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while (this->_data->window.isOpen()) {
            this->_data->machine.processStateChanges();

            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - curTime;

            if (frameTime > 0.25f) frameTime = 0.25f;
            curTime = newTime;
            accumulator += frameTime;

            while (accumulator >= dt) {
                this->_data->machine.getActiveState()->handleInput();
                this->_data->machine.getActiveState()->update(dt);
                accumulator -= dt;
            }

            interpolation = accumulator / dt;
            this->_data->machine.getActiveState()->draw(interpolation);
        }
    }

}
