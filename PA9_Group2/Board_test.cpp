

#include "Board_test.h"

void BoardTest::testAddTower()
{
	sf::RenderWindow window(sf::VideoMode(800, 500), "Tower Defense");

	bool result;
	int returned;
	Board test;
	sf::Vector2f position(100, 275), position2(375,0), oddPosition(27, 3), slightyInvalid(105,280), superInvalid(600, 300);

	//Test rounding coordinates
	cout << "Test msg: Should place tower at (25,0)\n";
	test.addTower(oddPosition);
	assert("addTower(): Coordinate adjustment", !test.isOpen(sf::Vector2f(25, 0)), "");

	//Test placing a tower in the enemy path (invalid)
	returned = test.addTower(position2); 
	assert("addTower(): Path", returned == 0, "Should be 0");

	//Test placing a tower in a valid position
	cout << "Test msg: Should place tower at (100,275)\n";
	returned = test.addTower(position); 
	assert("addTower(): Valid", returned == 1, "Should be 1");

	//Test placing a tower in an occupied position (invalid)
	returned = test.addTower(position);
	assert("addTower(): Occupied", returned == -1, "Should be -1");

	//Test placing a tower in an occupied position (invalid)
	returned = test.addTower(slightyInvalid);
	assert("addTower(): Occupied2", returned == -1, "Should be -1");

	//Test placing a tower outside of the grid (invalid)
	returned = test.addTower(superInvalid);
	assert("addTower(): Outside range", returned == -1, "Should be -1");

	cout << test.getTowerCount() << " towers placed.\n";
	testPrint(window, test);
}
void BoardTest::testGetDirection()
{
	Board test;
	Direction result;
	sf::Vector2f invalidPos(155, 227), downPos(310,110), leftPos(375,115), badDownPos(324,100), badLeftPos(320,280);

	cout << "Test msg: Should print 'Coordinates not in path.'\n";
	result = test.getDirection(invalidPos);
	assert("getDirection(): Invalid", result == DOWN, "Should be DOWN");

	result = test.getDirection(downPos);
	assert("getDirection(): Down", result == DOWN, "Should be DOWN");

	result = test.getDirection(leftPos);
	assert("getDirection(): Left", result == LEFT, "Should be LEFT");

	result = test.getDirection(badDownPos);
	assert("getDirection(): Not yet down", result == LEFT, "Should be LEFT");

	result = test.getDirection(badLeftPos);
	assert("getDirection(): Not yet left", result == DOWN, "Should be DOWN");

}
void BoardTest::testPrint(sf::RenderWindow& window, Board& test)
{	
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) 
				window.close();
		}

		//Render
		window.clear();
		test.draw(window);
		window.display();
	}
}
void BoardTest::testIsAtEnd()
{
	Board test;
	bool result;
	sf::Vector2f endPos(49,425), endPos2(40,440), invalidPos(600,300), notEndPos(60,425);

	result = test.isAtEnd(endPos);
	assert("isAtEnd(): End position", result, "Should be true.");
	result = test.isAtEnd(endPos2);
	assert("isAtEnd(): End position 2", result, "Should be true.");
	cout << "Test msg: Should print a location error.\n";
	result = test.isAtEnd(invalidPos);
	assert("isAtEnd(): Invalid position", !result, "Should be false.");
	result = test.isAtEnd(notEndPos);
	assert("isAtEnd(): Not end position", !result, "Should be false.");

}
void BoardTest::assert(string testName, bool testCase, string errorMessage)
{
	if (testCase)
		cout << testName << " test passed.\n";
	else
		cout << testName << " test failed." << errorMessage << endl; 
}