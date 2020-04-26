

#include "Board_test.h"

BoardTest::BoardTest() : Board()
{
}

BoardTest::~BoardTest()
{
}

void BoardTest::testAddTower()
{
	bool result;
	int returned;
	Board test;
	sf::Vector2f position(0, 0), position2(375,0);
	
	returned = test.addTower(position2); 
	if (returned == 1)
		cout << "addTower(): Path test passed.\n";
	else
		cout << "addTower(): Path test returned " << returned << ". Should be 1.\n";

	returned = test.addTower(position); 
	if (returned == 1)
		cout << "addTower(): Valid test passed.\n";
	else
		cout << "addTower(): Valid test returned " << returned << "Should be 1\n";

	returned = test.addTower(position);
	if(returned == -1)
		cout << "addTower(): Occupied test passed.\n";
	else
		cout << "addTower(): Occupied test returned " << returned << "Should be -1\n";

}