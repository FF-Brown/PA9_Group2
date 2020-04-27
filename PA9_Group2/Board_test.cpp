

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
	sf::Vector2f position(0, 0), position2(375,0), oddPosition(27, 3);

	//Test rounding coordinates
	test.addTower(oddPosition);
	if (!test.isOpen(sf::Vector2f(25, 0)))
		cout << "addTower(): Coordinate adjustment test passed.\n";
	else
		cout << "addTower(): Coordinate adjustment test failed.\n";
	
	//Test placing a tower in the enemy path (invalid)
	//Should be 0
	returned = test.addTower(position2); 
	if (returned == 0) 
		cout << "addTower(): Path test passed.\n";
	else
		cout << "addTower(): Path test returned " << returned << ". Should be 0.\n";

	//Test placing a tower in a valid position
	//Should be 1
	returned = test.addTower(position); 
	if (returned == 1)
		cout << "addTower(): Valid test passed.\n";
	else
		cout << "addTower(): Valid test returned " << returned << ". Should be 1\n";

	//Test placing a tower in an occupied position (invalid)
	//Should be -1
	returned = test.addTower(position);
	if(returned == -1)
		cout << "addTower(): Occupied test passed.\n";
	else
		cout << "addTower(): Occupied test returned " << returned << ". Should be -1\n";



}
void assert(string testName, bool testCase, string errorMessage)
{
	if (testCase)
		cout << testName << " test passed.\n";
	else
		cout << testName << " test failed." << errorMessage << endl; 
}