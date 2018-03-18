#pragma once

#include <string>
#include <cmath>

#include <SFML/Graphics.hpp>

class Animation {
public:
    Animation(std::string textureLocation, float frameWidth, float speed, int pos = 0);

    void update(float dt);
    void draw(sf::RenderWindow &window);

    int pos;
private:
    int _maxPos;
    float _fwidth;
    float _speed;
    float _accum = 0.0f;

    sf::Texture _texture;
    sf::IntRect _srcRect;
    sf::Sprite _body;
};