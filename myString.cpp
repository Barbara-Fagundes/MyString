/********************************/
/* SOURCE CLASS myString.cpp    */
/********************************/
#include <iostream> 
#include <string.h>
#include "myString.h"
using namespace std;

myString::myString(const char*  charString)
//Constructor by initialisation, will be called when an array of char is given as parameter 
{
//The private member myStringSize is assigned with the length of the array of char given in parameter increased from 1, an extra space is allocated for a null character (\0) 
    myStringSize = strlen(charString) + 1;
//An array of char from the length of the one given in parameter plus 1 is created     
    Arr = new char[myStringSize];
//The array passed in parameter is copied in the one we just created 
    strcpy(Arr, charString);
}

myString::myString(const myString &other)
//Copy constructor, will be used if:
//- a myString object is returned by a function
//- a myString object is given as parameter by value to a function
//- a myString object is assigned by another using overload from opetator =
{
//The private member myStringSize is assigned with the same value than the myStringSize member from the myString object given in patameter 
    myStringSize = other.myStringSize;
//An array of char from same length than the one from the myString object given in parameter is created    
    Arr = new char[myStringSize];
//The array from the myString object passed in parameter is copied in the one we just created      
    strcpy(Arr , other.Arr);
}

myString::~myString()
//Destructor, frees memory that was allocated to the array of char 
{
    delete []Arr;
//And sets its size to 0    
    myStringSize = 0;
}

friend istream & operator >>(istream& input, myString& inputmyString)
//Overload from operator >>, it allows to assign a text introduced through the keyboard to the array of char from a new myString object 
{
//A new array of char from size 100 is declared    
    char tempArr[100];
//The input value is cut to the length from the temporary array of char if bigger then assigned to it            
    input >> setw(100) >> tempArr;
//The temporary array of char is assigned as parameter to a new myString object   
    inputmyString = tempArr; 
//input is returned    
    return input; 
}
    
friend ostream & operator <<(ostream& output, const myString& outputmyString)
//Overload from operator <<, it allows to display the private members from a myString object thanks to cout
{
//Assigns output with the text and size from the array of char 
    output << "\nText : " << outputmyString.Arr << "\nSize : " << strlen(outputmyString.Arr) << "\n" << endl;
//And returns it    
    return output;     
}

myString myString::operator =(const myString &other)
//Overload from the operator =, it allows us to assign the private members from a myString object with the values from the private members from another myString object given in parameter 
{
//If the myString given in parameter is not having the same length than the one that is assigned, 
    if(other.myStringSize != this->myStringSize)
    {
//We delete the existing array   
        delete []Arr;
//We adjust its size to the size of the parameter   
        this->myStringSize = other.myStringSize;
//A new array from that size is created        
        Arr = new char[this->myStringSize];
    }
//It is now assigned with the value from the one from the myString object given in parameter 
    strcpy(this->Arr ,other.Arr);
//The myString object that was assigned with new values is now returned   
    return *this;    
}

char myString::operator [](int n) const
//Overload from the opetator [], it allows us to access the member from the array contained in the myString object which index is given inside the []
{
//Returns the required member from the array 
    return this->Arr[n];
}

bool myString::operator ==(const myString& other) const
//Overload from the opetator ==, it allows us to compare 2 myString objects and see if they are the sames (what means if their private members are having the same values)
{
//strcmp returns 0 if the items compared are the sames, return from the function strcmp is evaluated with the value of 0, if strcmp returns 0, true is returned, if the 2 items are different, strcmp doesn't return 0, then the return value is false 
    return strcmp(this->Arr,other.Arr) == 0;
}
    
bool myString::operator <(const myString& other) const
//Overload from the opetator <, it allows us to compare 2 myString objects 
{
//strcmp returns -1 if the item from left value is lexicographically smaller compared to the one given in parameter. If strcmp returns -1, the expression is evaluated to true and true is returned. Else, return value is false. 
    return strcmp(this->Arr,other.Arr) < 0;    
}

bool myString::operator >(const myString& other) const
//Overload from the opetator >, it allows us to compare 2 myString objects 
{
//strcmp returns 1 if the item from left value is lexicographically bigger compared to the one given in parameter. If strcmp returns 1, the expression is evaluated to true and true is returned. Else, return value is false.
    return strcmp(this->Arr,other.Arr) > 0;    
}

void myString::clear()
//Called to delete the values from the data members from a myString object
{
//delete calls the destructor from the Class 
    delete this; 
}

int myString::getLength() const
//Called to know the length from a myString object
{
//Returns the length from the array of char contained in the myString object 
    return strlen(this->Arr); 
}

void myString::print() const
//Prints the text contained in the array private member 
{
//Loops in the array 
    for(int x = 0; x < myStringSize - 1; x++)
    {
//And prints each char one y one     
        cout << this->Arr[x];
    }
//Goes to the next line    
    cout << "\n";
}

void myString::showStructure() const
//Will display the index numbers and the text from the array
{
//Loops in the array 
    for(int x = 0; x < myStringSize; x++) 
    {
//While index from the array is smaller than 10    
        if(x < 10)
        {
//index is displayed separated with 2 tabulations        
            cout << x << "\t\t"
;    
        }
        else
//When index reaches 10         
        {
//Index values are now separated only by 1 tabulation        
            cout << x << "\t"
;     
        }
    } 
//Goes to the next line    
    cout << endl;
    
    for(int x = 0; x < myStringSize - 1; x++)
//Loop to read the array 
    {
//A char is created and given the value from the char that was just read in the array   
        char c = this->Arr[x];
//Each char is displayed separated with 2 tabulations         
        cout << c << "\t\t";
    }
//A null character is displayed on screen at the end of the string     
    cout << "\\o\n" << endl;
}

myString myString::toUpper() const 
//Sets the myString array of char to uppercase 
{
//A new array of char from size 100 is created 
    char tempArr[100];
    for(int x = 0; x < myStringSize; x++)
//Loops in the array of char from the myString object and copy each char set to uppercase in the new array     
    {
        tempArr[x] = toupper(this->Arr[x]);
    }
//The new array of char set to uppercase is given as parameter to create a new myString object    
    myString tempMyStr(tempArr);
//The new myString object is returned        
    return tempMyStr;
}
                         
myString myString::toLower() const
//Sets the myString array of char to lowercase 
{
//A new array of char from size 100 is created 
    char tempArr[100];
    for(int x = 0; x < myStringSize; x++)
//Loops in the array of char from the myString object and copy each char set to lowercase in the new array    
    {
        tempArr[x] = tolower(this->Arr[x]);
    }
//The new array of char set to lowercase is given as parameter to create a new myString object    
    myString tempMyStr(tempArr);
//The new myString object is returned        
    return tempMyStr; 
}
