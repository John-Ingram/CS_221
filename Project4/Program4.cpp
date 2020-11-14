// John Ingram|November 14 2020|CS 221
// This program creates a list of BaseballPlayer objects from a file, puts them into a PlayerList, 
// and then outputs some data about the players.
// This program was compiled using gcc version 9.3.0 (Ubuntu 9.3.0-10ubuntu2) using g++ and the supplied makefile.
// it is a modefied version of the program used for project 3

#include "PlayerList.h"
#include <fstream>
#include <iomanip>

using namespace std;

// Prints the report on the player data in 'players' to stream
void printReport(PlayerList &players, ostream &stream,  bool reverse = false)
{
    stream << "BASEBALL TEAM REPORT --- "<< players.count() << " PLAYERS FOUND IN FILE\n";
    stream << "OVERALL BATTING AVERAGE is " << setprecision(3) << players.getTeamBattingAverage() << "\n\n";
    stream << setw(18) << "PLAYER NAME " << ":" << setw(11) << "AVERAGE" << setw(11) << "OPS"<<endl;
    stream << "---------------------------------------------\n";
    players.display(stream, reverse);
    stream << "---------------------------------------------\n";
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
            output.insert(*player);
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
    ofstream outFile;

    // Welcome text
    cout << "Welcome to the baseball team statistics test program.\n";
    cout << "This program reads in player data from a file, and outputs\n";
    cout << "it's results to a different file\n";
    cout << "When prompted enter the input and output file paths.\n";

    //Start infinate loop to repeat test if desired
    string inFilePath, outFilePath;
    char wantToDelete = 'n';
    // Prompt
    cout << "\n\nPlease enter the path to your input file: ";
    cin >> inFilePath;
    cout << "\n\nPlease enter the path to your output file: ";
    cin >> outFilePath;

    PlayerList players = readPlayers(inFilePath);
    cout << "Data grabbed from file " << inFilePath << "\n";
    outFile.open(outFilePath, std::ofstream::out);
    printReport(players, outFile);
    outFile.close();
    cout << "Report written to " << outFilePath << "\n\n";

    printReport(players, cout, true);

    cout << "Testing Complete. The new version of your list has been added to the report file." << endl;

    return 0;
}   