#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H
#include<vector>
#include "Media.h"
#include "Video.h"
#include "Book.h"
#include "film.h"
#include "Periodical.h"
#include <sstream>
#include <fstream>

class SearchEngine {
  public:
    SearchEngine();//read in 4 text files and fill up card_catalog
    vector<Media*> title_search(const string&) const;
    vector<Media*> call_number_search(const string&) const;
    vector<Media*> subjects_search(const string&) const;
    vector<Media*> other_search(const string&) const;
    ~SearchEngine();
  private:
    vector<Media*> card_catalog;

};

#endif