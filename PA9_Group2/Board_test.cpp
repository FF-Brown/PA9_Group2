

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
	test.addTower(oddPosition, TURRET);
	assert("addTower(): Coordinate adjustment", !test.isOpen(sf::Vector2f(25, 0)), "");

	//Test placing a tower in the enemy path (invalid)
	returned = test.addTower(position2, TURRET);
	assert("addTower(): Path", returned == 0, "Should be 0");

	//Test placing a tower in a valid position
	cout << "Test msg: Should place tower at (100,275)\n";
	returned = test.addTower(position, TURRET);
	assert("addTower(): Valid", returned == 1, "Should be 1");

	//Test placing a tower in an occupied position (invalid)
	returned = test.addTower(position, TURRET);
	assert("addTower(): Occupied", returned == -1, "Should be -1");

	//Test placing a tower in an occupied position (invalid)
	returned = test.addTower(slightyInvalid, TURRET);
	assert("addTower(): Occupied2", returned == -1, "Should be -1");

	//Test placing a tower outside of the grid (invalid)
	returned = test.addTower(superInvalid, TURRET);
	assert("addTower(): Outside range", returned == -1, "Should be -1");

	cout << test.getTowerCount() << " towers placed.\n";
	testPrint(window, test);
}
void BoardTest::testGetDirection()
{
	Board test;
	Direction result;
	sf::Vector2f invalidPos(155, 227), downPos(375,12), leftPos(375,100), downPos2(324,100), leftPos2(150,280);

	cout << "Test msg: Should print 'Coordinates not in path.'\n";
	result = test.getDirection(invalidPos);
	assert("getDirection(): Invalid", result == DOWN, "Should be DOWN");

	result = test.getDirection(downPos);
	assert("getDirection(): Down", result == DOWN, "Should be DOWN");

	result = test.getDirection(leftPos);
	assert("getDirection(): Left", result == LEFT, "Should be LEFT");

	result = test.getDirection(downPos2);
	assert("getDirection(): Down2", result == DOWN, "Should be DOWN");

	result = test.getDirection(leftPos2);
	assert("getDirection(): Left2", result == LEFT, "Should be LEFT");

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
void BoardTest::assert(string testName, bool testCase, string errorMessage)
{
	if (testCase)
		cout << testName << " test passed.\n";
	else
		cout << testName << " test failed." << errorMessage << endl; 
}