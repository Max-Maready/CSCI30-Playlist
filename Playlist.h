#include <iostream>
#include <string>
#include "Audiostream.h"


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
        Audiostream* temp;
        temp = m_list[index1];
        m_list[index1] = m_list[index2];
        m_list[index2] = temp;
    }
};