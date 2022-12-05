#include "commands.h"
#include "field.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void dump(field data, string path) {
    ofstream out(path);
    if (out.is_open()) {
        out << "#N " + data.name + "\n";
        out << "#R B" + data.born + "/S" + data.death + "\n";
        out << "#S " + to_string(data.sizeX) + " " + to_string(data.sizeY) + "\n";
        for (int i = 0; i < data.sizeY; i++) {
            for (int j = 0; j < data.sizeX; j++) {
                if (data.area[i][j].value == 1) {
                    out << to_string(j) + " " + to_string(i) + "\n";
                }
            }
        }
    }
    out.close();
    return;
};

void tick(field data, int n) {
    for (int i = 0; i < n; i++) {
        data.iteration();
    }
    //вывести результат на экран
};