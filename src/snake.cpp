#include "snake.hpp"

Snake::Snake(int initX, int initY) : x(initX), y(initY) {};

int Snake::getX() const {
    return x;
}

int Snake::getY() const {
    return y;
}

std::vector<std::pair<int, int>> Snake::getTail() const {
    return tail;
}

/*
    Grows the snake
*/
void Snake::grow() {
    tail.push_back({x, y});
}

/*
    Moves the snake based on pressed key.

*/
void Snake::move(char direction) {
    int prevX = x, prevY = y;
    if (direction == 'a') x--;
    else if (direction == 'd') x++;
    else if (direction == 'w') y--;
    else if (direction == 's') y++;
    
    for (long i = tail.size(); i > 0; i--) {
        tail[i] = tail[i - 1];
    }
    tail[0] = std::make_pair(prevX, prevY);
}

/*
    Checks collision with the walls in the game
*/
bool Snake::checkCollision(int width, int height) const {
    return x >= width || x < 0 || y >= height || y < 0;
}

/*
    Checks collision with the snake itself
*/
bool Snake::checkSelfCollision() const {
    for (const auto &segment : tail) {
        if (segment.first == x && segment.second == y) {
            return true;
        }
    }
    return false;
}

