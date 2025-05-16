#include <iostream>
using namespace std;
class Book
{
    string Title, Author, ISBN;
    int Quantity;
    bool Availability;

public:
    Book(){};
    Book(string a, string b, string c, int d)
    {
        Title = a;
        Author = b;
        ISBN = c;
        Quantity = d;
        if (Quantity > 0)
            Availability = true;
        else
            Availability = false;
    }
    void show()
    {
        cout << "\nTitle: " << Title << "\nAuthor: " << Author << "\nISBN: " << ISBN << "\nQuantity: " << Quantity << endl;
        if (Availability == true)
            cout << "Available: Yes" << endl;
        else
            cout << "Available: No" << endl;
    }
    void availability()
    {
        if (Availability == true)
            cout << "\nThe book is available." << endl;
        else
            cout << "\nThe book is not available." << endl;
    }
    void issue()
    {
        if (Quantity > 0)
        {
            cout << "\nBook is issued." << endl;
            Quantity--;
            if (Quantity == 0)
                Availability = false;
        }
        else
            cout << "\nBook is not available." << endl;
    }
    void returnBook()
    {
        cout << "\nBook is returned." << endl;
        Quantity++;
        Availability = true;
    }
};
int main()
{
    int num, quan, t, tb;
    string tit, auth, isbn;
    char temp;
    cout << "Enter number of books: ";
    cin >> num;
    Book b[num];
    for (int i = 0; i < num; i++)
    {
        cout << "\nEnter title of book " << i + 1 << " :";
        cin.ignore();
        getline(cin, tit);
        cout << "Enter author: ";
        getline(cin, auth);
        cout << "Enter ISBN: ";
        getline(cin, isbn);
        cout << "Enter quantity of book: ";
        cin >> quan;
        b[i] = Book(tit, auth, isbn, quan);
    }
    do
    {
        cout << "\n\nEnter book number: ";
        cin >> tb;
        cout << "\n\n1. Show book information.\n2. Show availablity\n3. Issue a book.\n4. Return a book.\n\nWhich function do you want to perform: ";
        cin >> t;
        switch (t)
        {
        case 1:
            b[tb - 1].show();
            break;
        case 2:
            b[tb - 1].availability();
            break;
        case 3:
            b[tb - 1].issue();
            break;
        case 4:
            b[tb - 1].returnBook();
            break;
        default:
            cout
                << "Enter an valid input."
                << endl;
            break;
        }
        cout << "\nDo you want to continue(press y to continue): ";
        cin >> temp;
    } while (temp == 'y');
}