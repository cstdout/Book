#include "book.h"
Book::Book()
{

}
Book::Book(const string& title,
           const string& authorFirstName,
           const string& authorLastName,
           uint32_t price,
           uint32_t pageCount,
           uint32_t circulation)
{
    _title = title;
    _authorFirstName = authorFirstName;
    _authorLastName = authorLastName;
    _price = price;
    _pageCount = pageCount;
    _circulation = circulation;

}
void Book::setTitle(const string& title)
{
    _title = title;
}
void Book::setAuthorFirstName(const string& authorFirstName)
{
    _authorFirstName = authorFirstName;
}
void Book::setAuthorLastName(const string& authorLastName)
{
    _authorLastName = authorLastName;
}
void Book::setPrice(uint32_t price)
{
    _price = price;
}
void Book::setPageCount(uint32_t pageCount)
{
    _pageCount = pageCount;
}
void Book::setCirculation(uint32_t circulation)
{
    _circulation = circulation;
}

string& Book::getTitle() const
{
    string* s = new string(_title);
    return *s;
}
string& Book::getAuthorFirstName() const
{
    string* s = new string(_title);
    return *s;
}
string& Book::getAuthorLastName() const
{
    string* s = new string(_title);
    return *s;
}
uint32_t Book::getPrice() const
{
    return _price;
}
uint32_t Book::getPageCount() const
{
    return _pageCount;
}
uint32_t Book::getCirculation() const
{
    return _circulation;
}

ostream& operator<<(ostream& out, const Book& b)
{
    out << b._title << ' ' << b._authorFirstName << ' ' << b._authorLastName << ' ' << b._price << ' ' << b._pageCount << b._circulation;
    return out;
}
std::istream& operator>>(std::istream& in, Book& b)
{
    in >> b._title >> b._authorFirstName >> b._authorLastName >> b._price >> b._pageCount >> b._circulation;
    return in;
}


