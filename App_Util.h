#pragma once

#include "Playlist.h"
#include "Song.h"

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::string;
using std::unordered_map;
using std::vector;

unordered_map<string, Song> app_songlist{};
unordered_map<string, Playlist> app_playlists{};

Playlist *selected_playlist{};

string getString() {
    string str{};
    std::getline(cin, str);
    return str;
}

vector<string> getStrings() {
    string input_string{};
    std::getline(cin, input_string);
    std::istringstream iss(input_string);
    string buffer{};
    vector<string> strings{};
    while (iss >> buffer)
        strings.push_back(buffer);

    return strings;
}

void songImport(string name, vector<string> tags, int weight) {
    Song newsong{name, true, tags, weight};
    app_songlist.insert({name, newsong});
}

void songDelete(string name) { app_songlist.erase(name); }

void addTag(string name, string tag) { app_songlist[name].addTag(tag); }

void removeTag(string name, string tag) { app_songlist[name].removeTag(tag); }

void createPlaylist(string name, vector<Song> songs) {
    if (!songs.empty()) {
        Playlist newplaylist(name, songs);
        app_playlists.insert({name, newplaylist});
    } else {
        Playlist newplaylist(name);
        app_playlists.insert({name, newplaylist});
    }
}

void selectPlaylist(string name) {
    if (name == "")
        selected_playlist = nullptr;
    else if (!(app_playlists.find(name) == app_playlists.end()))
        selected_playlist = &app_playlists[name];
}

void deletePlaylist(string name) {
    if (selected_playlist == &app_playlists[name])
        selected_playlist = nullptr;

    app_playlists.erase(name);
}

Song lookupSong(string name) {
    for (auto song : app_songlist) {
        if (name == song.first)
            return song.second;
    }

    return Song();
}

void playMusic() {
    if (selected_playlist == nullptr) {
        std::cout << "\nNo playlist selected, playing all "
                     "music\n---------------------------------------\n\n";
        for (auto song : app_songlist) {
            song.second.print();
        }
    } else {
        std::cout << "\nPlaying selected playlist\n-------------------------\n";
        selected_playlist->print();
    }

    std::cout << std::endl;
}
