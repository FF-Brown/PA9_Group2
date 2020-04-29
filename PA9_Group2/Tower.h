
//Class Definition File for the base Tower

#pragma once


#include "Projectile.h"
#include "Utility.h"

#include <SFML/Graphics.hpp>

#include <string>

#define SQUARE_SIZE 25 //Size of a square on the board
#define NUM_TOWERS 3

enum TowerType
{
    TURRET,
    SNIPER,
    NONE
};


class Tower
{
protected:
    sf::Vector2f position;

    std::string name;
    TowerType type;
    int price;

    double range; //Pixels
    int attSpeed; //Shots per minute
    double coolDownTime; //In seconds
    int damage;
    int projSpeed; //Projectile speed

    bool activeStatus = true;
    sf::Clock clock;
    sf::Time lastFireTime;


    void update_status(void)
    {
        if (Utility::time_since(clock, lastFireTime).asSeconds() < coolDownTime)
            activeStatus = false;
        else
            activeStatus = true;
    }

    void set_cool_down(void)
        { coolDownTime = 60 / (double)attSpeed; }

public:
    //Constructor with position argument
    Tower(sf::Vector2f initPosition)
    {
        position = initPosition;
        activeStatus = true;

        name = "";
        type = NONE;
        price = 0;
        range = 0;
        attSpeed = 0;
        damage = 0;
        projSpeed = 0;
        coolDownTime = 0;
        lastFireTime = sf::Time();
    }

    //Default Construcctor
    Tower()
    {
        position = { 0, 0 };
        name = "None";
        type = NONE;
        price = 0;
        range = 0;
        attSpeed = 0;
        coolDownTime = 0;
        damage = 0;
        projSpeed = 0;
        lastFireTime = sf::Time();
        activeStatus = false;
    }

    bool is_active(void)
    {
        update_status();
        return activeStatus;
    }

    sf::Vector2f get_center_position(void)
    {
        sf::Vector2f center;
        center.x = position.x + (float)SQUARE_SIZE / 2.f;
        center.y = position.y + (float)SQUARE_SIZE / 2.f;
        return center;
    }

    sf::Vector2f get_position(void)
        { return position; }

    double get_range(void)
        { return range; }

    int get_attack_speed(void)
        { return attSpeed; }

    void fire(void)
        { lastFireTime = clock.getElapsedTime(); }

    int get_damage(void)
        { return damage; }

    void setPosition(sf::Vector2f pos)
        { position = pos; }

    std::string get_name(void)
        { return name; }

    TowerType get_type(void)
        { return type; }

    int get_price(void)
        { return price; }

    int get_proj_speed(void)
        { return projSpeed; }
};

