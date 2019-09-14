// calories burn off.cpp : Defines the entry point for the console application.

//CIS 180
//Assigment 1
//Felix Feliu

/*Running and walking burns out about 100 calories per mile.
write a program to calculate how many mile you have to run or walk to burn off the burritos, salads and shake
that you consume*/

#include "stdafx.h"
#include<iostream>
#include<iomanip>
using namespace std;

// main

int main()
{
	int beanburritos, saladwithdressing, milkshake;
	float calories;
	float miles;
	float a = 100;

	//Get the number of calories for food
	cout << "How many bean burritos, bowls of salad, and milk shakes did you consume?";
	cin >> beanburritos  >> saladwithdressing  >> milkshake;

	//How many calories you consumed
	calories = (beanburritos * 357) + (saladwithdressing * 185) + (milkshake * 388);
	cout << "You ingested " << calories << " calories.\n";

	//How many miles you have to run to burn off the calories
	miles = calories / a;
	cout << "You will have to run " << miles << " miles to expend that much energy.\n";

	return 0;

    
}

