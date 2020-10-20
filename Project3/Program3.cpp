// John Ingram|October 19 2020|CS 221
// This program creates a list of BaseballPlayer objects from a file, puts them into a PlayerList, 
// and then outputs some data about the players.
// This program was compiled using gcc version 9.3.0 (Ubuntu 9.3.0-10ubuntu2) using g++ and the supplied makefile.
// it is a modefied version of the program used for project 2

#include "PlayerList.h"
#include <fstream>
#include <iomanip>

using namespace std;

// Prints the report on the player data in 'players' to a text file at 'path'
void printReport(string path, PlayerList &players, bool forwards = true)
{
    ofstream outFile;
    outFile.open(path, std::ofstream::app);
    players.reset(); 

    if (!forwards) // really wish I had a lambda right about now
    {
        players.goToEnd();
        while (players.hasPrevious())
        {
            BaseballPlayer player = players.getPrevious();
            string firstLast = player.getLastName();
            firstLast += ", " + player.getFirstName() + " "; 
            outFile << setw(18) << firstLast << ":" << setw(11) << player.getBattingAverage() << setw(11) << player.getOPS() << endl;
        }
    }else
    {
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
        outFile << "---------------------------------------------\n";
    }
    outFile.close();   
    players.reset(); 
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
    string inFilePath, outFilePath;
    char wantToDelete = 'n';
    // Prompt
    cout << "\n\nPlease enter the path to your input file: ";
    cin >> inFilePath;
    cout << "\n\nPlease enter the path to your output file: ";
    cin >> outFilePath;

    PlayerList players = readPlayers(inFilePath);
    cout << "Data grabbed from file " << inFilePath << "\n";
    printReport(outFilePath, players);
    cout << "Report written to " << outFilePath << "\n";

    while (true)
    {
        // Ask if the user wants to test again
        cout << "Do you wish delete any players from the list [y/n]?";
        cin >> wantToDelete;
        if (towlower(wantToDelete) != 'y') break; // If the user enters anything other than y, break out of the infinite loop to end the program
        string firstName, lastName;
        cout << "Enter the first and last name of the player: ";
        cin >> firstName;
        cin >> lastName;
        players.deletePlayer(firstName, lastName);
    }
    printReport(outFilePath, players);
    printReport(outFilePath, players, false);
    cout << "Testing Complete. The new version of your list has been added to the report file." << endl;

    return 0;
}   