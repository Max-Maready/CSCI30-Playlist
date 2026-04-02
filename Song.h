#pragma once
#include <iostream>
#include <string>
#include "Audiostream.h"
#include "supportFunctions.h"

using namespace std;

class Song : public Audiostream {
    private:
    string albumName;

    public:
    Song(string songTitle, string artistName, int songDuration, string album) : Audiostream(songTitle, artistName, songDuration)
    {
        albumName = album;
    }

    void play() const override {
        cout << "Now playing Song: " << title << " by " <<
        artist << " [Album: " << albumName << "]" << endl;
        ab.play();
    }
};