#pragma once

#include "Song.h"
#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Playlist {
private:
    string m_name;
    vector<Song> m_songlist{};

public:
    Playlist() = default;

    Playlist(string name, Song song = Song()) : m_name(name) {
        if (!song.invalid())
            m_songlist.push_back(song);
    }

    Playlist(string name, vector<Song> songlist)
        : m_name(name), m_songlist(songlist) {}

    void addSong(Song song) { m_songlist.push_back(song); }
    void removeSong(Song song) {
        for (auto i = m_songlist.begin(); i < m_songlist.end(); ++i) {
            if (i->m_title == song.m_title) {
                m_songlist.erase(i);
            }
        }
    }

    void print() {
        std::cout << "Name: " << m_name << "\n\n";

        for (auto song : m_songlist) {
            song.print();
        }
    }
};
