#pragma once

#include <iostream>
#include <cmath>

#include <SFML/Graphics.hpp>

namespace ch {

    struct SpriteData {
        sf::Vector2f vel;
        float avel;
        sf::FloatRect bounds;
    };

    class Animation {
    public:
        Animation() {  };
        Animation(
            sf::Vector2f initPos,
            SpriteData data,
            float initRot,
            sf::Vector2f center,
            sf::Texture texture,
            float frameWidth,
            float speed,
            int pos = 0);

        void init(
            sf::Vector2f initPos,
            SpriteData data,
            float initRot,
            sf::Vector2f center,
            sf::Texture texture,
            float frameWidth,
            float speed,
            int pos = 0);

        void update(float dt, sf::Vector2f vel, float avel);
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

}