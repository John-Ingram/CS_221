// John Ingram|September 5 2020|CS 221
// This Program Creates a Player object to handle data about baseball players. The file also contains a small test program.
// Future versions of this Program will not contain the test program, as it will be moved.
// This program was compiled using gcc version 9.3.0 (Ubuntu 9.3.0-10ubuntu2) using default compiler flags.

#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    // Field variables
    string firstname, lastname;
    int statistics [8]; //integer statistics in this order: plateappearances atbats singles doubles triples homeruns walks hitbypitch


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
    // Set Data about the player from 'data'
    // expected input format is: firstname lastname plateappearances atbats singles doubles triples homeruns walks hitbypitch
    void setData(istream &data) 
    {
        data >> this->firstname;
        data >> this->lastname;
        for (int i = 0; i < 8; i++)
        {
            data >> this->statistics[i];
        }
    }
    // getters for player data. These will all be very similar
    string getFirstName()
    {
        return this->firstname;
    }
    
    string getLastName()
    {
        return this->lastname;
    }

    int getPlateAppearances()
    {
        return this->statistics[0];
    }
    
    int getAtBats()
    {
        return this->statistics[1];
    }

    int getSingles()
    {
        return this->statistics[2];
    }

    int getDoubles()
    {
        return this->statistics[3];
    }

    int getTriples()
    {
        return this->statistics[4];
    }

    int getHomeRuns()
    {
        return this->statistics[5];
    }

    int getWalks()
    {
        return this->statistics[6];
    }

    int getHitByPitch()
    {
        return this->statistics[7];
    }

    // This method is used by both getBattingAverage and getOnBasePercentage,
    // It does not technically need to be public, but I figured that it may be useful to a user.
    int getHits()
    {
        return this->getSingles() + this->getDoubles() + this->getTriples() + this->getHomeRuns();
    }
    // Calculate batting average
    float getBattingAverage()
    {
        return (float) this->getHits()/(float) this->getAtBats();
    }

    float getOnBasePercentage()
    {
        return (float)(this->getHits()+this->getWalks()+this->getHitByPitch())/(float) this->getPlateAppearances();
    }

};

int main(int argc, char const *argv[])
{
    // Welcome text
    cout << "Welcome to the test driver program for the Player class.\n";
    cout << "When prompted enter the players data in the form of\n";
    cout << "firstname lastname plateappearances atbats singles doubles triples homeruns walks hitbypitch\n";

    //Start infinate loop to repeat test if desired
    while (true)
    {
        Player myPlayer;
        char restart = 'n';
        // Prompt
        cout << "Please enter your data, and confirm with enter: ";
        myPlayer.setData(cin);
        // Result output 
        // firstname and lastname have to be converted to a pointer to the char array, becuse  printf's %s expects a char array
        printf("\n\t%s %s's Batting Average = %.3f and OBP = %.3f\n\n", myPlayer.getFirstName().c_str(), myPlayer.getLastName().c_str(), myPlayer.getBattingAverage(), myPlayer.getOnBasePercentage());

        // Ask if the user wants to test again
        cout << "Do you wish to test another [y/n]?";
        cin >> restart;
        if (towlower(restart) != 'y') break; // If the user enters anything other than y, break out of the infinite loop to end the program
        
    }
    return 0;
}

