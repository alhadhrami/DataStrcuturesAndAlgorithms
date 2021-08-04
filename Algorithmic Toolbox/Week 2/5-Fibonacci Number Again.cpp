#include <iostream>
#include <cassert>

unsigned long long fibonacci(unsigned long long n, unsigned long long m)
{
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

    return current % m;
}

unsigned long long fibonacciPeriodLength(unsigned long long m)
{
    long long previous = 0;
    long long current = 1;

    unsigned int length = 2;

    long long currentModuloResult = previous % m;
    long long previousModuloResult = current % m;

    for (unsigned long long i = 2; i <= (m * m); ++i)
    {
        unsigned long long temp = current;
        current = (previous + current) % m;
        previous = temp;
        previousModuloResult = previous % m;
        currentModuloResult = current % m;

        if (previousModuloResult == 0 && currentModuloResult == 1)
        {
            --length;
            return length;
        }
        else
        {
            ++length;
        }
    }
    return length;
}

unsigned long long getFibonacciModulo(unsigned long long n, unsigned int m)
{
    if (n <= 1)
    {
        return n;
    }

    unsigned long long length = fibonacciPeriodLength(m);
    unsigned long long newFibonacci = n % length;
    unsigned long long result = fibonacci(newFibonacci, m);
    return result;
}

void testSolution()
{
    assert(getFibonacciModulo(239, 1000) == 161);
    assert(getFibonacciModulo(2816213588, 239) == 151);
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::cout << getFibonacciModulo(n, m) << '\n';

    //testSolution();

    return 0;
}
