#include "SearchEngine.h"

int main()
{
  SearchEngine SearchEngine_object;
  string patron_selection,patrons_string;
  while(1)
  {
    cout<<"1) call_number"<<endl;
    cout<<"2) title"<<endl;
    cout<<"3) subject"<<endl;
    cout<<"4) other"<<endl;
    cout<<"5) exit"<<endl;
    getline(cin,patron_selection);    //take input
    // cout<<patron_selection<<endl;
    if(patron_selection=="5")
    {
      // cout<<"exiting"<<endl;
      break;
    }
    else if(patron_selection=="1")  //call_number
    {
      cout<<"Enter keyphrase: "<<endl;
      getline(cin,patrons_string);
      // cout<<patrons_string<<endl;
      vector<Media*> m;
      m=SearchEngine_object.call_number_search(patrons_string);
      for(int i=0;i<m.size();i++)
      {
        Media* mp=m.at(i);
        mp->display();
      }
    }
    else if(patron_selection=="2") //title
    {
      cout<<"Enter keyphrase: "<<endl;
      getline(cin,patrons_string);
      vector<Media*> m;
      m=SearchEngine_object.title_search(patrons_string);
      for(int i=0;i<m.size();i++)
      {
        Media* mp=m.at(i);
        mp->display();
      }
    }
    else if(patron_selection=="3") //subject
    {
      cout<<"Enter keyphrase: "<<endl;
      getline(cin,patrons_string);
      vector<Media*> m;
      m=SearchEngine_object.subjects_search(patrons_string);
      for(int i=0;i<m.size();i++)
      {
        Media* mp=m.at(i);
        mp->display();
      }
    }
    else if(patron_selection=="4") //other
    {
      cout<<"Enter keyphrase: "<<endl;
      getline(cin,patrons_string);
      vector<Media*> m;
      m=SearchEngine_object.other_search(patrons_string);
      for(int i=0;i<m.size();i++)
      {
        Media* mp=m.at(i);
        mp->display();
      }
    }
    else  //if other number than 1-5 then break
    {
      cout<<"bye";
      break;
    }
  }
  return 0;
}
