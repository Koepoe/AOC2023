#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

int checkNumbers(std::vector <int> own, std::vector <int> win) {
    int matches = 0;
    for (int i = 0; i < win.size(); i++) {
        for (int j = 0; j < own.size(); j++) {
            if ((win.at(i) == own.at(j))) {
                matches++;
            }
        }
    }
    return matches;
}

int main() {
    std::fstream myfile;
    std::string a = "";
    int number = 0;
    myfile.open("Day4Input.txt");
    std::vector <int> ownNumbers;
    std::vector <int> winningNumbers;
    std::vector <int> amtMatches;
    std::vector <int> total;
    while (std::getline(myfile, a)) {
        bool ownNumber = false;
        for (int i = 8; i < a.length(); i++) {
            if (isdigit(a.at(i))) {
                number = 10 * number + (a.at(i) - '0');
            }
            else if (a.at(i) == '|') {
                ownNumber = true;
            }
            else if (a.at(i) == ':') {

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
        amtMatches.push_back(checkNumbers(ownNumbers, winningNumbers));
        total.push_back(1);
        ownNumbers.clear();
        winningNumbers.clear();
    }
    for (int i = 0; i < amtMatches.size(); i++) {
        for (int j = i + 1; j < amtMatches.at(i) + i + 1; j++) {
            total.at(j) += total.at(i);
        }
    }  
    int sum = 0;
    for (int n = 0; n < total.size(); n++) {
        sum += total.at(n);
    } 
    std::cout << sum;
}