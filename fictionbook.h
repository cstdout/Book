#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H
#include "book.h"

enum FictionBookType
{
    NOVEL = 0,
    STORY,
    POEM
};

class FictionBook : public Book
{
    FictionBookType _type;
    uint32_t _soldCopies;
public:
    FictionBook(FictionBookType type,
                uint32_t soldCopies,
                const string& title,
                const string& authorFirstName,
                const string& authorLastName,
                uint32_t price,
                uint32_t pageCount,
                uint32_t circulation);

    void setType(FictionBookType type);
    void setSoldCopies(uint32_t soldCopies);

    FictionBookType getType() const;
    uint32_t getSoldCopies() const;

    float popularity() const;
    float expensive() const;

    friend ostream& operator<<(ostream&, const FictionBook&);
    friend istream& operator>>(istream&, FictionBook&);
};

#endif // FICTIONBOOK_H
