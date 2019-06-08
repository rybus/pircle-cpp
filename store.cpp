#include "store.h"

using namespace std;

void generate(int numberOfPrime)
{
    int generatedPrimes = 0;
    int i = 0;

    while (numberOfPrime > generatedPrimes)
    {
        if (isPrime(i)) {
            cout << i << endl;
            generatedPrimes++;
        }
        i++;
    }
}

vector<int> getPrimes(int numberOfPrimes)
{
    int numberOfReadPrimes = 0;
    vector<int> primeList;

    ifstream primeFile("primes.txt");

    if(primeFile)
    {
        string primeNumber;

        while(getline(primeFile, primeNumber) && primeList.size() <= numberOfPrimes)
        {
            primeList.push_back(stoi(primeNumber));
            numberOfReadPrimes++;
        }
    }
    else
    {
        cout << "ERREUR: Cannot open primes.txt." << endl;
    }

    return primeList;
}

bool isPrime(int number)
{
    int i;

    for (i = 2; i < number; i++)
    {
        if (number % i == 0)
            return false;
    }

    if (i == number) {
        return true;
    }
    
    return false;
}
