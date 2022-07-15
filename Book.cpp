#include "Book.h"

bool Book::compare_other(const string& str) const
{
    if(compare_notes(str)){ //check notes
        return true;
    }
    else if(city.find(str)!= string::npos||author.find(str)!= string::npos||description.find(str)!= string::npos||publisher.find(str)!= string::npos||year.find(str)!= string::npos||series.find(str)!= string::npos){
        return true;
    }
    else{
        return false;
    }
}

void Book:: display() const
{
    cout<<"=========================="<<endl;
    cout<<"========== BOOK =========="<<endl;
    cout<<"=========================="<<endl;
    cout<<"call_number:          "<<call_number<<endl;
    cout<<"title:                "<<title<<endl;
    cout<<"subjects:             "<<subjects<<endl;
    cout<<"author:               "<<author<<endl;
    cout<<"description:          "<<description<<endl;
    cout<<"publisher:            "<<publisher<<endl;
    cout<<"city:                 "<<city<<endl;
    cout<<"year:                 "<<year<<endl;
    cout<<"series:               "<<series<<endl;
    cout<<"notes:                "<<notes<<endl;
}

//constructor
Book::Book(const string& city,const string& author,const string& description,
            const string& publisher,const string& year,const string& series,const string& call_number,
            const string& title,const string& subjects,const string& notes):Media(call_number,title,subjects,notes),city(city),author(author)
            ,description(description),publisher(publisher),year(year),series(series)
{
    //cerr<<"book constructor"<<endl;
}
