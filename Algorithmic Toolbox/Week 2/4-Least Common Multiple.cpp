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

long long lcm(int a, int b) {
  
    return (long long)a * b / gcd(a, b);
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << lcm(a, b) << std::endl;
    return 0;
}