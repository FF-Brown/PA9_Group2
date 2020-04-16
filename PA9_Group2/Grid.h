#pragma once


#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


// May have to redo. Might need to be a collection of squares instead of a collection of lines
sf::VertexArray createGrid(double width, double height, double cellSize);