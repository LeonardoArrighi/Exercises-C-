#include <cstdlib>  
#include <iostream> 
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstring>
#include <random>

using namespace std;

void filename_inc (string*);
char* initialize (char*, int, int);
void step (int, int, char[]);
void write (string, int, int, char[]);
double randomize (int&, double);
int converti (char);


int main ( )
{
  string filename = "Step000.txt";

  const int iterations {100};
  const int m {36}; //length grid
  const int n {48}; //heigth grid
  char * grid;

  cout << "Game of Life" << endl;

  for (int iter = 0; iter <= iterations; iter++)
  {
    if (iter == 0)
    {
      grid = initialize (grid, m, n);
    }
    else
    {
      step (m, n, grid);
    }

    // Print on a file
    write (filename, m, n, grid);
    cout << "  " << filename << "\n";
    filename_inc (&filename);
  }

  delete [] grid;

  cout << "End!" << endl;

  return 0;
}


// Build the world
char * initialize (char * grid, int m, int n)
{
  grid = new char[(m+2)*(n+2)];

  // Fill the grid with '-'
  for (int j=0; j <= n+1; j++)
  {
    for (int i=0; i <= m+1; i++)
    {
      grid[i + j*(m+2)] = '-';
    }
  }

  // Fill the grid (manually) 
  grid[63]='O';
  grid[99]='O';
  grid[101]='O';
  grid[127]='O';
  grid[128]='O';
  grid[135]='O';
  grid[136]='O';
  grid[164]='O';
  grid[168]='O';
  grid[173]='O';
  grid[174]='O';
  grid[149]='O';
  grid[150]='O';
  grid[191]='O';
  grid[192]='O';
  grid[187]='O';
  grid[188]='O';
  grid[229]='O';
  grid[230]='O';
  grid[201]='O';
  grid[207]='O';
  grid[211]='O';
  grid[212]='O';
  grid[239]='O';
  grid[243]='O';
  grid[245]='O';
  grid[246]='O';
  grid[251]='O';
  grid[253]='O';
  grid[277]='O';
  grid[283]='O';
  grid[291]='O';
  grid[316]='O';
  grid[320]='O';
  grid[355]='O';
  grid[356]='O';

  return grid;
}


// Step of the game of life
void step (int m, int n, char grid[])
{
  // Count how many living cells are around itself
  int *counter = new int[m*n];

  // There are not living cells on the edges
  for (int j=1; j<=n; j++)
  {
    for (int i=1; i<=m; i++)
    {
      counter[(i-1) + (j-1)*m] = 
          converti(grid[(i-1) + (j-1)*(m+2)]) 
          + converti(grid[(i-1) + j*(m+2)]) 
          + converti(grid[(i-1) + (j+1)*(m+2)])
          + converti(grid[i + (j-1)*(m+2)])
          + converti(grid[i + (j+1)*(m+2)])
          + converti(grid[(i+1) + (j-1)*(m+2)])
          + converti(grid[(i+1) + j*(m+2)])
          + converti(grid[(i+1) + (j+1)*(m+2)]);
    }
  }

// Any dead cell with 3 live neighbors becomes alive
// Any living cell with less than 2 or more than 3 neighbors dies
  for (int j=1; j<=n; j++)
  {
    for (int i=1; i <= m; i++)
    {
      if (grid[i + j*(m+2)] == '-')
      {
        if (counter[(i-1) + (j-1)*m] == 3)
        {
          grid[i + j*(m+2)] = 'O';
        }
      }
      else if (grid[i + j*(m+2)] == 'O')
      {
        if (counter[(i-1) + (j-1)*m] < 2 || 3 < counter[(i-1) + (j-1)*m])
        {
          grid[i + j*(m+2)] = '-';
        }
      }
    }
  }

  delete [] counter;
}


// Print function
void write(string filename, int m, int n, char grid[])
{
  ofstream output;

  //  Open the file.
  output.open(filename.c_str()); //converts a c++ string in a c-style string (returns a const char * that points to a null-terminated string)
  
  if (!output )
  {
    cerr << "LIFE_WRITE - Fatal error!\n";
    exit (1); //terminate the program
  }

  //  Write the data.
  for (int j=0; j<=n+1; j++)
  {
    for (int i=0; i<=m+1; i++)
    {
      output << " " << grid[i + j*(m+2)];
    }
    output << "\n";
  }

  //  Close the file.
  output.close ();
}


// "filename_inc()" increments a partially numeric file name
// https://stackoverflow.com/questions/10854514/creating-a-partial-file-name-with-a-variable-in-c
void filename_inc ( string* filename)
{
  char c;
  int change;
  
  int len = (*filename).length();

  change = 0;

  for (int i=len-1; 0<=i; i--)
  {
    c = (*filename)[i];

    if ('0' <= c && c <= '9')
    {
      change = change + 1;

      if (c == '9')
      {
        c = '0';
        (*filename)[i] = c;
      }
      else
      {
        c = c + 1;
        (*filename)[i] = c;
        return;
      }
    }
  }

  if (change == 0)
  {
    for (int i=len-1; 0<=i; i--)
    {
      (*filename)[i] = ' ';
    }
  }
}


// Essentially useless function
// But I wanted to print the world as '-' and 'o' for a more readable aspect
int converti (char index)
{
  int value;
  if (index == '-') value = 0;
  if (index == 'O') value = 1;
  return value;
}