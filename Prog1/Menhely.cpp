#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Allat
{
    string faj;
    string nev;
    int kor;
    string szin;
};

istream &operator>>(istream &stream, Allat &a)
{
    stream >> a.faj;
    stream >> a.nev;
    stream >> a.kor;
    stream >> a.szin;
    return stream;
}

ostream& operator<<(ostream& stream, Allat& a){
    stream << a.faj << " " << a.nev << " " << a.kor << " " << a.szin << endl;
    return stream;
}

int main()
{

    fstream adatb;
    adatb.open("menhely.txt", ios::out | ios::in);
    vector<Allat> tarol;
    Allat allatka;
    while (adatb >> allatka)
    {
        tarol.push_back(allatka);
    }
    tarol.shrink_to_fit();
    /*for( int i = 0; i < tarol.size(); i++ ){
        cout << tarol[i].nev << endl;
    }*/
    cout << "Milyen allatot keresel?\n(faj/nev/kor/szin)\n";
    string filter;
    int korertek;
    string masertek;
    cin >> filter;
    transform(filter.begin(), filter.end(), filter.begin(), ::toupper);
    if (filter == "KOR")
    {
        cin >> korertek;
    }
    else
    {
        cin >> masertek;
    }
    transform(masertek.begin(), masertek.end(), masertek.begin(), ::toupper);
    bool talalat = false;
    switch (filter[0])
    {
    case 'F':
        for (int i = 0; i < tarol.size(); i++)
        {
            transform(tarol[i].faj.begin(), tarol[i].faj.end(), tarol[i].faj.begin(), ::toupper);
            if( tarol[i].faj == masertek ){
                cout << tarol[i];
                talalat = true;
            }
        }
        if( !talalat ){
            cout << "Nincs ilyen állat a menhelyen :'(" << endl;
        }
        break;
    case 'N':
        for (int i = 0; i < tarol.size(); i++)
        {
            transform(tarol[i].nev.begin(), tarol[i].nev.end(), tarol[i].nev.begin(), ::toupper);
            if( tarol[i].nev == masertek ){
                cout << tarol[i];
                talalat = true;
            }
        }
        if( !talalat ){
            cout << "Nincs ilyen állat a menhelyen :'(" << endl;
        }
        break;
    case 'K':
        for( int i = 0; i < tarol.size(); i++ ){
            if( tarol[i].kor == korertek ){
                cout << tarol[i];
                talalat = true;
            }
        }  
        if( !talalat ){
            cout << "Nincs ilyen állat a menhelyen :'(" << endl;
        }
        break;
    case 'S':
        for (int i = 0; i < tarol.size(); i++)
        {
            transform(tarol[i].szin.begin(), tarol[i].szin.end(), tarol[i].szin.begin(), ::toupper);
            if( tarol[i].szin == masertek ){
                cout << tarol[i];
                talalat = true;
            }
        }
        if( !talalat ){
            cout << "Nincs ilyen állat a menhelyen :'(" << endl;
        }
        break;
    }

    return 0;
}
