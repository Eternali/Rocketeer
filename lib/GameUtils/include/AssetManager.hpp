#pragma once

#include <map>

#include <SFML/Graphics.hpp>

namespace ch {

    class AssetManager {
    public:
        AssetManager() {  }
        ~AssetManager() {  }

        void loadTexture(std::string name, std::string filename);
        sf::Texture &getTexture(std::string name);

        void loadFont(std::string name, std::string filename);
        sf::Font &getFont(std::string name);

        std::string defaultTex;
    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
    };

}