#include <iostream>
#include <string>
using namespace std;

class Book {
    string Title;
    string Author;
    int ISBN;
    bool Status;
public:
    void Display() const{
        cout << "----------------\nTitle: " << Title << endl;
        cout << "Author: " << Author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Availability status: " << Status << endl;
    }
    void Input(int isbn){
        cout << "Enter book title \n";
        getline(cin >> ws, Title);
        cout << "Enter book author \n";
        getline(cin >> ws,Author);
        ISBN=isbn;
        int temp;
        do{
            cout << "Enter whether book is available for borrowing(1 for yes and 0 for no) \n";
            cin >> temp;
        } while(temp<0 || temp>1);
        Status=temp;
    }
    int GetIsbn() const{
        return ISBN;
    }
    void Borrow(){        
        if(Status==true){
            Status=false;
            cout << "Book borrowed successfully\n";
        }
        else{
            cout << "Book already borrowed\n";
        }
    }
    void Return(){
        if(Status==true){
            cout << "Error: Book is marked as not borrowed\n";
        }
        else{
           Status=true;
           cout << "Book successfully returned\n";
        }   
    }
};

class Library {
public:
    Book *books;
    int size;
    Library(int s){
        size=s;
        books=new Book[size];
    }
    ~Library(){
        delete[] books;
    }
    void EnterDetails() {
        int temp;
        for(int a=0;a<size;a++){
            do{
                cout << "Enter book ISBN(unique) \n";
                cin >> temp;
            } while(Search(temp)!=-1);
            books[a].Input(temp);
        }
    }
    void OutputDetails() const{
        cout << boolalpha;
        for(int a=0;a<size;a++){
            books[a].Display(); 
        }
    }
    int Search(int isbn) const{
        int found=-1;
        for(int a=0;a<size;a++){
            if(books[a].GetIsbn()==isbn){
                found=a;
                break;
            }
        }
        return found;
    }
};

int main(){
    int size;
    cout << "Enter the number of books \n";
    cin >> size;
    if(size<=0){
        cout << "Invalid number of books\n";
        return 1;
    }
    Library library(size);
    int temp;
    do{
        cout << "Enter 1 to enter details for all books, 2 to display all book details, 3 to borrow a book, 4 to return a book, 5 to search for book by ISBN, 6 to exit \n";
        cin >> temp;
        switch (temp){
            case 1:
                library.EnterDetails();
                break;
            case 2:
                library.OutputDetails();
                break;
            case 3: {
                int isbn;
                cout << "Enter isbn of the book to borrow \n";
                cin >> isbn;
                int result=library.Search(isbn);
                if(result==-1){
                    cout << "Book not found\n";
                }
                else{
                    library.books[result].Borrow();
                }
                break;
            }
            case 4: {
                int isbn;
                cout << "Enter isbn of the book to return \n";
                cin >> isbn;
                int result=library.Search(isbn);
                if(result==-1){
                    cout << "Book not found\n";
                }
                else{
                    library.books[result].Return();
                }
                break;
            }
            case 5: {
                int isbn;
                cout << "Enter isbn of the book to search \n";
                cin >> isbn;
                int result=library.Search(isbn);
                (result==-1)? cout << "Book not found\n": cout << "Book found\n";
                break;
            }
            case 6:
                cout << "Exitting...\n";
                break;
            default:
                cout << "Invalid Option\n";
        }
    } while(temp!=6);
    return 0;
}