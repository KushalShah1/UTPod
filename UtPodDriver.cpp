//
/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Song.h"
#include "UTPod.h"

using namespace std;

int main(int argc, char *argv[]){

    string temp;
    ifstream inputFile("C:\\Users\\kusha\\Desktop\\312\\UTPod\\testEntries");
    UtPod music= UtPod(512);

    if(inputFile.is_open()){
        Song song;
        while(inputFile>>temp){
            song.setTitle(temp);
            inputFile>>temp;
            song.setArtist(temp);
            inputFile>>temp;
            song.setSize(stoi(temp));

            cout<<song.getTitle()<<" Success- "<<music.addSong(song)<<endl;
            cout<<"Remaining Memory- "<<music.getRemainingMemory()<<endl;
        }
        cout<<
        music.showSongList();
    }




}