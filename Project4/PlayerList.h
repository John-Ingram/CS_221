
// John Ingram|November 14 2020|CS 221
// This header file defines a BinaryTree of BaseballPlayer objects, as well as the Node class needed to make it work.
#ifndef  __PLAYERLIST_H_
#define __PLAYERLIST_H_
#include "BaseballPlayer.h"

class PlayerList;

class Node
{
    // making both of these public because I am treating this more like a struct than a class
    BaseballPlayer data;
    Node *left, *right;
    friend PlayerList;

};

class PlayerList
{
private:
    Node *root;
    int listSize;
    float battingAverageSum(Node *n);
    void deleteNodes(Node *n);
    void displayRecursive(std::ostream &stream, Node *n, bool reverse);
    int insertRecursive(Node *&n, BaseballPlayer &playerData);

public:
    PlayerList();
    ~PlayerList();
    void insert(BaseballPlayer &playerData);
    bool isEmpty();
    int count();
    float getTeamBattingAverage();
    void free();
    void display(std::ostream &stream, bool reverse = false);
};
#endif
