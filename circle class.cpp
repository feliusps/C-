// circle class lab8.cpp 

//CIS 180
//Assignment 8
//Feliu, Felix

/*
Write a program the demonstrate the Circle class perform the following tasks:
Create a Circle object called C1 with radius equal to zero.
Create a Circle object called C2 with radius equal to 5.0
Input the radius for the circle C1 from the keyboard.Enter a value of 3.0 for the radius of the Circle C1.
Display  the area of  the circle C2 by calling the function getArea.
Display the diameter of the circle C2 by calling the function getDiameter.
Display the radius and area of the circle C1 by calling the function displayCircle.
Change the radius of the circle C1 to 10.0.
Display the circumference of the circle C1 by calling the function getCircumference.
*/


#include "stdafx.h"
#include <iostream> 
#include <string>
using namespace std;

// geometry class declaretion
class geometry {
          private:
			  double radius; //data member
			  double pi = 3.1416;     //data member
          public:
			  //A default constructor that sets radius to 0.0.
			      geometry(double r);
				  void setRadius(double);          //A mutator function for the radius variable.
				  double getRadius() const;        //An accessor function for the radius variable.
				  double getArea() const;          //Return the area of the circle, which is calculated as area = pi * radius * radius
				  void displayCircle();            // In this object function you need to call the function getArea to calculate the area of a circle, then display the radius of a circle and its area - format:  Radius: ______, Area = ______ .
				  double getDiameter() const;      //Return the diameter of the circle, which is calculated as diameter = radius * 2
				  double getCircumference() const; //Return the circumference of the circle, which is calculated as circumference = 2 * pi * radius.
};

//********************************************
// All constructor are defined outside the class
//********************************************

geometry::geometry(double r )
	
{
	radius = r = 0.0;
}



//********************************************
// All funtions are defined outside the class
//********************************************

//Assig a value to the radius member.
void geometry :: setRadius(double r)
{
	radius = r;
}

//return the value in the radius member.
double geometry ::getRadius() const
{
	return radius;
}

//Return the area of the circle, which is calculated as area = pi * radius * radius
double geometry::getArea() const
{
	return radius * radius * pi;
}

// In this object function you need to call the function getArea to calculate the area of a circle,
//then display the radius of a circle and its area - format:  Radius: ______, Area = ______ .
void geometry::displayCircle()
{
	double area = getArea();
	cout << " Radius = " << radius << " Area = " << area << endl;
}

//Return the diameter of the circle, which is calculated as diameter = radius * 2
double geometry :: getDiameter() const
{
	return radius * 2;
}

//Return the circunference of the circle which is calculated C = 2*pi*r
double geometry::getCircumference() const
{
	return  2 * pi * radius;
}

//Requirements:Constructors and class functions must be defined outside the class-Define constant PI = 3.1416 in the the private section of the class


int main()
{
	geometry circleC1(0.0);       //Define an instance or object of the geometry class
	geometry circleC2(5.0);
	double localradius;    // Local variable for radius

	// Get the radius fron the user
	cout << " Enter the radius for circle C1 \n ";
	cin >> localradius;
	
	// Store the radius of  the geometry class in the circle object
	circleC1.setRadius(localradius);
		
	//Display the circle data
	circleC2.setRadius(5.0);
	cout << " Area of circle C2 : " << circleC2.getArea() << endl;
	cout << " Diameter of circle C2 : " << circleC2.getDiameter() <<endl;
	circleC1.displayCircle();
	circleC1.setRadius(10);
	cout << " Circunference of cirle C1 : " << circleC1.getCircumference() << endl;

	
	return 0;
}

