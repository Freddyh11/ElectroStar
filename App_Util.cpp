#include "App_Util.h"

unordered_map<string, Song> app_songlist{}; // Global list of songs (see Song.h)
unordered_map<string, Playlist> app_playlists{}; // Global list of playlists (see Playlist.h)
Playlist *selected_playlist{}; // Pointer to the selected playlist (see selectPlaylistc function below)

// Used to get strings from on-screen linetext boxes
string getLinetextString(QLineEdit* linetext) {
    string str{linetext->text().toStdString()};
    return str;
}

// Used to get strings from on-screen linetext boxes
vector<string> getLinetextStrings(QLineEdit* linetext) {
    string str{linetext->text().toStdString()};
    std::istringstream iss(str);
    string buffer{};
    vector<string> strings{};
    while (iss >> buffer)
        strings.push_back(buffer);

    return strings;
}


// All below functions directly interact with back-end, self-explanatory
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

void playMusic(QPlainTextEdit* screen_text) {
    string str{};
    if (selected_playlist == nullptr) {
        str.append("No playlist selected, playing all music\n");
        for (auto song : app_songlist) {
            song.second.getPrint(str);
        }
    } else {
        str.append("Playing selected playlist\n");
        selected_playlist->getPrint(str);
    }

    screen_text->setPlainText(QString::fromStdString(str));
}


void showHelp() {

}
