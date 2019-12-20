#include "Grid.h"
#include <iostream>

void Grid::inputString(std::string& input,int lengthOfGrid) {
	int heightOfGrid = input.length() / lengthOfGrid;
	for (int i = 0; i < heightOfGrid+1; i++) {
		grid1.push_back(StringManipulator.SplitToVector(input, i * lengthOfGrid, (i + 1) * lengthOfGrid - 1));
	}
}

int Grid::MultiplyInDirection(Grid::Direction Dir, int length,int index_x, int index_y) {
	int DirVert;
	int DirHor;

	switch (Dir) {
	case Grid::DOWN:
		DirVert = 1;
		DirHor = 0;
		break;
	
	case Grid::RIGHT:
		DirVert = 0;
		DirHor = 1;
		break;

	case Grid::DOWN_LEFT:
		DirVert = 1;
		DirHor = -1;
		break;

	case Grid::DOWN_RIGHT:
		DirVert = 1;
		DirHor = -1;
		break;

	default:
		DirVert = 0;
		DirHor = 0;
	}
	int VerLimit = (DirVert * length) + index_y;
	int HorLimit = (DirHor * length) + index_x;
	if (0 > VerLimit || VerLimit > grid1.size()) {
		return 0;
	}
	if (0 > HorLimit || HorLimit > grid1[0].size()) {
		return 0;
	}


	int output = 1;

	for (int i = 0; i < length; i++) {
		output *= stoi(grid1[index_y][index_x]);
		index_x += DirHor;
		index_y += DirVert;
	}

	return output;
}