#include "Player.hpp"

Player::Player(ch::GameDataRef gameData, std::string bodyTexLoc, sf::Vector2i initPos, std::vector<sf::Keyboard::Key> inputs) {
    this->init(gameData, bodyTexLoc, initPos, inputs);
}

void Player::init(ch::GameDataRef gameData, std::string bodyTexLoc, sf::Vector2i initPos, std::vector<sf::Keyboard::Key> inputs) {
    this->_gameData = gameData;
    this->inputActivations.left = { inputs[0], false };
    this->inputActivations.right = { inputs[1], false };
    this->inputActivations.fire = { inputs[2], false };
    
    this->_gameData->assets.loadTexture("p1Tex", bodyTexLoc);
    this->_gameData->assets.loadTexture("p1Tex_t", "../assets/anims/rocketfire.png");

    this->_body.setTexture(this->_gameData->assets.getTexture("p1Tex"));
    this->_tail.init(this->_gameData->assets.getTexture("p1Tex_t"), 128.0f, 0.25f);

    this->inputActivations.left.isActive = false;
    this->inputActivations.right.isActive = false;
    this->inputActivations.fire.isActive = false;
    
}

void Player::update(float dt) {
    this->_body.rotate(this->data.avel);
    this->_body.move(this->data.vel.x, this->data.vel.y);

    this->data.bounds = this->_body.getGlobalBounds();
}

void Player::handleInput() {
    this->_gameData->input.getKeyboardActivation(this->inputActivations.left);
    this->_gameData->input.getKeyboardActivation(this->inputActivations.right);
    this->_gameData->input.getKeyboardActivation(this->inputActivations.fire);

    if (this->inputActivations.left.isActive) {
        this->data.avel -= this->_turnSpeed;
    }
    if (this->inputActivations.right.isActive) {
        this->data.avel += this->_turnSpeed;
    }
    if (this->inputActivations.fire.isActive) {
        this->data.vel.x += this->_fforce * std::cos(this->_body.getRotation());
        this->data.vel.y += this->_fforce * std::sin(this->_body.getRotation());
    }
}

void Player::draw() {
    this->_gameData->window.draw(this->_body);
    if (this->_firing)
        this->_tail.draw(this->_gameData->window);
}

