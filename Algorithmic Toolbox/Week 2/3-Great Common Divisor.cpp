#include <iostream>
#include <cassert>

int gcd(int a, int b)
{
    if (a < b)
    {
        std::swap(a, b);
    }

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b) << std::endl;
    return 0;
}
