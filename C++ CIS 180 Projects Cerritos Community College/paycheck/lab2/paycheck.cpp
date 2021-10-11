
/*CIS 180
Assignment 2 paycheck
Feliu, Felix*/

/*Write a program that calculates and prints monthly paycheck for an employee.
Conditions:
   The net pay is calculated after taking severals deductions.
   Your program should prompt the user to input the gross amount.
   Format your output to have two decimal places. */

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Declare all constant variables ,all deductions

const double FEDERAL_INCOME_TAX = 0.2;
const double STATE_TAX = 0.04;
const double SOCIAL_SECURITY_TAX = 0.035;
const double MEDICARE_MEDICAID_TAX = 0.0275;
double PENSION_PLAN = 0.06;
const double HEALTH_INSURANCE = 80.00;                  //US Dollars

int main()
{
	
	// calculations
	double grossamount, fitd, std, ssd, mmd, ppd, net_pay;

	/* Input/Calculate gross amount, federate tax, sale tax, social security, medicare/medicaid tax, pension plan, health insurance and net pay*/

	// Input your gross amount
		cout << left << " Gross amount : ";
		cin >> grossamount;
	// Calculate federal income tax deductions
		fitd = FEDERAL_INCOME_TAX * grossamount;
	// Calculate State Tax Dedution.
		std = STATE_TAX * grossamount;
	// Calculate Social Security Tax
		ssd = SOCIAL_SECURITY_TAX * grossamount;
	// Calculate Medicare Medicaid Tax 
		mmd = MEDICARE_MEDICAID_TAX * grossamount;
	// Calculate pension plan
		ppd = PENSION_PLAN * grossamount;
	// Calculate Net pay
		net_pay = grossamount - (fitd + std + ssd + mmd + ppd + HEALTH_INSURANCE);
   
	// Display Outputs for all deduction amounts including gross pay and net pay. All columns must be aligned.
	// Should have two digits to the rigth of decimal point.
		cout << left << setw(26) << " Gross amount : " << right << "  $  " << setw(7)<< setprecision(6) << showpoint << grossamount << endl;
		cout << left << setw(26) << " Federal Tax : "<< right  << "  $  " << setw(7)<< setprecision(5) << showpoint << fitd << endl ;
		cout << left << setw(26) << " State tax : " << right << "  $  " << setw(7)<< setprecision(5) << showpoint << std << endl;
		cout << left << setw(26) << " Social Security Tax : "<< right << "  $  " << setw(7) <<setprecision(5) << showpoint << ssd << endl;
		cout << left << setw(26) << " Medicare/Medicaid Tax : " << right << "  $  " << setw(7) << setprecision(4) << showpoint  << mmd << endl;
		cout << left << setw(26) << " Pension Plan : " << right << "  $  " << setw(7) << setprecision(5) << showpoint << ppd << endl;
		cout << left << setw(26) << " Health Insurance : " << right << "  $  " << setw(7) << setprecision(4) << showpoint << HEALTH_INSURANCE << endl;
		cout << left << setw(26) << " Net Pay : " << right << "  $  " << setw(7)<< setprecision(6) << showpoint <<  net_pay << endl;
		
		
		return 0;
}

