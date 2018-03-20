#include "Animation.hpp"

namespace ch {

    Animation::Animation(
        sf::Vector2f initPos,
        float initRot,
        sf::Vector2f center,
        sf::Texture texture,
        float frameWidth,
        float speed,
        int pos,
        SpriteDataRef data) {

        this->init(initPos, initRot, center, texture, frameWidth, speed, pos, data);

    }

    void Animation::init(
        sf::Vector2f initPos,
        float initRot,
        sf::Vector2f center,
        sf::Texture texture,
        float frameWidth,
        float speed,
        int pos,
        SpriteDataRef data) {

        this->data = data;

        this->_texture = texture;
        this->_fwidth = frameWidth;
        this->_speed = speed;
        this->pos = pos;

        this->_srcRect = sf::IntRect(pos * this->_fwidth, 0, this->_fwidth, static_cast<float>(this->_texture.getSize().y));

        this->_body.setTexture(this->_texture);
        this->_body.setTextureRect(this->_srcRect);
        this->_body.setOrigin(center);
        this->_body.setPosition(initPos);
        this->_body.setRotation(initRot);

        this->_maxPos = std::round(this->_texture.getSize().x - this->_fwidth / this->_fwidth);

    }

    /**
     * Update logic outline:
     * 1: accumulator is updated with the time since the sprite was last rendered
     * 2: if this is less than the frequency of animation, just return
     * 3: position delta is calculated from the accumulated timedelta / frequency of animation
     * 4: update accumulator with time consumed by this animation
     * 5: if the animation position will extend beyond texture range limits,
     *    reverse the direction and reduce position delta by difference consumed by wrap-around
     * 6: update rotation, position(s), move animator source rect, and update sprite texture view.
     */
    void Animation::update(float dt) {
        this->_accum += dt;
        // if (this->_accum < std::abs(this->_speed)) return;
        
        int delta = std::round(this->_accum / this->_speed);
        this->_accum -= this->_accum / std::abs(this->_speed);
        if (this->pos + delta > this->_maxPos || this->pos + delta < 0) {
            this->_speed *= -1;
            delta -= ((this->pos + delta < 0) ? 0 : this->_maxPos) - this->pos;
        }

        this->_body.rotate(this->data->avel);
        this->_body.move(this->data->vel.x, this->data->vel.y);
        this->pos += delta;
        this->_srcRect.left = this->pos * this->_fwidth;
        this->_body.setTextureRect(this->_srcRect);
    }

    void Animation::draw(sf::RenderWindow &window) {
        window.draw(this->_body);
    }

}