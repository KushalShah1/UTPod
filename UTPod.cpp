//
// Created by kusha on 10/23/2019.
//

#include "UTPod.h"


UtPod::UtPod() {
    memSize=MAX_MEMORY;
}

UtPod::UtPod(int size) {
    if(size>MAX_MEMORY ||size<=0){
        memSize=MAX_MEMORY;
    } else
        memSize=size;
}

int UtPod::addSong(Song const &s) {
    if(getRemainingMemory()>=s.getSize()){
        SongNode* temp= new SongNode;
        temp->s=s;
        temp->next=songs;
        songs=temp;
    }
    else
        return NO_MEMORY;
}
int UtPod::removeSong(Song const &s) {
    
}