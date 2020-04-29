
//Class Definition File for the base Tower

#pragma once


#include "Projectile.h"
#include "Utility.h"

#include <SFML/Graphics.hpp>

#include <string>

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
        lastFireTime = clock.getElapsedTime();
        activeStatus = true;

        name = "";
        type = NONE;
        price = 0;
        range = 0;
        attSpeed = 0;
        coolDownTime = 0;
        damage = 0;
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
        damage - 0;
        lastFireTime = sf::Time();
        activeStatus = false;
    }

    bool is_active(void)
    {
        update_status();
        return activeStatus;
    }

    double get_range(void)
        { return range; }

    int get_attack_speed(void)
        { return attSpeed; }

    void fire(void)
        { lastFireTime = clock.getElapsedTime(); }

    sf::Vector2f get_position(void)
        { return position; }

    int get_damage(void)
        { return damage; }

    std::string get_name(void)
        { return name; }

    TowerType get_type(void)
        { return type; }

    int get_price(void)
        { return price; }
};

