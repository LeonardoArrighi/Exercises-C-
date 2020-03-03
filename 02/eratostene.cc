#include <iostream>
#include <cmath>

int main()
{   
    int N;
    std::cout << "Max N: ";
    std::cin >> N;


    int * griglia = new int[N+1];

    for (int i=0; i<N+1; i++)
    {
        griglia[i] = i;
    }

    //inizializzazione elemento 1, che per definzione non è primo
    griglia[1]=0;

    for (int k=0; k<std::sqrt(N); k++)
    {
        if (griglia[k]!=0)
        {
            for (int j=std::pow(k,2); j<N+1; j+=k)
                griglia[j]=0;
        }
    }

    std::cout << "Prime numbers: {";
    for (int i=0; i<N+1; i++)
    {
        if (griglia[i]!=0){
            std::cout << griglia[i] << ", ";
        }
    }
    std::cout << "...}\n";
    
    delete[] griglia;
 
    return 0;


}