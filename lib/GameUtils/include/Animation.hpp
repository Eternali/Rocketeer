#pragma once

#include <cmath>
#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

namespace ch {

    struct SpriteData {
        sf::Vector2f vel;
        float avel;
        sf::FloatRect bounds;
    };

    typedef std::shared_ptr<SpriteData> SpriteDataRef;

    class Animation {
    public:
        Animation() {  };
        Animation(
            sf::Vector2f initPos,
            float initRot,
            sf::Vector2f center,
            sf::Texture texture,
            float frameWidth,
            float speed,
            int pos = 0,
            SpriteDataRef data = nullptr);

        void init(
            sf::Vector2f initPos,
            float initRot,
            sf::Vector2f center,
            sf::Texture texture,
            float frameWidth,
            float speed,
            int pos = 0,
            SpriteDataRef data = nullptr);

        void update(float dt);
        void draw(sf::RenderWindow &window);

        SpriteDataRef data;
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