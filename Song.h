#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <QPlainTextEdit>

using std::string;
using std::vector;

// Not concerned with actually making audio functionality in this demo,
// so just typedef-ing a bool-- true if audio file exists, false if not.
// Client-side song initializations will always make it true.
typedef bool audio;

class Song {
private:
    string m_title{};
    vector<string> m_tags{};
    audio m_audiofile{};
    int m_weight{};

public:
    Song() = default;

    Song(string title, audio audiofile = false, string tag = "", int weight = 0)
        : m_title{title}, m_audiofile{audiofile}, m_weight{weight} {
        if (tag != "")
            m_tags.push_back(tag);
    }

    Song(string title, audio audiofile, vector<string> tags, int weight)
        : m_title{title}, m_tags{tags}, m_audiofile{audiofile}, m_weight{weight} {
    }

    void addTag(string tag) { m_tags.push_back(tag); }

    void removeTag(string tag) {
        auto i{std::find(m_tags.begin(), m_tags.end(), tag)};
        if (i != m_tags.end())
            m_tags.erase(i);
    }

    void setWeight(int x) { m_weight = x; }

    void setAudio(int x) {
        if (x)
            m_audiofile = true;
        else
            m_audiofile = false;
    }

    bool invalid() {
        if (m_title == "")
            return true;

        return false;
    }

    void getPrint(string& str) {
        str.append("-[Title: ");
        str.append(m_title);
        str.append("] [Tags: ");

        for (auto tag : m_tags) {
            str.append(tag);
            if (tag != *(m_tags.end() - 1))
                str.append(", ");
        }
        str.append("]\n");
    }

    friend class Playlist;
};

