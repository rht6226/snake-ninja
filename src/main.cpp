#include <iostream>
#include <unistd.h>
#include "game.hpp"

int main() {
    std::string playerName;
    std::cout << "Enter your name: ";
    std::cin >> playerName;

    Game game(100, 100);
    game.init();

    while (!game.isOver()) {
        game.render(playerName);
        game.handleInput();
        game.update();
        usleep(100000);
    }

    std::cout << "Game Over! Your score is: " << game.getScore() << std::endl;
    return 0;
}