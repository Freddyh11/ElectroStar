#pragma once

#include "Playlist.h"
#include "Song.h"

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <QLineEdit>
#include <QPlainTextEdit>

using std::cin;
using std::cout;
using std::string;
using std::unordered_map;
using std::vector;

/// App_Util.h
/// ----------
/// Contains all global data, as well as core functions


// Global data

extern unordered_map<string, Song> app_songlist; // Global list of songs (see Song.h)
extern unordered_map<string, Playlist> app_playlists; // Global list of playlists (see Playlist.h)

extern Playlist *selected_playlist; // Pointer to the selected playlist (see selectPlaylistc function below)

// Core Functions

// Used to get strings from on-screen linetext boxes
string getLinetextString(QLineEdit* linetext);

// Used to get strings from on-screen linetext boxes
vector<string> getLinetextStrings(QLineEdit* linetext);


// All below functions directly interact with back-end, self-explanatory
void songImport(string name, vector<string> tags={}, int weight={});

void songDelete(string name);

void addTag(string name, string tag);

void removeTag(string name, string tag);

void createPlaylist(string name, vector<Song> songs);

void selectPlaylist(string name);

void deletePlaylist(string name);

Song lookupSong(string name);

void playMusic(QPlainTextEdit* screen_text);

void showHelp();
