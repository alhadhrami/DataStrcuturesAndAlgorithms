#include <iostream>
using namespace std;
int main() {
    long long n;
    cin >> n;

    long long biggestNumber = 1;
    long long secondBiggestNumber = 1;
    long long temp = 0;

    cin >> biggestNumber;
    
    for (long long i = 1; i < n; ++i) {
        cin >> temp;
        if (temp > biggestNumber)
        {
            secondBiggestNumber = biggestNumber;
            biggestNumber = temp;
        }
        else if (temp > secondBiggestNumber)
        {
            secondBiggestNumber = temp;
        }
    }

    cout << (secondBiggestNumber * biggestNumber) << endl;

    return 0;
}