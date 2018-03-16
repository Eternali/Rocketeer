#include <string>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

#include <Box2D/Box2D.h>

#include "GameUtils/GameUtils.hpp"

#include "MenuState.hpp"
#include "settings.hpp"

int main() {

    ch::Game game(WINDOW_WIDTH, WINDOW_HEIGHT, "Blocker");

    game.getData()->machine.addState(ch::StateRef(new MenuState(game.getData())));

    game.run();

    return EXIT_SUCCESS;
}