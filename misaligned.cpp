#include <iostream>
#include <assert.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            int number = printNumberToConsole(i , j);
            printColourPairToConsole(i, j);
            assert(number >=1 && number <=25);
        }
    }
    return i * j;
}

int printNumberToConsole(int i , int j)
{
    int number = i * 5 + j
    std::cout << number;
    return number;
}

void printColourPairToConsole(int i , int j)
{
    std::cout << "\t | " << majorColor[i] << "\t | " << minorColor[i] << "\n"
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
