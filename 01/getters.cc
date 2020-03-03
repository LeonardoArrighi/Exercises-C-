#include <iostream>
#include <sstream>

bool is_double(std::string const&);
bool is_int(std::string const&);

int main()
{
    std::string user;
    
    //std::string line;
    //while(std::getline(std::cin,line))
    while(true)
    {
        std::cin >> user;
        if (is_int(user))
        {
            std::cout << "INT" << std::endl;
            break;
        }
        else if (is_double(user)) 
        {
            std::cout << "DOUBLE" << std::endl;
            break;
        }
        else
        {
            std::cin.ignore();
            std::cin.clear();
        }
    }
    return 0;
}


bool is_double(std::string const& str) 
{   
    double test;
    //isstringstream -> read from a string
    std::istringstream ss(str);
    ss >> test;
    // ws is for white space 
    // eof() -> we hit end of input
    return (ss && (ss >> std::ws).eof());
}

bool is_int(std::string const& str) 
{
    int test;
    //isstringstream -> read from a string
    std::istringstream ss(str);
    ss >> test;
    // ws is for white space 
    // eof() -> we hit end of input
    return (ss && (ss >> std::ws).eof());
}