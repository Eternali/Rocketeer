#pragma once

#include <SFML/Graphics.hpp>

#include "GameUtils/GameUtils.hpp"

#include "RectButton.hpp"
#include "Player.hpp"

class GameState : public ch::State {
public:
    GameState(ch::GameDataRef data);

    void init();

    void handleInput();
    void update(float dt);
    void draw(float dt);  // deltatime for framerate independence

private:
    void initButtons();
    void initPlayers();

    ch::GameDataRef _data;

    sf::Clock _clock;

    // buttons
    RectButton _pauseButton;

    // background
    std::vector<sf::Sprite> _stars;
    
    // characters
    Player player1;
    Player player2;
};
