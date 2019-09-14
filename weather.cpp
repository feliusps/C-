// weather table categories lab5.cpp 


//CIS 180
//Assignment 5
//Feliu, Felix

/* The Weather Service Bureau department has data representing  monthly rainfall for a year and we would like to create a table categorizing 
each month as rainy (rainfall 20% higher than average) dry (rainfall 25% lower than average) or average. The data file for monthly rain fall
is called rainfall.txt.*/

#include "stdafx.h"
#include<iostream>
#include<fstream>   //required for inputFile variable
#include<iomanip>
#include<math.h>
#include<string>
using namespace std;


// funtion prototypes
void inputRainFall(int rainFall[], int size);
int calculateAverageRainFall(int rainFall[], int size);
void classifyAndDisplayRainfall(int rainFall[], int months);

//Begin main funtion

int main() 
{
	//Variables declaretion

	const int NUM_MONTHS = 12;                   // Months in one year is array size
	const double RAIN_RATE = 0.20;               //20% more rain than average
	const double DRY_RATE = 0.25;                //25% lower rain than average
	int rainFall [NUM_MONTHS];                   //array with size declarator
	int averageRainFall, months;

//Read rainfall from the the file and the fill them in the array
// Call funtion Input rain fall
	inputRainFall(rainFall , NUM_MONTHS);

//Calculate the average rainfall by calling the function calculateAverageRainFall and display the average rainfall
	averageRainFall = calculateAverageRainFall(rainFall , NUM_MONTHS);
	cout << " The year's average monthly rainfall was ( " << averageRainFall << "mm)." << endl;

//Classify months as Dry, Average, or Rainy and display the result by calling the function classifyAndDisplayRainFall
//	Call funtion clasify and display. 
	classifyAndDisplayRainfall(rainFall, NUM_MONTHS);

    return 0;
}


//Define the function inputRainFall
void inputRainFall(int rainFall[], int size)
{ 
	int count = 0;
 	ifstream inFile;

 //open file The rainfall read from the file rainfall.txt and store them in the array rainFall.
	inFile.open("rainfall.txt"); // numeric data
 //Read the montly rainfall from file and move it into array
	while (count <  size && inFile >> rainFall[count])
 // Close file
		inFile.close();

}


// Define funtion calculate average
int calculateAverageRainFall(int rainFall[], int size)
{
//Use the function ceil(double x) to round a number up.
	
	
	int sum = 0;
	int count = 0;
	for (count = 0; count < size; count++)
		sum += rainFall[count];
	//return and calculate average rainFall
	return   ceil (int (sum / size));

}


//Define a funtion  clasify and display rainfall
void classifyAndDisplayRainfall(int rainFall[], int size)
{

	//Use a one-dimensional array month to store string month

	string months[] = { "January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December" };
	int averageRainFall;
	int DRY_RATE, RAIN_RATE;
	int highestRainFall, count, lowestRainFall;
	const int NUM_MONTHS = 12;
	int highestRainFallindex = 0;
	int lowestRainFallindex = 0;
	//Classify months as Dry, Average, or Rainy and display the result

	//Call the function calculateAverageRainFall to get rainfall average
	averageRainFall = calculateAverageRainFall(rainFall, NUM_MONTHS);

	//average between dryCut and rainCut
	double dryCut = averageRainFall - DRY_RATE * averageRainFall;
	double rainCut = averageRainFall + RAIN_RATE * averageRainFall;
	

	// find highest rainFall month page 401
	highestRainFall = rainFall[0];
	for (count = 1; count < NUM_MONTHS; count++)
	{
		if (rainFall[count] > highestRainFall)
			highestRainFall = rainFall[count];
		    highestRainFallindex = count;
			
	}
	// find lowest rainFall month page 401
	lowestRainFall = rainFall[0];
	for (count = 1; count < NUM_MONTHS; count++)
	{
		if (rainFall[count] < lowestRainFall)
			lowestRainFall = rainFall[count];
		    lowestRainFallindex = count;
			
	}

	// months with highest and lowest rainfall
	cout << months[highestRainFallindex] << " has the highest rainfall ( " << highestRainFall << "mm)." << endl;
	cout << months[lowestRainFallindex] << " has the lowes rainfall ( " << lowestRainFall << "mm)." << endl;

	// create table
	cout << "Month\tRainfall(mm)\tClassification\n";
	cout << "-----\t------------\t--------------\n";
	
	//find the type of year
	for (count = 0; count < NUM_MONTHS; count++)
	{
		cout << left << setw(8) <<count + 1 << "\t" << setw(8) << rainFall[count] << "\t\t";
		if (rainFall[count] >= rainCut)
		{
			cout << right << setw(8) << "Rainy\n";
		}
		else if (rainFall[count] <= dryCut)
		{
			cout <<right << setw(8) << "dry\n";
		}
		else
		{
			cout << right << setw(8) << "Average\n";
		}

		
		
	}
}
