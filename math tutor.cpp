//math tutor lab3.cpp 


/* CIS 180
   Assignment 3
   Feliu Felix */

/* Problem and Requirements
Write a program that can be used as a math tutor for an elementary student. 
The program should display two random integer numbers.
The program should wait for the students to enter the answer.
If the answer is correct, a message of congratulations should be printed.
If the answer is incorrect, a message should be printed showing the correct answer.
The program displays a menu allowing the user to select an addition, subtraction, multiplication, or division problem.
The final selection on the menu should let the user quit the program.
After the user has finished the math problem, the program should display the menu again. 
This process is repeated until the user chooses to quit the program.
Input Validation: If the user select an item not on the menu, display an error message and display the menu again.*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cstdlib> // for rand and srand
#include <ctime>   // for the time funtion
using namespace std;



int main()
{
	//Constants for menu choices.
	const int  ADDITION_PROBLEM = 1;
	const int  SUBTRACTION_PROBLEM = 2;
	const int  MULTIPLICATION_PROBLEM = 3;
	const int  DIVISION_PROBLEM = 4;
	const int  QUIT_THIS_PROGRAM = 5;

	// Costants for range values in mathematics operations
	const int MIN1_VALUE = 0;  //Minimun value addition
	const int MAX1_VALUE = 9;  //Maximun value addition
	const int MIN2_VALUE = 0;  //Mininum value subtraction
	const int MAX2_VALUE = 9;  //Maximun value subtraction
	const int MIN3_VALUE = 0;  // minimun Value multiplication
	const int MAX3_VALUE = 10; //First in the range 0 - 10 multiplication
	const int MAX31_VALUE = 9; //Second in the range 0 - 9 multiplication
	

	// get the system time
	unsigned seed = time(0);
	// seed the randon number generator
	srand(seed);
	
	//Variables all integers
	int choice, num1 , num2 , addition , subtraction , multiplication , division ;
	int answer1, answer2, answer3, answer4;

	// Repeating The menu Do-While loop
	do
	{
		// display the main menu
		cout << "\n\tMenu\n\n";
		cout << "1.Addition problem\n";
		cout << "2.Subtraction problem\n";
		cout << "3.Multiplication problem\n";
		cout << "4.Division problem\n";
		cout << "5.Quit this program\n\n";
		cout <<	"Enter your choice (1-5):";
		cin >> choice;

		//validating the menu selection
		while (choice < ADDITION_PROBLEM || choice > QUIT_THIS_PROGRAM)
		{
			//Explain the error
			cout << "The valid choices are 1, 2, 3, 4, and 5. Please choose: ";
			//Get the input again
			cin >> choice;
		}

		//Process the user's choice.
		if (choice != QUIT_THIS_PROGRAM)
		{
			//Respond to the user's menu selection
			switch (choice)
			{
				 // 1. Addition problem generate two random numbers in the range 0 - 9.

			     case ADDITION_PROBLEM:
					
					 // Variables
					 num1 = (rand() % (MAX1_VALUE - MIN1_VALUE + 1)) + MIN1_VALUE; //Hold first value
					 num2 = (rand() % (MAX1_VALUE - MIN1_VALUE + 1)) + MIN1_VALUE; //Hold second value

					 //get the input
					 cout << num1 << endl;
					 cout << "+" << num2 << endl;
					 cout << "---" << endl;
					 cin >> answer1 ;
					 addition = num1 + num2 ;

					 //Display the answer to the problen
					 if (addition == answer1)
						 cout << " Congratulations!That's right.\n";
					 else
						 cout << " Sorry, the correct answer is " << addition << ".\n";
					 break;

				  // 2. Subtraction problem generate two random numbers in the range 0 - 9.

				  case SUBTRACTION_PROBLEM:

					 //Variables
					 num1 = (rand() % (MAX2_VALUE - MIN2_VALUE + 1)) + MIN2_VALUE;
				     num2 = (rand() % (MAX2_VALUE - MIN2_VALUE + 1)) + MIN2_VALUE;
					 
					 //Get the input
					 // Make sure num1 is greater o iqual to num2
					 while (num2 > num1)
					 {
						 num2 = (rand() % (MAX2_VALUE - MIN2_VALUE + 1)) + MIN2_VALUE;
					 }
					 cout << num1 << endl;
					 cout << "-" << num2 << endl;
					 cout << "---" << endl;
					 cin >> answer2;
					 subtraction = num1 - num2;

					 //Display the answer to the problen
					 if (subtraction == answer2)
						 cout << " Congratulations!That's right.\n";
					 else
						 cout << " Sorry, the correct answer is " << subtraction << ".\n";
					 break;
					  
				// 3.Multiplication generate two random numbers. The first in the range 0 - 10, the second in the range 0 - 9.	

				 case MULTIPLICATION_PROBLEM:

					 //Variables
					 num1 = (rand() % (MAX3_VALUE - MIN3_VALUE + 1)) + MIN3_VALUE; // first in the range 0 - 10
					 num2 = (rand() % (MAX31_VALUE - MIN3_VALUE + 1)) + MIN3_VALUE; // Second in the range 0 - 9

					 //Get the input
					 cout << num1 << endl;
					 cout << "*" << num2 << endl;
					 cout << "---" << endl;
					 cin >> answer3;
					 multiplication = num1 * num2 ;

					 //Display the answer to the problen
					 if (multiplication == answer3)
						 cout << " Congratulations!That's right.\n";
					 else
						 cout << " Sorry, the correct answer is " << multiplication << ".\n";
					 break;

				 // 4.Division generate a single digit divisor

				 case DIVISION_PROBLEM:

					 //Variables
					 num2 = 1 + rand() % 9;
					 num1 = num2 * (rand() % 50 + 1);

					 //Get the input
					 cout << num1 << "/" << num2 << endl;
					 cin >> answer4;
					 division = num1 / num2;

					 //Display the answer to the problen
					 if (division == answer4)
						 cout << " Congratulations!That's right.\n";
					 else
						 cout << " Sorry, the correct answer is " << division << ".\n";
					 break;

				 
			}
			
		}

		//5.User quit the program
		else
		{
			cout << "\n Thank you for using math tutor!\n ";
		}

		
	} //return to menu choices
	   while (choice != QUIT_THIS_PROGRAM);
	   return 0;
	   
}

