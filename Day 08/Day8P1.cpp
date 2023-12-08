#include <iostream>
#include <vector>
#include <fstream>
#include <utility>

int findPosOfValue (std::string toBeFound, std::vector <std::string> allValues) {
    for (int i = 0; i < allValues.size(); i++) {
        if (toBeFound == allValues.at(i)) {
            return i;
        }
    }
    return 1;
}

int followInstructions (std::vector <std::pair <std::string, std::string>> Options, std::vector <std::string> Locations, std::string Instructions) {
    std::string currLocation = Locations.at(findPosOfValue("AAA", Locations));
    int steps = 0;
    while (currLocation != "ZZZ") {
        for (int i = 0; i < Instructions.length(); i++) {
            int pos = findPosOfValue (currLocation, Locations);
            if (Instructions.at(i) == 'L') {
                currLocation = Options.at(pos).first;
            }
            else {
                currLocation = Options.at(pos).second;
            }
            steps++;
            if (currLocation == "ZZZ") {
                break;
            }
        }
    }
    return steps; 
}

int main() {
    std::fstream myfile;
    std::string a;
    std::string instructions = "LLLRRLRRRLLRRLRRLLRLRRLRRRLRRLRRLRRRLRLRRLRLRRLRRLLRRLRLLRRLLLRRRLRRLRLRLRRRLRLLRRLRRRLRRLRRLRRLRLLRLLRRLRRRLRRLRLRRLRRRLRRLLRLLRRLRRRLLRRRLRLRRRLLRLRRLRRLLRRLRRLLLRRRLRLRRRLRRLLRLRRLRLLRRRLRLRLLRLRRRLRLRRRLRRLRLRLLRLRRRLRRLRRRLRRRLRLRRRLRRRLLLLRLRLRRRLLLRLRRRLRRLRLRRLLRLLRRRR";
    std::pair <std::string, std::string> Options;
    std::vector <std::pair <std::string, std::string>> allOptions;
    std::vector <std::string> Location;
    myfile.open("Day8Input.txt");
    std::getline(myfile, a);
    while (std::getline(myfile, a)) {
        Location.push_back(a.substr(0, 3));
        allOptions.push_back(std::make_pair(a.substr(7, 3), a.substr(12, 3)));
    }
    std::cout << followInstructions(allOptions, Location, instructions);
}