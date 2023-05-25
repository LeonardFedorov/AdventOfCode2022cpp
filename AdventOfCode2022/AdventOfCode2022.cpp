#include <iostream>
#include <string>
#include <ctype.h>
#include <sstream>

using namespace std;

//Declare functions in this file

string getSourcePath();
struct inputResult;
inputResult* evaluateInput(string* userInput);

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

    parsedInput = evaluateInput(&userInput);

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

inputResult* evaluateInput(string* userInput) {

    //Initialise the inputResult with false validity, so we can return it directly on all failing branches
    inputResult* output = new inputResult;
    output->valid = false;

    //Check string length for validity
    if (userInput->length() > 0 && userInput->length() < 4) {

        istringstream input (*userInput);

        if (isdigit(input.peek())) {

            //since the first char is a number, extract the day
            int dayValue;
            input >> dayValue;
            output->day = dayValue;

            //Check day is in valid range
            if (dayValue > 0 && dayValue < 26) {

                //Check if the string has ended. If it has, then this is a valid numeric string
                if (input.peek() == EOF) {
                    output->valid = true;
                    output->test = false;
                } else if (input.get() == 't') {
                    output->valid = true;
                    output->test = true;
                } else {
                    //Do nothing, input is invalid
                }

            }

        }

    }

    return output;

}