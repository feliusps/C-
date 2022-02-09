/*
 complete the next code user should enter the date of birth using cin
  #include <iostream>
using namespace std;

void date_of_birth() {
    int m {};
    int d {};
    int y {};
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //---- WRITE YOUR CODE BELOW THIS LINE----
    
    
    
    //---- WRITE YOUR CODE ABOVE THIS LINE----
    //---- Do NOT MODIFY THE CODE BELOW THIS LINE----
    cout << m << " " << d << " " << y;*/
    
#include <iostream>
using namespace std;


int main()
 {
// declare variables   
int m {}; // months
int d  {}; //days
int y  {}; // years

cout << "Enter month of birth" << endl;
cin >> m;
cout << "Enter day of birth" << endl;
cin >> d;
cout << "Enter year of birth" << endl;
cin >> y;
    
    //The following will also work
   // cin >> m >> d >> y;
cout << "Date of Birth" << endl;       
cout << m << " / " << d << " / " << y << endl;
return 0;        
}
    
    