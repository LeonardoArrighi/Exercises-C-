#include <iostream>

template <typename T>
T* allocate(size_t);

template <typename T>
void print(T*, size_t);

int main()
{
    size_t length;
    std::cout << "Lunghezza array: " << std::endl;
    std::cin >> length;

    std::cout << "\n";

    int * first = allocate<int>(length);
    //double * first = allocate<double>(length);

    std::cout << "Reverse array:\n";
    print(first, length);

    delete [] first;

    return 0;
}

template <typename T>
T* allocate(size_t length)
{
    T* arr = new T[length]; 

    for (unsigned int i=0; i<length; i++)
    {   
        std::cout << "array[" << i << "]: ";
        std::cin >> arr[i];
    }

    std::cout << "\n";

    return arr;

}

template <typename T>
void print(T* arr, size_t length)
{
    for (unsigned int i=1; i<=length; i++)
    {   
        std::cout << "array[" << i-1 << "]: " << arr[length - i] << std::endl;
    }
}
