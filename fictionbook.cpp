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

void FictionBook::setType(FictionBookType type)
{
    _type = type;
}
void FictionBook::setSoldCopies(uint32_t soldCopies)
{
    _soldCopies = soldCopies;
}

ostream& operator<<(ostream& out, const FictionBook& b)
{
    string fictionBookTypeStr;
    switch (b._type) {
        case NOVEL:
            fictionBookTypeStr = "novel";
        break;

        case STORY:
            fictionBookTypeStr = "story";
        break;

        case POEM:
            fictionBookTypeStr = "poem";
        break;
    }
    out << fictionBookTypeStr << ' ' << b._soldCopies << b._title << ' ' << b._authorFirstName << ' ' << b._authorLastName << ' ' << b._price << ' ' << b._pageCount << b._circulation;
    return out;
}
istream& operator>>(istream& in, FictionBook& b)
{
    string fictionBookTypeStr;
    in >> fictionBookTypeStr;
    FictionBookType fictionBookType;
    if (fictionBookTypeStr == "novel")
    {
        fictionBookType = FictionBookType::NOVEL;
    }
    else if(fictionBookTypeStr == "story")
    {
        fictionBookType = FictionBookType::STORY;
    }
    else if(fictionBookTypeStr == "poem")
    {
        fictionBookType = FictionBookType::POEM;
    }
    b._type = fictionBookType;

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
float FictionBook::popularity() const
{
    return (_soldCopies / _circulation) / (_soldCopies * 1000);
}
float FictionBook::expensive() const
{
    return _price / _pageCount;
}
