// two dimendional arraylab6.cpp 



//CIS 180
//Assignment 6
//Feliu, Felix

/*Write a program that create a two-dimensional array initialized with test data.
The program should have the following functions:

getTotal - This function should accept two-dimensional array as its argument and return the total of all the values in the array.

getAverage - This function should accept a two-dimensional array as its argument and return the average of values in the array.

getRowTotal - This function should accept a two-dimensional array as its first argument and an integer as its second argument.
The second argument should be the subscript of a row in the array.
The function should return the total of the values in the specified row.

getColumnTotal - This function should accept a two-dimensional array as its first argument and an integer as its second argument.
The second argument should be the subscript of a column in the array.
The function should return the total of the values in the specified column.

getHighestInRow - This function should accept a two-dimensional array as its first argument and an integer as its second argument.
The second argument should be the subscript of a row in the array. 
The function should return the highest value in the specified row in the array.

getLowestInRow - This function should accept a two-dimensional array as its first argument and an integer as its second argument.
The second argument should be the subscript of a row in the array.
The function should return the lowest value in the specified row in the array.

*/

#include "stdafx.h"
#include<iostream>
#include<iomanip>
using namespace std;


//Global constants
int const ROWS = 4;    // number of rows
int const COLS = 5;    // number of columns
float  total, average;
int  rowAddition, columnAddition, higestValue, lowestValue;

//funtions prototype

int getTotal(const int matrix[][COLS], int ROWS);
float getAverage(const int matrix[][COLS], int ROWS);
int getRowTotal(const int matrix[][COLS], int ROWS);
int getColumnTotal(const int matrix[][COLS], int COLS);
int getHighestInRow(const int matrix[][COLS], int ROWS);
int getLowestInRow(const int matrix[][COLS], int ROWS);

int main()
{
	// Array initialization  with test data
	int testArray[ROWS][COLS] = { { 1, 2, 3, 4, 5 },{ 6, 7, 8, 9, 10 },	{ 11, 12, 13, 14, 15 },	{ 16, 17, 18, 19, 20 } };

	//Look like a matrix
	//  1,   2,   3,   4,   5
	//  6,   7,   8,   9,   10
	//  11,  12,  13,  14,  15
	//  16,  17,  18,  19,  20

	//1.call funtion getTotal and display total addition
	total = getTotal(testArray, ROWS );
	cout << "The total of the array elements is " << total << endl;

	//2.call funtion getAverage and display the average of the array elements.
	average = getAverage(testArray, ROWS);
	cout << "The average value of an element is " << setprecision(3) <<showpoint << average << endl;

	//3.call funtion getRowTotal  and display the total addition of row 0.
	rowAddition = getRowTotal(testArray, 0);
	cout << "The total of row 0 is " << rowAddition << endl;

	//4.call funtion  getColumnTotal and display the total addition of column 2
	columnAddition = getColumnTotal(testArray, 2);
	cout << "The total of col 2 is " << columnAddition << endl;

	//5.call funtion getHighestInRow and display the higest value in row 2.
	higestValue = getHighestInRow(testArray, 2);
	cout << "The highest value in row 2 is " << higestValue << endl;

	//6. call funtion getLowestInRow and display the lowest value in row 2.
	lowestValue = getLowestInRow(testArray, 2);
	cout << "The lowest value in row 2 is " << lowestValue << endl;

	cin.get();

    return 0;


}


//                       --------------------
//                             FUNTIONS
//                       --------------------

// Make a funtion to get the total sum of the elements into the array.
int getTotal(const int matrix[][COLS], int ROWS)
{
	// variable declaretion
	int sum = 0;
		
	//sum all the  elements into the array.
	for (int row = 0; row < ROWS; row++)
	{
		//add elements.
		for (int col = 0; col < COLS; col++)
			sum += matrix[row][col];
	}

	return sum;
	
}

// Make a funtion to get the average of the array elements.
float getAverage(const int matrix[][COLS], int ROWS)
{
	//call getTotal funtion.
	
	float aver = total / (ROWS * COLS); // find the average using first funtion

	return aver;

}

// Make a funtion to get the additon of all elements in row 0.
int getRowTotal(const int matrix[][COLS], int ROWS)
{
	// variable declaretion
	// set accumulator
	int addition = 0;
	for (int row = 0; row <= (ROWS); row++)  //in order to get only row 0
	{   
		    //sum a row
			for (int col = 0; col < COLS; col++)
				addition += matrix[row][col];
		
	}
	return addition;
}



//Make a funtion to get the additon of all elements in column 2.
int getColumnTotal(const int matrix[][COLS], int COLS)
{

	// variable declaretion
	// set accumulator
	int addition = 0;

	for (int col = 2; col <= (COLS); col++) //add elements only in column 2.
	{
		//sum a columns
		for (int row = 0; row < ROWS; row++)
			addition += matrix[row][col];

	}

	return addition;

}

//Make a funtion to get the higest value in row 2.
int getHighestInRow(const int matrix[][COLS], int ROWS)
{
	// variable declaretion 
	int higest;
	
	for (int row = 2; row <= ROWS; row++)
	{   
		//initilize higest
		higest = matrix[2][0];

			//higest value in a row
		for (int col = 0; col < COLS; col++)
			if (matrix[row][col] > higest)
				higest = matrix[row][col];
				
	}
	return higest;

}

// //Make a funtion to get the lowest value in row 2.
int getLowestInRow(const int matrix[][COLS], int ROWS)
{
	// variable declaretion 
	int lowest;

	for (int row = 2; row <= ROWS; row++)
	{
		//initialized lowest
		lowest = matrix[2][0];

		//lowest value in a row
		for (int col = 0; col < COLS; col++)
			if (matrix[row][col] < lowest)
				lowest = matrix[row][col];

	}
	return lowest;


}
