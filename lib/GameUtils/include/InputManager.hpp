#pragma once

#include <list>

#include <SFML/Graphics.hpp>

namespace ch {

    struct KeyActivation {
        sf::Keyboard::Key key;
        bool isActive;
    };

    class InputManager {
    public:
        InputManager() {  }
        ~InputManager() {  }

        bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
        sf::Vector2f getMousePosition(sf::RenderWindow &window);
        void getKeyboardActivation(KeyActivation &key);
        // void getKeyboardActivation(std::list<KeyActivation> keys);
    };

}
