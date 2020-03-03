#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
//for version 2
#include <fstream>

double mean(std::vector<double>&);
double median(std::vector<double>&);

//service functions (for version 1)
bool is_double(std::string const&);
double readfrom(std::string const&);

//version 1
int main()
{
    std::vector<double> stored;
    
    std::string line;
    while(std::getline(std::cin,line))
    {   
        if(is_double(line))
        {   
            stored.push_back(readfrom(line));
        }
        else
        {
            stored.clear();
            std::cout << "WRONG" << std::endl;
            break;
        }
    }

    std::cout << "Median: " << median(stored) << "\n";

    std::cout << "Mean: " << mean(stored) << "\n";

    return 0;
}



//version 2
// int main()
// {
//     std::vector<double> stored;
    
//     std::ifstream inFile;
//     inFile.open("temperatures.txt");
    
//     double tmp;
//     while(!(inFile.eof()))
//     {
//         inFile>>tmp;
//         stored.push_back(tmp);
//     } 

//     inFile.close();


//     std::cout << "Median: " << median(stored) << "\n";

//     std::cout << "Mean: " << mean(stored) << "\n";

//     return 0;
// }

 


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

double mean(std::vector<double>& vec)
{
    double sum{0};
    unsigned int n = vec.size();
    for(auto i: vec)
    {
        sum += i;
    }
    return (sum/n);
}

double median(std::vector<double>& vec)
{
    std::sort(vec.begin(), vec.end());
    double med;
    unsigned int n = vec.size();
    if(n%2 == 0)
    {
        med = (vec[n/2-1] + vec[n/2])/2;
    }
    else
    {
        med = vec[n/2];
    }
    return med;

}

