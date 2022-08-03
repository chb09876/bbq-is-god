#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
    if (a % b == 0)
        return (b);

    return (gcd(b, a%b));
}

int main()
{
    long long a, b;
    long long result;

    cin >> a >> b;

    result = gcd(a, b);
    for (long long j = 0; j < result; j++)
        cout << "1";

    return (0);
}