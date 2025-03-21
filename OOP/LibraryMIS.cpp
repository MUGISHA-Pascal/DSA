#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Book{
    private:
         string title;
         string author;
         string ISBN;
         bool isAvailable;
    public:
         Book(string t,string a,string i):title(t),author(a),ISBN(i),isAvailable(true){}
         string getTitle() const {return title;}
         string getAuthor() const {return author;}
         string getISBN() const {return ISBN;}
         bool getAvailability() const{return isAvailable;}
         void borrowBook(){
            if(isAvailable){
                isAvailable = false;
                cout << "you borrowed \""<<title<<"\" successfully \n";
            }else{
                cout<<"Sorry , \""<<title<<"\" is arleady borrowed. \n";

            }
         }
         void returnBook(){
            isAvailable = true;
            cout<<"you returned \""<<title<<"\" successfully.\n"; 
         }
        void displayBook() const{
            cout << "Title : "<<title<<", Author: "<<author<<", ISBN : "<<ISBN<<", Available : "<<(isAvailable?"yes":"no")<<endl;
        }
};
class Library{
    private:
           vector<Book> books;
    public:
          void addBook(const Book& book){
            books.push_back(book);
            cout<<"Book \"" <<book.getTitle() <<"\" added to the library .\n";
          }
          void displayAvailableBooks() const{
            cout <<"\n Available Books :\n ";
            for(const auto& book:books){
                if(book.getAvailability()){
                    book.displayBook();
                }
            }
          }
          void borrowBook(const string& title){
            for(auto& book:books){
                if(book.getTitle() == title){
                    book.borrowBook();
                    return;
                }
            }
            cout<<"Book \""<<title <<"\" not found in the library. \n";
          }
          void returnBook(const string& title){
            for(auto& book:books){
                if(book.getTitle() == title){
                    book.returnBook();
                    return;
                }
            }
            cout<<"Book \""<<title<<"\" not found in the library. \n";
          }
};
int main(){
    Library library;
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", "123456789"));
    library.addBook(Book("1984", "George Orwell", "987654321"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", "456789123"));
    library.displayAvailableBooks();
    library.borrowBook("1984");
    library.displayAvailableBooks();
    library.returnBook("1984");
    library.displayAvailableBooks();
    return 0;
}