#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>

template<typename T>
std::vector<int> check(std::vector<T>&);

template<typename T>
std::vector<T> remove_spaces(std::vector<T>&);

std::vector<std::string> split(const char *str, char c = ' ');

int main()
{
    std::cout << "Write your text:" << std::endl;

    std::vector<std::string> words;
    std::vector<int> how_many;
    
    std::string line;
    std::string empty{};
    while(std::getline(std::cin,line))
    {   
        if(line != empty) words.push_back(line);
    }

    how_many = check(words);

    std::cout << "\n" << "That's your text, without repetitions:" << std::endl;
    
    for(int i=0; i<words.size(); i++)
    {
        std::cout << how_many[i] << " - ";
        std::cout << words[i] << std::endl; 
    }

    return 0;
}


template<typename T>
std::vector<int> check(std::vector<T>& vec)
{   
    unsigned int atm {0};
    int new_elem {0};
    std::vector<int> counter = {new_elem};

    std::sort(vec.begin(), vec.end());
    
    while (atm+1 != vec.size())
    {       
        if(vec[atm]==vec[atm+1])
        {   
            counter[atm] ++;
            vec.erase(vec.begin()+(atm+1));
        }
        else
        {
            counter[atm] ++;
            counter.push_back(new_elem);
            atm++;
        }
    }
    counter[atm] ++;

    return counter;
}

//https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
template<typename T>
std::vector<T> remove_spaces(std::vector<T>& vec)
{
    for (int i=0; i<vec.size(); i++)
    {
        if (vec[i] == " ") std::cout<<"s";
    }
}





