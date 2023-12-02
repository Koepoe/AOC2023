#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::fstream myfile;
    std::string a;
    int number = 0;
    int total = 0;
    int red = 0, green = 0, blue = 0;
    myfile.open("Day2Input.txt");
    while (std::getline(myfile, a)) {
        int maxRed = 0, maxGreen = 0, maxBlue = 0;
        for (int i = 8; i < a.length(); i++) {
            if (a.at(i) == ';' || i == a.length() - 1) {
                if (red > maxRed) {
                    maxRed = red;
                }
                if (green > maxGreen) {
                    maxGreen = green;
                }
                if (blue > maxBlue) {
                    maxBlue = blue;
                }
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
        total += (maxRed * maxGreen * maxBlue);
    }
    myfile.close();
    std::cout << total;
    return 0;
}