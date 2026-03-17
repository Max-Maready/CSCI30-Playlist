#include <iostream>
#include <string>
#include "Audiostream.h"

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
        cout << "Now playing Podcast: " << title << " Episode #" << episodeNumber << ", featuring "
        << guest << "." << endl;
    }
};