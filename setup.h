#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<vector>
#include<list>
#include<limits.h>
#include<queue>

using namespace std;

int stationIdUsed = -1;         // To maintain station Id

class node        // For Tries
{
public:
    char c;
    unordered_map<char, node*> m;
    bool t;

    node(char ch)
    {
        c=ch;
        t=false;
    }
};

class Stations    // implementation of Tries to store all stations
{

    node* station;

public:
    Stations()
    {
        station = new node('\0');
    }

    void insert(string word)
    {
        node *temp = station;
        for(int i=0; word[i]!='\0'; i++)
        {
            if(temp->m.count(word[i]))
            {
                temp = temp->m[word[i]];
            }
            else
            {
                node * n = new node(word[i]);
                temp->m[word[i]]= n;
                temp = n;
            }
        }

        temp->t=true;
    }

    bool find(string word)
    {
        node*temp = station;

        for(int i=0; word[i]!='\0'; i++)
        {
            if(temp->m.count(word[i])==0)
            {
                return false;
            }
            else
            {
                temp = temp->m[word[i]];
            }
        }
        return temp->t;
    }

    void setStations()
    {
        insert("welcome");
        insert("seelampur");
        insert("shastri park");
        insert("kashmere gate");
        insert("tis hazari");
        insert("pulbangash");
        insert("pratap nagar");
        insert("shastri nagar");
        insert("inderlok");
        insert("kanhaiya nagar");
        insert("netaji subhash place");
        insert("rithala");
        insert("madipur");
        insert("shivaji park");
        insert("punjabi bagh");
        insert("ashok park");
        insert("sat guru ram singh marg");
        insert("kirti nagar");
        insert("shadipur");
        insert("keshav puram");
        insert("patel nagar");
        insert("rajender place");
        insert("karol bagh");
        insert("rajiv chowk");
        insert("barakhamba road");
        insert("mandi house");
        insert("pragati maiden");
        insert("inderprastha");
        insert("yamuna bank");
        insert("vishwavidalaya");
        insert("vidhan sabha");
        insert("civil lines");
        insert("chandni chowk");
        insert("chawri bazar");
        insert("new delhi");
        insert("patel chowk");
        insert("central secretariat");
        insert("udyog bhawan");
        insert("lok kalyan marg");
        insert("jor bagh");
        insert("lal qila");
        insert("jama masjid");
        insert("delhi gate");
        insert("ito");
        insert("janptah");
        insert("khan market");
        insert("jl nehru stadium");
        insert("jangpura");
        insert("rajouri garden");
        insert("ramesh nagar");
        insert("moti nagar");
    }

    void addStation(string word)
    {
        insert(word);
    }
};

Stations s;

class LineColors        // To store information about metro colors
{
public:
    unordered_map<string,unordered_set<string> > colors;

    LineColors()
    {

    }

    void setColors()
    {
        colors["welcome"].insert("Red");
        colors["seelampur"].insert("Red");
        colors["shastri park"].insert("Red");
        colors["kashmere gate"].insert("Red");
        colors["kashmere gate"].insert("Yellow");
        colors["kashmere gate"].insert("Violet");
        colors["tis hazari"].insert("Red");
        colors["pulbangash"].insert("Red");
        colors["pratap nagar"].insert("Red");
        colors["shastri nagar"].insert("Red");
        colors["inderlok"].insert("Green");
        colors["inderlok"].insert("Red");
        colors["kanhaiya nagar"].insert("Red");
        colors["netaji subhash place"].insert("Red");
        colors["rithala"].insert("Red");
        colors["madipur"].insert("Green");
        colors["shivaji park"].insert("Green");
        colors["punjabi bagh"].insert("Green");
        colors["ashok park"].insert("Green");
        colors["sat guru ram singh marg"].insert("Green");
        colors["kirti nagar"].insert("Green");
        colors["kirti nagar"].insert("Blue");
        colors["shadipur"].insert("Blue");
        colors["keshav puram"].insert("Red");
        colors["patel nagar"].insert("Blue");
        colors["rajender place"].insert("Blue");
        colors["karol bagh"].insert("Blue");
        colors["rajiv chowk"].insert("Blue");
        colors["rajiv chowk"].insert("Yellow");
        colors["barakhamba road"].insert("Blue");
        colors["mandi house"].insert("Blue");
        colors["mandi house"].insert("Violet");
        colors["pragati maiden"].insert("Blue");
        colors["inderprastha"].insert("Blue");
        colors["yamuna bank"].insert("Blue");
        colors["vishwavidalaya"].insert("Yellow");
        colors["vidhan sabha"].insert("Yellow");
        colors["civil lines"].insert("Yellow");
        colors["chandni chowk"].insert("Yellow");
        colors["chawri bazar"].insert("Yellow");
        colors["new delhi"].insert("Yellow");
        colors["patel chowk"].insert("Yellow");
        colors["central secretariat"].insert("Yellow");
        colors["central secretariat"].insert("Violet");
        colors["udyog bhawan"].insert("Yellow");
        colors["lok kalyan marg"].insert("Yellow");
        colors["jor bagh"].insert("Yellow");
        colors["lal qila"].insert("Violet");
        colors["jama masjid"].insert("Violet");
        colors["delhi gate"].insert("Violet");
        colors["ito"].insert("Violet");
        colors["janptah"].insert("Violet");
        colors["khan market"].insert("Violet");
        colors["jl nehru stadium"].insert("Violet");
        colors["jangpura"].insert("Violet");
        colors["rajouri garden"].insert("Blue");
        colors["ramesh nagar"].insert("Blue");
        colors["moti nagar"].insert("Blue");
    }

    void addColors(string station, vector<string> &color)
    {
        for(auto x: color)
        {
            colors[station].insert(x);
        }
    }

};

LineColors c;

class Mapping       // mapping stations with codes
{
public:
    vector<string> stationFromId;

    Mapping()
    {
        stationFromId.resize(51);
        stationIdUsed = 50;
    }

    void setMapping()
    {
        stationFromId[0] = "welcome";
        stationFromId[1] = "seelampur";
        stationFromId[2] = "shastri park";
        stationFromId[3] = "kashmere gate";
        stationFromId[4] = "tis hazari";
        stationFromId[5] = "pulbangash";
        stationFromId[6] = "pratap nagar";
        stationFromId[7] = "shastri nagar";
        stationFromId[8] = "inderlok";
        stationFromId[9] = "kanhaiya nagar";
        stationFromId[10] = "keshav puram";
        stationFromId[11] = "netaji subhash place";
        stationFromId[12] = "rithala";
        stationFromId[13] = "madipur";
        stationFromId[14] = "shivaji park";
        stationFromId[15] = "punjabi bagh";
        stationFromId[16] = "ashok park";
        stationFromId[17] = "sat guru ram singh marg";
        stationFromId[18] = "kirti nagar";
        stationFromId[19] = "shadipur";
        stationFromId[20] = "patel nagar";
        stationFromId[21] = "rajender place";
        stationFromId[22] = "karol bagh";
        stationFromId[23] = "rajiv chowk";
        stationFromId[24] = "barakhamba road";
        stationFromId[25] = "mandi house";
        stationFromId[26] = "pragati maiden";
        stationFromId[27] = "inderprastha";
        stationFromId[28] = "yamuna bank";
        stationFromId[29] = "vishwavidalaya";
        stationFromId[30] = "vidhan sabha";
        stationFromId[31] = "civil lines";
        stationFromId[32] = "chandni chowk";
        stationFromId[33] = "chawri bazar";
        stationFromId[34] = "new delhi";
        stationFromId[35] = "patel chowk";
        stationFromId[36] = "central secretariat";
        stationFromId[37] = "udyog bhawan";
        stationFromId[38] = "lok kalyan marg";
        stationFromId[39] = "jor bagh";
        stationFromId[40] = "lal qila";
        stationFromId[41] = "jama masjid";
        stationFromId[42] = "delhi gate";
        stationFromId[43] = "ito";
        stationFromId[44] = "janptah";
        stationFromId[45] = "khan market";
        stationFromId[46] = "jl nehru stadium";
        stationFromId[47] = "jangpura";
        stationFromId[48] = "rajouri garden";
        stationFromId[49] = "ramesh nagar";
        stationFromId[50] = "moti nagar";
    }

    void addStationId(string station)
    {
        ++stationIdUsed;
        stationFromId.push_back(station);
    }

    void displayAll()
    {
        system("cls");

        cout<<"STATION LIST WITH SERIAL NUMBER "<<endl<<endl;


        for(int i=0; i<=stationIdUsed; ++i)
        {
            cout<<i<<"    ";
            if(i<10) cout<<" ";
            cout<<stationFromId[i]<<endl;
        }

        cout<<endl<<"Press any key to go back... ";

        getch();
        system("cls");
        home();
    }

};

Mapping m;

void generatePath(vector<string> &journey)         // to print journey route
{

    string startingColor;
    for(auto x: c.colors[journey[0]])
    {
        if(c.colors[journey[1]].find(x)!= c.colors[journey[1]].end())
        {
            startingColor = x;
            break;
        }
    }

    cout<<endl<<" > Start with "<<startingColor<<" colour line"<<endl;

    cout<<journey[0];

    for(int i=1; i<journey.size(); ++i)
    {
        if(c.colors[journey[i]].find(startingColor)!=c.colors[journey[i]].end())
        {
            cout<<"->"<<journey[i];
        }
        else
        {
            for(auto x: c.colors[journey[i-1]])
            {
                if(c.colors[journey[i]].find(x)!= c.colors[journey[i-1]].end())
                {
                    startingColor = x;
                    break;
                }
            }
            cout<<endl<<endl<<" > Switch to "<<startingColor<<" color line"<<endl;
            cout<<journey[i];
        }
    }
}

class info                          // for graph
{
public:
    string station;
    int cost;
    double distance;

    info(string s, int c, double d)
    {
        station = s;
        cost = c;
        distance = d;
    }
};

class Lines                     // graph to store network connection
{
    unordered_map<string,list<info>> line;

public:

    void addLine(string a, string b, int c, double d)
    {
        info temp1(a,c,d);
        info temp2(b,c,d);
        line[a].push_back(temp2);
        line[b].push_back(temp1);
    }

    void setLines()
    {
        addLine("rithala","netaji subhash place",30,5.2);
        addLine("netaji subhash place","keshav puram",10,1.2);
        addLine("keshav puram","kanhaiya nagar",10,0.8);
        addLine("kanhaiya nagar","inderlok",10,1.2);
        addLine("madipur","shivaji park",10,1.1);
        addLine("shivaji park","punjabi bagh",10,1.6);
        addLine("punjabi bagh","ashok park",10,0.9);
        addLine("ashok park","sat guru ram singh marg",10,1.1);
        addLine("ashok park","inderlok",10,1.4);
        addLine("rajouri garden","ramesh nagar",10,1);
        addLine("ramesh nagar","moti nagar",10,1.2);
        addLine("inderlok","shastri nagar",10,1.2);
        addLine("moti nagar","kirti nagar",10,1);
        addLine("sat guru ram singh marg","kirti nagar",10,1);
        addLine("shastri nagar","pratap nagar",10,1.7);
        addLine("kirti nagar","shadipur",10,0.7);
        addLine("pratap nagar","pulbangash",10,0.8);
        addLine("vishwavidalaya","vidhan sabha",10,1);
        addLine("shadipur","patel nagar",10,1.3);
        addLine("pulbangash","tis hazari",10,0.9);
        addLine("vidhan sabha","civil lines",10,1.3);
        addLine("patel nagar","rajender place",10,0.9);
        addLine("tis hazari","kashmere gate",10,1.1);
        addLine("civil lines","kashmere gate",10,1.1);
        addLine("rajender place","karol bagh",10,1);
        addLine("kashmere gate","shastri park",20,2.2);
        addLine("kashmere gate","lal qila",10,1.5);
        addLine("kashmere gate","chandni chowk",10,1.1);
        addLine("shastri park","seelampur",10,1.6);
        addLine("lal qila","jama masjid",10,0.8);
        addLine("chandni chowk","chawri bazar",10,1);
        addLine("seelampur","welcome",10,1.1);
        addLine("jama masjid","delhi gate",10,1.4);
        addLine("chawri bazar","new delhi",10,0.8);
        addLine("karol bagh","rajiv chowk",20,3.4);
        addLine("new delhi","rajiv chowk",10,1.1);
        addLine("delhi gate","ito",10,1.3);
        addLine("rajiv chowk","barakhamba road",10,0.7);
        addLine("rajiv chowk","patel chowk",10,1.3);
        addLine("ito","mandi house",10,0.8);
        addLine("barakhamba road","mandi house",10,1);
        addLine("mandi house","pragati maiden",10,0.8);
        addLine("mandi house","janptah",10,1.4);
        addLine("inderprastha","pragati maiden",10,0.8);
        addLine("janptah","central secretariat",10,1.3);
        addLine("patel chowk","central secretariat",10,0.9);
        addLine("inderprastha","yamuna bank",10,1.8);
        addLine("central secretariat","udyog bhawan",10,0.3);
        addLine("central secretariat","khan market",20,2.1);
        addLine("udyog bhawan","lok kalyan marg",10,1.6);
        addLine("khan market","jl nehru stadium",10,1.4);
        addLine("lok kalyan marg","jor bagh",10,1.2);
        addLine("jl nehru stadium","jangpura",10,0.9);
    }

    void displayNetwork()
    {
        system("cls");
        cout<<"NETWORK CONNECTION OF ALL STATIONS "<<endl<<endl;

        for(auto x:line)
        {
            cout<<"Station '"<<x.first<<"' is connected to ->"<<endl;
            for(auto y:x.second)            // or auto x:m[p.first]
            {
                cout<<"     "<<y.station<<" by cost "<<y.cost<<" and distance "<<y.distance<<endl;

            }
            cout<<endl;
        }

        cout<<endl;
        cout<<"Press any key to go back... ";

        getch();
        system("cls");
        home();
    }

    void cheapestRoute(string src, string dest)
    {

        unordered_map<string,int> visitedCost;
        unordered_map<string,string> parent;

        for(int i=0; i<= stationIdUsed; ++i)
        {
            visitedCost[m.stationFromId[i]] = INT_MAX;
            parent[m.stationFromId[i]] = "none";
        }

        priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string> > > pq;

        visitedCost[src] = 0;
        pq.push({0,src});

        while(!pq.empty())
        {

            auto t = pq.top();
            pq.pop();

            int c = t.first;
            string stat = t.second;

            if(stat == dest) break;

            for(auto nbr: line[stat])
            {
                string nbrstat = nbr.station;
                int addc = nbr.cost;

                if(visitedCost[nbrstat]> addc + c)
                {
                    visitedCost[nbrstat] = addc + c;
                    parent[nbrstat] = stat;
                    pq.push({visitedCost[nbrstat],nbrstat});
                }
            }
        }

        string temp = dest;
        vector<string> journey;

        while(temp!="none")
        {
            journey.push_back(temp);
            temp = parent[temp];
        }

        reverse(journey.begin(),journey.end());
        generatePath(journey);

        cout<<endl<<endl<<"*** Total cost of journey will be rupees "<<visitedCost[dest]<<" ***"<<endl<<endl<<endl;
    }




    void ShortestRoute(string src, string dest)
    {

        unordered_map<string,double> visitedDist;
        unordered_map<string,string> parent;

        for(int i=0; i<= stationIdUsed; ++i)
        {
            visitedDist[m.stationFromId[i]] = INT_MAX;
            parent[m.stationFromId[i]] = "none";
        }

        priority_queue<pair<double,string>, vector<pair<double,string>>, greater<pair<double,string> > > pq;

        visitedDist[src] = 0;
        pq.push({0,src});

        while(!pq.empty())
        {

            auto t = pq.top();
            pq.pop();

            double d = t.first;
            string stat = t.second;

            if(stat == dest) break;

            for(auto nbr: line[stat])
            {
                string nbrstat = nbr.station;
                double addd = nbr.distance;

                if(visitedDist[nbrstat]> addd + d)
                {
                    visitedDist[nbrstat] = addd + d;
                    parent[nbrstat] = stat;
                    pq.push({visitedDist[nbrstat],nbrstat});
                }
            }
        }

        string temp = dest;
        vector<string> journey;

        while(temp!="none")
        {
            journey.push_back(temp);
            temp = parent[temp];
        }
        reverse(journey.begin(),journey.end());
        generatePath(journey);

        cout<<endl<<endl<<"*** Total Distance of journey will be "<<visitedDist[dest]<<" kms ***"<<endl<<endl<<endl;
    }

};

Lines l;


void getReady()                 // to initialize the application
{
    s.setStations();

    m.setMapping();

    c.setColors();

    l.setLines();
}