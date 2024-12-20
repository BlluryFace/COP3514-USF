#include <iostream> // The library that contains the I/O functions

using namespace std;
// Namespace is to separate identifiers from other namespace or identifiers

int main(){
    cout << "Hello World!" << endl;
    // << is C++ insertion operator
    // cout writes to the terminal
    // endl end in new line

    int number;
    cout << "Enter an integer" << endl;
    cin >> number;
    // cin read data from keyboard
    // >> is the extraction operator
    cout << number << endl;


    string hello = "Hello";
    // Here, string is a class that created an instance called hello
    string world = "world";
    string msg;
    msg = hello + " " + world;
    // The class string defines some data and functions.
    // In this case, the concatenate function is being used
    cout << msg << endl;
    msg[0] = 'h';
    // You can access and modify an element of a string through indexing
    msg = msg + '!';
    cout << msg << endl;
    cout << msg.size() << endl;
    // Count the number of character in the string;
    string msg2 = "C program";
    cout << (msg < msg2) << endl;
    // string can also be compared using the string comparator, return 1 or 0
    return 0;
}
