#include <iostream>
#include <cassert>

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }

    int f1 = 0;
    int f2 = 1;

    for (int i = 2; i <= n; ++i)
    {
        int temp = f2;
        f2 = (f1 + f2) % 10;
        f1 = temp;
    }

    return f2;
}

int main()
{
    int n;
    std::cin >> n;
    int c = fibonacci(n);
    std::cout << c << '\n';
}