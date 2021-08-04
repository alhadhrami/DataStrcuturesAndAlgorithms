#include <iostream>
#include <cassert>

#define CYCLE_LENGTH 60
#define CYCLE_SUM 280

unsigned long long sumOfFibonacciNumbers(unsigned long long n, bool mod = false)
{
    if (n <= 1)
    {
        return n < 0 ? 0 : n;
    }

    unsigned long long f1 = 0;
    unsigned long long f2 = 1;

    unsigned long long sum = f1 + f2;

    for (int i = 2; i <= n; ++i)
    {
        unsigned long long temp = f2;
        f2 = (f1 + f2);
        if (mod)
        {
            f2 %= 10;
        }
        f1 = temp;
        sum += f2;
    }

    return sum;
}

unsigned long long rangedFibonacciSum(unsigned long long m, unsigned long long n)
{
    int numberOfCycles = 0;
    if (n - m >= CYCLE_LENGTH)
    {
        numberOfCycles = (int)((n - m) / CYCLE_LENGTH);
    }

    m = m % CYCLE_LENGTH;
    n = n % CYCLE_LENGTH;

    unsigned long long answer = 0;
    if (numberOfCycles == 0)
    {
        answer = sumOfFibonacciNumbers(n) - sumOfFibonacciNumbers(m == 0 ? 0 : m - 1);
    }
    else
    {
        int firstPart = (CYCLE_SUM - sumOfFibonacciNumbers(m == 0 ? 0 : m - 1, true)) % 10;
        int secondPart = (int)(sumOfFibonacciNumbers(n, true) % 10);
        answer = (unsigned long long)firstPart + secondPart;
    }

    answer %= 10;

    return answer;
}

void testSolution()
{
    assert(rangedFibonacciSum(3, 7) == 1);
    assert(rangedFibonacciSum(10, 10) == 5);
    assert(rangedFibonacciSum(10, 200) == 2);
    assert(rangedFibonacciSum(0, 0) == 0);
    assert(rangedFibonacciSum(0, 239) == 0);
    assert(rangedFibonacciSum(1234, 12345) == 8);
}

int main()
{
    unsigned long long m;
    unsigned long long n;
    std::cin >> m >> n;
    std::cout << rangedFibonacciSum(m, n) << std::endl;
    // testSolution();

    return 0;
}