// John Ingram|September 26 2020|CS 221
// This header file defines and implements an unsorted linked list of BaseballPlayer objects, as well as the Node class needed to make it work.
#include "BaseballPlayer.h"

class Node
{
    // making both of these public because I am treating this more like a struct than a class
    public:
        BaseballPlayer data;
        struct Node *next;
};

class PlayerList
{
private:
    Node *head, *tail, *current;

    int listSize;

    // returns the sum of batting averages starting from 'n'
    float battingAverageSum(Node *n)
    {
        if (n == tail) return n->data.getBattingAverage();
        return n->data.getBattingAverage() + battingAverageSum(n->next);
    }

    // removes all nodes from the list. 
    // The parameter should only be used for recursion, hence the wrapper method clearList()
    void deleteNodes(Node *n = NULL) 
    {
        if (n == NULL) n = this->head;
        if (n == tail)
        {
            delete tail;
            this->head = NULL;
            tail = NULL;
            return;
        }
        Node *temp = this->head;
        this->head = temp->next;
        delete temp;
        deleteNodes(this->head);
    }

public:
    //default constructor
    PlayerList()
    {
        head = NULL;
        tail = NULL;
        current = NULL;
        listSize = 0;
    }

    //Add a player to the linked list
    void add(BaseballPlayer &playerData)
    {
        Node *temp = new Node;
        temp->data = playerData;
        temp->next = NULL;

        if (head == NULL) // is this the first Node in the list?
        {
            head = temp;
            current = temp;
            tail = temp;
        }else
        {
            tail->next = temp;  //move this Node to the back of the list
            tail = tail->next;  //set the tail of the list to the new pointer at the back of the list
        }
        listSize++;
    }

   

    //check if the list is false
    bool isEmpty()
    {
        return head == NULL;
    }

    // returns size of the list
    int size()
    {
        return listSize;
    }

    // Returns the average off all batting averages in the list
    float getTeamBattingAverage()
    {
        return battingAverageSum(head) / (float) listSize;
    }

    // delete every node in the list
    void clearList()
    {
        deleteNodes();
        listSize = 0;
    }

    //check if there is a Node after current
    bool hasNext()
    {
        return current != NULL;
    }

    // sets 'current' to the begining of the list
    void reset()
    {
        current = head;
    }

    // return 'current''s data and advance current by one 
    BaseballPlayer getNext()
    {
        BaseballPlayer dataCopy;
        dataCopy = current->data;
        current = current->next;
        return dataCopy;
    }    
};
