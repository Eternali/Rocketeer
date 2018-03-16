#include "RectButton.hpp"

RectButton::RectButton() {  }

RectButton::RectButton(
        sf::Vector2f pos, 
        sf::Vector2f size,
        void (*onClickCallback)(ch::GameDataRef data),
        sf::Color background,
        sf::Color activeBackground)
        : Button(pos),
        _size(size),
        _background(background),
        _activeBackground(activeBackground) {
    this->onClick = onClickCallback;
    this->init();
}

RectButton::RectButton(
        sf::Vector2f pos, 
        sf::Vector2f size,
        sf::Text label,
        void (*onClickCallback)(ch::GameDataRef data),
        sf::Color background,
        sf::Color activeBackground)
        : Button(pos),
        _size(size),
        _label(label),
        _background(background),
        _activeBackground(activeBackground) {
    this->onClick = onClickCallback;
    this->_label = label;
    this->_label.setPosition(this->getRawPos());

    this->init();
}

void RectButton::init() {
    this->_body = sf::RectangleShape();
    this->_body.setPosition(this->getRawPos());
    this->_body.setSize(this->_size);
    this->_body.setFillColor(this->_background);
}

void RectButton::init(
        sf::Vector2f pos, 
        sf::Vector2f size,
        void (*onClickCallback)(ch::GameDataRef data),
        sf::Color background,
        sf::Color activeBackground) {
    this->_pos = pos;
    this->_size = size;
    this->_background = background;
    this->_activeBackground = activeBackground;
    this->onClick = onClickCallback;

    this->init();
}

void RectButton::init(
        sf::Vector2f pos, 
        sf::Vector2f size,
        sf::Text label,
        void (*onClickCallback)(ch::GameDataRef data),
        sf::Color background,
        sf::Color activeBackground) {
    this->init(pos, size, onClickCallback, background, activeBackground);

    this->_label = label;
    this->_label.setPosition(this->centerText(this->_label, this->_pos));
}

bool RectButton::isOver(sf::Vector2f pos) {
    float left = this->_pos.x - this->_size.x / 2;
    float right = this->_pos.x + this->_size.x / 2;
    float top = this->_pos.y - this->_size.y / 2;
    float bottom = this->_pos.y + this->_size.y / 2;
    
    return (pos.x >= left && pos.x <= right) && (pos.y >= top && pos.y <= bottom);
}

void RectButton::onEnter() {
    this->state.isHovered = true;
    this->_body.setFillColor(this->_activeBackground);
}

void RectButton::onLeave() {
    this->state.isHovered = false;
    this->_body.setFillColor(this->_background);
}

void RectButton::whileActive() {
    
}

void RectButton::draw(sf::RenderWindow& window) {
    window.draw(this->_body);
    window.draw(this->_label);
}

void RectButton::update() {
    
}

inline sf::Vector2f RectButton::getRawPos() {
    return sf::Vector2f(this->_pos.x - this->_size.x / 2.0f,
                        this->_pos.y - this->_size.y / 2.0f);
}

inline sf::Vector2f RectButton::centerText(sf::Text& text, sf::Vector2f pos) {
    return sf::Vector2f(pos.x - text.getLocalBounds().width / 2,
                        pos.y - text.getLocalBounds().height / 2);
};
