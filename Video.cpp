#include "Video.h"

bool Video::compare_other(const string& str) const
{
    if(compare_notes(str)){
        return true;
    }
    else if(distributor.find(str)!=string::npos||description.find(str)!=string::npos||lable.find(str)!=string::npos||series.find(str)!=string::npos){
        return true;
    }
    else{
        return false;
    }
}

void Video::display() const
{
    cout<<"=========================="<<endl;
    cout<<"========== VIDEO ========="<<endl;
    cout<<"=========================="<<endl;
    cout<<"call_number:          "<<call_number<<endl;
    cout<<"title:                "<<title<<endl;
    cout<<"subjects:             "<<subjects<<endl;
    cout<<"description:          "<<description<<endl;
    cout<<"distributor:          "<<distributor<<endl;
    cout<<"notes:                "<<notes<<endl;
    cout<<"series:               "<<series<<endl;
    cout<<"label:                "<<lable<<endl;

}

Video::Video(string call_number,string title,string subjects,string description,string distributor,
        string notes,string series,string lable):Media(call_number,title,subjects,notes),distributor(distributor),
        description(description),series(series),lable(lable)
{
    // cerr<<"video constructor"<<endl;
}