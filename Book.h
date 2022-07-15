#ifndef BOOK_H
#define BOOK_H
#include "Media.h"

class Book:public Media{
    private:
        string city;
        string author;
        string description;
        string publisher;
        string year;
        string series;
    public:
        bool compare_other(const string& str) const;
        void display() const;
        Book(const string& city,const string& author,const string& description,
             const string& publisher,const string& year,const string& series,
             const string& call_number,const string& title,const string& subjects,const string& notes);
};
#endif