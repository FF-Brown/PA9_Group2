/*
Authors: Derek Henderson, Koji Nastuhara, Nathan Brown, Sammy West
Description: Epic tower defense game
*/

#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
    window.setFramerateLimit(60);

    //creating tower
    Tower t1;
    std::vector<Tower> towers;

    //creating bullets
    Bullet b1;
    std::vector<Bullet> bullets;

    //creating enemies
    Enemy e1;
    std::vector<Enemy> enemies;
    int enemySpawnTimer = 0;

    sf::Vector2f mousePosWindow;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;
    float range;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Update
        mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(window));

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            t1.shape.setPosition(mousePosWindow);
            towers.push_back(Tower(t1));
        }

        if (!enemies.empty() && !towers.empty())
        {
            for (size_t j = 0; j < towers.size(); j++)
            {
                if (towers[j].shootTimer < towers[j].atkSpeed)
                    towers[j].shootTimer++;

                std::cout << towers[0].shootTimer << std::endl;
                for (size_t i = 0; i < enemies.size(); i++)
                {
                    towers[j].playerCenter = sf::Vector2f(towers[j].shape.getPosition().x + towers[j].shape.getRadius(), towers[j].shape.getPosition().y + towers[j].shape.getRadius());
                    enemies[i].enemyPosWindow = sf::Vector2f(enemies[i].shape.getPosition().x + enemies[i].shape.getSize().x / 2,
                        enemies[i].shape.getPosition().y + enemies[i].shape.getSize().x / 2);
                    aimDir = enemies[i].enemyPosWindow - towers[j].playerCenter;
                    aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
                    range = abs(aimDirNorm.x) + abs(aimDirNorm.y);

                    if (enemies[i].alive && towers[j].shootTimer >= towers[j].atkSpeed && range <= towers[j].range) //sf::Mouse::isButtonPressed(sf::Mouse::Left)
                    {
                        b1.shape.setPosition(towers[j].playerCenter);
                        b1.currVelocity = aimDirNorm * b1.maxSpeed;
                        bullets.push_back(Bullet(b1));
                        towers[j].shootTimer = 0;
                    }
                }
            }
        }

        for (size_t i = 0; i < bullets.size(); i++)
        {
            bullets[i].shape.move(bullets[i].currVelocity);
            if (bullets[i].shape.getPosition().x < 0 || bullets[i].shape.getPosition().x > window.getSize().x
                || bullets[i].shape.getPosition().y < 0 || bullets[i].shape.getPosition().y > window.getSize().y)
            {
                bullets.erase(bullets.begin() + i);
            }
            else
            {
                //Enemy collision
                for (size_t k = 0; k < enemies.size(); k++)
                {
                    if (bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
                    {
                        bullets.erase(bullets.begin() + i);
                        enemies[k].health = enemies[k].health - t1.damage;
                        enemies[k].checkHealth();
                        if (enemies[k].health <= 0)
                        {
                            enemies[k].alive = false;
                            enemies.erase(enemies.begin() + k);
                        }
                        break;
                    }
                }
            }
        }

        //Enemies
        if (enemySpawnTimer < 150)
            enemySpawnTimer++;

        if (enemySpawnTimer >= 150) //>= 150
        {
            //enemy.setPosition(0.f, rand() % int(window.getSize().y - enemy.getSize().y - 250.f));
            enemies.push_back(Enemy(e1));
            enemySpawnTimer = 0;
        }

        for (size_t i = 0; i < enemies.size(); i++)
        {
            enemies[i].shape.move(0.5f, 0.f);
            if (enemies[i].shape.getPosition().x > window.getSize().x)
            {
                enemies.erase(enemies.begin() + i);
            }
        }

        window.clear();

        for (size_t i = 0; i < towers.size(); i++)
            window.draw(towers[i].shape);
        for (size_t i = 0; i < enemies.size(); i++)
            window.draw(enemies[i].shape);
        for (size_t i = 0; i < bullets.size(); i++)
            window.draw(bullets[i].shape);
        window.display();
    }
	return 0;
}
