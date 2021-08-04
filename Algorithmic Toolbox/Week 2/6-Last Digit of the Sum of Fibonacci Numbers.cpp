#include <iostream>
#include <cassert>

int sumOfFibonacciNumbers(unsigned long long n)
{
    n %= 60;
    if (n <= 1)
    {
        return (int)n;
    }


    unsigned long long f1 = 0;
    unsigned long long f2 = 1;

    unsigned long long sum = f1 + f2;

    for (unsigned long long i = 2; i <= n; ++i)
    {
        unsigned long long temp = f2;
        f2 = (f1 + f2) % 10;
        f1 = temp;
        sum += f2;
    }

    return sum % 10;
}

void testSolution()
{
    assert(sumOfFibonacciNumbers(3) == 4);
    assert(sumOfFibonacciNumbers(100) == 5);
    assert(sumOfFibonacciNumbers(614162383528) == 9);
    assert(sumOfFibonacciNumbers(240) == 0);    
}

int main()
{
    unsigned long long n;
    std::cin >> n;
    int sum = sumOfFibonacciNumbers(n);
    std::cout << sum << std::endl;
    
    // testSolution();

    return 0;
}