#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void check(std::vector<T>&);

template<typename T>
void stampa(std::vector<T>&);

int main()
{
    std::cout << "Write your text:" << std::endl;

    std::vector<std::string> words;
    
    std::string line;
    std::string empty{};
    while(std::getline(std::cin,line))
    {   
        if(line != empty) words.push_back(line);
    }

    check(words);

    std::cout << "\n" << "That's your text, without repetitions:" << std::endl;
    stampa(words);   
    std::cout << "Please, don't complain about the order!" << std::endl;

    return 0;
}


template<typename T>
void check(std::vector<T>& vec)
{   
    unsigned int atm {0};

    std::sort(vec.begin(), vec.end());
    
    while (atm+1 != vec.size())
    {       
        if(vec[atm]==vec[atm+1])
        {   
            vec.erase(vec.begin()+(atm+1));
        }
        else
        {
            atm++;
        }
    }
}


template<typename T>
void stampa(std::vector<T>& vec)
{
    for(int i=0; i<vec.size(); i++)
        std::cout << vec[i] << std::endl;   
}

