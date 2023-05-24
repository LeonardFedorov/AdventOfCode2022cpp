#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

//Declare functions in this file

string getSourcePath();
struct inputResult;
inputResult* evaluteInput(string userInput);
inline int digitToInt(char c);

int main()
{
    
    //Set up the filepath to the input data
    string sourcePath = getSourcePath();
    string extension = "Input.txt";
    string test = "Test";
    string loadPath;

    int dayChoice;
    string userInput;
    inputResult* parsedInput;

    //Get a line from the user and give a pointer to the result to the input analysis
    getline(cin, userInput);

    parsedInput = evaluteInput(&userInput);


    const char* one = "1";

    loadPath = sourcePath + one + extension;

    std::cout << loadPath;


    return 0;

}

//Get the standard sourcePath lead in
string getSourcePath()
{

    string sourcePath = __FILE__;
    string dataFolder = "InputData\\Day";

    //Declare i outside the loop so we can read its value after the loop finishes
    int i = sourcePath.length() - 1;

    for (; i > -1; i--) {
        if (sourcePath[i] == '\\') {
            break;
        }
    }

    //If i gets to -1, no backslash was found so something is wrong with the path
    if (i == -1) { throw exception("No backslash found in source file path"); }

    //Resize the string to remove the trailing file name and then add the path into the data folder
    sourcePath.resize(i + 1);
    sourcePath.append(dataFolder);

    return sourcePath;
}

//Data type to hold results data from the analysis of the user's input
struct inputResult {
    bool valid;
    int day;
    bool test;
};

inline int digitToInt(char c) {
    return c - '0';
}

inputResult* evaluteInput(string* userInput) {

    //Initialise the inputResult with false validity, so we can return it directly on all failing branches
    inputResult* output = new inputResult;
    output->valid = false;

    int sLength = userInput->length();
    char c0, c1, c2;

    //Break down cases based on string length
    switch (sLength) {
        case 1:
            //If the string is one char long, then this is only valid if this is a day number
            c0 = userInput->[0];
            if (isdigit(c0)) {
                output->day = c0 - '0';
                output->test = false;
                output->valid = output->day > 0;
            }

        case 2:
            //If it is two chars long, could be a 2 digit day or a 1 digit day with the test flag
            c0 = userInput->[0];
            c1 = userInput->[1];
            if (isdigit(c0)) {
                if (c1 == 't') {
                    output->day = c0 - '0';
                    output->test = true;
                    output->valid = output->day > 0;
                } else if (isdigit(c1)) {
                    output->day = 10 * (c0 - '0') + c1 - '0';
                    output->test = false;
                    output->valid = output->day > 0;
                }



            } else {
                //Invalid, no action needed
            }

        case 3:




        default:
            //Do nothing - string cannot be valid and output is already in invalid state
    }

    return output;

}