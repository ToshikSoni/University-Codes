//https://leetcode.com/problems/plus-one/
// Microsoft
// Hewlett Packard Enterprise
// Google
// American Express Media.net
// Genpact GE (General Electric)
// Tiger Analytics Coditas
// Airtel
// Betsol

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> res;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
            if (carry == 1)
                if (digits[i] == 9)
                    res.push_back(0);
                else
                {
                    carry = 0;
                    res.push_back(digits[i] + 1);
                }
            else
            {
                carry = 0;
                res.push_back(digits[i]);
            }
        if (carry == 1)
            res.push_back(1);
        for (int i = 0; i < res.size() / 2; i++)
            swap(res[i], res[res.size() - i - 1]);
        return res;
    }
};