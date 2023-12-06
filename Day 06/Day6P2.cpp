#include <iostream>
#include <vector>
#include <fstream>

long getNumbers(std::string input) {
    long number = 0;
    for (int i = 0; i < input.length(); i++) {
        if (isdigit(input.at(i))) {
            number = 10 * number + (input.at(i) - '0');
        }
    }
    return number;
}

int main() {
    std::fstream myfile;
    std::string a = "";
    int time = 0;
    long distance = 0;
    long totalDistance = 0;
    int timeRemaining = 0;
    int waysToWin = 0;
    myfile.open("Day6Input.txt");
    std::getline(myfile, a);
    time = getNumbers(a);
    std::getline(myfile, a);
    distance = getNumbers(a);
    for (long i = 0; i < time / 2; i++) {
        timeRemaining = time - i;
        totalDistance = timeRemaining * i;
        if (totalDistance > distance) {
            waysToWin++;
        }
    } 
    std::cout << waysToWin * 2 + 1;
    return 0;
}