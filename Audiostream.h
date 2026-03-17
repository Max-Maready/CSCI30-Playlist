#include <iostream>
#include <string>

#pragma once

using namespace std;

class Audiostream {
    protected:
    string title;
    string artist;
    int duration;
    static int currentAudio;

    public:
    Audiostream(string audiotitle, string artistName, int audioDuration) {
        title = audiotitle;
        artist = artistName;
        duration = audioDuration;
    }

    virtual ~Audiostream() {}

    void print() {
        cout << ":The stream " << title << " is " << duration << " seconds, performed by " << artist << "." << endl;
        //currentAudio++;
    }

    virtual void play() const = 0;

};