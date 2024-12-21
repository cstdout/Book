#include <iostream>
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <sstream>
#include "fictionbook.h"
using namespace std;

int main()
{
    srand(time(0));

    map<string, vector<string>> books;

    books["classic"] = {
            "Pride and Prejudice;Jane;Austen",
            "1984;George;Orwell",
            "Moby-Dick;Herman;Melville",
            "To Kill a Mockingbird;Harper;Lee",
            "Wuthering Heights;Emily;Brontë",
            "Frankenstein;Mary;Shelley"
    };
    books["fantasy"] = {
            "The Name of the Wind;Patrick;Rothfuss",
            "Mistborn: The Final Empire;Brandon;Sanderson",
            "The Lies of Locke Lamora;Scott;Lynch",
            "The Priory of the Orange Tree;Samantha;Shannon"
    };
    books["science fiction"] = {
            "Dune;Frank;Herbert",
            "Neuromancer;William;Gibson"
            "The Martian;Andy;Weir"
            "Foundation;Isaac;Asimov"
            "Snow Crash;Neal;Stephenson"
    };




    string keys[] = {"classic", "fantasy", "science fiction"};
    vector<FictionBook> fictionBooks;
    string book, type, s;
    vector<string> booksByGenre;
    vector<string> bookInfo;
    stringstream bookRawInfo;
    for(int i = 0; i < 100; ++i)
    {
        type = keys[rand() % 3];
        booksByGenre = books[type];
        bookRawInfo.str(booksByGenre[rand() % booksByGenre.size()]);
        while(getline(bookRawInfo, s, ';'))
        {
            bookInfo.push_back(s);
        }

        fictionBooks.push_back(FictionBook(type,
                                           rand() % 100000000,
                                           bookInfo[0],
                                           bookInfo[1],
                                           bookInfo[2],
                                           rand() % 200,
                                           rand() % 1000,
                                           rand() % 10000));
        bookInfo.clear();
    }

    cout << "Enter a number:" << endl;
    double n;
    cin >> n;

    for(int i = 0; i < fictionBooks.size(); ++i)
    {
        if(fictionBooks[i].popularity() > n)
        {
            cout << fictionBooks[i] << endl;
        }
    }

    return 0;
}
