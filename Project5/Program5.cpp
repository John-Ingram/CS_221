// John Ingram|December 3 2020|CS 221
// This program creates a list of BaseballPlayer objects from a file, puts them into an array, 
// and then outputs some data about the players sorted by batting average.
// note that any number of players is supported (provided the machine has enough ram)
// This program was compiled using gcc version 9.3.0 (Ubuntu 9.3.0-10ubuntu2) using g++ and the supplied makefile.
// it is a heavily modified version of the program used for project 4

#include "BaseballPlayer.h"
#include <fstream>
#include <iomanip>

using namespace std;

// Prints the report on the player data in 'players', an array of players 
// to 'stream', an ostream like cout. 'listSize' is the count of players in 'players'
void printReport(BaseballPlayer players[], ostream &stream, int listSize)
{
    stream << "BASEBALL TEAM REPORT --- "<< listSize << " PLAYERS FOUND IN FILE\n";
    stream << setw(18) << "PLAYER NAME " << ":" << setw(11) << "AVERAGE" << setw(11) << "OPS"<<endl;
    stream << "---------------------------------------------\n" << setprecision(3) << fixed;
    for(size_t i = 0; i < listSize; i++)
    {
        string playerName;
        playerName = players[i].getLastName() + ", " + players[i].getFirstName() + " ";
        stream << setw(18) << playerName << ":" << setw(11) << players[i].getBattingAverage();
        stream << setw(11) << players[i].getOPS() << endl;
    }
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

// Reads player data from an input file into The list of players
BaseballPlayer * readPlayers(string path)
{
    int lineCount;
    BaseballPlayer *player = new BaseballPlayer();
    ifstream inFile(path);
    lineCount = getLineCount(path);
    BaseballPlayer *list{ new BaseballPlayer[lineCount]{}};
    if (inFile.is_open())
    {   
        for(size_t i = 0; i < lineCount; i++)
        {
            player->setData(inFile);
            list[i] = *player;
        }
        inFile.close();  
    }
    else
    {
        cout << "Unable to open file";    
        exit(1);
    } 
    return list;
}

// Merges two sorted arrays of baseball players ('left' and 'right') into one sorted array
// 'leftSize' and 'rightSize' are the sizes of their repective array
BaseballPlayer * merge(BaseballPlayer left[], int leftSize, BaseballPlayer right[], int rightSize)
{
    int listSize, lpos, rpos;
    // is the left list empty?
    if(leftSize == 0)
    {
        return right;
    }
    // is the right list empty?
    if(rightSize == 0)
    {
        return left;
    }
    
    listSize = leftSize + rightSize;
    lpos = 0;
    rpos = 0;
    BaseballPlayer *result{ new BaseballPlayer[listSize]{} };
    for(size_t i = 0; i < listSize; i++)
    {
        if(lpos == leftSize) // is left empty?
        {
            result[i] = right[rpos];
            rpos++;
        }else if(rpos == rightSize) // is right empty
        {
            result[i] = left[lpos];
            lpos++;
        }else if(left[lpos].getBattingAverage() >= right[rpos].getBattingAverage())
        {
            result[i] = left[lpos];
            lpos ++;
        }else if(right[rpos].getBattingAverage() > left[lpos].getBattingAverage())
        {
            result[i] = right[rpos];
            rpos ++;
        }
    }
    return result;
    
}

// Sorts 'players', an array of baseball players of size 'listSize' by batting average(high to low)
BaseballPlayer * mergeSort(BaseballPlayer players[], int listSize)
{
    int leftSize, rightSize;
    if(listSize <= 1) // base case
    {
        return players;
    }
    leftSize = listSize/2;
    rightSize = leftSize;

    if(leftSize + rightSize != listSize)
    {
        leftSize++;
    }
    
    BaseballPlayer *left{ new BaseballPlayer[leftSize]{} };
    BaseballPlayer *right{ new BaseballPlayer[rightSize]{} };

    for(size_t i = 0; i < listSize; i++) // populate left and right list
    {
        if(i < leftSize)
        {
            left[i] = players[i];
        }else
        {
            right[i-leftSize] = players[i];
        }
    }
    
    
    return merge(mergeSort(left, leftSize), leftSize, mergeSort(right, rightSize), rightSize);
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
    // Prompt
    cout << "\n\nPlease enter the path to your input file: ";
    cin >> inFilePath;
        cout << "\n\nPlease enter the path to your output file: ";
    cin >> outFilePath;

    BaseballPlayer *players = readPlayers(inFilePath);
    int listSize = getLineCount(inFilePath);
    cout << "Data grabbed from file " << inFilePath << "\n";
    players = mergeSort(players, listSize);
    outFile.open(outFilePath, std::ofstream::out);

    printReport(players, cout, listSize);
    printReport(players, outFile, listSize);

    outFile.close();
    cout << "Testing Complete. The list displayed above has also been printed to your Outfile." << endl;

    return 0;
}   