#include <iostream>
#include "store.h"

using namespace std;

#define WINDOW_LENGTH 1000

int main(int argc, char** argv)
{
    double expensionFactor;
    int numberOfPrimes = 0;

    if (argc == 3)
    {
        if (string(argv[1]) == "generate")
        {
            numberOfPrimes = stoi(argv[2]);

            generate(numberOfPrimes);

            return 0;
        }
        else
        {
            numberOfPrimes = stoi(argv[1]);
            expensionFactor = stod(argv[2]);

            cout << numberOfPrimes << expensionFactor;
            return 0;
            // return display(numberOfPrimes, expension_factor);
        }
    }

    cout << "no enough argument provided: " << argc << " provided, 3 expected" << endl;

    return 0;
}
