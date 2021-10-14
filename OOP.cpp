#include <iostream>

using namespace std;

// Size of grid
#define N 9

// Print grid
void print(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

// Check whether assigning given number will be legal
bool isSafe(int grid[N][N], int row,
            int col, int num)
{

    // Check if number already exists in same row
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;

    // Check if number already exists in same column
    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;

    // Check if number exists in grid
    int startRow = row - row % 3,
        startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j +
                                   startCol] == num)
                return false;

    return true;
}

//function to solve sudoku by
bool solveSuduko(int grid[N][N], int row, int col)
{
    // Check if we have reached the 8th row and 9th column
    if (row == N - 1 && col == N)
        return true;

    // If 9th column value is reached, move to next row
    if (col == N)
    {
        row++;
        col = 0;
    }

    //Check if current position already contains a value
    if (grid[row][col] > 0)
        return solveSuduko(grid, row, col + 1);

    for (int num = 1; num <= N; num++)
    {

        // Check if it is safe to place a number from (0-9) in position
        if (isSafe(grid, row, col, num))
        {

            //Putting a number in the position
            grid[row][col] = num;

            // Checking for next possibility with next column
            if (solveSuduko(grid, row, col + 1))
                return true;
        }

        // Removing the assigned num since assumption was wrong and assigning another number
        grid[row][col] = 0;
    }
    return false;
}

// Driver
int main()
{
    // 0 means unassigned cells
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if (solveSuduko(grid, 0, 0))
        print(grid);
    else
        cout << "no solution exists " << endl;

    return 0;
}
