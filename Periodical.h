#ifndef PERIODICAL_H
#define PERIODICAL_H
#include "Media.h"
class Periodical:public Media{
    private:
        string author;
        string description;
        string publisher;
        string publishing_history;
        string series;
        string related_titles;
        string other_titles;
        string gov_doc_number;
    public:
        bool compare_other(const string& str) const;
        void display() const;
        Periodical(const string& publishing_history,const string& call_number,const string& title,const string& subjects,const string& notes,
                    const string& author,const string& description,const string& publisher,const string& series,const string& related_titles,
                    const string& other_titles,const string& gov_doc_number);
};
#endif