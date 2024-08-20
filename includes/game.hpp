# pragma once
# include <string>
# include "snake.hpp"

class Game {
    private:
        int width, height;
        int fruitX, fruitY;
        int score;
        bool gameOver;
        Snake snake;
        void generateFruit();
    public:
        Game(int initWidth, int initHeight);
        void init();
        void render(const std::string &playerName);
        void update();
        void handleInput();
        bool isOver() const;
        int getScore() const;
};