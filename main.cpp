#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

struct Card {
    string uuid;
    string name;
    string colors;
    string manaCost;
    float manaValue;
    string rarity;
    int power;
    int toughness;
    string type;
    string types;
    string artistIds;
};

struct Artist {
    string uuid;
    string name;
};

struct Colection {
    string uuid;
    int cant;
};

void loadCards(vector<Card> &cards);
void loadArtists(vector<Artist> &artists);
char menu();
void SearchCard();
string SearchCardByName(string name);
void SearchArtist();
string SearchArtistByName(string name);

int main() {
    vector<Card> cards;
    vector<Artist> artists;
    vector<Colection> collection;
    char op;

    //loadCards(cards);
    loadArtists(artists);

    op = menu();
    while (op != '0') {
        if (op == '1') {
            SearchCard();
        } else if (op == '2') {
            SearchArtist();
        }
        op = menu();
    }

    return 0;
}

void loadCards(vector<Card> &cards) {
    Card c;

    cards.clear();

    ifstream file("cards.txt");

    while (file >> c.uuid >> c.name >> c.colors >> c.manaCost >> c.manaValue >> c.rarity >> c.power >> c.toughness >> c.type >> c.types >> c.artistIds) {
        cards.push_back(c);
    }

    file.close();

    cout << "Loaded " << cards.size() << " cards" << endl;
}

void loadArtists(vector<Artist> &artists) {
    Artist a;

    artists.clear();

    ifstream file("artists.txt");

    while (file >> a.name >> a.uuid ) {
        artists.push_back(a);
        cout << a.name << ", ";
    }

    file.close();

    cout << "Loaded " << artists.size() << " artists" << endl;
}

char menu() {
    char op;

    cout << "*****************************" << endl;
    cout << "1.- Buscar carta" << endl;
    cout << "2.- Buscar artista" << endl;
    cout << "3.- Opcion cual" << endl;
    cout << "0.- Salir" << endl;
    cout << "*****************************" << endl;

    cin >> op;

    return op;
}

void SearchCard() {
    string uuid;
    string name;

    cout << "Card name: ";
    cin >> name;

    uuid = SearchCardByName(name);

    if (uuid == "") {
        cout << "Not found" << endl;
    } else {
        cout << uuid << endl;
    }
}

string SearchCardByName(string name) {
    Card c;
    bool found = false;

    ifstream file("cards.txt");

    while (found == false && file >> c.uuid >> c.name >> c.colors >> c.manaCost >> c.manaValue >> c.rarity >> c.power >> c.toughness >> c.type >> c.types >> c.artistIds) {
        if (c.name == name) {
            found = true;
        }
    }

    file.close();
    if (found) {
        return c.uuid;
    } else {
        return "";
    }
}


void SearchArtist() {
    string uuid;
    string name;

    cout << "Artist name: ";
    cin >> name;

    uuid = SearchArtistByName(name);

    if (uuid == "") {
        cout << "Not found" << endl;
    } else {
        cout << uuid << endl;
    }
}

string SearchArtistByName(string name) {
    Artist a;
    bool found = false;

    ifstream file("artist.txt");

    while (found == false && file >> a.name >> a.uuid) {
        if (a.name == name) {
            found = true;
        } else {
            cout << a.name;
        }
    }

    file.close();
    if (found) {
        return a.name;
    } else {
        return "";
    }
}
