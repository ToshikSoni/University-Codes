#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int countDigits(int num)
{
    if (num == 0)
        return 0;
    return (1 + countDigits(num / 10));
}
    
int main()
{
}