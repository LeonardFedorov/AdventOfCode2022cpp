#include <iostream>

#define EXPAND(x) #x


int main()
{
    
    const char* s = EXPAND(AOCDATA);


    std::cout << "Hello World!\n";

}

