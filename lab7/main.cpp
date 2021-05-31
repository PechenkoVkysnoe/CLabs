#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Sity
{
    string name;
    vector <string> hotels;
    vector <string> relaxations;
    vector <string> monuments;
};
void nameOf(Sity name)
{
    cout << "Name of sity " << name.name << endl;
}
void hotel(vector<string> h)
{
    for (int i = 0; i < h.size(); i++)
    {
        cout << h[i] << endl;
    }
}
void relaxation(vector<string> r)
{
    for (int i = 0; i < r.size(); i++)
    {
        cout << r[i] << endl;
    }
}
void monument(vector<string> m)
{
    for (int i = 0; i < m.size(); i++)
    {
        cout << m[i] << endl;
    }
}
void functions(Sity name)
{
    int temp=42;
    nameOf(name);
    while (temp)
    {
        cout << "Enter 1 to select view hotels" << endl;
        cout << "Enter 2 to select view relaxations" << endl;
        cout << "Enter 3 to select view monuments" << endl;
        cout << "Enter 0 to go back" << endl;
        cin >> temp;
        switch (temp)
        {
        case 1:
            hotel(name.hotels);
            break;
        case 2:
            relaxation(name.relaxations);
            break;
        case 3:
            monument(name.monuments);
            break;
        case 0:
            break;
        default:
            break;
        }
    }
}

int main()
{
    vector <int> value;
    int tmp=42;
    value.push_back(tmp);
    vector <Sity> sity;
    Sity Grodno;
    Grodno.name = "Grodno";
    Grodno.hotels.push_back("Semashko, Kalyuchinskaya street 23, around the clock");
    Grodno.hotels.push_back("Crown Park, Pyshki tract, around the clock");
    Grodno.hotels.push_back("Tyrist, Yanki Kupaly street 63, around the clock");
    Grodno.relaxations.push_back("October, Popovich street 3, from 12 am to 12 pm, cinema");
    Grodno.relaxations.push_back("Space, Olga Solomova street 49, from 3 pm to 3 am, cinema");
    Grodno.relaxations.push_back("BEERloga, Popovich street 3, from 12 am to 1 am, bar");
    Grodno.relaxations.push_back("Grodno Regional Drama Theater, Mostovaya street 35, from 6 pm to 12 pm, theater");
    Grodno.relaxations.push_back("Grodno Regional Puppet Theater, Dzerzhinsky street 1 / 1, from 10 am to 3 pm, theater");
    Grodno.monuments.push_back("Lenin monument, Lenin Square");
    Grodno.monuments.push_back("Monument to Eliza Ozheshko, Telegraph street");
    sity.push_back(Grodno);

    Sity Minsk;
    Minsk.name = "Minsk";
    Minsk.hotels.push_back("Aqua-Minsk, praspiekt Pieramožcaŭ 118, around the clock");
    Minsk.hotels.push_back("IT Time, Kuprevicha Street 4, around the clock");
    Minsk.hotels.push_back("East Time, Vtoroy Velosipedny Pereulok 5, around the clock");
    Minsk.relaxations.push_back("Silver Screen, Bobruiskaya street 6, temporarily closed, cinema");
    Minsk.relaxations.push_back("October, Independence Avenue 73, from 3 pm to 12 pm, cinema");
    Minsk.relaxations.push_back("Craftman, Gikalo street 5, from 12 am to 1 am, bar");
    Minsk.relaxations.push_back("Nuahule Minsk, Red street 12, from 12 am to 3 am, bar");
    Minsk.relaxations.push_back("TBolshoi Theater of Belarus, Paris Commune 1, from 6 pm to 12 pm, theater");
    Minsk.monuments.push_back("Lenin monument, Lenin Square");
    Minsk.monuments.push_back("Monument to IT student, Gikalo street 9");
    sity.push_back(Minsk);

    Sity Baranovichi;
    Baranovichi.name = "Baranovichi";
    Baranovichi.hotels.push_back("Mariinskiy, Haharyna street 29, around the clock");
    Baranovichi.hotels.push_back("Villa Sarra, Chernyshevsky street 39, around the clock");
    Baranovichi.hotels.push_back("Karlion, Novomyshsky village council, around the clock");
    Baranovichi.relaxations.push_back("Star, Komsomolskaya street 11, from 12 am to 12 pm, cinema");
    Baranovichi.relaxations.push_back("October, Lenina street 2, from 3 pm to 12 pm, cinema");
    Baranovichi.relaxations.push_back("Old city, Gorky 4, from 12 am to 1 am, bar");
    Baranovichi.relaxations.push_back("Textile worker Palace of Culture GU, Kirova street 62, from 6 pm to 12 pm, theater");
    Baranovichi.monuments.push_back("Lenin monument, Lenin Square");
    Baranovichi.monuments.push_back("Monument to Borobey, Lenin Square");
    sity.push_back(Baranovichi);

    Sity Orsha;
    Orsha.name = "Orsha";
    Orsha.hotels.push_back("Agrousadba Prostokvashino, Ul. Tsentralnaia 51, around the clock");
    Orsha.hotels.push_back("Apartment on Mogilevskaya, Mogilevskaya Street 101, around the clock");
    Orsha.relaxations.push_back("Victory, Lenin street 31,  from 3 pm to 12 pm, cinema");
    Orsha.relaxations.push_back("Motor, Textile workers street 111, from 12 am to 3 am, bar");
    Orsha.relaxations.push_back("House of culture of railway workers, Molokova street 7, from 6 pm to 12 pm, theater");
    Orsha.relaxations.push_back("IR 8, Lenin street 135, jail");
    Orsha.monuments.push_back("Lenin monument, Lenin Square");
    Orsha.monuments.push_back("Monument to the heroes - liberators of Orsha, Mir street 11");
    sity.push_back(Orsha);

    Sity Vitebsk;
    Vitebsk.name = "Vitebsk";
    Vitebsk.hotels.push_back("Vitebsk, Zamkovaya Street 5/2а, around the clock");
    Vitebsk.hotels.push_back("Smart Boutique, Suvorava Street 11, around the clock");
    Vitebsk.relaxations.push_back("Home Cinema, Lenin street 40,  from 3 pm to 12 pm, cinema");
    Vitebsk.relaxations.push_back("Mir, Chekhov street 4,  from 12 am to 12 pm, cinema");
    Vitebsk.relaxations.push_back("BREVIS, Red street 1, from 16 pm to 2 am, bar");
    Vitebsk.relaxations.push_back("BAR 212, Lenin street 26A, temporarily closed, bar");
    Vitebsk.relaxations.push_back("National Academic Drama Theater named after Yakub Kolas, Zamkovaia street 3, theater");
    Vitebsk.monuments.push_back("Lenin monument, Lenin Square");
    Vitebsk.monuments.push_back("Monument to the Children of War, Uritskogo street 11");
    sity.push_back(Vitebsk);

    while (tmp)
    {
        cout << "Enter 1 to select Grodno" << endl;
        cout << "Enter 2 to select Minsk" << endl;
        cout << "Enter 3 to select Baranovichi" << endl;
        cout << "Enter 4 to select Orcha" << endl;
        cout << "Enter 5 to select Vitebsk" << endl;
        cout << "Enter 6 to view visited cities" << endl;
        cout << "Enter 0 to exit the program" << endl;
        cin >> tmp;
        switch (tmp)
        {
        case 1:
            functions(Grodno);
            break;
        case 2:
            functions(Minsk);
            break;
        case 3:
            functions(Baranovichi);
            break;
        case 4:
            functions(Orsha);
            break;
        case 5:
            functions(Vitebsk);
            break;
        case 6:
            sort(value.begin(), value.end());
            for (int i = 0; i < value.size(); i++)
            {
                bool tr = false;
                for (int j = i+1; j < value.size(); j++)
                {
                    if (value[i]==value[j])
                    {
                        value.erase(value.begin()+i);
                        j--;
                    }
                }
            }
            for (int i = 0; i < value.size()-1; i++)
            {
                nameOf(sity[value[i]-1]);
            }
            break;
        case 0:
        {
            return 0;
        }
        default:
            break;
        }
        if (tmp!=6)
        {
            value.push_back(tmp);
        }
    }
}