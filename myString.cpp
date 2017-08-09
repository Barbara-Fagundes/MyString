/*********************************/
/*MAIN FUNCTION: TestMyString.cpp*/
/*********************************/
#include <iostream>
#include "myString.h"
using namespace std;
//--------------------------------------------------------------------
//
//  Function prototype

void copyTester(myString copymyString);   // copymyString is passed by value
void print_help();

//--------------------------------------------------------------------

int main()
{
    myString a("a"),                // Predefined test myString objects
        alp("alp"),
        alpha("alpha"),
        epsilon("epsilon"),
        empty,
        assignmyString,          // Destination for assignment
        inputmyString;           // Input myString object
    int n;                        // Input subscript
    char ch,                      // Character specified by subscript
        selection;        // Input test selection
// Displays options to user.
    print_help();

    //User selects a test to do.
    cin >> selection;

    cout << endl;
//The selected test is evaluated
    switch (selection)
    {
        case '1':
        // Test 1 : Tests the constructors. Displays the myString objects that have been created
        cout << "Structure of various myString objects: " << endl;
        cout << "myString object: alpha" << endl;
        alpha.print();
        alpha.showStructure();
        cout << "myString object: epsilon" << endl;
        epsilon.print();
        epsilon.showStructure();
        cout << "myString object: a" << endl;
        a.print();
        a.showStructure();
        cout << "empty myString object" << endl;
        empty.print();
        empty.showStructure();
        break;

    case '2':
        // Test 2 : Tests the length operation.
        cout << "Lengths of various myString object:" << endl;
        cout << " alpha   : " << alpha.getLength() << endl;
        cout << " epsilon : " << epsilon.getLength() << endl;
        cout << " a       : " << a.getLength() << endl;
        cout << " empty   : " << empty.getLength() << endl;
        break;

    case '3':
        // Test 3 : Tests the subscript operation.
        cout << "Enter a subscript : ";
        cin >> n;
        ch = alpha[n];
        cout << "  alpha[" << n << "] : ";
        if (ch == '\0')
            cout << "\\0" << endl;
        else
            cout << ch << endl;
        break;

    case '4':
        // Test 4 : Tests the assignment and clear operations. The myString object "assignmyString" is assigned with other myString objects tnanks to the overload from the operator =
        cout << "Assignments:" << endl;
        cout << "assignmyString = alpha" << endl;
        assignmyString = alpha;
        assignmyString.showStructure();
        cout << "assignmyString = a" << endl;
        assignmyString = a;
        assignmyString.showStructure();
        cout << "assignmyString = empty" << endl;
        assignmyString = empty;
        assignmyString.showStructure();
        cout << "assignmyString = epsilon" << endl;
        assignmyString = epsilon;
        assignmyString.showStructure();
        cout << "assignmyString = assignmyString" << endl;
        assignmyString = assignmyString;
        assignmyString.showStructure();
        cout << "assignmyString = alpha" << endl;
        assignmyString = alpha;
        assignmyString.showStructure();
        cout << "Clear assignmyString" << endl;
        assignmyString.clear();
        assignmyString.showStructure();
        cout << "Confirm that alpha has not been cleared" << endl;
        alpha.showStructure();
        break;

    case '5':
        // Test 5 : Tests the copy constructor and operator= operations.
        cout << "Calls by value:" << endl;
        cout << "alpha before call" << endl;
        alpha.showStructure();
        copyTester(alpha);
        cout << "alpha after call" << endl;
        alpha.showStructure();

        cout << "a before call" << endl;
        a.showStructure();
        a = epsilon;
        cout << "a after call" << endl;
        a.showStructure();
        cout << "epsilon after call" << endl;
        epsilon.showStructure();
        break;

    case '6':
        // Test 6 : Tests toUpper and toLower
        cout << "Testing toUpper and toLower."
            << "Enter a mixed case string: " << endl;
        cin >> inputmyString;
        cout << "Input string:" << endl;
        inputmyString.showStructure();
        cout << "Upper case copy: " << endl;
        inputmyString.toUpper().showStructure();
        cout << "Lower case copy: " << endl;
        inputmyString.toLower().showStructure();
        break;

    case '7':
        // Test 7 : Tests the relational operations and displays the relations existing between different myString objects.
        cout << "  left     right     <   ==   > " << endl;
        cout << "--------------------------------" << endl;
        cout << " alpha    epsilon    " << (alpha<epsilon)
            << "    " << (alpha == epsilon) << "   "
            << (alpha>epsilon) << endl;
        cout << " epsilon   alpha     " << (epsilon<alpha)
            << "    " << (epsilon == alpha) << "   "
            << (epsilon>alpha) << endl;
        cout << " alpha     alpha     " << (alpha<alpha) << "    "
            << (alpha == alpha) << "   " << (alpha>alpha) << endl;
        cout << "  alp      alpha     " << (alp<alpha) << "    "
            << (alp == alpha) << "   " << (alp>alpha) << endl;
        cout << " alpha      alp      " << (alpha<alp) << "    "
            << (alpha == alp) << "   " << (alpha>alp) << endl;
        cout << "   a       alpha     " << (a<alpha) << "    "
            << (a == alpha) << "   " << (a>alpha) << endl;
        cout << " alpha       a       " << (alpha<a) << "    "
            << (alpha == a) << "   " << (alpha>a) << endl;
        cout << " empty     alpha     " << (empty<alpha) << "    "
            << (empty == alpha) << "   " << (empty>alpha) << endl;
        cout << " alpha     empty     " << (alpha<empty) << "    "
            << (alpha == empty) << "   " << (alpha>empty) << endl;
        cout << " empty     empty     " << (empty<empty) << "    "
            << (empty == empty) << "   " << (empty>empty) << endl;
        break;

    default:
        cout << "'" << selection << "' specifies an inactive or invalid test" << endl;
    }

    return 0;
}

//--------------------------------------------------------------------

void copyTester(myString copymyString)

// Dummy routine that is passed a myString object using call by value. Outputs
// copymyString and clears it.

{
    cout << "Copy of myString object" << endl;
    copymyString.showStructure();
    cout << "Clear copy" << endl;
    copymyString.clear();
    copymyString.showStructure();
}

//--------------------------------------------------------------------

void print_help()
{
    cout << endl << "Tests:" << endl;
    cout << "  1  Tests the constructors" << endl;
    cout << "  2  Tests the length operation" << endl;
    cout << "  3  Tests the subscript operation" << endl;
    cout << "  4  Tests the assignment and clear operations" << endl;
    cout << "  5  Tests the copy constructor and operator= operations" << endl;
    cout << "  6  Tests the toUpper and toLower operations      " << endl;
    cout << "  7  Tests the relational operations    " << endl;
    cout << "Select the test to run : "<<endl;
}
