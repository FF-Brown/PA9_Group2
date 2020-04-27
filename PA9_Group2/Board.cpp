
#include "Board.h"

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
Board::Board()
{
	gridWidth = GRID_WIDTH;
	gridHeight = GRID_HEIGHT;
	cellSize = CELL_SIZE;
	grid = createGrid(gridWidth, gridHeight, cellSize);
	columns = (int)(gridWidth / cellSize);
	rows = (int)(gridHeight / cellSize);
	pathLength = 0;
	squareCount = columns * rows; //(width / cellsize) * (width / cellsize)
	readPath("path.csv");
	markPath();
}
void Board::draw(sf::RenderWindow& window)
{
	//Draws grid on board. Must be used BEFORE any other calls of window.draw()
	//or it will hide other objects
	for (int i = 0; i < squareCount; ++i) {
		window.draw(grid[i]);
	}
}
void Board::markPath()
{
	//Draws path on board in red. Marks player castle yellow
	for (int i = 0; i < pathLength; ++i) {
		grid[path[i]].setFillColor(sf::Color::Red);
		if(i == pathLength - 1)
			grid[path[i]].setFillColor(sf::Color::Yellow);
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
int Board::addTower(sf::Vector2f position)
{
	//printf("Input: (%.1f, %.1f)\n", position.x, position.y);
	int cell = getSquareCoord(position.x, position.y);
	//cout << "Cell number " << cell << endl;
	position = grid[cell].getPosition();
	//printf("Corrected input: (%.1f, %.1f)\n", position.x, position.y);
	int result = 1;
	//Check that not in path
	if (inPath(cell)) {
		cout << "Cell is in enemy path.\n";
		result = 0;
	}
	else {
		//Check that no tower there
		if (!isOpen(position)) {
			cout << "Cell is occupied.\n";
			result = -1;
		}
		else {
			//Add tower 
			Tower newTower;
			newTower.setPosition(position);
			towers[towerCount] = newTower;
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
		if ((towers + i)->getPosition() == position)
			return false;
	}
	return true;
}
//Function to detect corners
//Dependent on current grid size
//Will need to be redone with better math to accomodate any size
