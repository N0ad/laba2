#include <string>
#include <fstream>
#include <iostream>
#include "field.h"
#include "commands.h"
using namespace std;

int main() {
    string File, line, name, ruleB, ruleS;
    int counter;
    field area;

    ifstream in(File);
    if (in.is_open()) {
        getline(in, line);
        if (line != "#Life 1.06") {
            //ошибка неверного формата входного файла 
        }
        getline(in, line);
        if (line.substr(0, 3) == "#N ") {
            line.erase(0, 3);
            name = line;
        }
        else {
            //ошибка неверного формата входного файла 
        }
        getline(in, line);
        if (line.substr(0, 3) == "#R B") {
            line.erase(0, 3);
            counter = 0;
            while (1) {
                if (line.substr(counter, 2) == "/S") {
                    ruleB = line.substr(0, counter);
                    ruleS = line.substr(counter + 2);
                    break;
                }
                counter++;
                if (counter > line.length()) {
                    //неверный формат входного файла
                    break;
                }
            }
        }
        else {
            //ошибка неверного формата входного файла 
        }
        getline(in, line);
        if (line.substr(0, 3) == "#S ") {
            line.erase(0, 3);
            counter = 0;
            while (1) {
                if (line[counter] == ' ') {
                    area.setField(stoi(line.substr(0, counter)), stoi(line.substr(counter + 1)), ruleB, ruleS, name);
                    break;
                }
                counter++;
                if (counter > line.length()) {
                    //неверный формат входного файла
                    break;
                }
            }
        }
        else {
            //ошибка неверного формата входного файла 
        }
        while (getline(in, line)) {
            if ((line == "\0") || (line == "\n")) {
                break;
            }
            counter = 0;
            while (1) {
                if (line[counter] == ' ') {
                    area.setCell(stoi(line.substr(0, counter)), stoi(line.substr(counter)));
                    break;
                }
                counter++;
                if (counter > line.length()) {
                    //неверный формат входного файла
                    break;
                }
            }
        }
    }
    in.close();

	return 0;
}