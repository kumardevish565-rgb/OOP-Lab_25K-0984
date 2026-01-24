#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    int Id;
    string Title;
    string AuthorName;
    float Price;
} Book;

int main()
{
    Book books[3];
    for (int a = 0; a < 3; a++)
    {
        cout << "Enter book Id \n";
        cin >> books[a].Id;
        cout << "Enter book title \n";
        getline(cin >> ws, books[a].Title);
        cout << "Enter author name of the book \n";
        getline(cin >> ws, books[a].AuthorName);
        cout << "Enter the price of book \n";
        cin >> books[a].Price;
    }
    float total=0;
    cout << "Book Details\n";
    for (int b = 0; b < 3; b++)
    {
        cout << "Book Title: " << books[b].Title << endl;
        cout << "Book Id: " << books[b].Id << endl;
        cout << "Author Name: " << books[b].AuthorName << endl;
        cout << "Price: " << books[b].Price << endl <<endl;
        total += books[b].Price;
    }
    cout << "Total price of all books is " << total << endl;
    return 0;
}