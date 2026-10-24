#include <iostream>
using namespace std;

int main() {
int num , sum = 0 ;
int digit = 0 ; 

    cout<<"Enter a number: ";
        cin>>num;
    
    while ( num != 0 ){
        digit = num % 10; // Taking the last digit of the number
        sum += digit;    
        num = num / 10;  // Removes the last digit which is already taken 
    }
    cout<<"The sum of all the digits is " << sum<<endl;

    return 0;
}
