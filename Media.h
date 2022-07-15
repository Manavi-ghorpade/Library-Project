#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#include<iostream>
#include<iomanip>
using namespace std;

//abstract base class because it contains pure virtual function
class Media
{
    protected:
        string call_number;
        string title;
        string subjects;
        string notes;
    public:
        Media(const string& call_number,const string& title,const string& subjects,const string& notes);
        bool compare_call_number(const string& call_number) const;
        bool compare_title(const string& title) const;
        bool compare_subjects(const string& subjects) const;
        bool compare_notes(const string& notes) const;
        virtual bool compare_other(const string& str) const=0;  //pure virtual function
        virtual void display() const=0;
        virtual ~Media();  //for virtual functions
};
#endif