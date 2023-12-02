#include <iostream>
#include <fstream>
#include <vector>

int isValid(int red, int green, int blue) {
    if (red > 12 || green > 13 || blue > 14) {
        return 1;
    }
    return 0;
} 

int main() {
    std::fstream myfile;
    std::string a;
    int number = 0;
    int pos = 1;
    int total = 0;
    int red, green, blue;
    myfile.open("Day2Input.txt");
    while (std::getline(myfile, a)) {
        int valid = 0;
        for (int i = 8; i < a.length(); i++) {
            if (a.at(i) == ';' || i == a.length() - 1) {
                valid += isValid(red, green, blue);
                red = 0;
                green = 0;
                blue = 0;
            }
            if (isdigit(a.at(i)) && isdigit(a.at(i + 1))) {
                number = 10 * (a.at(i) - '0') + (a.at(i + 1) - '0');
                i++;
            }
            else if (isdigit(a.at(i))) {
                number = a.at(i) - '0';
            }
            switch (a.at(i)) {
                case 'r':
                    red += number;
                    number = 0;
                case 'g':
                    green += number;
                    number = 0;
                case 'b':
                    blue += number;
                    number = 0;
            }
        }
        if (!(valid)) {
            total += pos;
        }
        pos++;
    }
    myfile.close();
    std::cout << total;
    return 0;
}