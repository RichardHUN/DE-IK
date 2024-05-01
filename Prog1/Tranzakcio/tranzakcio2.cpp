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
    int totalTransactions = 0;

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
        totalTransactions++;
    }

    for (const auto& parok : kombinaciok) {
        const vector<string>& elemek = parok.first;
        int count = parok.second;
        double appearanceRatio = (static_cast<double>(count) / totalTransactions) * 100;

        for (const string& elem : elemek) {
            cout << elem << " ";
        }
        cout << ": " << appearanceRatio << "%" << endl;
    }

    return 0;
}
