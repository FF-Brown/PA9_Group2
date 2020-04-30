
//Defines the constructor for each individual round

#include "Round.h"

Round::Round(int roundNum)
{
    num = roundNum;
    switch (roundNum)
    {
    //Define Round 1
    case 1:
        reward = 50;
        spawnCoolDown = 0.8;
        for (int i = 0; i < 3; i++) //3 Basic enemies
            enemyQueue.push(Basic());
        break;

    //Define Round 2
    case 2:
        reward = 65;
        spawnCoolDown = 0.8;
        for (int i = 0; i < 5; i++) //5 basic enemies
            enemyQueue.push(Basic());
        for (int i = 0; i < 2; i++) //2 gaps
            enemyQueue.push(Empty());
        for (int i = 0; i < 5; i++) //5 Basic enemies
            enemyQueue.push(Basic());
        break;

    //Define Round 3
    case 3:
        reward = 80;
        spawnCoolDown = 0.8;
        for (int i = 0; i < 8; i++) //8 basic enemies
            enemyQueue.push(Basic());
        for (int i = 0; i < 2; i++) //2 gaps
            enemyQueue.push(Empty());
        for (int i = 0; i < 8; i++) //8 Basic enemies
            enemyQueue.push(Basic());
        break;

    //Define Round 4
    case 4:
        reward = 100;
        spawnCoolDown = 0.8;
        for (int i = 0; i < 12; i++) //12 Basics
            enemyQueue.push(Basic());
        enemyQueue.push(Empty()); //1 gap
        enemyQueue.push(BigBoi()); //1 BigBoi
        break;

    //Define Round 5
    case 5:
        reward = 105;
        spawnCoolDown = 0.8;
        enemyQueue.push(BigBoi()); //1 BigBoi
        for (int i = 0; i < 8; i++) //8 Basics
            enemyQueue.push(Basic());
        for (int i = 0; i < 2; i++) //2 gaps
            enemyQueue.push(Empty());
        for (int i = 0; i < 4; i++) //5 BigBois
            enemyQueue.push(BigBoi());
        break;

    //Define Round 6
    case 6:
        reward = 110;
        spawnCoolDown = 0.8;
        enemyQueue.push(BigBoi());  //3 BigBois
        enemyQueue.push(Empty());   //1 gap
        for (int i = 0; i < 3; i++) //2 Basics, 1 BigBoi, repeating 6 times
        {
            for (int j = 0; j < 2; j++)
                enemyQueue.push(Basic());
            enemyQueue.push(BigBoi());
        }
        for (int i = 0; i < 2; i++) //2 gaps
            enemyQueue.push(Empty());
        for (int i = 0; i < 5; i++) //5 BigBois
            enemyQueue.push(BigBoi());
        for (int i = 0; i < 10; i++) //10 Basics
            enemyQueue.push(Basic());
        for (int i = 0; i < 2; i++) //2 gaps
            enemyQueue.push(Empty());
        for (int i = 0; i < 5; i++) //5 SpeedyBois
            enemyQueue.push(SpeedyBoi());
        break;

    //Define Round 7
    case 7:
        reward = 115;
        spawnCoolDown = 0.5;
        for (int i = 0; i < 10; i++) //10 Basics
            enemyQueue.push(Basic());
        for (int i = 0; i < 8; i++) //8 BigBois
            enemyQueue.push(BigBoi());
        for (int i = 0; i < 4; i++) //3 gaps
            enemyQueue.push(Empty());
        for (int i = 0; i < 8; i++) //8 SpeedyBois
            enemyQueue.push(SpeedyBoi());
        break;

    //Define Round 8
    case 8:
        reward = 120;
        spawnCoolDown = 0.5;
        for (int i = 0; i < 12; i++)
            enemyQueue.push(BigBoi()); //12 BigBois
        for (int i = 0; i < 2; i++)
            enemyQueue.push(SpeedyBoi()); //5 SpeedyBois
        for (int i = 0; i < 2; i++)
            enemyQueue.push(Empty()); //2 gaps
        for (int i = 0; i < 12; i++)
            enemyQueue.push(BigBoi()); //12 BigBois
        for (int i = 0; i < 20; i++)
            enemyQueue.push(Basic()); //20 Basics
        break;

    //Define Round 9
    case 9:
        reward = 125;
        spawnCoolDown = 0.5;
        for (int i = 0; i < 12; i++) //12 SpeedyBois
            enemyQueue.push(SpeedyBoi());
        for (int i = 0; i < 5; i++) //5 Basics
            enemyQueue.push(Basic());
        for (int i = 0; i < 10; i++) //Alternating BigBoi and gap, repeating 10 times
        {
            enemyQueue.push(BigBoi());
            enemyQueue.push(Empty());
        }
        for (int i = 0; i < 16; i++) //16 SpeedyBois
            enemyQueue.push(SpeedyBoi());
        break;

        //Define Round 10
    case 10:
        reward = 130;
        spawnCoolDown = 0.3;
        for (int i = 0; i < 5; i++) //Alternating Basic and gap, repeating 5 times
        {
            enemyQueue.push(Basic());
            enemyQueue.push(Empty());
        }
        for (int i = 0; i < 5; i++)
            enemyQueue.push(BigBoi()); //5 BigBois
        for (int i = 0; i < 10; i++) //Alternating BigBoi and SpeedyBoi, repeating 20 times
        {
            enemyQueue.push(SpeedyBoi());
            enemyQueue.push(BigBoi());
        }
        break;

        //Define Round 11
    case 11:
        reward = 135;
        spawnCoolDown = 0.3;
        for (int i = 0; i < 10; i++) //Alternating BigBoi and gap, repeating 10 times
        {
            enemyQueue.push(BigBoi());
            enemyQueue.push(Empty());
        }
        for (int i = 0; i < 10; i++) //Alternating BigBoi, Basic, and SpeedyBoi, repeating 20 times
        {
            enemyQueue.push(BigBoi());
            enemyQueue.push(Basic());
            enemyQueue.push(SpeedyBoi());
        }
        break;

    default:
        num = 0;
        reward = 0;
        spawnCoolDown = 0;
    }
}
