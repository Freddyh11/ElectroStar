#include <iostream>
#include <string>
#include <map>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <random>
using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::vector;
using std::string;
using std::default_random_engine;

struct tagInfo {
    string name;
    string disp;
    int id;
    int color;
    void setDisp(string input) {
        name = input;
        char temp[6];
        for (int i = 0; i < sizeof(input) && i < 4; i++) {
            temp[i] = input[i];
        }
        temp[5] = '\0';
        disp = temp;
    }
    void setID(int num) {
        id = num;
    }
    void setColor() {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        int temp;
        cout << "Colors:\n"
             << "Text color 0\n";
        for (int i = 1; i < 16; i++) {
            SetConsoleTextAttribute(h, i);
            cout << "Text color " << i << endl;
        }
        SetConsoleTextAttribute(h, 7);
        do {
            cout << "Enter color number: ";
            cin >> temp;
        } while (temp < 0 || temp > 15);
        if (temp == 0)
            temp = 7;
        color = temp;
        cout << endl;
    }
    void init(string name, int num) {
        setDisp(name);
        setID(num);
        setColor();
    }
};

class Tags {
private:
    map<string, tagInfo> tags;

    int tCount = 0;
public:
    map<string, tagInfo> SendTags() {
        return tags;
    }
    void AddTags(string input) {
        if (tags.find(input) == tags.end()) {
            tagInfo info;
            info.init(input, tCount);
            tags[input] = info;
            tCount++;
        }
        else
            cout << "Cannot duplicate tags!\n";
    }
    void RemoveTags(string input) {
        if (tags.find(input) != tags.end()) {
            tags.erase(input);
        }
        else
            cout << "Tag not found!\n";
    }
};

Tags tagslist;

void PrintTags(map<string, tagInfo> tags) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 7);
    map<string, tagInfo>::iterator it = tags.begin();
    int num = 1;
    cout << "Tags:\n";
    while (it != tags.end()) {
        SetConsoleTextAttribute(h, it->second.color);
        cout << "[" << num << "]: " << it->first << endl;
        it++;
        num++;
    }
    SetConsoleTextAttribute(h, 7);
    cout << endl;
}

struct songInfo {
    string name;
    map<string, tagInfo> tags;
    int heat = 1;
    int getColor() {
        map<string, tagInfo>::iterator it = tags.begin();
        map<int, int> colors;
        int color;
        while (it != tags.end()) {
            color = it->second.color;
            if (colors.find(color) != colors.end()) {
                colors.find(color)->second++;
            }
            else
                colors[color] = 1;
            it++;
        }
        map<int, int>::iterator itc = colors.begin();
        int selected[2]{ 0, 0 };
        while (itc != colors.end()) {
            if (itc->second > selected[1]) {
                selected[0] = itc->first;
                selected[1] = itc->second;
            }
            itc++;
        }
        if (selected[0] > 0)
            return selected[0];
        else
            return 7;
    }
    void TagsA(string input) {
        cout << "Adding tag\n";
        map<string, tagInfo> templist = tagslist.SendTags();
        if (templist.find(input) != templist.end()) {
            cout << "Tag found\n";
            tags[input] = tagslist.SendTags().find(input)->second;
        }
        else {
            cout << "Tag not found, please add tag:\n";
            tagslist.AddTags(input);
            tags[input] = tagslist.SendTags().find(input)->second;
        }
    }
    void TagsR(string name) {
        if (tags.find(name) != tags.end()) {
            tags.erase(name);
        }
        else
            cout << "Tag not found!\n";
    }

    void HeatS(int h) {
        heat = h;
    }

    void init(string n) {
        name = n;
        string input;
        cout << "Existing tags:\n";
        PrintTags(tagslist.SendTags());
        cout << "Enter tags to add to song\nEnter \"exit\" to exit : \n";
        do {
            cout << "Enter tag [" << tags.size() + 1 << "]: ";
            cin >> input;
            if (input != "exit")
                TagsA(input);
        } while (input != "exit");
    }
};

void PrintSongs(map<string, songInfo> songlist) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 7);
    map<string, songInfo>::iterator it = songlist.begin();
    int num = 1;
    cout << "Songs:\n";
    while (it != songlist.end()) {
        SetConsoleTextAttribute(h, it->second.getColor());
        cout << "[" << num << "]: " << it->first << endl;
        PrintTags(it->second.tags);
        it++;
        num++;
    }
    SetConsoleTextAttribute(h, 7);
    cout << endl;
}

class Songs {
private:
    map<string, songInfo> songs;
public:
    map<string, songInfo> SendSongs() {
        return songs;
    }
    void AddSong(string input) {
        if (songs.find(input) == songs.end()) {
            songInfo song;
            song.init(input);
            songs[input] = song;
        }
        else
            cout << "Cannot duplicate songs!\n";
    }
    void RemoveSong(string input) {
        if (songs.find(input) != songs.end()) {
            songs.erase(input);
        }
        else
            cout << "Song not found!\n";
    }
};

Songs songlist;

struct playInfo {
    string name;
    map<string, songInfo> songs;

    int getColor() {
        map<string, songInfo>::iterator it = songs.begin();
        map<int, int> colors;
        int color;
        while (it != songs.end()) {
            color = it->second.getColor();
            if (colors.find(color) != colors.end()) {
                colors.find(color)->second++;
            }
            else
                colors[color] = 1;
            it++;
        }
        map<int, int>::iterator itc = colors.begin();
        int selected[2]{ 0, 0 };
        while (itc != colors.end()) {
            if (itc->second > selected[1]) {
                selected[0] = itc->first;
                selected[1] = itc->second;
            }
            itc++;
        }
        if (selected[0] > 0)
            return selected[0];
        else
            return 7;
    }
    void SongListA(songInfo song) {
        songs[song.name] = song;
    }
    void SongListR(songInfo song) {
        songs.erase(song.name);
    }

    void init(string n) {
        name = n;
        string input;
        map<string, songInfo> tempSongs = songlist.SendSongs();
        cout << "Existing songs:\n";
        PrintSongs(tempSongs);
        cout << "Enter songs to add to playlist\nEnter \"exit\" to exit : \n";
        do {
            cout << "Enter song [" << songs.size() + 1 << "]: ";
            cin >> input;
            if (input != "exit") {
                if (tempSongs.find(input) != tempSongs.end())
                    SongListA(tempSongs.find(input)->second);
                else
                    cout << "Song not found!\n";
            }
        } while (input != "exit");
    }
};

void PrintPlay(map<string, playInfo> playlists) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 7);
    map<string, playInfo>::iterator it = playlists.begin();
    int num = 1;
    cout << "Playlists:\n";
    while (it != playlists.end()) {
        SetConsoleTextAttribute(h, it->second.getColor());
        cout << "[" << num << "]: " << it->first << endl;
        PrintSongs(it->second.songs);
        it++;
        num++;
    }
    SetConsoleTextAttribute(h, 7);
    cout << endl;
}

class Playlists {
private:
    string name;
    map<string, playInfo> playlists;
public:
    map<string, playInfo> SendPlay() {
        return playlists;
    }
    void AddPlay(string input) {
        if (playlists.find(input) == playlists.end()) {
            playInfo play;
            play.init(input);
            playlists[input] = play;
        }
        else
            cout << "Cannot duplicate playlists!\n";
    }
    void RemovePlay(string input) {
        if (playlists.find(input) != playlists.end()) {
            playlists.erase(input);
        }
        else
            cout << "Song not found!\n";
    }
};

Playlists playlists;
vector<string> selection;

void PlaySongs() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 7);
    int i = 1;
    for (int i = 0; i < selection.size(); i++) {
        SetConsoleTextAttribute(h, songlist.SendSongs().at(selection[i]).getColor());
        cout << "[Song " << i << "]: " << selection[i] << endl;
        PrintTags(songlist.SendSongs().at(selection[i]).tags);
        cout << "\n\n";
    }
    SetConsoleTextAttribute(h, 7);
}

void Shuffle() {
    map<string, songInfo> songs;
    for (int i = 0; i < selection.size(); i++) {
        if (songs.find(selection[i]) == songs.end())
            songs[selection[i]] = songlist.SendSongs().find(selection[i])->second;
    }
    selection.clear();
    map<string, songInfo>::iterator it = songs.begin();
    int counter = 1;
    for (int i = 0; i < songs.size(); i++) {
        selection.push_back(it->first);
        if (it->second.heat - counter == 0) {
            counter = 1;
            it++;
        }
        else
            counter++;
    }
    auto rng = default_random_engine{};
    shuffle(begin(selection), end(selection), rng);
    PlaySongs();
}

void Search(vector<string> search, string input) {
    cout << "Searching " << input << ":\n";
    if (selection.size() == 0)
        return;
    map<string, songInfo> results;
    map<string, songInfo> song = songlist.SendSongs();
    for (int i = 0; i < selection.size(); i++) {
        if (song.find(selection[i]) != song.end())
            results[song.find(selection[i])->first] = song.find(selection[i])->second;
    }
    map<string, songInfo>::iterator it = results.begin();
    if (input == "word") {
        while (it != results.end()) {
            bool del = true;
            for (int i = 0; i < search.size(); i++) {
                cout << search[i] << endl;
                if (it->first.find(search[i]) != string::npos)
                    del = false;
            }
            string key = it->first;
            it++;
            if (del == true)
                results.erase(key);
        }
    }
    else if (input == "all") {
        while (it != results.end()) {
            bool del = false;
            for (int i = 0; i < selection.size(); i++) {
                cout << search[i] << endl;
                if (it->second.tags.find(search[i]) == it->second.tags.end())
                    del = true;
            }
            string key = it->first;
            it++;
            if (del == true)
                results.erase(key);
        }
    }
    else if (input == "none") {
        while (it != results.end()) {
            bool del = false;
            for (int i = 0; i < search.size(); i++) {
                cout << search[i] << endl;
                if (it->second.tags.find(search[i]) != it->second.tags.end())
                    del = true;
            }
            string key = it->first;
            it++;
            if (del == true)
                results.erase(key);
        }
    }
    else if (input == "one") {
        while (it != results.end()) {
            bool del = true;
            for (int i = 0; i < search.size(); i++) {
                cout << search[i] << endl;
                if (it->second.tags.find(search[i]) != it->second.tags.end())
                    del = false;
            }
            string key = it->first;
            it++;
            if (del == true)
                results.erase(key);
        }
    }
    selection.clear();
    it = results.begin();
    while (it != results.end()) {
        selection.push_back(it->first);
        it++;
    }
}

void LibrarySearch(string input) {
    selection.clear();
    map<string, songInfo> song = songlist.SendSongs();
    map<string, songInfo>::iterator it = song.begin();
    while (it != song.end()) {
        selection.push_back(it->first);
    }
    vector<string> search;
    int pos = 0;
    int len = 0;
    search.push_back(input);
    /*for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            search.push_back(input.substr(pos, len));
            pos = i + 1;
            len = 0;
        }
        else {
            len++;
        }
    }*/
    vector<string> Word;
    vector<string> All;
    vector<string> None;
    vector<string> One;
    for (int i = 0; i < search.size(); i++) {
        switch (search[i][0]) {
        case '+': All.push_back(search[i].substr(1, search[i].length()));
            break;
        case '-': None.push_back(search[i].substr(1, search[i].length()));
            break;
        case '\\': One.push_back(search[i].substr(1, search[i].length()));
            break;
        default: Word.push_back(search[i]);
            break;
        }
    }
    it = song.begin();
    selection.clear();
    while (it != song.end()) {
        selection.push_back(it->first);
        it++;
    }
    if (Word.size() > 0)
        Search(Word, "word");
    if (All.size() > 0)
        Search(All, "all");
    if (None.size() > 0)
        Search(None, "none");
    if (One.size() > 0)
        Search(One, "one");
}

void TagsMenu() {
    int choice;
    string input;
    do {
        cout << "Tags Menu:\n1: Add Tags\n2: Remove Tags\n3: Print Tags\n0: Exit\n\nChoice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 0:
            break;
        case 1:
            cout << "Add Tag: ";
            cin >> input;
            tagslist.AddTags(input);
            break;
        case 2:
            cout << "Delete Tag: ";
            cin >> input;
            tagslist.RemoveTags(input);
            break;
        case 3:
            PrintTags(tagslist.SendTags());
            break;
        default:
            break;
        }
    } while (choice != 0);
}

void SongsMenu() {
    int choice;
    string input;
    do {
        cout << "Songs Menu:\n1: Add Songs\n2: Remove Songs\n3: Print Songs\n0: Exit\n\nChoice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 0:
            break;
        case 1:
            cout << "Add Song: ";
            cin >> input;
            songlist.AddSong(input);
            break;
        case 2:
            cout << "Remove Song: ";
            cin >> input;
            songlist.RemoveSong(input);
            break;
        case 3:
            PrintSongs(songlist.SendSongs());
            break;
        default:
            break;
        }
    } while (choice != 0);

}

void PlaylistsMenu() {
    int choice;
    string input;
    do {
        cout << "Playlists Menu:\n1: Add Playlist\n2: Remove Playlist\n3: Print Playlists\n0: Exit\n\nChoice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 0:
            break;
        case 1:
            cout << "Add Song: ";
            cin >> input;
            playlists.AddPlay(input);
            break;
        case 2:
            cout << "Remove Song: ";
            cin >> input;
            playlists.RemovePlay(input);
            break;
        case 3:
            PrintPlay(playlists.SendPlay());
            break;
        default:
            break;
        }
    } while (choice != 0);
}

void SelectionMenu() {
    if (!selection.empty())
        selection.clear();
    cout << "test\n";
    map<string, songInfo> song = songlist.SendSongs();
    map<string, songInfo>::iterator it = song.begin();
    while (it != song.end()) {
        selection.push_back(it->first);
        it++;
    }
    int choice;
    string input;
    do {
        cout << "Selection Menu:\n1: Play Songs\n2: Shuffle Songs\n3: Search Songs\n0: Exit\n\nChoice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 0:
            break;
        case 1:
            cout << "Play Songs:\n";
            PlaySongs();
            break;
        case 2:
            cout << "Shuffle Songs:\n";
            Shuffle();
            break;
        case 3:
            cout << "Search Songs:\nEnter search terms: ";
            cin >> input;
            LibrarySearch(input);
            break;
        default:
            break;
        }
    } while (choice != 0);
}

int main()
{
    int choice;
    do {
        cout << "Main Menu:\n1: Tags\n2: Songs\n3: Playlists\n4: Selection\n0: Exit\n\nChoice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 0:
            break;
        case 1:
            TagsMenu();
            break;
        case 2:
            SongsMenu();
            break;
        case 3:
            PlaylistsMenu();
            break;
        case 4:
            SelectionMenu();
            break;
        default:
            break;
        }
    } while (choice != 0);
    return 0;
}
