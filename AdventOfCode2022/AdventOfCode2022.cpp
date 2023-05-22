#include <iostream>
#include <string>

int main()
{
    
    //Set up the filepath to the input data
    std::string sourcePath = __FILE__;
    std::string dataFolder = "InputData\\Day";
    std::string extension = "Input.txt";
    std::string test = "Test";

    //Declare i outside the loop so we can read its value after the loop finishes
    int i = sourcePath.length() - 1;

    for (; i > -1; i--) {
        if (sourcePath[i] == '\\') {
            break;
        }
    }

    //Resize the string to remove the trailing file name
    sourcePath.resize(i + 1);

    const char* one = "1";

    std::string loadPath = sourcePath + dataFolder + one + extension;

    std::cout << loadPath;

}

