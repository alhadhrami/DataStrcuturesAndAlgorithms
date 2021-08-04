#include <iostream>
#include <cassert>

unsigned long long sumOfFibonacciSquares(unsigned long long n, unsigned long long m = 10)
{

    n = n % 60;

    if (n <= 1)
    {
        return static_cast<unsigned int>(n);
    }


    unsigned long long previous = 0;
    unsigned long long current = 1;

    for (unsigned long long i = 2; i <= n; ++i)
    {
        unsigned long long temp = current;
        current = (previous + current) % m;
        previous = temp;
    }
    int answer = (current * (current + previous)) % 10;
    return answer;
}


void testSolution()
{
    assert(sumOfFibonacciSquares(7) == 3);
    assert(sumOfFibonacciSquares(73) == 1);
    assert(sumOfFibonacciSquares(1234567890) == 0);
    assert(sumOfFibonacciSquares(240) == 0);
}

int main()
{
    unsigned long long n;
    std::cin >> n;
    std::cout << sumOfFibonacciSquares(n) << '\n';

    //testSolution();
    return 0;
}
