#include "InputManager.hpp"

namespace ch {

    bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window) {
        if (sf::Mouse::isButtonPressed(button)) {
            sf::IntRect tempRect(object.getPosition().x,
                                 object.getPosition().y,
                                 object.getGlobalBounds().width,
                                 object.getGlobalBounds().height);
            if (tempRect.contains(sf::Mouse::getPosition(window)))
                return true;
        }

        return false;
    }

    sf::Vector2f InputManager::getMousePosition(sf::RenderWindow &window) {
        return static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    }

}
