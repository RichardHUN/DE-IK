#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    ifstream file("tranzakciok.txt");

    map<vector<string>, int> kombinaciok;

    string sor;
    while (getline(file, sor)) {
        vector<string> elemek;
        string elem;
        stringstream ss(sor);
        while (ss >> elem) {
            elemek.push_back(elem);
        }

        sort(elemek.begin(), elemek.end());

        kombinaciok[elemek]++;
    }

    for (const auto& parok : kombinaciok) {
        const vector<string>& elemek = parok.first;
        int count = parok.second;

        for (const string& elem : elemek) {
            cout << elem << " ";
        }
        cout << ": " << count << endl;
    }

    return 0;
}
