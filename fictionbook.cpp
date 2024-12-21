#include "fictionbook.h"
FictionBook::FictionBook(FictionBookType type,
                         uint32_t soldCopies,
                         const string& title,
                         const string& authorFirstName,
                         const string& authorLastName,
                         uint32_t price,
                         uint32_t pageCount,
                         uint32_t circulation)
{
    _type = type;
    _soldCopies = soldCopies;
    _title = title;
    _authorFirstName = authorFirstName;
    _authorLastName = authorLastName;
    _price = price;
    _pageCount = pageCount;
    _circulation = circulation;
}

FictionBook::FictionBook(const string& type,
                         uint32_t soldCopies,
                         const string& title,
                         const string& authorFirstName,
                         const string& authorLastName,
                         uint32_t price,
                         uint32_t pageCount,
                         uint32_t circulation)
{
    setType(type);
    _soldCopies = soldCopies;
    _title = title;
    _authorFirstName = authorFirstName;
    _authorLastName = authorLastName;
    _price = price;
    _pageCount = pageCount;
    _circulation = circulation;
}

void FictionBook::setType(FictionBookType type)
{
    _type = type;
}
void FictionBook::setType(const string& type)
{
    FictionBookType fictionBookType;
    if (type == "classic")
    {
        fictionBookType = FictionBookType::CLASSIC;
    }
    else if(type == "fantasy")
    {
        fictionBookType = FictionBookType::FANTASY;
    }
    else if(type == "science fiction")
    {
        fictionBookType = FictionBookType::SCIENCE_FICTION;
    }
    _type = fictionBookType;
}
void FictionBook::setSoldCopies(uint32_t soldCopies)
{
    _soldCopies = soldCopies;
}

ostream& operator<<(ostream& out, const FictionBook& b)
{
    string fictionBookTypeStr;
    switch (b._type) {
        case CLASSIC:
            fictionBookTypeStr = "classic";
        break;

        case FANTASY:
            fictionBookTypeStr = "fantasy";
        break;

        case SCIENCE_FICTION:
            fictionBookTypeStr = "science fiction";
        break;
    }
    out << fictionBookTypeStr << ' ' << b._soldCopies << ' ' << b._title << ' ' << b._authorFirstName << ' ' << b._authorLastName << ' ' << b._price << ' ' << b._pageCount << b._circulation;
    return out;
}
istream& operator>>(istream& in, FictionBook& b)
{
    string fictionBookTypeStr;
    in >> fictionBookTypeStr;
    b.setType(fictionBookTypeStr);

    in >> b._soldCopies >> b._title >> b._authorFirstName >> b._authorLastName >> b._price >> b._pageCount >> b._circulation;
    return in;
}

uint32_t FictionBook::getSoldCopies() const
{
    return _soldCopies;
}

FictionBookType FictionBook::getType() const
{
    return _type;
}
double FictionBook::popularity() const
{
    return (double(_soldCopies * _soldCopies) / double(1000 * _circulation));
}
float FictionBook::expensive() const
{
    return float(_price) / float(_pageCount);
}
