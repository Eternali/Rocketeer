#pragma once

#include <SFML/Graphics.hpp>

#include "GameUtils/GameUtils.hpp"

#include "Button.hpp"
#include "RectButton.hpp"

class MenuState : public ch::State {
public:
    MenuState(ch::GameDataRef data);

    void init();

    void handleInput();
    void update(float dt);
    void draw(float dt);  // deltatime for framerate independence

private:
    void initButtons();

    ch::GameDataRef _data;

    sf::Clock _clock;
    sf::Sprite _background;

    RectButton _startButton;
};
