#include <iostream>
using namespace std;

class Book
{
  private:
    char *title;
    char *isbn;
    int price;

  public:
    Book(const char *_title, const char *_isbn, int _price)
        : price(_price)
    {
        title = new char[strlen(_title) + 1];
        strcpy(title, _title);
        isbn = new char[strlen(_isbn) + 1];
        strcpy(isbn, _isbn);
    }
    ~Book()
    {
        delete[] title;
        delete[] isbn;
    }
    void ShowBookInfo()
    {
        cout << "제목: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "가격: " << price << endl;
    }
};

class Ebook : public Book
{
  private:
    char *DRMKey;

  public:
    Ebook(const char *_title, const char *_isbn, int _price, const char *_key)
        : Book(_title, _isbn, _price)
    {
        DRMKey = new char[strlen(_key) + 1];
        strcpy(DRMKey, _key);
    }
    ~Ebook()
    {
        delete[] DRMKey;
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout << "인증키: " << DRMKey << endl;
    }
};

int main()
{
    Book book("좋은 C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout << endl;

    Ebook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i1wsa");
    ebook.ShowEBookInfo();
    return 0;
}