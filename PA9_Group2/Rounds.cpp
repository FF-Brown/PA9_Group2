
#include "Round.h"


Round::Round(int roundNum)
{
    num = roundNum;

    switch (roundNum)
    {
        //Define Round 1: 3 basic enemies
    case 1:
        reward = 50;
        for (int i = 0; i < 3; i++)
            enemyQueue.push(Basic()); //5 Basic enemies
        break;

        //Define Round 2: 2 waves of 3 basic enemies
    case 2:
        reward = 70;
        for (int i = 0; i < 3; i++)
            enemyQueue.push(Basic()); //3 basic enemies
        for (int i = 0; i < 2; i++)
            enemyQueue.push(Empty()); //2 gaps
        for (int i = 0; i < 3; i++)
            enemyQueue.push(Basic()); //3 Basic enemies
        break;

        //Define Round 3: 2 waves of 5 basic enemies
    case 3:
        reward = 95;
        for (int i = 0; i < 5; i++)
            enemyQueue.push(Basic()); //5 basic enemies
        for (int i = 0; i < 2; i++)
            enemyQueue.push(Empty()); //2 gaps
        for (int i = 0; i < 5; i++)
            enemyQueue.push(Basic()); //5 Basic enemies
        break;

        //Define Round 4: 2 waves of 3 basic enemies, then 1 big boi
    case 4:
        reward = 110;
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
        reward = 125;
        enemyQueue.push(BigBoi()); //1 BigBoi
        for (int i = 0; i < 5; i++)
            enemyQueue.push(Basic()); //5 Basics
        for (int i = 0; i < 2; i++)
            enemyQueue.push(Empty()); //2 gaps
        for (int i = 0; i < 3; i++)
            enemyQueue.push(BigBoi()); //3 BigBois
        break;

        //Define Round 6:
    case 6:
        reward = 150;
        enemyQueue.push(BigBoi());  //1 BigBoi
        enemyQueue.push(Empty());   //1 gap
        for (int i = 0; i < 3; i++) //2 Basics, 1 BigBoi, repeating 4 times
        {
            for (int j = 0; j < 3; j++)
                enemyQueue.push(Basic());
            enemyQueue.push(BigBoi());
        }
        for (int i = 0; i < 2; i++)
            enemyQueue.push(Empty()); //2 gaps
        for (int i = 0; i < 5; i++)
            enemyQueue.push(BigBoi()); //5 BigBois
        for (int i = 0; i < 5; i++)
            enemyQueue.push(Basic()); //5 Basics
        break;

        //Define Round 7:
    case 7:
        reward = 170;
        for (int i = 0; i < 15; i++) //15 Basics
            enemyQueue.push(Basic());
        for (int i = 0; i < 7; i++)
            enemyQueue.push(BigBoi()); //7 BigBois
        break;

        //Define Round 8
    case 8:
        reward = 190;
        for (int i = 0; i < 10; i++)
            enemyQueue.push(BigBoi()); //10 BigBois
        for (int i = 0; i < 20; i++)
            enemyQueue.push(Basic()); //20 Basics
        break;
    default:
        num = 0;
        reward = 0;
    }
}
