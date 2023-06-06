#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

#include "AoCHeader.h"

//Data type to hold results data from the analysis of the user's input
struct inputResult {
    bool valid;
    int day;
    bool test;
};

//Declare functions in this file that are defined further down

string getSourcePath();
inputResult* evaluateInput(string* userInput);
void dispatchDay(int day, string* path);

int main()
{
    
    //Print the intro message
    cout << "#####################\n";
    cout << "#Advent Of Code 2022#\n";
    cout << "#####################\n";

    //Set up the filepath to the input data
    string sourcePath = getSourcePath();
    string extension = "Input.txt";
    string test = "Test";
    string loadPath;

    string userInput;
    inputResult* parsedInput;
    
    bool reLoop;

    while (1) {

        cout << "\nPlease enter a day to calculate. Append a 't' to load the test data set. Type anything else to exit.\n";

        //Get a line from the user and give a pointer to the result input analysis
        getline(cin, userInput);
        parsedInput = evaluateInput(&userInput);

        //Exit the loop and end if the input is not a valid day request
        if (parsedInput->valid) {
            //Build the path to the target file to load
            loadPath = sourcePath + to_string(parsedInput->day) + (parsedInput->test ? test : "") + extension;
            //cout << loadPath << "\n";
            dispatchDay(parsedInput->day, &loadPath);
            reLoop = true;
        } else {
            reLoop = false;
        }
        
        //Clear the parsedInput as we no longer need it
        delete parsedInput;
        
        //If an invalid input was read, then break out of the loop and end the program
        if (!reLoop) { break; }

    }

    return 0;

}

//Get the standard sourcePath lead in
string getSourcePath()
{

    string sourcePath = __FILE__;
    string dataFolder = "InputData\\Day";

    //Declare i outside the loop so we can read its value after the loop finishes
    //Use 64 bit int to avoid compiler warning
    int64_t i = sourcePath.length() - 1;

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

//Evalute the User's Input, returning the evaluation in the inputResult data type
inputResult* evaluateInput(string* userInput) {

    //Initialise the inputResult with false validity, so we can return it directly on all failing branches
    inputResult* output = new inputResult;
    output->valid = false;

    //Check string length for validity
    if (userInput->length() > 0 && userInput->length() < 4) {

        //Wrap string in a stream object to make reading easier
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

void dispatchDay(int day, string* path) {

    //Set up variables for code timing
    chrono::high_resolution_clock clock;
    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock::time_point end;
    __int64 time;

    //Load the file from disk before timing is begun
    ifstream file;
    int size;
    char* fileData;

    //Open the file at the end and read the stream position as the size
    file.open(*path, ios::in | ios::binary | ios::ate);

    //Check the file was able to open, if not return an error message
    if (file.is_open()) {
        size = (int)file.tellg(); //cast to int is fine, since filesize is never going to be more than a few kB
        fileData = new char[size];

        //Set the pointer back to the beginning and perform the read before closing the file
        file.seekg(0, ios::beg);
        file.read(fileData, size);
        file.close();

        start = clock.now();

        //Initalise the day result struct with non-implemented fields
        dayResult output;
        output.part1 = "Not implemented!";
        output.part2 = "Not implemented!";

        int testGCD = 0;

        switch (day) {

            case 1:
                //output = day1Main(fileData, size);
                testGCD = GCD1(2040, 1560);

                break;

            //If the day hasn't been coded up, then just return the default state of the output values
            default:
                break;
        }

        output.part1 = to_string(testGCD);

        //Stop timing and then write the outputs
        end = clock.now();
        time = chrono::duration_cast<chrono::microseconds>(end - start).count();

        cout << "Part 1: " << output.part1 << "\nPart 2: " << output.part2 << "\n";
        cout << "Execution time (exc. file load): " << time << " microseconds\n";
    } else {
        cout << "Could not find source file: " << *path << "\n";
    }

    return;
}