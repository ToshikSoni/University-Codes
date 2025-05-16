#include <iostream>
using namespace std;
struct Complex
{
    int real;
    int imag;
};
int main()
{
    Complex a, b;
    cout << "Enter real value of 1st number: ";
    cin >> a.real;
    cout << "Enter imaginary value of 1st number: ";
    cin >> a.imag;
    cout << "Enter real value of 2nd number: ";
    cin >> b.real;
    cout << "Enter imaginary value of 2nd number: ";
    cin >> b.imag;
    cout << "\nFirst number: " << a.real << " + " << a.imag << "i\n\n";
    cout << "Second number: " << b.real << " + " << b.imag << "i\n\n";
    cout << "Sum of numbers: " << (a.real + b.real) << " + " << (a.imag + b.imag) << "i\n";
    cout << "Subtracion of numbers: " << (a.real - b.real) << " + " << (a.imag - b.imag) << "i";
}