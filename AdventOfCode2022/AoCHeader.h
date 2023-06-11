#pragma once

#include <string>
#include <ctype.h>

using namespace std;

struct dayResult {
    string part1;
    string part2;
};

//asm utils
extern "C" {
    //Parses unsigned int as number given the length of the number text and a pointer to the first digit
    //Does not validate if the number is valid and will return a nonsense result if it isn't
    int parseUInt(int length, char* startPoint);

    //GCD version 1 using Euclidean division algorithm
    int GCD1(int a, int b);
    //GCD version 2 using binary division approach
    int GCD2(int a, int b);
}

//other stuff
int GCDcpp1(int a, int b);



//day functions
dayResult day1Main(char* inputData, int dataLength);

