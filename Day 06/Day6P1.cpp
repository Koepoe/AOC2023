#include <iostream>
#include <vector>
#include <fstream>

std::vector <int> getNumbers(std::string input) {
    int number = 0;
    std::vector <int> numbers;
    for (int i = 0; i < input.length(); i++) {
        if (isdigit(input.at(i))) {
            number = 10 * number + (input.at(i) - '0');
        }
        else if ((!(isdigit(input.at(i))) || i == input.length() - 1)  && number > 0) {
            numbers.push_back(number);
            number = 0;
        }
    }
    return numbers;
}

int main() {
    std::fstream myfile;
    std::string a = "";
    std::vector <int> time;
    std::vector <int> distance;
    int totalDistance = 0;
    int timeRemaining = 0;
    int total = 1;
    int waysToWin = 0;
    myfile.open("Day6Input.txt");
    std::getline(myfile, a);
    time = getNumbers(a);
    std::getline(myfile, a);
    distance = getNumbers(a);
    for (int j = 0; j < time.size(); j++) {
        waysToWin = 0;
        for (int i = 1; i < time.at(j); i++) {
            timeRemaining = time.at(j) - i;
            totalDistance = timeRemaining * i;
            if (totalDistance > distance.at(j)) {
                waysToWin++;
            }
        }
        total *= waysToWin;
    }
    std::cout << total;
    return 0;
}