#pragma once

#include "Board.h"

/*
    Board board;
    int test = 0;
    BoardTest testBoard;
    testBoard.testAddTower();

    return 0;
*/
#include <string> 

class BoardTest : Board
{
public:
	BoardTest();
	~BoardTest();
	void testAddTower(); 
    void assert(string testName, bool testCase, string errorMessage); 

private:

};

/*
    while (window.isOpen()) {
        //Input detection
        sf::Event event;

        //Check if the window was closed
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();

            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    test = board.getSquareCoord(event.mouseButton.x, event.mouseButton.y);
                    if (test != -1)
                        board.colorCell(test);
                }
            }

        }

        //Render
        window.clear();
        board.displayBoard(window);
        window.display();
    }
    return 0;
*/