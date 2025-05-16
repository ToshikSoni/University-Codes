#include <iostream>
#include <vector>
using namespace std;
vector<int> LPS(string text)
{
    vector<int> lps(text.size(), 0);
    for (int i = 1; i < text.size(); i++)
    {
        int count = 0;
        while (text[i] == text[count++] && i < text.size())
            lps[i++] = count;
    }
    return lps;
}
vector<int> searchPattern(vector<int> lps, string text, string pattern)
{
    vector<int> res;
    int j = 0;
    for (int i = 0; i < text.size(); i++)
    {
    x:
        bool flag = false;
        while (text[i++] == pattern[j++] && i < text.size() && j < pattern.size())
            flag = true;
        if (flag)
            if (j == pattern.size())
            {
                res.push_back(i - pattern.size());
                j = 0;
                i--;
            }
            else
            {
                j = lps[j];
                goto x;
            }
    }
    return res;
}
int main()
{
    string pattern = "ababc";
    vector<int> lps = LPS(pattern);
    vector<int> res = searchPattern(lps, "ababcababcababcababc", pattern);
    for (auto x : res)
        cout << x << ' ';
}