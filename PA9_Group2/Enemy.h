

#pragma once

//Included Project Files
#include "Board.h"
enum Direction { UP, DOWN, LEFT, RIGHT }; class Board { public: Direction get_direction(); }; //temp

//Included SFML Libraries
#include <SFML/Graphics.hpp>


class Enemy
{
protected:
    unsigned int ID;

public:
    bool isEnemy;

    Enemy(void);

    void set_ID(int nID)
    {
        ID = nID;
    }

    unsigned int get_ID(void)
    {
        return ID;
    }


    void move(Board& board);

    void draw(sf::RenderWindow& window);
};
