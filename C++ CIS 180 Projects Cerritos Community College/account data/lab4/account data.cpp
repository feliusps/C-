// account datalab4.cpp


//CIS 180
//Assignment 4
//Feliu , Felix


/*The No Interest Credit Company provides zero-interest loans to customers.
Design an application that gets customer account data that includes an account number, customer name, and balance due.
For each customer, display the account number and name; then print the customer's projected balance each month for the next 10 months.
Assume that there is no finance charge on this account, that the customer makes no new purchases,
and that the customer pays off the balance with equal monthly payments, which are 10 percent of the original bill.*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>            //for string class
using namespace std;

//Funcion prototypes
void displayColumnTitle();
float calculateBlanceDue(float, float);
void dipslayBalance(int, float);


int main()
{   
	//Declaring variables 
	int accountnumber ;                 // variable account number
	string name;                          // Name account owner
	const int TERMINATE_INPUT = -1;     // For finish the program
	float balance, payment, balanceDue ;// input output variables
	const double PERCENTAGE = 0.10 ;    // 10% even payment
	
	

	// Repeating customer account information using Do-While loop
	do
	{
		// display customer information
		cout << "Enter Account Number (-1 to terminate the imput) : \n";
		cin >> accountnumber; 

		// if the user does not want to quit, proceed.
		if (accountnumber != TERMINATE_INPUT )
		{
			cout << "Enter name\n";
		    cin >> name;
		    cout << "Enter balance due:\n\n";
		    cin >> balance;
			cout << " Account Number: " << accountnumber << endl;
			cout << " Name: " << name << endl;

			//calculate customen payments 10 porcent of the original amount 
			payment = balance * PERCENTAGE;

			// call display column
			displayColumnTitle();

			int month = 1;
			while (month <= 10)
			{
				
				//Call  calculate balance
				balanceDue = calculateBlanceDue(balance, payment);
				//Call display balance 
				dipslayBalance(month, balanceDue);
				//update balance
				balance = balanceDue;
				//next month
				month++;
			}
		}
		//5.User quit the program
		else
		{
			cout << "\n Thank you \n ";
		}


   } //return to menu user's input
    while (accountnumber != TERMINATE_INPUT);
    return 0;

}




//**************************************************************************
//Display the column titles
//**************************************************************************

void displayColumnTitle()
{
	cout << left << setw(8) << " MONTH " << right << setw(15) << " BALANCE DUE " << endl;
}



//**************************************************************************
//Calculate and return the balance due.
//**************************************************************************

float calculateBlanceDue(float balanceDue, float paymentAmt)
{

	return   balanceDue = balanceDue - paymentAmt;
	
}


//**************************************************************************
//Display the month and the balance due
//**************************************************************************
void dipslayBalance(int month, float balanceDue)
{
	cout << setprecision(2) << fixed ;
	cout << left << setw(8) << month << right << setw(15) << balanceDue << endl;

}
