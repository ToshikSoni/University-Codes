#include <iostream>
#include <vector>
using namespace std;
int hashfn(string text)
{
    int hashvalue = 0;
    for (auto x : text)
        hashvalue += int(x);
    return hashvalue;
}
vector<int> rabinkarb(string TT, string PP)
{
    int hashpp = hashfn(PP);
    int lenpp = PP.length();
    vector<int> res;
    for (int i = 0; i < (TT.length() - lenpp + 1); i++)
        if (hashfn(TT.substr(i, lenpp)) == hashpp)
        {
            bool flag = true;
            int count = 0;
            for (int j = i; j < lenpp; j++)
                if (TT[j] != PP[count++])
                    flag = false;
            if (flag)
                res.push_back(i);
        }
    return res;
}
int main()
{
    string TT = "THIS IS A SIMPLE EXAMPLE";
    string PP = "EXAMPLE";
    vector<int> res = rabinkarb(TT, PP);
    for (auto x : res)
        cout << x << endl;
}