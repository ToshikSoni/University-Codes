#include <iostream>
using namespace std;
class Complex
{
    int imag, real;

public:
    Complex(){};
    Complex(int r, int i)
    {
        imag = i;
        real = r;
    }
    friend Complex add(Complex c1, Complex c2)
    {
        Complex c;
        c.imag = c1.imag + c2.imag;
        c.real = c1.real + c2.real;
        return c;
    }
    friend Complex multiply(Complex c1, Complex c2)
    {
        Complex c;
        c.real = c1.real * c2.real - c1.imag * c2.imag;
        c.imag = c1.real * c2.imag + c2.real * c1.imag;
        return c;
    }
    void display()
    {
        cout << "(" << real << " + " << imag << "i)" << endl;
    }
};
int main()
{
    Complex c1(2, 3), c2(4, 5);
    Complex a = add(c1, c2);
    cout << "The sum of two complex numbers is: ";
    a.display();
    Complex m = multiply(c1, c2);
    cout << "The product of two complex numbers is: ";
    m.display();
}