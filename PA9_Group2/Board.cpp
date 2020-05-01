
#include "Board.h"

using namespace std;

sf::RectangleShape* createGrid(double width, double height, double cellSize) {

    //Number of squares across and down
    int x = width / cellSize, y = height / cellSize, total = x * y;

    double xCoord = 0, yCoord = 0;

    sf::RectangleShape* squareGrid = new sf::RectangleShape[total];

    for (int m = 0; m < total; m++, xCoord += cellSize) {
        squareGrid[m].setSize(sf::Vector2f(cellSize, cellSize));
        squareGrid[m].setFillColor(sf::Color::Black);
        squareGrid[m].setOutlineThickness(2);
        squareGrid[m].setOutlineColor(sf::Color::White);
        if (m % x == 0 && m != 0) {
            xCoord = 0;
            yCoord += cellSize;
        }
        squareGrid[m].setPosition(sf::Vector2f(xCoord, yCoord));
    }

    return squareGrid;
}
void Board::createSpriteGrid(double width, double height, double cellSize)
{
	//Number of squares across and down
	int x = width / cellSize, y = height / cellSize, total = x * y;

	double xCoord = 0, yCoord = 0;

	spriteGrid = new sf::Sprite[total];

	for (int m = 0; m < total; m++, xCoord += cellSize) {
		if (m % x == 0 && m != 0) {
			xCoord = 0;
			yCoord += cellSize;
		}
		spriteGrid[m].setPosition(sf::Vector2f(xCoord, yCoord));
	}
}
Board::Board()
{
	gridWidth = GRID_WIDTH;
	gridHeight = GRID_HEIGHT;
	cellSize = CELL_SIZE;
	//grid = createGrid(gridWidth, gridHeight, cellSize);
	columns = (int)(gridWidth / cellSize);
	rows = (int)(gridHeight / cellSize);
	pathLength = 0;
	squareCount = columns * rows; //(width / cellsize) * (width / cellsize)
	readPath("Resources/path.csv");

	//Load textures
	if (!tower.loadFromFile("Resources/towerWithGrass.png"))
		cout << "Error: Tower texture file not loaded.\n";
	if (!dirt.loadFromFile("Resources/dirtSquareResized.png"))
		cout << "Error: Dirt texture file not loaded.\n";
	if (!grass.loadFromFile("Resources/grassSquareResized.png"))
		cout << "Error: Grass texture file not loaded.\n";
	if (!castle.loadFromFile("Resources/fortressWithGrass.png"))
		cout << "Error: Castle texture file not loaded.\n";
	if (!sniperTower.loadFromFile("Resources/sniperTowerWithGrass.png"))
		cout << "Error: Sniper tower texture file not loaded.\n";
	if (!rapidTower.loadFromFile("Resources/rapidTowerWithGrass.jpg"))
		cout << "Error : Rapid Tower Texture file not loaded\n";

	createSpriteGrid(gridWidth, gridHeight, cellSize);
	drawTextures();
}
void Board::draw(sf::RenderWindow& window)
{
	//Draws grid on board. Must be used BEFORE any calls of window.draw()
	//or it will hide other objects
	for (int i = 0; i < squareCount; ++i) {
		window.draw(spriteGrid[i]);
	}
}
void Board::markPath()
{
	//Draws path on board. Marks player castle 
	//Called by drawTextures() 
	for (int i = 0; i < pathLength; ++i) {
		//grid[path[i]].setFillColor(sf::Color::Red);
		spriteGrid[path[i]].setTexture(dirt);
		//if(i == pathLength - 1)
		//	grid[path[i]].setFillColor(sf::Color::Yellow);
		if (i == pathLength - 1)
			spriteGrid[path[i]].setTexture(castle);
	}
}
void Board::readPath(string fileName)
{
	//Note that grid is a 1D array, not 2D which would be preferrable 
	//Therefore path values are just big numbers
	//Path.csv is dependent on current grid size
	//Can be used with other files for different paths
	//Any csv file used must have all values on a single line and end with a comma
	//See path.csv for reference
	
	fstream inFile;
	inFile.open(fileName, fstream::in);
	if (!inFile) {
		cout << fileName << " failed to open.\n";
		path = 0; //Ensures path is initialized
	}
	else {
		string buff;
		getline(inFile, buff);
		int commaCount = 0, i = 0;
		for (i = 0; i < buff.length(); i++) {
			if (buff[i] == ',')
				++commaCount;
		}
		path = new int[commaCount];
		stringstream s_stream(buff);
		string substr;
		i = 0;
		while (s_stream.good()) {
			getline(s_stream, substr, ',');
			if (substr == "")
				break;
			*(path + i) = stoi(substr);
			++i;
		}
		pathLength = commaCount;
	}
	inFile.close();

}
bool Board::inPath(int square) 
{
	//Determines if a square is in the enemy marching path
	//Can be used for checking if a square is a valid location for a tower
	for (int i = 0; i < pathLength; ++i) {
		if (square == path[i])
			return true;
	}
	return false;
}
Board::~Board()
{
	delete[] path;
	delete[] grid;
}
int Board::getSquareCoord(double x, double y)
{
	int column = 0, row = 0;
	int cellNumber = 0;

	if (x >= 0 && x < gridWidth && y >= 0 && y < gridHeight) {
		row = y / cellSize;
		column = x / cellSize;
		cellNumber = (row * columns) + column;
		return cellNumber;
	}
	else
		return -1;
}
void Board::colorCell(int cellNum)
{
	grid[cellNum].setFillColor(sf::Color::Blue); 
}
bool Board::addTower(sf::Vector2f position, TowerType nTowerType)
{
    if (nTowerType == NONE)
        return false;

    int cell = getSquareCoord(position.x, position.y);
	if (cell == -1)
		return false;

	position = spriteGrid[cell].getPosition();
	bool result = true;
	//Check that not in path
	if (inPath(cell)) {
		cout << "Cell is in enemy path.\n";
		result = false;
	}
	else {
		//Check that no tower there
		if (!isOpen(position)) {
			cout << "Cell is occupied.\n";
			result = false;
		}
		else {
			//Add tower 
            switch (nTowerType)
            {
            case TURRET: towers[towerCount] = Turret(position);
                         spriteGrid[cell].setTexture(tower); 
                         break;
            case SNIPER: towers[towerCount] = Sniper(position);
                         spriteGrid[cell].setTexture(sniperTower); 
                         break;
            case RAPID:  towers[towerCount] = Rapid(position);
                         spriteGrid[cell].setTexture(rapidTower); //Change this to sniper texture
                         break;
            }
			++towerCount;
		}
	}
	return result;
}
bool Board::isOpen(sf::Vector2f position)
{
	if (towerCount == 0)
		return true;
	for (int i = 0; i < towerCount; ++i) { 
		if ((towers + i)->get_position() == position)
			return false;
	}
	return true;
}
sf::Vector2f Board::getStartingPosition(void)
{
	//Lazy way: just report default starting point
	return sf::Vector2f(387, -12);
	//Better way: report first square on path
}
Direction Board::getDirection(sf::Vector2f position)
{
	int cell = getSquareCoord(position.x, position.y);
	int index = -1;
	Direction prevDir = DOWN;
	if (cell == -1) {
		//cout << "Coordinates not on board.\n";
		return DOWN;
	}
	for (int i = 0; i < pathLength; ++i) {
		if (path[i] == cell)
			index = i;
	}
	if (index == -1) {
		cout << "(" << position.x << "," << position.y << ") " <<  "Coordinates not in path.\n";
		return DOWN;
	}
	else if (index == 0)
		return DOWN;
	//Get previous direction
	if (path[index - 1] + 20 == path[index])
		prevDir = DOWN;
	else if (path[index - 1] - 1 == path[index])
		prevDir = LEFT;
	else if (path[index - 1] - 20 == path[index])
		prevDir = UP;
	else if (path[index - 1] + 1 == path[index])
		prevDir = RIGHT;
	
	//Down
	if(path[index] + 20 == path[index + 1]) {
		int midpoint = (spriteGrid[path[index]].getPosition().x + spriteGrid[path[index] + 1].getPosition().x) / 2;
		if (position.x <= midpoint)
			return DOWN;
		else
			return prevDir;
	}
	//Up
	if (path[index] - 20 == path[index + 1]) {
		int midpoint = (spriteGrid[path[index]].getPosition().x + spriteGrid[path[index] + 1].getPosition().x) / 2;
		if (position.x <= midpoint)
			return UP;
		else
			return prevDir;
	}
	//Right
	if(path[index] + 1 == path[index + 1]) {
		int midpoint = (spriteGrid[path[index]].getPosition().y + spriteGrid[path[index] + 20].getPosition().y) / 2;
		if (position.y >= midpoint)
			return RIGHT;
		else
			return prevDir;
	}
	//Left
	if(path[index] - 1 == path[index + 1]) {

		int midpoint = (spriteGrid[path[index]].getPosition().y + spriteGrid[path[index] + 20].getPosition().y) / 2;
		if (position.y >= midpoint)
			return LEFT;
		else
			return prevDir;
	}
	//cout << "Path could not be determined.\n";

	return DOWN;
}
void Board::drawTextures()
{
	for (int i = 0; i < squareCount; ++i) {
		spriteGrid[i].setTexture(grass);
	}
	markPath();
}

bool Board::isAtEnd(sf::Vector2f position)
{
	int cell = getSquareCoord(position.x, position.y);
	if (cell == -1) {
		//cout << "Enemy location error.\n";
		return false;
	}
	if (path[pathLength - 1] == cell)
		return true;
	else
		return false;
}
