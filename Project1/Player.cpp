
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Player
{
private:
    // Field variables
    string firstname, lastname;
    int statistics [8]; //integer statistics in this order: plateappearances atbats singles doubles triples homeruns walks hitbypitch

    // grab everything up to and including 'delim' from 'data' and put it in a string 
    // will ask about this in class, because it seems like a pretty slow way to do this
    string grabString(istream &data, char delim)
    {
        string result = "";
        char character;
        while (true)
        {
            data >> character;
            if (character == delim) break;
            result += character;
        }
        return result;
    }

public:
    // Default constructor
    Player()
    {
        this->firstname = "unknown";
        this->lastname = "unknown";
        // set all statistics to zero
        for (int i = 0; i < 8; i++)
        {
            this->statistics[0] = 0;
        }
    }

    void grabData(istream &data)
    {
        // grab names
        this->firstname = grabString(data, ' ');
        this->lastname = grabString(data, ' ');
        // grab other data
        for (int i = 0; i < 8; i++)
        {
            data >> this->statistics[i];
        }
        cout << "\n" << firstname << " " << lastname;
        for (int i = 0; i < 8; i++)
        {
            cout << "\n" << statistics[i];
        }
        
    }
    

};

int main(int argc, char const *argv[])
{
    Player myPlayer;
    myPlayer.grabData(cin);

    return 0;
}

