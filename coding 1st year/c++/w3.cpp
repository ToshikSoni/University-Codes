#include <iostream>
using namespace std;
class Fraction
{
private:
    int num;
    int deno;

public:
    void get_data(int n, int d);
    void GCD();
};
void Fraction::get_data(int n, int d)
{
    num = n;
    deno = d;
}
void Fraction::GCD()
{
    int n = num;
    int d = deno;
    if (n > d)
    {
        for (int i = (n - 1); i > 0; i--)
            if (n % i == 0 && d % i == 0)
            {
                cout << "GCD: " << i;
                break;
            }
    }
    else if (n < d)
    {
        for (int i = (d - 1); i > 0; i--)
            if (n % i == 0 && d % i == 0)
            {
                cout << "GCD: " << i;
                break;
            }
    }
    else
        cout << "GCD: " << n;
}
int main()
{
    Fraction a;
    int b, c;
    cout << "Enter two numbers: ";
    cin >> b >> c;
    a.get_data(b, c);
    a.GCD();
}