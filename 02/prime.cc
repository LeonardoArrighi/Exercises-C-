#include <iostream>

template <typename T>
bool is_prime(T);

template <typename T>
T* new_array (T*, size_t, T);

int main()
{
    int n;
    std::cout << "Stampa i numeri primi fino a n\n" << "n: ";
    std::cin >> n;

    //ovviamente i numeri primi sono naturali
    size_t length = 0;
    int * container = new int[length];

    for (int i=2; i<=n; i++) //start from 2
    {
        if(is_prime(i))
        {
            container = new_array(container, length, i);
            length++;
        }
    }

    //stampa tutto
    std::cout << "Prime numbers: {";
    for (size_t j=0; j<length; j++)
        std::cout << container[j] << ", ";
    std::cout << "...}\n";

    delete[] container;

    return 0;

}

//templetizzato per esercizio
template <typename T>
bool is_prime(T test)
{
    //NRVO
    bool flag = true;
    
    for (int i=2; i<=test/2; i++)
    {
        if (test%i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}


template <typename T>
T* new_array (T* old, size_t old_length, T add_this)
{
    //Costruiamo un nuovo array
    T* notold = new T[old_length + 1];

    //Lo riempiamo con gli elementi del precedente
    for (size_t j=0; j<old_length; j++)
    {
        notold[j] = old[j];
    }

    //Aggiungiamo l'ultimo
    notold[old_length]=add_this;

    //E cancelliamo il vecchio
    delete[] old;

    return notold;
}



