//
// Created by kusha on 10/23/2019.
//

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#include <string>
#include <cstring>
using namespace std;
class Song {
    private:
        string title;
        string artist;
        int size;
    public:
        Song();
        Song(string _title, string _artist, int _size);
        string getTitle() const;
        string getArtist() const;
        int getSize() const;
        void setTitle(string _title);
        void setArtist(string _artist);
        void setSize(int _size);
        bool operator >(Song const &song);
        bool operator <(Song const &song);
        bool operator ==(Song const &song);

};


#endif //UTPOD_SONG_H
