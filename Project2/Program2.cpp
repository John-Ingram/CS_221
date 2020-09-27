// John Ingram|September 26 2020|CS 221
// This program creates a list of BaseballPlayer objects from a file, puts them into a PlayerList, 
// and then outputs some data about the players.
// This program was compiled using gcc version 9.3.0 (Ubuntu 9.3.0-10ubuntu2) using g++ and default compiler flags.

#include "PlayerList.h"
#include <fstream>
#include <iomanip>

using namespace std;

// Prints the report on the player data in 'players' to a text file at 'path'
void printReport(string path, PlayerList &players)
{

    ofstream outFile;
    outFile.open(path);

    outFile << "BASEBALL TEAM REPORT --- "<< players.size() << " PLAYERS FOUND IN FILE\n";
    outFile << "OVERALL BATTING AVERAGE is " << setprecision(3) << players.getTeamBattingAverage() << "\n\n";
    outFile << setw(18) << "PLAYER NAME " << ":" << setw(11) << "AVERAGE" << setw(11) << "OPS"<<endl;
    outFile << "---------------------------------------------\n";
    while (players.hasNext())
    {
        BaseballPlayer player = players.getNext();
        string firstLast = player.getLastName();
        firstLast += ", " + player.getFirstName() + " "; 
        outFile << setw(18) << firstLast << ":" << setw(11) << player.getBattingAverage() << setw(11) << player.getOPS() << endl;
    }
    outFile.close();    
}

// Counts the lines in the file at 'path'
int getLineCount(string path)
{
    int output = 0;
    string trash;
    ifstream file(path);
    if (file.is_open())
    {   
        while (getline(file, trash))
        {
            output++;
        }
        file.close();  
    }
    return output;
}

// Reads player data from an input file into a PlayerList
PlayerList readPlayers(string path)
{
    int lineCount;
    BaseballPlayer *player = new BaseballPlayer();
    PlayerList output;
    ifstream inFile(path);
    lineCount = getLineCount(path);
    if (inFile.is_open())
    {   
        for(size_t i = 0; i < lineCount; i++)
        {
            player->setData(inFile);
            output.add(*player);
        }
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
        cout << "Data grabbed from file " << inFilePath << "\n";
        printReport(outFilePath, players);
        cout << "Report written to " << outFilePath << "\n";

        // Ask if the user wants to test again
        cout << "Do you wish to test another [y/n]?";
        cin >> restart;
        if (towlower(restart) != 'y') break; // If the user enters anything other than y, break out of the infinite loop to end the program
        
    }
    return 0;
}   