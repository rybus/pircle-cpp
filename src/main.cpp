#include <iostream>
#include <string>

#include "sdl.h"
#include "prime.h"
#include "ulam.h"
#include "generate.h"

using namespace std;

extern int const windowLength(1000);
vector<int> readPrimesFromFile(std::istream& in);
vector<int> primeNumbers;

int main(int argc, char** argv)
{
    long int numberOfPrimes = 0;
    SDL_Renderer *window;

    if (string(argv[1]) == "generate")
    {
        if (argc != 3) {
            cout << "Not enough arguments provided." << endl;
            cout << "Usage: generate [NUMBER]" << endl;
            exit(EXIT_FAILURE);
        } 

        numberOfPrimes = stoi(argv[2]);

        generate(numberOfPrimes);

        exit(EXIT_SUCCESS);
    }
    else if (argc == 3  && string(argv[1]) == "square")
    {
        numberOfPrimes = stoi(argv[2]);

        window = drawWindow();
        primeNumbers = readPrimesFromFile(std::cin);
        drawPrimesOnSquare(window, primeNumbers);
    
        SDL_RenderPresent(window);
        pause();

        exit(EXIT_SUCCESS);
    }
    if (argc == 2  && string(argv[1]) == "ulma")
    {
        numberOfPrimes = stoi(argv[2]);

        window = drawWindow();
        primeNumbers = readPrimesFromFile(std::cin);
        drawUlamSpiral(window, primeNumbers);

        SDL_RenderPresent(window);
        pause();

        exit(EXIT_SUCCESS);
    }

    cout << "no enough argument provided: " << argc << " provided, 3 expected" << endl;

    exit(EXIT_FAILURE);
}

vector<int> readPrimesFromFile(std::istream& in)
{
   
}