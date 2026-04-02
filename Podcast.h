#pragma once
#include <iostream>
#include <string>
#include "Audiostream.h"
#include "supportFunctions.h"

using namespace std;

class Podcast : public Audiostream {
    private:
    int episodeNumber;
    string guest;

    public:
    Podcast(string pcTitle, string pcArtist, int pcDuration, 
    int pcEpisodeNumber, string pcGuest) : Audiostream(pcTitle, pcArtist, pcDuration) 
    {
        episodeNumber = pcEpisodeNumber;
        guest = pcGuest;
    }

    void play() const override {
        cout << "Now playing Podcast: " << title << " Ep #" << episodeNumber << " (Host: "
        << artist << ", Guest: " << guest << ")" << endl;
        ab.play();
    }
};