/******************************/
/* HEADER CLASS myString.h    */
/******************************/
#ifndef myString_H
#define myString_H

#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;

class myString
{
  public:


    myString ( const char *charString = "" );
    myString ( const myString &other );
    myString operator = ( const myString &other );
    ~myString ();


    int getLength () const;
    char operator [] ( int n ) const;
    void clear ();


    void print () const;
    void showStructure() const;


    myString toUpper( ) const;
    myString toLower( ) const;


    bool operator == ( const myString& other ) const;
    bool operator <  ( const myString& other ) const;
    bool operator >  ( const myString& other ) const;

  private:

    // Data members
    int myStringSize;
    char *Arr;


    // myString input/output
    friend istream & operator >> (istream& input, myString& inputmyString);
    friend ostream & operator << (ostream& output, const myString& outputmyString);
};

#endif
