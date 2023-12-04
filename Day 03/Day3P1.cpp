#include <iostream>
#include <vector>
#include <fstream>

std::vector <int> getNumbers (std::vector <std::string> schematic) {
    int number = 0;
    bool valid = false;
    std::vector <int> numbers;
    for (int i = 0; i < schematic.size(); i++) {
        for (int j = 0; j < schematic.at(i).length(); j++) {
            while (isdigit(schematic.at(i).at(j))) {
                number = 10 * number + (schematic.at(i).at(j) - '0');
                if (!(isdigit(schematic.at(i - 1).at(j - 1))) && schematic.at(i - 1).at(j - 1) != '.') { // TopLeft
                    valid = true;
                } 
                if (!(isdigit(schematic.at(i - 1).at(j))) && schematic.at(i - 1).at(j) != '.') { // TopMid
                    valid = true;
                }
                if (!(isdigit(schematic.at(i - 1).at(j + 1))) && schematic.at(i - 1).at(j + 1) != '.') { // TopRight
                    valid = true;
                }
                if (!(isdigit(schematic.at(i).at(j + 1))) && schematic.at(i).at(j + 1) != '.' && j) { // RightMid
                    valid = true;
                }
                if (!(isdigit(schematic.at(i + 1).at(j + 1))) && schematic.at(i + 1).at(j + 1) != '.') { // BottomRight
                    valid = true;
                }
                if (!(isdigit(schematic.at(i + 1).at(j))) && schematic.at(i + 1).at(j) != '.') { // BottomMid
                    valid = true;
                }
                if (!(isdigit(schematic.at(i + 1).at(j - 1))) && schematic.at(i + 1).at(j - 1) != '.') { // BottomLeft
                    valid = true;
                }
                if (!(isdigit(schematic.at(i).at(j - 1))) && schematic.at(i).at(j - 1) != '.') { // LeftMid
                    valid = true;
                }
                j++;
            }
            if (valid) {
                numbers.push_back(number);
                valid = false;
            }
            number = 0;
        }
    }   
    return numbers;
}

int main() {
    std::fstream myfile;
    std::string a;
    std::string b;
    std::string c;
    std::vector <std::string> engine;
    std::vector <int> parts;
    int total = 0;
    myfile.open("Day3Input.txt");
    for (int i = 0; i < 141; i++) {
        c += '.';
    }
    engine.push_back(c);
    while (std::getline(myfile, a)) {
        b = '.' + a;
        engine.push_back(b);
    }
    engine.push_back(c);
    parts = getNumbers(engine);
    for (int i = 0; i < parts.size(); i++) {
        total += parts.at(i);
    } 
    std::cout << total; 
}