#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
unsigned long long fibonacciIterative(unsigned long long n)
{
    if (n <= 1)
        return n;
    unsigned long long a = 0, b = 1, c;
    for (unsigned long long i = 2; i <= n; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
unsigned long long fibonacciRecursive(unsigned long long n)
{
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}
int main()
{
    unsigned long long n = 40;
    auto start = high_resolution_clock::now();
    cout << "recursive: " << fibonacciRecursive(n) << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "took " << duration.count() << " microseconds." << endl;T
}