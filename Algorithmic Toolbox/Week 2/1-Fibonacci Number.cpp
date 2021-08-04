#include <iostream>
#include <cassert>

long long fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }

    long long f1 = 0;
    long long f2 = 1;

    for (int i = 2; i <= n; ++i)
    {
        f2 = f1 + f2;
        f1 = f2 - f1;
    }

    return f2;
}

int main()
{
    int n = 0;
    std::cin >> n;
    std::cout << (long long)fibonacci(n) << '\n';
    return 0;
}
