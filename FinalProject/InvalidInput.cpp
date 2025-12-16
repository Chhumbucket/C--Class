#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

class InvalidInput
{
    private:
    const string message;

    public:
    
    InvalidInput(string input) : message("Invalid input \"" + input + "\".\n"){};

 
    void reason()
    {cout << message;}
    
};
