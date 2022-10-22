#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <array>

using namespace std;


int muenzrollen[] {4,8,20,25,50};
string muenzrollenwerte[] {"10 cent","20 cent","50 cent","1 euro","2 euro"};

int scheinwerte[] {5,10,20,50,100};
string schein[]{"5 euro", "10 euro", "20 euro", "50 euro", "100 euro"};

int muenzeingabe(int wert){
    string eingabe;
    int result;

    cout << "Anzahl der " << muenzrollenwerte[wert] << " Muenzrollen, oder b um neu zu beginnen \n";
    cin >> eingabe;
    if(eingabe != "b"){
        result = stoi (eingabe);
    }
    else
        result = -1;

    return result;
}

vector<int> kassenzaehlung()
{
    vector<int> anzahl (5,0);
    cout << "Begin der Abrechnung ..... \n";
    
    bool cond = true;
    int count = 0;
    while(cond == true){
         if(count == 5){
            cond = false;
            break;
        }
        int tmp = muenzeingabe(count);
       
        if(tmp != -1){
            anzahl[count] = tmp;
            count++;
        }
        else
            count = 0;
    }
    return anzahl;
}

int get_sum(vector<int> anzahlen, int prod[] )
{
    int sum;
    for (int i = 0; i<anzahlen.size(); i++)
        sum = sum + anzahlen[i] * muenzrollen[i];
    
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

int scheineingabe(int wert){
    string eingabe;
    int result;

    cout << "Anzahl der " << schein[wert] << " scheine, oder b um neu zu beginnen \n";
    cin >> eingabe;
    if(eingabe != "b"){
        result = stoi (eingabe);
    }
    else
        result = -1;

    return result;
}


void schein_print(int wert, int anzahl){
    cout << schein[wert] << " x " << anzahl << " = " << scheinwerte[wert] * anzahl << "\n";
}

int umsatz()
{
    vector<int> anzahl (5,0);
    cout << "Begin der Umsatz berechnung ..... \n";
    
    bool cond = true;
    int count = 0;
    while(cond == true){
         if(count == 5){
            cond = false;
            break;
        }
        int tmp = scheineingabe(count);
       
        if(tmp != -1){
            anzahl[count] = tmp;
            schein_print(count, tmp);
            count++;
        }
        else
            count = 0;
    }

    int result;
    for(int i = 0; i < 5; i++){
        result = result + anzahl[i] * scheinwerte[i];
    }
    return result;
}


int main()
{
    buendel();

    vector<int> anzahlen = kassenzaehlung();

    int sum = get_sum(anzahlen, scheinwerte);

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