
//Class Definition File for the base Tower

#pragma once

//Included project files
#include "Projectile.h"
#include "Utility.h"

//Included SFML library
#include <SFML/Graphics.hpp>

//Included std libraries
#include <string>

#define SQUARE_SIZE 25 //Size of a square on the board
#define NUM_TOWERS 4

//Enum for each type of tower
enum TowerType
{
    TURRET,
    SNIPER,
    RAPID,
    NONE
};


class Tower
{
protected:
    sf::Vector2f position;

    std::string name;
    TowerType type;
    int price;

    double range; //In pixels
    int attSpeed; //Shots per minute
    double coolDownTime; //In seconds
    int damage;
    int projSpeed; //Projectile speed

    bool activeStatus = true;
    sf::Clock clock;
    sf::Time lastFireTime;

    //Updates the active status of the tower based on cool down time
    void update_status(void)
    {
        if (Utility::time_since(clock, lastFireTime).asSeconds() < coolDownTime)
            activeStatus = false;
        else
            activeStatus = true;
    }

    //Sets the cool down time based on attack speed
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

    //Updates the active status and returns it
    bool is_active(void)
    {
        update_status();
        return activeStatus;
    }

    //Returns the coordinate of the center of the tower
    sf::Vector2f get_center_position(void)
    {
        sf::Vector2f center;
        center.x = position.x + (float)SQUARE_SIZE / 2.f;
        center.y = position.y + (float)SQUARE_SIZE / 2.f;
        return center;
    }

    //Returns the coordinate of the tower origin
    sf::Vector2f get_position(void)
        { return position; }

    //Resets the clock for tracking cool down time
    void fire(void)
        { lastFireTime = clock.getElapsedTime(); }

    double get_range(void)
        { return range; }

    int get_attack_speed(void)
        { return attSpeed; }

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

