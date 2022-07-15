#ifndef VIDEO_H
#define VIDEO_H
#include "Media.h"

class Video:public Media{
    private:
        string distributor;
        string description;
        string series;
        string lable;
    public:
        bool compare_other(const string& str) const;
        void display() const;
        Video(string call_number,string title,string subjects,string description,string distributor,
        string notes,string series,string lable);
};
#endif