#include "Media.h"

Media::Media(const string& c,const string& t,const string& s,const string& n)
    :call_number(c),title(t),subjects(s),notes(n)
{
    // cerr<<"media constructor"<<endl;
}

bool Media::compare_call_number( const string& c) const
{
    
    if(call_number.find(c) != string::npos){  //npos indicates no matches as return value. it indicates large value which is return by find when no matches are found  
        return true;
    }
    else{
        return false;
    }
}

bool Media::compare_title(const string& t) const
{
    if(title.find(t)!= string::npos){
        return true;
    }
    else{
        return false;
    }
}

bool Media::compare_subjects(const string& s) const
{
    if(subjects.find(s)!=string::npos){
        return true;
    }
    else{
        return false;
    }
}

bool Media::compare_notes(const string& str) const
{
    if(notes.find(str)!=string::npos){
         return true;
    }
    else{
        return false;
    }
}

Media::~Media()
{

}