#include <iostream>
#include <string>
#include "AudioBuffer.h"
#include "supportFunctions.h"

#pragma once

using namespace std;

class Audiostream {
    protected:
    string title;
    string artist;
    int duration;
    AudioBuffer ab;


    public:
    Audiostream(string audiotitle, string artistName, int audioDuration) : ab(audioDuration, audiotitle) {
        title = audiotitle;
        artist = artistName;
        duration = audioDuration;
    }

    virtual ~Audiostream() {}

    void print() {
        cout << ":The stream " << title << " is " << duration << " seconds, performed by " << artist << "." << endl;
    }

    virtual void play() const = 0;

};