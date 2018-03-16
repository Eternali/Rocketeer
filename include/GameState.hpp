#pragma once

#include <list>

#include <SFML/Graphics.hpp>

#include "GameUtils/GameUtils.hpp"

#include "Button.hpp"
#include "RectButton.hpp"

class GameState : public ch::State {
public:
    GameState(ch::GameDataRef data);

    void init();

    void handleInput();
    void update(float dt);
    void draw(float dt);  // deltatime for framerate independence

private:
    void initButtons();

    ch::GameDataRef _data;

    sf::Clock _clock;

    // buttons
    RectButton _pauseButton;

    // sprites
    std::list<sf::Sprite> stars;
    sf::Sprite _ship;
};
