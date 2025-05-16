#include <iostream>
#include <vector>
using namespace std;
int hashfn(string text)
{
    int hashval = 0;
    for (int i = 0; i < text.length(); i++)
        hashval += text[i];
    return hashval;
}
int updated_hash(char newc, char oldc, int hash)
{
    return hash - oldc + newc;
}
vector<int> rabinkarp(string text, string pattern)
{
    int hashp = hashfn(pattern);
    int hasht = hashfn(text.substr(0, pattern.size()));
    vector<int> res;
    for (int i = 0; i < text.size() - pattern.size() + 1; i++)
    {
        if (hashp == hasht)
        {
            bool flag = true;
            int count = 0;
            for (int j = i; j < pattern.size() + i; j++)
                if (text[j] != pattern[count++])
                    flag = false;
            if (flag)
                res.push_back(i);
        }
        hasht = updated_hash(text[i + 1], text[i], hasht);
    }
    return res;
}
int main()
{
    string text = "HELLO THIS IS A EXAMPLE HELLO TEXT HELLO", pattern = "HELLO";
    vector<int> res = rabinkarp(text, pattern);
    for (auto x : res)
        cout << x << endl;
}