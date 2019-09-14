// dynamic allocation lab7.cpp 

//CIS 180
//Assignment 7
//Feliu, Felix

/*Write program that dynamically allocates an array large enough to hold a user-input number of test scores
(No one dimensional array declaration is allowed in the solution).
Once all the test scores are entered, the array should be passed to a function that sorts them in ascending order.
Another function should be called that calculates the average score. 
The program should display sorted list of scores and averages with headings shown in the output sample.
Use pointer notation rather array notation whenever possible.*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Funtion prototypes
void sort(double *, int );
void showArray(double *, int );
double gradeAverage(double *, int);

int main()
{
	int numgrades;                   //To hold number of grades
	int i;                           // counter variable
	double  *grade = nullptr,        //Dinamically allocate a array
		     average,                // to hold average
		     total = 0.0;            //Accumulator
	
	//Enter the number of test scores to be procesed
	cout << "How many test scores will you enter?: ";
	cin >> numgrades ;   //how many grades will be entered
	
	//Dinamically allocate an array large enough to hold that many test scores
	grade = new double[numgrades];
	 

	//Get the grade inputs
	 for (i = 0; i < numgrades; i++)
	 {
		 cout << " Enter test score " << (i + 1) << " : ";
		 cin >> *(grade + i);         // or cin >> *(grade + i);
		 
	 }


	 //Call funtion to sort grade in ascending order
	 sort(grade, numgrades);

     // display values again after sorting
	 cout << endl;
	 cout << "The test scores in ascending order, and their average, are : \n\n";
	 cout << "   Score  \n\n ";
	 cout << "----------\n\n" ;
	 showArray(grade, numgrades);

	 

	 // call funtion average
	 cout << endl;
	 average = gradeAverage(grade, numgrades);
	 cout << "Average score : " << setprecision(2) << showpoint << fixed <<average << endl;


	 //Free dinamically allocated memory
	 delete[] grade;
	 grade = nullptr;

    return 0;
}


// Funtion to sort the grade in ascending order
// Using selection sort
void sort(double *score, int numScore)
{ 
	int startScan, minIndex;
	double minValue;

	for (startScan = 0; startScan < (numScore - 1); startScan++)
	{
		minIndex = startScan;
		minValue = *(score + startScan);
		for (int index = startScan + 1; index < numScore; index++)
		{
			if (score[index] < minValue)
			{
				minValue = *(score + index);
			}   minIndex = index;
		}
		score[minIndex] = score[startScan];
		score[startScan] = minValue;
		
	}
	
	
}



//funtion to get the grades average
double gradeAverage(double *score, int numScore)
{
	// Calculate the total addition of all grade
	double total = 0.0;
	int i;

	// Add score
	for (i = 0; i < numScore; i++)
	{
		total += *(score + i );
	}
	//calculate average
	double Ave = total / numScore;
	return Ave;
}

void showArray(double *score, int numScore)
{
	
	for (int count = 0; count < numScore; count++)
	{
		cout << setprecision(2) << showpoint << fixed << *(score + count) << endl;

	}   
} 