# pragma once
# include <vector>

class Snake {
    private:
        int x, y;
        std::vector<std::pair<int, int>> tail;
    public:
        Snake(int initX, int initY);
        void move(char direction);
        void grow();
        bool checkSelfCollision() const;
        bool checkCollision(int width, int height) const;
        int getX() const;
        int getY() const;
        std::vector<std::pair<int, int>> getTail() const;
};