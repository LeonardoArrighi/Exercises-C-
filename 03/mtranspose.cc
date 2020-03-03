#include <iostream>
#include <array>
#include <utility>
#include <iomanip>


template <typename T>
void stampa(T, int, int);

template <typename T>
void trasponi(T&, int, int);

int main()
{
    const int nrows = 4;
    const int ncols = 5;

    std::array<double,(nrows*ncols)> matrix;

    for (int i=0; i<(nrows*ncols); i++)
    {
        matrix[i] =i;
    }

    std::cout << "Input matrix:" << std::endl;
    stampa(matrix, nrows, ncols);
    std::cout << std::endl;

    trasponi(matrix, nrows, ncols);

    std::cout << "Swapped matrix:" << std::endl;
    stampa(matrix, ncols, nrows);
    std::cout << std::endl;

    return 0;

}


template <typename T>
void stampa(T matrix, int row, int col)
{
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            std::cout << std::setw(3) << matrix[i*col + j] << " ";
        }
        std::cout << std::endl;
    }
}


template <typename T>
void trasponi(T& matrix, int row, int col)
{
    if(row==col)
    {
        for(int i=0; i<row; i++)
        {
            for(int j=i; j<col; j++)
            {
                std::swap(matrix[i*col+j], matrix[j*col+i]);
            }
        }
    }
    else
    {
        auto swapped = matrix;
        for (int i=0; i < col; ++i)
        {
            for (int j=0; j < row; ++j) 
            {
                swapped[i * row + j] = matrix[j * col + i];
            }
        }
        matrix = swapped;
    }
    
}