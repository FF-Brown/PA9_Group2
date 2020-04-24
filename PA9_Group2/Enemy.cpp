
#include "Enemy.h"

Enemy::Enemy(void)
{
    isEnemy = true;
}

void Enemy::move(Board& board)
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
