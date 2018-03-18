#include "Player.hpp"

Player::Player(ch::GameDataRef gameData, sf::Texture bodyTexture, sf::Vector2i initPos)
    : _gameData(gameData) {
    this->_body.setTexture(bodyTexture);
    this->_tail.setTexture();
}

Player::~Player() {
    
}

void Player::update() {

}

void Player::handleInput() {

}

void Player::draw() {
    this->_body.draw(this->_gameData->window);
    if (this->_firing)
        this->_tail.draw(this->_gameData->window);
}

