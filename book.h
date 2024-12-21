#ifndef BOOK_H
#define BOOK_H

#include <iostream>
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
    Book();
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

    friend ostream& operator<<(ostream& out, const Book&);
    friend istream& operator>>(istream& in, Book&);


};

#endif // BOOK_H
