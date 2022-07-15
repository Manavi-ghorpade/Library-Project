#include "Film.h"

bool Film::compare_other(const string& str) const
{
    if(compare_notes(str)){ 
        return true;
    }
    else if(director.find(str)!= string::npos||year.find(str)!= string::npos){
        return true;
    }
    else{
        return false;
    }
}

void Film::display() const
{
    cout<<"=========================="<<endl;
    cout<<"========== FILM =========="<<endl;
    cout<<"=========================="<<endl;
    cout<<"call_number:          "<<call_number<<endl;
    cout<<"title:                "<<title<<endl;
    cout<<"subjects:             "<<subjects<<endl;
    cout<<"director:             "<<director<<endl;
    cout<<"notes:                "<<notes<<endl;
    cout<<"year:                 "<<year<<endl;
}

Film::Film(const string& director,const string& year,const string& call_number,const string& title,const string& subjects,const string& notes)
    :Media(call_number,title,subjects,notes),director(director),year(year)
{
    // cerr<<"Film constructor"<<endl;
}