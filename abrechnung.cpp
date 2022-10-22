#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int prod[] {4,8,20,25,50};

vector<int> kassenzaehlung()
{
    string ten_cent;
    string twenty_cent;
    string fifty_cent;
    string one_euro;
    string two_euro;
    vector<int> anzahl;

    cout << "Begin der Abrechnung ..... \n";
    //10 cent
    cout << "Anzahl der 10 cent Muenzrollen \n";
    cin >> ten_cent;
    anzahl.push_back(stoi (ten_cent));
    //20 cent
    cout << "Anzahl der 20 cent Muenzrollen \n";
    cin >> twenty_cent;
    anzahl.push_back(stoi (twenty_cent));
    //50 cnet
    cout << "Anzahl der 50 cent Muenzrollen \n";
    cin >> fifty_cent;
    anzahl.push_back(stoi (fifty_cent));
    //1 euro
    cout << "Anzahl der 1 euro Muenzrollen \n";
    cin >> one_euro;
    anzahl.push_back(stoi (one_euro));
    //2 euro
    cout << "Anzahl der 2 euro Muenzrollen \n";
    cin >> two_euro;
    anzahl.push_back(stoi (two_euro));
    return anzahl;
}

int get_sum(vector<int> anzahlen, int prod[] )
{
    int sum;
    for (int i = 0; i<anzahlen.size(); i++)
        sum = sum + anzahlen[i] * prod[i];
    
    return sum;
}

void print_vec(vector<int> vec)
{
    vector<int>::iterator it;
    it = vec.begin();
    for (it=vec.begin(); it<vec.end(); it++)
        cout << ' ' << *it;
        cout << '\n'; 
}

void buendel()
{
    cout << "Zaehle das 200euro Buendel in der Kasse\n";
    string anzahl;
    cin >> anzahl;
    int fehler = 200 - stoi (anzahl);
    cout << " im Buendel fehlen " << fehler << " euro\n";

}

int scheine()
{
    cout << "Zaehle die Scheine in der Kasse\n";
    string anzahl;
    cin >> anzahl;
    return stoi (anzahl);
}

int muenzen()
{
    cout << "Zaehle die Muenzen in der Kasse\n";
    string anzahl;
    cin >> anzahl;
    return stoi (anzahl);
}

int umsatz()
{
    string fuenf;
    string ten;
    string twenty;
    string fifty;
    string hund;
    cout << "gib die Anzahl an 5euro Scheinen an\n";
    cin >> fuenf;
    int first = stoi (fuenf) * 5;
    cout << "5 x " << fuenf << "  = " << first << "\n";

    cout << "gib die Anzahl an 10euro Scheinen an\n";
    cin >> ten;
    int second = stoi (ten) * 10;
    cout << "10 x " << ten << "  = " << second << "\n";

    cout << "gib die Anzahl an 20euro Scheinen an\n";
    cin >> twenty;
    int third = stoi (twenty) * 20;
    cout << "20 x " << twenty << "  = " << third << "\n";

    cout << "gib die Anzahl an 50euro Scheinen an\n";
    cin >> fifty;
    int fourth = stoi (fifty) * 50;
    cout << "50 x " << fifty << "  = " << fourth << "\n";
    
    cout << "gib die Anzahl an 100euro Scheinen an\n";
    cin >> hund;
    int fift = stoi (hund) * 100;
    cout << "100 x " << hund << "  = " << fift << "\n";

    return first + second + third + fourth + fift;

}
int main()
{
    vector<int> anzahlen = kassenzaehlung();

    int sum = get_sum(anzahlen, prod);

    //print_vec(anzahlen);
    cout << "In der Kasse befinden sich " << to_string(sum) << " in Muenzrollen\n";


    int fehler = 1120 - sum - scheine() - muenzen();
    if ( fehler > 0){
        cout << "In der Kasse fehlen " << to_string(fehler) << " euro in der Kasse \n";
    }
    else {
        cout << "In der Kasse sind " << to_string(fehler * -1) << " euro zuviel \n";
    }
    
    cout << "Begin Umsatz .....\n";
    int end = umsatz();
    cout << "Der Umsatz betraegt: " << to_string(end);

    string tmp;
    cin >> tmp;

    return 0;
}