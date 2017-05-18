// MultiDimArr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>			// for std::cout
#include <algorithm>		// for using std::max and min
#include <vector>			// for using std::vector
#include <unordered_map>	// for using std::unordere_map

#define TABLE_SIZE  3		// Colunm or row size of the arr array
#define START_OF_GRID 0		// The start index of grid

typedef std::vector<int> int_vec;	// use int_vec instead of std::vector<int> 

// Forward Declaration of FindNeighbours function
void FindNeighbours(const int IN_array[][TABLE_SIZE], const int row, const int col, int_vec &OUT_NeighboursVec); 

int main()
{
	int arr[][TABLE_SIZE] = { {1,2,3}, {4,5,6}, {7,8,9} };		// The array to lookup
	int_vec NeighboursVec;										// Neighbours vector that is going to be filled after the FindNeighbours function call 
	std::unordered_map<std::string,std::vector<int>> AdjList;

	/*AdjList.insert(std::make_pair("A", 1));
	AdjList.insert(std::make_pair("A", 2));*/		

	FindNeighbours(arr, 2, 2, NeighboursVec);					// FindNeighbours function call. In this case we are want to find the neighbours of item in last row and column

	std::cout << "Origin: " << arr[2][2] << "\n";				// Print the value that we want to find its neighbours

	for (int i = 0; i < NeighboursVec.size(); i++)				// Itarete through NeighboursVec 
	{
		std::cout << "Neighbours : " << NeighboursVec.at(i) << "\n"; //Print all neighbours
	}

    return 0;
}

// Finds the all neighbours of given array item
void FindNeighbours(const int IN_array[][TABLE_SIZE], const int row, const int col, int_vec &OUT_NeighboursVec)
{
	int RowStart = std::max(row - 1, START_OF_GRID);		//Decide the start of the row using std::max.
	int RowEnd = std::min(row + 1, TABLE_SIZE - 1);			//Decide the end of the row using std::min.
	int ColumnStart = std::max(col - 1, START_OF_GRID);		//Decide the start of the column using std::max.
	int ColumnEnd = std::min(col + 1, TABLE_SIZE - 1);		//Decide the end of the column using std::min.	
	

	for (int i = RowStart; i <= RowEnd; i++)
	{
		for (int j = ColumnStart; j <= ColumnEnd; j++)
		{
			if (IN_array[i][j] != IN_array[row][col])		// Do not include origin number
			{
				OUT_NeighboursVec.push_back(IN_array[i][j]); // Iterate through 2D array and add the neighbours to OUT vector	 			
			}
			
		}
	}

}

