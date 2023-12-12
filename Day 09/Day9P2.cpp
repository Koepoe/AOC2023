#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>

int findNextNumber (std::vector <std::vector <int>> numberSet) {
    std::vector <std::vector <int>> numbers;
    std::vector <int> differences = {};
    int total = 0;
    int difference = 0;
    for (int k = 0; k < numberSet.size(); k++) {
        bool finished = false;
        int n = 0;
        numbers.clear();
        numbers.push_back(numberSet.at(k));
        while (!(finished)) {
            for (int i = 0; i < numbers.at(n).size() - 1; i++) {
                difference = numbers.at(n).at(i + 1) - numbers.at(n).at(i);
                differences.push_back(difference);
            }
            if (std::accumulate(differences.begin(), differences.end(), 0) == 0) {
                finished = true;
                differences.push_back(0);
            }
            numbers.push_back(differences);
            differences.clear();
            n++;
        }
        for (int i = numbers.size() - 2; i >= 0; i--) {
            numbers.at(i).push_back(numbers.at(i + 1).at(numbers.at(i + 1).size() - 1) + numbers.at(i).at(numbers.at(i).size() - 1));
        }
        total += numbers.at(0).at(numbers.at(0).size() - 1);
    }
    return total; 
}

int main() {
    std::fstream myfile;
    std::string a;
    std::vector <std::vector <int>> numbers;
    std::vector <int> numbersPerLine;
    int number = 0;
    myfile.open("Day9Input.txt");
    while (std::getline(myfile, a)) {
        numbersPerLine.clear();
        std::istringstream ss(a);
        while (ss >> number) {
            numbersPerLine.push_back(number);
        }
        std::reverse(numbersPerLine.begin(), numbersPerLine.end());
        numbers.push_back(numbersPerLine);
    }
    std::cout << findNextNumber(numbers);
}