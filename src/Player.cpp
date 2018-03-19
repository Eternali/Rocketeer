#include "Player.hpp"

Player::Player(ch::GameDataRef gameData, std::string bodyTexLoc, sf::Vector2f initPos, std::vector<sf::Keyboard::Key> inputs) {
    this->init(gameData, bodyTexLoc, initPos, inputs);
}

void Player::init(ch::GameDataRef gameData, std::string bodyTexLoc, sf::Vector2f initPos, std::vector<sf::Keyboard::Key> inputs) {
    this->_gameData = gameData;
    this->inputActivations.left = { inputs[0], false };
    this->inputActivations.right = { inputs[1], false };
    this->inputActivations.fire = { inputs[2], false };
    
    this->_gameData->assets.loadTexture("p1Tex", bodyTexLoc);
    this->_gameData->assets.loadTexture("p1Tex_t", "../assets/anims/rocketfire.png");

    // initialize drawable bodies
    this->_body.setTexture(this->_gameData->assets.getTexture("p1Tex"));
    this->_body.setOrigin(this->_body.getLocalBounds().width / 2, this->_body.getLocalBounds().height / 2);
    this->_body.setPosition(initPos);
    this->_tail.init(this->_gameData->assets.getTexture("p1Tex_t"), 128.0f, 0.25f);

    // resize sprites to targets
    sf::Vector2f bodyTargetSize(64.0f, 128.0f);
    this->_body.setScale(
        bodyTargetSize.x / this->_body.getLocalBounds().width,
        bodyTargetSize.y / this->_body.getLocalBounds().height);

    this->inputActivations.left.isActive = false;
    this->inputActivations.right.isActive = false;
    this->inputActivations.fire.isActive = false;
    
}

void Player::update(float dt) {
    this->_body.rotate(this->data.avel);
    this->_body.move(this->data.vel.x, this->data.vel.y);

    // adjust to SFML's rotation scheme (and translate to radians)
    this->data.angle = (this->_body.getRotation() + 90.0f) * (M_PI / 180.0f);
    this->data.bounds = this->_body.getGlobalBounds();

    // check out of bounds
    if (this->data.bounds.left <= 0)
        this->data.vel.x = this->_bounce;
    else if (this->data.bounds.left + this->data.bounds.width >= this->_gameData->window.getSize().x)
        this->data.vel.x = -this->_bounce;
    if (this->data.bounds.top <= 0)
        this->data.vel.y = this->_bounce;
    else if (this->data.bounds.top + this->data.bounds.height >= this->_gameData->window.getSize().y)
        this->data.vel.y = -this->_bounce;
}

void Player::handleInput() {
    this->_gameData->input.getKeyboardActivation(this->inputActivations.left);
    this->_gameData->input.getKeyboardActivation(this->inputActivations.right);
    this->_gameData->input.getKeyboardActivation(this->inputActivations.fire);

    if (this->inputActivations.left.isActive && this->data.avel >= 0)
        this->data.avel = -this->_turnSpeed;
    else if (this->inputActivations.right.isActive && this->data.avel <= 0)
        this->data.avel = this->_turnSpeed;
    else this->data.avel = 0;

    if (this->inputActivations.fire.isActive) {
        this->data.vel.x -= this->_fforce * std::cos(this->data.angle);
        this->data.vel.y -= this->_fforce * std::sin(this->data.angle);
    }

    // adjust for friction and prevent overcompensation
    if (this->data.vel.x - FRICTION > 0) this->data.vel.x -= FRICTION;
    else if (this->data.vel.x + FRICTION < 0) this->data.vel.x += FRICTION;
    else this->data.vel.x = 0.0f;
    if (this->data.vel.y - FRICTION > 0) this->data.vel.y -= FRICTION;
    else if (this->data.vel.y + FRICTION < 0) this->data.vel.y += FRICTION;
    else this->data.vel.y = 0.0f;
}

void Player::draw() {
    this->_gameData->window.draw(this->_body);
    if (this->_firing)
        this->_tail.draw(this->_gameData->window);
}

