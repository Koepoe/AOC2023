#include <iostream>
#include <vector>
#include <fstream>
#include <utility>

std::vector <int> findPosOfBeginValues(std::vector <std::string> allValues) {
    std::vector <int> pos;
    for (int i = 0; i < allValues.size(); i++) {
        if (allValues.at(i).at(allValues.at(i).length() - 1) == 'A') {
            pos.push_back(i);
        }
    }
    return pos;
}

std::vector <int> findPosOfValues(std::vector <std::string> allValues, std::vector <std::string> valuesToBeFound) {
    std::vector <int> pos;
    for (int i = 0; i < allValues.size(); i++) {
        for (int j = 0; j < valuesToBeFound.size(); j++) {
            if (allValues.at(i) == valuesToBeFound.at(j)) {
                pos.push_back(i);
            }
        } 
    }  
    return pos;
}

bool checkVector(std::vector <std::string> currLocations) {
    for (int i = 0; i < currLocations.size(); i++) {
        if (currLocations.at(i).at(currLocations.at(i).length() - 1) != 'Z') {
            return false;
        }
    }
    return true;
}

int followInstructions (std::vector <std::pair <std::string, std::string>> Options, std::vector <std::string> Locations, std::string Instructions) {
    std::vector <std::string> currLocations;;
    std::vector <int> beginPos = findPosOfBeginValues(Locations);
    std::vector <int> locationsOfInstructions;
    bool finished = false;
    for (int i = 0; i < beginPos.size(); i++) {
        currLocations.push_back(Locations.at(beginPos.at(i)));
    }
    int steps = 0;
    while (!(finished)) {
        for (int i = 0; i < Instructions.length(); i++) {
            locationsOfInstructions = findPosOfValues(Locations, currLocations);
            if (Instructions.at(i) == 'L') {
                for (int n = 0; n < currLocations.size(); n++) {
                    currLocations.at(n) = Options.at(locationsOfInstructions.at(n)).first;
                    currLocations.at(n) = Options.at(locationsOfInstructions.at(n)).first;
                }
            }
            else {
                for (int j = 0; j < currLocations.size(); j++) {
                    currLocations.at(j) = Options.at(locationsOfInstructions.at(j)).second;
                    currLocations.at(j) = Options.at(locationsOfInstructions.at(j)).second;
                }
            }
            steps++;
            if (checkVector(currLocations)) {
                break;
            }
        }
        finished = checkVector(currLocations);
    }
    std::cout << currLocations.at(0) << " " << currLocations.at(1);
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