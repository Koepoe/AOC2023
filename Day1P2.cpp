#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int getNumbers(std::vector <int> numbers) {
    int firstAndLast;
    firstAndLast = 10 * numbers.at(0) + numbers.at(numbers.size() - 1);
    return firstAndLast;
}

int containsNumber (std::string part) {
    std::vector <std::string> numbersSpelledOut = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (int i = 0; i < numbersSpelledOut.size(); i++) {
        if (part.find(numbersSpelledOut.at(i)) != std::string::npos) {
            i++;
            return i;
        }
    }
    return 0;
}

int main() {
    std::string a;
    std::ifstream myfile;
    std::string word = "";
    std::vector <int> allNumbers;
    int total = 0;
    myfile.open("Day1Input.txt");
    while (std::getline(myfile, a)) {
        for (int i = 0; i < a.length(); i++) {
            if (isdigit(a.at(i))) {
                word = "";
                allNumbers.push_back(a.at(i) - '0');
            }
            else {
                word += a.at(i);
            }
            if ((containsNumber(word))) {
                allNumbers.push_back(containsNumber(word));
                word = word.at(word.length() - 1);
            }
        }
        if (allNumbers.size() == 1) {
            allNumbers.push_back(allNumbers.at(0));
        }
        std::cout << total << " + " << getNumbers(allNumbers) << std::endl;
        total += getNumbers(allNumbers);
        allNumbers.clear(); 
    } 
    std::cout << total << std::endl;
    myfile.close();
}