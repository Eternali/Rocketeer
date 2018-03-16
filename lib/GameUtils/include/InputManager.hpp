#pragma once

#include <SFML/Graphics.hpp>

namespace ch {

    class InputManager {
    public:
        InputManager() {  }
        ~InputManager() {  }

        bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
        sf::Vector2f getMousePosition(sf::RenderWindow &window);
    };

}
