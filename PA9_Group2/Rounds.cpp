
#include "Round.h"


Round::Round(int roundNum)
{
    num = roundNum;

    switch (roundNum)
    {
        //Define Round 1: 3 basic enemies
    case 1:
        reward = 100;
        for (int i = 0; i < 3; i++)
            enemyQueue.push(Basic()); //5 Basic enemies
        break;

        //Define Round 2: 2 waves of 3 basic enemies
    case 2:
        reward = 120;
        for (int i = 0; i < 3; i++)
            enemyQueue.push(Basic()); //3 basic enemies
        for (int i = 0; i < 2; i++)
            enemyQueue.push(Empty()); //2 gaps
        for (int i = 0; i < 3; i++)
            enemyQueue.push(Basic()); //3 Basic enemies
        break;

        //Define Round 3: 2 waves of 5 basic enemies
    case 3:
        reward = 150;
        for (int i = 0; i < 5; i++)
            enemyQueue.push(Basic()); //5 basic enemies
        for (int i = 0; i < 2; i++)
            enemyQueue.push(Empty()); //2 gaps
        for (int i = 0; i < 5; i++)
            enemyQueue.push(Basic()); //5 Basic enemies
        break;

        //Define Round 4: 2 waves of 3 basic enemies, then 1 big boi
    case 4:
        reward = 250;
        for (int i = 0; i < 3; i++)
            enemyQueue.push(Basic()); //3 Basics
        for (int i = 0; i < 2; i++)
            enemyQueue.push(Empty()); //2 gaps
        for (int i = 0; i < 3; i++)
            enemyQueue.push(Basic()); //3 Basics
        enemyQueue.push(BigBoi()); //1 BigBoi
        break;

        //Define Round 5: 1 big boi and 5 basics, then another wave of 3 big bois
    case 5:
        reward = 300;
        enemyQueue.push(BigBoi()); //1 BigBoi
        for (int i = 0; i < 5; i++)
            enemyQueue.push(Basic()); //5 Basics
        for (int i = 0; i < 2; i++)
            enemyQueue.push(Empty()); //2 gaps
        for (int i = 0; i < 3; i++)
            enemyQueue.push(BigBoi()); //3 BigBois
        break;
    default:
        num = 0;
        reward = 0;
    }
}
