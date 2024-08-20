#include "game.hpp"
#include "util.hpp"
#include <iostream>

/*
    Initialize a game with proper window size
*/
Game::Game(int width, int height) : width(width), height(height), 
snake(width / 2, height / 2), score(0), gameOver(false) {
    generateFruit();
};

/*
Intialize a created game
*/
void Game::init() {
    score = 0;
    gameOver = false;
    snake = Snake(width / 2, height / 2);
    generateFruit();
}

/*
    Render game graphics using characters
*/
void Game::render(const std::string &playerName) {
    system("clear");
    for (int i= 0; i < width + 2; i++) 
        std::cout << "-";
    std::cout << std::endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= width; j++) {
            if (j == 0 || j == width)
                std::cout << "|";
            else if (i == snake.getY() && j == snake.getX())
                std::cout << "O";
            else if (i == fruitY && j == fruitX)
                std::cout << "#";
            else {
                 bool printedTail = false;
                for (const auto& segment : snake.getTail()) {
                    if (segment.first == j && segment.second == i) {
                        std::cout << "o";
                        printedTail = true;
                        break;
                    }
                }
                if (!printedTail) std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

/*
    Generate fruit at random location
*/
void Game::generateFruit() {
    fruitX = rand() % width;
    fruitY = rand() % height;
}

bool Game::isOver() const {
    return gameOver;
}

int Game::getScore() const {
    return score;
}

/*
    handles input based on keyboard press
*/
void Game::handleInput() {
    if (Util::kbhit()) {
        char input = Util::getch();
        snake.move(input);
        if (input == 'x') gameOver = true;
    }
}

/*
    keep moving in last direction
    check collision with walls and itself
    game over / update the score
*/
void Game::update() {
    snake.move(' '); 
    if (snake.checkCollision(width, height) || snake.checkSelfCollision()) {
        gameOver = true;
    }
    if (snake.getX() == fruitX && snake.getY() == fruitY) {
        score += 10;
        snake.grow();
        generateFruit();
    }
}

