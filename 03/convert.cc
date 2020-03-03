#include <iostream>
#include <array>
#include <utility>
#include <iomanip>
#include <vector>


template <typename T>
void stampa(T&, int, int);

template <typename T>
void trasponi(T&, int, int);

int readfrom(std::string const&);


int main(int argc, char* argv[])
{
    int nrows = readfrom(argv[1]);
    int ncols = readfrom(argv[2]);

    std::vector<double> matrix;

    for (int i=0; i<(nrows*ncols); i++)
    {
        matrix.push_back(i);
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
void stampa(T& matrix, int row, int col)
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


int readfrom(std::string const& str)
{
    int ret;
    std::istringstream ss(str);
    ss >> ret;

    return ret;
}
