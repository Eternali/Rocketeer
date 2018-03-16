#pragma once

#include <SFML/Graphics.hpp>
#include "GameUtils/GameUtils.hpp"

struct ButtonState {
    bool isHovered;
    bool isActive;
};

class Button {
public:
    Button() {  };
    Button(sf::Vector2f pos) : _pos(pos) {  };

    virtual void init() = 0;

    virtual bool isOver(sf::Vector2f pos) = 0;
    void (*onClick)(ch::GameDataRef data);

    virtual void onEnter() {  };
    virtual void onLeave() {  };

    virtual void onLongPress() {  };
    virtual void onDoubleClick() {  };
    virtual void onRelease() {  };

    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void update() = 0;

    ButtonState state;  // stores state of button    
    
protected:
    sf::Vector2f _pos;  // position of center of button in window
};