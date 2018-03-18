#pragma once

#include <SFML/Graphics.hpp>

#include "GameUtils/GameUtils.hpp"

struct PlayerData {
    sf::Vector2f vel;
    sf::Vector2i bounds;
};

class Player {
public:
    Player(ch::GameDataRef gameData, sf::Texture &body);
    ~Player();

    void update();
    void handleInput();
    void draw();

    PlayerData data;

private:

    ch::GameDataRef _gameData;

    bool _firing = false;

    sf::Sprite _body;
    sf::Sprite _tail;

};