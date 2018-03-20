#pragma once

#include <iostream>
#include <cmath>
#include <string>

#include <SFML/Graphics.hpp>

#include "GameUtils/GameUtils.hpp"
#include "settings.hpp"

struct PlayerInput {
    ch::KeyActivation left;
    ch::KeyActivation right;
    ch::KeyActivation fire;
};

class Player {
public:
    Player() {  };
    Player(ch::GameDataRef gameData, std::string bodyTexLoc, sf::Vector2f initPos, std::vector<sf::Keyboard::Key> inputs);

    void init(ch::GameDataRef gameData, std::string bodyTexLoc, sf::Vector2f initPos, std::vector<sf::Keyboard::Key> inputs);

    void update(float dt);
    void handleInput();
    void draw();

    PlayerInput inputActivations;
    ch::SpriteDataRef data;
private:
    ch::GameDataRef _gameData;

    bool _firing = false;
    float _angle;  // angle in radians

    sf::Sprite _body;
    ch::Animation _tail;

    float _turnSpeed = 5.5f;
    float _fforce = 0.2f;
    float _bounce = 0.3f;
};