#pragma once

#include <iostream>
#include <string>
#include <functional>

#include <SFML/Graphics.hpp>

#include "GameUtils/GameUtils.hpp"
#include "Button.hpp"
#include "settings.hpp"

class RectButton : public Button {
public:
    RectButton();
    RectButton(
            sf::Vector2f pos, 
            sf::Vector2f size,
            void (*onClickCallback)(ch::GameDataRef data),
            sf::Color background = sf::Color::Black,
            sf::Color activeBackground = sf::Color::Magenta);
    RectButton(
            sf::Vector2f pos, 
            sf::Vector2f size,
            sf::Text label,
            void (*onClickCallback)(ch::GameDataRef data),
            sf::Color background = sf::Color::Black,
            sf::Color activeBackground = sf::Color::Magenta);

    void init();
    void init(
            sf::Vector2f pos,
            sf::Vector2f size,
            void (*onClickCallback)(ch::GameDataRef data),
            sf::Color background = sf::Color::Black,
            sf::Color activeBackground = sf::Color::Magenta);
    void init(
            sf::Vector2f pos, 
            sf::Vector2f size,
            sf::Text label,
            void (*onClickCallback)(ch::GameDataRef data),
            sf::Color background = sf::Color::Black,
            sf::Color activeBackground = sf::Color::Magenta);

    bool isOver(sf::Vector2f pos);
    void (*onClick)(ch::GameDataRef data);

    void onEnter();
    void onLeave();
    void whileActive();

    void draw(sf::RenderWindow& window);
    void update();

    bool isActive = false;

private:
    inline sf::Vector2f getRawPos();
    // returns the position to set the text to in order to center about pos    
    inline sf::Vector2f centerText(sf::Text& text, sf::Vector2f pos);

    sf::Vector2f _size;
    
    sf::Text _label;

    sf::Color _background;
    sf::Color _activeBackground;

    sf::RectangleShape _body;  // the body of the button
};