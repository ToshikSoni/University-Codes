#include <iostream>
using namespace std;
class BankAccount
{
    int Acc_No, Bal, Tran_Amou;
    char Type_Acc[50], Type_Tran[50];

public:
    void input()
    {
        cout << "Enter Account Number: ";
        cin >> Acc_No;
        cout << "Enter Account type: ";
        cin.ignore();
        gets(Type_Acc);
        cout << "Enter Balance: ";
        cin >> Bal;
    }
    void output()
    {
        cout << "Account Number: " << Acc_No << endl;
        cout << "Account type: " << Type_Acc << endl;
        cout << "Balance: " << Bal << endl;
    }
    void trans()
    {
        cout << "Enter transaction amount: ";
        cin >> Tran_Amou;
        cout << "Enter Transaction type: ";
        cin.ignore();
        gets(Type_Tran);
        Bal = Bal + Tran_Amou;
        cout << "\nUpdated balance: " << Bal;
    }
};
int main()
{
    int n;
    BankAccount a;
    while (true)
    {
        cout << "\nWhich operation do you want to perform press:\n1. For adding information\n2. For displaying information\n3. For transaction" << endl;
        cin >> n;
        if (n == 1)
            a.input();
        else if (n == 2)
            a.output();
        else if (n == 3)
            a.trans();
        else
            break;
    }
}