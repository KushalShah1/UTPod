//
// Created by kusha on 10/23/2019.
//

#include "UTPod.h"
#include <iostream>
#include <ctime>

UtPod::UtPod() {
    memSize=MAX_MEMORY;
    songs=nullptr;
    srand(time(0));
}

UtPod::UtPod(int size) {
    if(size>MAX_MEMORY ||size<=0){
        memSize=MAX_MEMORY;
    } else
        memSize=size;
}

int UtPod::addSong(Song const &s) {
    if(getRemainingMemory()>=s.getSize()){
        SongNode *temp;
        temp = new SongNode;
        temp->s=s;
        temp->next=songs;
        songs=temp;
        return SUCCESS;
    }
    else
        return NO_MEMORY;
}
int UtPod::removeSong(Song const &s) {
    SongNode* temp=songs;
    SongNode* previousNode=nullptr;
    while(temp!=nullptr){
        if(temp->s==s){
            previousNode->next=temp->next;
            delete(temp);
            return SUCCESS;
        }
        previousNode=temp;
        temp=temp->next;
    }
    return NO_MEMORY;
}

void UtPod::showSongList() {
    SongNode* temp=songs;
    while(temp!=NULL){
        cout<<temp->s.getTitle()<<", "<<temp->s.getArtist()<<", "<<temp->s.getSize()<<endl;
        temp=temp->next;
    }
}
void UtPod::clearMemory() {
    SongNode* temp=songs;
    SongNode *nextNode=NULL;
    if(temp!=NULL) {
        nextNode = temp->next;
    }

    while(nextNode!=nullptr){
        delete(temp);
        temp=nextNode;
        nextNode=nextNode->next;
    }
    songs=NULL;
}
UtPod::~UtPod() {
    this->clearMemory();
}
int UtPod::getRemainingMemory() {
    int totalMem=0;
    for (SongNode* p= songs; p != NULL; p=p->next){
        totalMem+=p->s.getSize();
    }
    return memSize-totalMem;
}





