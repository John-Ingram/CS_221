#include "PlayerList.h"
#include <fstream>
#include <sstream>

using namespace std;


void printReport(string path, PlayerList &players)
{
    cout << path;
    while (players.hasNext())
    {
        cout << players.getNext().getFirstName() << endl;
    }
    
}

// Reads player data from an input file into a PlayerList
PlayerList readPlayers(string path)
{
    stringstream lineStream;
    string line;
    BaseballPlayer *player = new BaseballPlayer();
    PlayerList output;

    ifstream inFile (path);
    if (inFile.is_open())
    {
        player->setData(inFile);
        inFile.close();   
    }
    else
    {
        cout << "Unable to open file";    
        exit(1);
    } 
    return output;
    
}

int main()
{
    // Welcome text
    cout << "Welcome to the baseball team statistics test program.\n";
    cout << "This program reads in player data from a file, and outputs\n";
    cout << "it's results to a different file\n";
    cout << "When prompted enter the input and output file paths.\n";

    //Start infinate loop to repeat test if desired
    while (true)
    {
        string inFilePath, outFilePath;
        char restart = 'n';
        // Prompt
        cout << "\n\nPlease enter the path to your input file: ";
        cin >> inFilePath;
        cout << "\n\nPlease enter the path to your output file: ";
        cin >> outFilePath;

        PlayerList players = readPlayers(inFilePath);
        cout<< "Data grabbed from file\n";

        printReport(outFilePath, players);


        // Ask if the user wants to test again
        cout << "Do you wish to test another [y/n]?";
        cin >> restart;
        if (towlower(restart) != 'y') break; // If the user enters anything other than y, break out of the infinite loop to end the program
        
    }
    return 0;
}   