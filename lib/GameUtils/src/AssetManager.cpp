#include "AssetManager.hpp"

namespace ch {

    void AssetManager::loadTexture(std::string name, std::string filename) {
        sf::Texture tex;

        if (tex.loadFromFile(filename))
            this->_textures[name] = tex;
    }

    sf::Texture &AssetManager::getTexture(std::string name) {
        return this->_textures.at(name);
    }

    void AssetManager::loadFont(std::string name, std::string filename) {
        sf::Font font;

        if (font.loadFromFile(filename))
            this->_fonts[name] = font;
    }

    sf::Font &AssetManager::getFont(std::string name) {
        return this->_fonts.at(name);
    }

}