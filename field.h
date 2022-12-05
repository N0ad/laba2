#include <vector>
#include <string>
#pragma once
using namespace std;

class cell
{
public:
	cell(int val);
	~cell();

	int value;
	int lifeNeighbours;
};



class field
{
	public:
		field() = default;
		~field();
		field& setField(int xSize, int ySize, string bornRule, string deathRule, string n);

		int sizeX;
		int sizeY;
		vector <vector <cell> > area;
		string born;
		string death;
		int lifeCells;
		int checkAction = 0;
		string name;

		field& setCell(int x, int y);
		field& deathCell(int x, int y, vector <vector <cell> > base);
		field& bornCell(int x, int y, vector <vector <cell> > base);
		bool check(int val, string data);

		field& iteration();
};

