#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

int checkNumbers(std::vector <int> own, std::vector <int> win) {
    int points = 0;
    int matches = 0;
    for (int i = 0; i < win.size(); i++) {
        for (int j = 0; j < own.size(); j++) {
            if ((win.at(i) == own.at(j))) {
                matches++;
            }
        }
    }
    if (matches > 0) {
        points += pow(2, matches - 1);
    }
    return points;
}

int main() {
    std::fstream myfile;
    std::string a = "";
    int number = 0;
    int total = 0;
    myfile.open("Day4Input.txt");
    std::vector <int> ownNumbers;
    std::vector <int> winningNumbers;
    while (std::getline(myfile, a)) {
        bool ownNumber = false;
        for (int i = 8; i < a.length(); i++) {
            if (isdigit(a.at(i))) {
                number = 10 * number + (a.at(i) - '0');
            }
            else if (a.at(i) == '|') {
                ownNumber = true;
            }
            if (!(isdigit(a.at(i))) && number > 0 && ownNumber) {
                ownNumbers.push_back(number);
                number = 0;
            }
            if (!(isdigit(a.at(i))) && number > 0 && !(ownNumber)) {
                winningNumbers.push_back(number);
                number = 0;
            }
        }
        total += checkNumbers(ownNumbers, winningNumbers);
        ownNumbers.clear();
        winningNumbers.clear();
    }
    std::cout << total << std::endl; 
}