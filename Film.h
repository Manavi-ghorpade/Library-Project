#ifndef FILM_H
#define FILM_H
#include "Media.h"

class Film:public Media{
    private:
        string director;
        string year;
    public:
        bool compare_other(const string& str) const;
        void display() const;
        Film(const string &director,const string& year,const string& call_number,const string& title,const string& subjects,const string& notes);
};
#endif
