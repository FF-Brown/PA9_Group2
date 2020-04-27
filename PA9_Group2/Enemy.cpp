
#include "Enemy.h"

Enemy::Enemy(void)
{
    isEnemy = true;
    //position = board.get_starting_position();
}

void Enemy::move(const Board& board)
{
    //Calculate distance to move from speed and potential frost/glue effect

    //switch (board.get_direction_to_move())
    //{
    //case UP:
    //    break;
    //case DOWN:
    //    break;
    //case LEFT:
    //    break;
    //case RIGHT:
    //    break;
    //}
}

void Enemy::draw(sf::RenderWindow& window)
{

}
