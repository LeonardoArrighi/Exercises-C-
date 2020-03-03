#include <iostream>
#include <sstream>

bool is_double(std::string const&);
double readfrom(std::string const&);

int main()
{
    std::string unit;
    double value;
    std::string input;
    const double inch_m {0.0254};
    const double m_inch {39.3701};

    while(true)
    {
        std::cin >> input;
        if (is_double(input))
        {
            value = readfrom(input);
        }
        else
        {
            if (input == "inch") 
            {
                std::cout << inch_m * value << " m" << std::endl; 
                break;
            }
            else if (input == "m")
            {
                std::cout << m_inch * value << " inch" << std::endl;
                break;
            }
            else
            {
                std::cout << "WRONG" << std::endl;
                break;
            }
        }
    }
    
    return 0;
}


bool is_double(std::string const& str) 
{   
    double test;
    std::istringstream ss(str);
    ss >> test;
    
    return (ss && (ss >> std::ws).eof());
}

double readfrom(std::string const& str)
{
    double ret;
    std::istringstream ss(str);
    ss >> ret;

    return ret;
}
