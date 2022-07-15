
#include "SearchEngine.h"

SearchEngine::SearchEngine()
{
  string call_number,title,subjects,notes,str;
  //////reading book.txt/////
  ifstream book("book.txt");
  if(!book.is_open()){
    cerr<<"cannot open the file book"<<endl;
  }
  else{
    string author,description,publisher,city,year,series;
    while(getline(book,str))  //get line and store it into the string
    {
      stringstream ss(str);  //for manupulating every line //it allow us to read from the string so that we can stop at "|"" in string
      getline(ss,call_number,'|'); //1 arg= information , 2nd arg= store info, 3rd arg=where to stop
      getline(ss,title,'|');
      getline(ss,subjects,'|');
      getline(ss,author,'|');
      getline(ss,description,'|');
      getline(ss,publisher,'|');
      getline(ss,city,'|');
      getline(ss,year,'|');
      getline(ss,series,'|');
      getline(ss,notes,'|');
      Media* mp=new Book(city,author,description,   //dynamically allocates memory
              publisher,year,series,call_number,
              title,subjects,notes);
      card_catalog.push_back(mp);
    }
    book.close();
  }
  /////reading film.txt/////////////
  ifstream film("film.txt");
  if(!film.is_open()){
    cerr<<"cannot open the file film"<<endl;
  }
  else{
    string director,year;
    while(getline(film,str)) 
    {
      stringstream st(str); 
      getline(st,call_number,'|');
      getline(st,title,'|');
      getline(st,subjects,'|');
      getline(st,director,'|');
      getline(st,notes,'|');
      getline(st,year,'|');
      Media* mp=new Film(director,year,call_number,title,subjects,notes);
      card_catalog.push_back(mp);
    }
    film.close();
  }

  ///reading video file//////////
  ifstream video("video.txt");
  if(!video.is_open()){
    cerr<<"cannot open the file video"<<endl;
  }
  else{
    string description,distributor,series,lable;
    while(getline(video,str))
    {
      stringstream st(str);
      getline(st,call_number,'|');
      getline(st,title,'|');
      getline(st,subjects,'|');
      getline(st,description,'|');
      getline(st,distributor,'|');
      getline(st,notes,'|');
      getline(st,series,'|');
      getline(st,lable,'|');
      Media* mp=new Video(call_number,title, subjects, description, distributor,
          notes, series, lable);
      card_catalog.push_back(mp);
    }
    video.close();
  }

  ///////////reading periodic.txt///////////
  ifstream periodic("periodic.txt");
  if(!periodic.is_open()){
    cerr<<"cannot open the file peroidic"<<endl;
  }
  else{
    string author,description,publisher,publisher_history,related_titles,other_titles,doc_num,series;
    while(getline(periodic,str))
    {
      stringstream ss(str);
      getline(ss,call_number,'|');
      getline(ss,title,'|');
      getline(ss,subjects,'|');
      getline(ss,author,'|');
      getline(ss,description,'|');
      getline(ss,publisher,'|');
      getline(ss,publisher_history,'|');
      getline(ss,series,'|');
      getline(ss,notes,'|');
      getline(ss,related_titles,'|');
      getline(ss,other_titles,'|');
      getline(ss,doc_num,'|');
      Media* mp=new Periodical(publisher_history, call_number, title, subjects, notes,
                      author, description, publisher, series, related_titles,
                      other_titles, doc_num);
      card_catalog.push_back(mp);
    }
    periodic.close();
  }

}

//title search
vector<Media*> SearchEngine::title_search(const string& patron_string) const
{
    vector<Media*> results;
    int size=card_catalog.size();
    //cout<<size;
    for(int i=0;i<size;i++)
    {
        Media* mp=card_catalog.at(i);
        bool it_is_there = mp->compare_title(patron_string);
        if(it_is_there)
        {
            results.push_back(mp);
        }
    }
    return results;
}

//call_number search
vector<Media*> SearchEngine::call_number_search(const string& patron_string) const
{
    vector<Media*> results;
    int size=card_catalog.size();
    for(int i=0;i<size;i++)
    {
        Media* mp=card_catalog.at(i);
        bool it_is_there = mp->compare_call_number(patron_string);
        if(it_is_there)
        {
            results.push_back(mp);
        }
    }
    return results;
}

//subject search
vector<Media*> SearchEngine::subjects_search(const string& patron_string) const
{
    vector<Media*> results;
    int size=card_catalog.size();
    for(int i=0;i<size;i++)
    {
        Media* mp=card_catalog.at(i);
        bool it_is_there = mp->compare_subjects(patron_string);
        if(it_is_there)
        {
            results.push_back(mp);
        }
    }
    return results;
}

//other search
vector<Media*> SearchEngine::other_search(const string& patron_string) const
{
    vector<Media*> results;
    int size=card_catalog.size();
    for(int i=0;i<size;i++)
    {
        Media* mp=card_catalog.at(i);
        bool it_is_there = mp->compare_other(patron_string);
        if(it_is_there)
        {
            results.push_back(mp);
        }
    }
    return results;
}

//destructor
SearchEngine::~SearchEngine()
{
  for(int i=0;i<card_catalog.size();++i)
  {
    delete card_catalog.at(i);  //delete all allocated memory
  }
}
