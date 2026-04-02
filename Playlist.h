#pragma once
#include <iostream>
#include <string>
#include "Audiostream.h"
#include "Song.h"
#include "Podcast.h"


using namespace std;

class Playlist 
{
    private:
    int m_count;

    public:
    Audiostream *m_list[100];

    Playlist() {
        m_count = 0;

        for(int i = 0; i < 100; i++) {
            m_list[i] = nullptr;
        }
    }

    //forgot to add a destructor when i checked back on previous labs
    ~Playlist() {
        for (int i = 0; i < m_count; i++) {
            delete m_list[i];
        }
    }

    void addStream(Audiostream* s) {
        m_list[m_count] = s;
        m_count++;
    }

    void playAll() {
        cout << "\n--- Playing Your Playlist ---" << endl;

        for(int i = 0; i < m_count; i++) {
             m_list[i]->play();
        }
    }

    void showPlaylist() {
        cout << "\n--- Listing Your Playlist ---" << endl;

        for(int i = 0; i < m_count; i++) {
            cout << i;
             m_list[i]->print();
        }
    }

    void swapSongs(int index1, int index2) {
        try {
            if(m_count < 2) {
                throw logic_error("Playlist must contain at least 2 items.");
            }
            else if((index1 > m_count || index1 < 0) || (index2  > m_count || index2 < 0)) {
                throw range_error("Invalid swap values " + to_string(index1) + ", " + to_string(index2));
            }

            Audiostream* temp;
            temp = m_list[index1];
            m_list[index1] = m_list[index2];
            m_list[index2] = temp;
        }
        catch (const range_error& re) {
            cout << "RANGE ERROR: " << re.what();
            exit(1);
        }
        catch(const logic_error& le) {
            cout << "LOGIC ERROR: " << le.what();
            exit(1);
        }
    }
    
    void addSong(string title, string host, int duration, string album) {

        Song* newSong = nullptr;
        cout << "Adding Song: " << title << "..." <<  endl;

        try{
            Song* newSong = new Song(title, host, duration, album);
            addStream(newSong);
        }
        catch(const runtime_error &re) {
            cout << "  [Playlist]: Failed to add " << title << " -> " << re.what() << endl;
            delete newSong;
        }
    }

    void addPodcast(string title, string host, int duration, int episode, string guest) {

        Podcast* newPodcast  = nullptr;
        cout << "Adding Podcast: " << title << "..." <<  endl;
        
        try{
            Podcast* newPodcast  = new Podcast(title, host, duration, episode, guest);
            addStream(newPodcast);
        }
        catch(const runtime_error &re) {
            cout << " [Playlist]: Failed to add " << title << " -> " << re.what() << endl;
            delete newPodcast;
        } 
    }
};

 