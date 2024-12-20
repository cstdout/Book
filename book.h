#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <cstdint>
using namespace std;
class Book
{
protected:
    string _title;
    string _authorFirstName;
    string _authorLastName;
    uint32_t _price;
    uint32_t _pageCount;
    uint32_t _circulation;
public:
    Book(const string& title,
         const string& authorFirstName,
         const string& authorLastName,
         uint32_t price,
         uint32_t pageCount,
         uint32_t circulation);

    void setTitle(const string& title);
    void setAuthorFirstName(const string& authorFirstName);
    void setAuthorLastName(const string& authorLastName);
    void setPrice(uint32_t price);
    void setPageCount(uint32_t pageCount);
    void setCirculation(uint32_t circulation);

    string& getTitle() const;
    string& getAuthorFirstName() const;
    string& getAuthorLastName() const;
    uint32_t getPrice() const;
    uint32_t getPageCount() const;
    uint32_t getCirculation() const;

    friend std::ostream& operator<<(std::ostream& out, const Book& v);
    friend std::istream& operator>>(std::istream& in, Book& v);


};

#endif // BOOK_H
