#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){

    map<string, int> tranzakciok;
    vector<string> sorok;
    ifstream f;
    f.open("tranzakciok.txt", ios::in);
    string elem;
    string sor;
    int nrTranzakciok = 0;
    while ( getline(f, sor) ) {
        nrTranzakciok++;
        stringstream sor1(sor);
        while( sor1 >> elem ){
            std::transform(elem.begin(), elem.end(), elem.begin(), ::toupper);
            tranzakciok[elem]++;
        }
    }
    for( auto i : tranzakciok ){
        cout << i.first << ": " << (double)i.second/nrTranzakciok*100 << "%" << endl;
    }
    f.close();
    return 0;
}
