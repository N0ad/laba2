#include "field.h"
#include <vector>
#include <string>
using namespace std;

cell::cell(int val) {
	value = val;
	lifeNeighbours = 0;
}

field& field::setField(int xSize, int ySize, string bornRule, string deathRule, string n) {
	sizeX = xSize;
	sizeY = ySize;
	born = bornRule;
	death = deathRule;
	name = n;
	lifeCells = 0;
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			area[i][j] = 0;
		}
	}
	return *this;
}



field& field::bornCell(int x, int y, vector <vector <cell> > base) {
	if (area[y][x].value == 0) {
		if (check(base[y][x].lifeNeighbours, born)) {
			for (int i = y - 1; i <= y + 1; i++) {
				for (int j = x - 1; j <= x + 1; j++) {
					area[i % sizeY][j % sizeX].lifeNeighbours++;
				}
			}
			area[y][x].lifeNeighbours--;
			area[y][x].value = 1;
			lifeCells++;
		}
	}
	return *this;
}

field& field::deathCell(int x, int y, vector <vector <cell> > base) {
	if (area[y][x].value == 0) {
		if (not check(base[y][x].lifeNeighbours, death)) {
			for (int i = y - 1; i <= y + 1; i++) {
				for (int j = x - 1; j <= x + 1; j++) {
					area[i % sizeY][j % sizeX].lifeNeighbours--;
				}
			}
			area[y][x].lifeNeighbours++;
			area[y][x].value = 0;
			lifeCells--;
			checkAction = 1;
		}
	}
	return *this;
}

bool check(int val, string data) {
	int ch = 0;
	for (int i = 0; i < data.length(); i++) {
		if (val == data[i] - '0') {
			ch = 1; 
			break;
		}
	}
	return (ch == 1);
}

field& field::iteration() {
	vector <vector <cell> > copyArea = area;
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			this->deathCell(j, i, copyArea);
			if (checkAction == 0) {
				this->bornCell(i, j, copyArea);
			}
			checkAction = 0;
		}
	}
	return *this;
}

field& field::setCell(int x, int y) {
	if (area[y][x].value == 0) {
		for (int i = y - 1; i <= y + 1; i++) {
			for (int j = x - 1; j <= x + 1; j++) {
				area[i % sizeY][j % sizeX].lifeNeighbours++;
			}
		}
		area[y][x].lifeNeighbours--;
		area[y][x].value = 1;
		lifeCells++;
	}
	return *this;
}

