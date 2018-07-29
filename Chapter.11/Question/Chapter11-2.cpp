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
    Book &operator=(const Book &ref)
    {
        delete[] title;
        delete[] isbn;

        title = new char[strlen(ref.title) + 1];
        strcpy(title, ref.title);
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(isbn, ref.isbn);
        price = ref.price;
        return *this;
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
    EBook(const Ebook &ref)
    {
        DRMKey = new char[strlen(ref.DRMKey) + 1];
        strcpy(DRMKey, ref.DRMKey);
        title = new char[strlen(ref.title) + 1];
        strcpy(title, ref.title);
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(isbn, ref.isbn);
        price = ref.price;
        return *this;
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
    Ebook &operator=(const Ebook &ref)
    {
        delete[] DRMKey;
        Book::operator=(ref);
        DRMkey = ref.DRMKey;
        return *this;
    }
};

int main()
{
    Book book1("좋은 C++", "555-12345-890-0", 20000);
    Book book2=book1;
    book2.ShowBookInfo();

    Ebook ebook1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i1wsa");
    Ebook ebook2("좋은","555-12345-890-0",20000,"fasdws12s");
    ebook2 = ebook1;
    ebook2.ShowEBookInfo)();
    return 0;
}