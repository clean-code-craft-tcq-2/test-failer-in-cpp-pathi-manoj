#include <iostream>
#include <assert.h>

void printNumberToConsole(int i , int j)
{
    int number = i * 5 + j;
    std::cout << number;
    assert(number >=1 && number <=25);
}

void printMajorColorToConsole(int i)
{
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    std::cout << "\t | " << majorColor[i] << "\n";
}

void printMinorColorToConsole(int i)
{
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::cout << "\t | " << minorColor[i] << "\n";
}

int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printNumberToConsole(i , j);
            printMajorColorToConsole(j);
            printMinorColorToConsole(j);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
