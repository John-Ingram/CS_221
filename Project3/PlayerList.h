
// John Ingram|October 19 2020|CS 221
// This header file defines an unsorted linked list of BaseballPlayer objects, as well as the Node class needed to make it work.
#ifndef  __PLAYERLIST_H_
#define __PLAYERLIST_H_
#include "BaseballPlayer.h"

class Node
{
    // making both of these public because I am treating this more like a struct than a class
    public:
        BaseballPlayer data;
        Node *next, *previous;
};

class PlayerList
{
private:
    Node *head, *tail, *current;
    int listSize;
    float battingAverageSum(Node *n);
    void deleteNodes(Node *n);
    void insertBetween(Node *content, Node *left, Node *right);

public:
    PlayerList();
    void add(BaseballPlayer &playerData);
    bool isEmpty();
    int size();
    float getTeamBattingAverage();
    void clearList();
    bool hasNext();
    bool hasPrevious();
    void reset();
    void goToEnd();
    bool deletePlayer(std::string firstName, std::string lastName);
    BaseballPlayer getNext();
    BaseballPlayer getPrevious();
};
#endif
