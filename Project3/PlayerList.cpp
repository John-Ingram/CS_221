// John Ingram|October 19 2020|CS 221
// This file implements a sorted doubly linked list of BaseballPlayer objects.
#include "BaseballPlayer.h"
#include "PlayerList.h"

//Private 

// returns the sum of batting averages starting from 'n'
float PlayerList::battingAverageSum(Node *n)
{
    if (n == tail) return n->data.getBattingAverage();
    return n->data.getBattingAverage() + battingAverageSum(n->next);
}

// removes all nodes from the list. 
// The parameter should only be used for recursion, hence the wrapper method clearList()
void PlayerList::deleteNodes(Node *n = NULL) 
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

//Public
//default constructor
PlayerList::PlayerList()
{
    head        = NULL;
    tail        = NULL;
    current     = NULL;
    listSize    = 0;
}

//Add a player to the linked list. Note that adding players will "reset" the ADT to the beginning of the list
void PlayerList::add(BaseballPlayer &playerData)
{
    Node *temp, *l, *r;
    bool found;

    temp            = new Node;
    temp->data      = playerData;
    temp->next      = NULL;
    temp->previous  = NULL;
    l = NULL;
    r = head;
    found = false;


    if (head == NULL) // is this the first Node in the list?
    {
        head    = temp;
        current = temp;
        tail    = temp;
    }else
    {
        while(!found && r != NULL)
        {
            if(r->data.compare(temp->data) > 0)
            {
                found = true;
            }else
            {
                l = r;
                r = r->next;
            }   
        }
        if(l == NULL) // found at beginning of list
        {
            temp->next = head;
            head->previous = temp;
            head = temp;
        }else
        {
            l->next = temp;
            temp->previous = l;
            temp->next = r;
            if(r != NULL)
            {
            r->previous = temp;
            }else tail = temp;
        }
        
    }

    listSize++;
}




//check if the list is false
bool PlayerList::isEmpty()
{
    return head == NULL;
}

// returns size of the list
int PlayerList::size()
{
    return listSize;
}

// Returns the average off all batting averages in the list
float PlayerList::getTeamBattingAverage()
{
    return battingAverageSum(head) / (float) listSize;
}

// delete every node in the list
void PlayerList::clearList()
{
    deleteNodes();
    listSize = 0;
}

//check if there is a Node that hasn't been "gotten"
bool PlayerList::hasNext()
{
    return current != NULL;
}

//this is implemented the same as hasNext, but should exist for usability
bool PlayerList::hasPrevious()
{
    return current != NULL;
}

// sets 'current' to the begining of the list
void PlayerList::reset()
{
    current = head;
}

// sets 'current' to the end of the list
void PlayerList::goToEnd()
{
    current = tail;
}

// removes the player from the list if found. otherwise returns 1
bool PlayerList::deletePlayer(std::string firstName, std::string lastname)
{
    this->reset();
    bool found = false;
    Node *l,*r;
    l = NULL;
    r = head;
    while (!found && r != NULL)
    {
        if (r->data.getFirstName() == firstName && r->data.getLastName() == lastname)
        {
            found = true;
        }else
        {
            l = r;
            r = r->next;
        }
    }

    if (found)
    {
        if(r == tail)
        {
            r->previous->next = NULL;
            tail = r->previous;
            delete r;
            return 0;
        }else if (r == head)
        {
            r->next->previous = NULL;
            head = r->next;
            delete r;
            return 0;
        }
        r = r->next;
        delete l->next;
        l->next = r;
        r->previous = l;
        return 0;
    }else
    {
        return 1;
    }
    
    
    
}

// return 'current''s data and advance current by one 
BaseballPlayer PlayerList::getNext()
{
    BaseballPlayer dataCopy;
    dataCopy = current->data;
    current = current->next;
    return dataCopy;
}    

// move 'current' back by one and return it's data
BaseballPlayer PlayerList::getPrevious()
{
    BaseballPlayer dataCopy;
    dataCopy = current->data;
    current = current->previous;
    return dataCopy;

}
