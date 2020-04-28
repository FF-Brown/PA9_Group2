
#include "Enemy.h"

Enemy::Enemy(void)
{
    isEnemy = true;
    shape.setPosition(Board::getStartingPosition());
}

void Enemy::move(Board& board)
{
    float dx, dy;

    switch (board.getDirection(shape.getPosition()))
    {
    case UP:    dx = 0;
                dy = -1 * speed;
                break;
    case DOWN:  dx = 0;
                dy = speed;
                break;
    case LEFT:  dx = -1 * speed;
                dy = 0;
                break;
    case RIGHT: dx = speed;
                dy = 0;
                break;
    default:    dx = 0;
                dy = 0;
    }
    dx *= SPEED_SCALE;
    dy *= SPEED_SCALE;

    shape.move(dx, dy);
}

void Enemy::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}
