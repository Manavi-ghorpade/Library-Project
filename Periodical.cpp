#include "Periodical.h"

bool Periodical::compare_other(const string& str) const
{
    if(compare_notes(str))
    {
        return true;
    }
    else if(publishing_history.find(str)!=string::npos||author.find(str)!=string::npos||description.find(str)!=string::npos||publisher.find(str)!=string::npos||series.find(str)!=string::npos||related_titles.find(str)!=string::npos||other_titles.find(str)!=string::npos||gov_doc_number.find(str)!=string::npos){
        return true;
    }
    else{
        return false;
    }
}

void Periodical::display() const
{
    cout<<"=========================="<<endl;
    cout<<"======= PERIODICAL ======="<<endl;
    cout<<"=========================="<<endl;
    cout<<"call_number:          "<<call_number<<endl;
    cout<<"title:                "<<title<<endl;
    cout<<"subjects:             "<<subjects<<endl;
    cout<<"author:               "<<author<<endl;
    cout<<"description:          "<<description<<endl;
    cout<<"publisher:            "<<publisher<<endl;
    cout<<"publishing_history:   "<<publishing_history<<endl;
    cout<<"series:               "<<series<<endl;
    cout<<"notes:                "<<notes<<endl;
    cout<<"related_titles:       "<<right<<related_titles<<endl;
    cout<<"other_forms_of_title: "<<other_titles<<endl;
    cout<<"govt_doc_number:      "<<gov_doc_number<<endl;
}

//constructor
Periodical::Periodical(const string& publishing_history,const string& call_number,const string& title,const string& subjects,const string& notes,
                    const string& author,const string& description,const string& publisher,const string& series,const string& related_titles,
                    const string& other_titles,const string& gov_doc_number):Media(call_number,title,subjects,notes),
                    publishing_history(publishing_history),author(author),description(description),publisher(publisher),
                    series(series),related_titles(related_titles),other_titles(other_titles),gov_doc_number(gov_doc_number)
{
    // cerr<<"periodical constructor"<<endl;
}
