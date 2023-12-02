#include <iostream>
#include <fstream>
#include <vector>

int getNumbers(std::vector <int> numbers) {
    int firstAndLast;
    firstAndLast = 10 * numbers.at(0) + numbers.at(numbers.size() - 1);
    return firstAndLast;
}

int main() {
    std::string a;
    std::ifstream myfile;
    std::vector <int> allNumbers;
    int total = 0;
    myfile.open("Day1Input.txt");
    while (std::getline(myfile, a)) {
        for (int i = 0; i < a.length(); i++) {
            if (isdigit(a.at(i))) {
                allNumbers.push_back(a.at(i) - '0');
            }
        }
        if (allNumbers.size() == 1) {
            allNumbers.push_back(allNumbers.at(0));
        }
        total += getNumbers(allNumbers);
        allNumbers.clear();
    }
    std::cout << total << std::endl;
    myfile.close();
}