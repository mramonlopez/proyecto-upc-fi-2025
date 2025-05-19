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

int main() {
    vector<Card> cards;
    vector<Artist> artists;
    vector<Colection> collection;
    char op;

    loadCards(cards);
    loadArtists(artists);

    op = menu();
    while (op != '0') {
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

    while (file >> a.uuid >> a.name) {
        artists.push_back(a);
    }

    file.close();

    cout << "Loaded " << artists.size() << " artists" << endl;
}

char menu() {
    char op;

    cout << "*****************************" << endl;
    cout << "1.- Opcion 1" << endl;
    cout << "2.- Opcion tal" << endl;
    cout << "3.- Opcion cual" << endl;
    cout << "0.- Salir" << endl;
    cout << "*****************************" << endl;

    cin >> op;

    return op;
}
