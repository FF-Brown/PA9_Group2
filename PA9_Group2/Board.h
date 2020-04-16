#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
using namespace std;
//class for game board with grid, display options, enemy marching path, rules for acceptable builds (can't build on the same square 2x, etc)


sf::VertexArray createGrid(double width, double height, double cellSize);
