#include <iostream>
#include <fstream>
// #include <conio.h>

#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <limits> // For std::numeric_limits
#include <cstdlib> 
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <algorithm>
#include<queue>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include<cmath>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include<string>
#include <valarray>
#include <vector>
using namespace std;

void exit();
void displayFunctions();
void showmap();
void home();
void cheapest();
void fastest();
void addStation();

#include "setup.h"

int main()
{

    getReady();
    home();
    system("cls");
    exit();

    return 0;
}

void displayFunctions()
{
    ifstream ip("home.txt");
    string m;
    while (ip.eof() == 0)
    {
        getline(ip, m);
        cout << m << endl;
    }
    ip.close();

    cout << "What would you like to do ?" << endl;
    cout << "1. Display List Of Stations" << endl;
    cout << "2. See network of Stations" << endl;
    cout << "3. Complete Map of MetroLines" << endl;
    cout << "4. Cheapest way to reach your Destination" << endl;
    cout << "5. Fastest way to reach your Destination";
    cout << "                                             -1. Add Stations(Admin Only)" << endl
         << endl;
    cout << "Press 0 to exit" << endl
         << endl;
}

void home()
{
    displayFunctions();
    cout << "Enter Your Choice : ";
    int choice;
A:
    cin >> choice;

    switch (choice)
    {

    case 0:
        break;
    case 1:
        m.displayAll();
        break;

    case 2:
        l.displayNetwork();
        break;

    case 3:
        system("cls");
        showmap();
        break;

    case 4:
        system("cls");
        cheapest();
        break;

    case 5:
        system("cls");
        fastest();
        break;

    case -1:
        system("cls");
        addStation();
        break;

    default:
        system("cls");
        displayFunctions();
        cout << "Oops!!! Invalid Input.... Enter your choice again : ";
        goto A;
    }
}
void clearBuffer() {
    // Clear the input buffer to handle newline characters
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void showmap()
{
    cout << "----------------------------------------------------METRO LINES NETWORK-------------------------------------------------" << endl
         << endl;
    ifstream ip("map.txt");
    string m;
    while (ip.eof() == 0)
    {
        getline(ip, m);
        cout << m << endl;
    }
    ip.close();
    cout << endl
         << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl
         << "Press any key to go back...";
    clearBuffer(); // Clear the input buffer
    std::cin.get(); // Wait for Enter key
    std::system("cls");
    home();
}

void cheapest()
{
    string src, dest;
    cin.ignore();
B:
    cout << "Enter starting station ('back' to go back): ";
    string org;
    getline(cin, src);
    org = src;
    bool digit = true;
    for (int i = 0; i < src.length(); ++i)
    {
        if (src[i] < '0' or src[i] > '9')
            digit = false;
    }

    if (digit)
    {
        if (stoi(src) >= 0 && stoi(src) <= stationIdUsed)
            src = m.stationFromId[stoi(src)];
    }

    for (int i = 0; !digit && i < src.length(); ++i)
    {
        if (src[i] >= 'A' && src[i] <= 'Z')
            src[i] += 32;
    }
    if (src == "back")
    {
        system("cls");
        home();
        return;
    }
    if (!s.find(src))
    {
        system("cls");
        cout << "Invalid Starting Location" << endl
             << endl;
        goto B;
    }

C:
    cout << "Enter destination station ('back' to go back): ";
    getline(cin, dest);

    digit = true;
    for (int i = 0; i < dest.length(); ++i)
    {
        if (dest[i] < '0' or dest[i] > '9')
            digit = false;
    }

    if (digit)
    {
        if (stoi(dest) >= 0 && stoi(dest) <= stationIdUsed)
            dest = m.stationFromId[stoi(dest)];
    }

    for (int i = 0; !digit && i < dest.length(); ++i)
    {
        if (dest[i] >= 'A' && dest[i] <= 'Z')
            dest[i] += 32;
    }
    if (dest == "back")
    {
        system("cls");
        home();
        return;
    }
    if (!s.find(dest))
    {
        system("cls");

        cout << "Invalid Destination Location" << endl
             << endl;
        cout << "Enter starting location : " << org << endl;
        goto C;
    }
    system("cls");
    l.cheapestRoute(src, dest);

    cout << endl
         << endl;

    cout << "Press any key to go back... ";
    clearBuffer(); // Clear the input buffer
    std::cin.get(); // Wait for Enter key
    std::system("cls");
    home();
}

void fastest()
{
    string src, dest;
    cin.ignore();
B:
    cout << "Enter starting station ('back' to go back): ";
    string org;
    getline(cin, src);
    org = src;
    bool digit = true;
    for (int i = 0; i < src.length(); ++i)
    {
        if (src[i] < '0' or src[i] > '9')
            digit = false;
    }

    if (digit)
    {
        if (stoi(src) >= 0 && stoi(src) <= stationIdUsed)
            src = m.stationFromId[stoi(src)];
    }

    for (int i = 0; !digit && i < src.length(); ++i)
    {
        if (src[i] >= 'A' && src[i] <= 'Z')
            src[i] += 32;
    }
    if (src == "back")
    {
        system("cls");
        home();
        return;
    }
    if (!s.find(src))
    {
        system("cls");
        cout << "Invalid Starting Location" << endl
             << endl;
        goto B;
    }

C:
    cout << "Enter destination station ('back' to go back): ";
    getline(cin, dest);

    digit = true;
    for (int i = 0; i < dest.length(); ++i)
    {
        if (dest[i] < '0' or dest[i] > '9')
            digit = false;
    }

    if (digit)
    {
        if (stoi(dest) >= 0 && stoi(dest) <= stationIdUsed)
            dest = m.stationFromId[stoi(dest)];
    }

    for (int i = 0; !digit && i < dest.length(); ++i)
    {
        if (dest[i] >= 'A' && dest[i] <= 'Z')
            dest[i] += 32;
    }
    if (dest == "back")
    {
        system("cls");
        home();
        return;
    }
    if (!s.find(dest))
    {
        system("cls");

        cout << "Invalid Destination Location" << endl
             << endl;
        cout << "Enter starting location : " << org << endl;
        goto C;
    }
    system("cls");
    l.ShortestRoute(src, dest);

    cout << endl
         << endl;

    cout << "Press any key to go back... ";
    clearBuffer(); // Clear the input buffer
    std::cin.get(); // Wait for Enter key
    std::system("cls");
    home();
}

void addStation()
{
    system("cls");

    string pass;
    cout << "Enter Password ('back' to go back): ";
    char ch = 'A';

    while (ch != 13) // 13 is ASCII value of Enter key
    {
        cin >> ch;

        if (isprint(ch))
        {
            cout << "*";
            pass.push_back(ch);
        }

        else if (ch == 8 && pass.length()) // 8 is ASCII value of Backspace key
        {
            pass.pop_back();
            cout << ("\b \b");
        }
    }

    if (pass == "back")
    {
        system("cls");
        home();
        return;
    }
    else if (pass != "yes")
    {
        system("cls");
        cout << "ERROR!!!! INVALID PASSWORD ! ";
        cout << endl
             << endl;
        cout << "Press any key to go back and try again... ";
        clearBuffer(); // Clear the input buffer
    std::cin.get(); // Wait for Enter key
    // std::system("cls");
        addStation();
        return;
    }

    system("cls");
    cout << "***Login Successful***" << endl
         << endl;

    string name;
    cout << "Enter station Name : ";
    cin.ignore();

    getline(cin, name);
    s.addStation(name);
    m.addStationId(name);

    vector<string> color;
    string temp;
    int i = 1;

    while (i)
    {
        cout << "Enter color number " << i << " (NULL to stop entering): ";
        getline(cin, temp);
        if (temp == "NULL")
            break;
        color.push_back(temp);
        i++;
    }

    c.addColors(name, color);
    i = 1;
    int c;
    double d;
    while (i)
    {
        cout << "Enter directly connected Station number " << i << " (NULL to stop entering): ";
        if (i > 1)
            cin.ignore();
        getline(cin, temp);
        if (temp == "NULL")
            break;
        cout << "Enter cost of travel : ";
        cin >> c;
        cout << "Enter distance between stations : ";
        cin >> d;
        l.addLine(name, temp, c, d);
        i++;
    }

    cout << endl;

    cout << "Adding Station";
    for (int i = 1; i < 6; i++)
    {
        for (int j = 0; j < 200000000; j++)
        {
        }
        cout << ".";
    }
    cout << endl
         << endl;

    cout << "Station added successfully... " << endl;
    cout << "Press any key to go back...";
    clearBuffer(); // Clear the input buffer
    std::cin.get(); // Wait for Enter key
    std::system("cls");
    home();
}

void exit()
{
    string m;
    ifstream ip("exit.txt");
    while (ip.eof() == 0)
    {
        getline(ip, m);
        cout << m << endl;
    }
    ip.close();
    cout << "Press any key to exit... ";
    clearBuffer(); // Clear the input buffer
    std::cin.get(); // Wait for Enter key
    std::system("cls");
}