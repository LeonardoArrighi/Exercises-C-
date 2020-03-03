#include <iostream>

int main()
{
    unsigned int counter {1};
    const std::string empty {};
    std::string test {};
    std::string line;
    
    while(std::getline(std::cin,line))
    {   
        if(line != empty)
        {
            if(test == line)
            {
                counter++;
            }
            else 
            {
                if(test != empty) std::cout << counter << " " << test << std::endl;
                counter = 1;
                test = line;
            }
        }
    }
    std::cout << counter << " " << test << std::endl;

    // (void) counter;
    // (void) test;
    // (void) salta;
    return 0;
}