// John Ingram|September 26 2020|CS 221
// This header file implements a sorted doubly linked list of BaseballPlayer objects.
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
    Node *temp      = new Node;
    temp->data      = playerData;
    temp->next      = NULL;
    temp->previous  = NULL;

    if (head == NULL) // is this the first Node in the list?
    {
        head    = temp;
        current = temp;
        tail    = temp;
    }else
    {
        // iterate through the list and check where to put the new node
        this->reset();
        do 
        {
            if (current == NULL) //have to check if i've reached the end of the list first to avoid calling an undefined operator on NULL
            {
                temp->previous = tail;
                tail = temp;
                break;
    
            } else if (current->data <= temp->data)
            {
                temp->previous = current->previous;
                temp->next = current;
                current->previous = temp;
                break;
            }
            this->getNext();
        } while(true);
        
        // tail->next = temp;  //move this Node to the back of the list
        // tail = tail->next;  //set the tail of the list to the new pointer at the back of the list
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

//check if there is a node before 'current'
bool PlayerList::hasPrevious()
{
    return current->previous != NULL;
}

// sets 'current' to the begining of the list
void PlayerList::reset()
{
    current = head;
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
    current = current->previous;
    dataCopy = current->data;
    return dataCopy;

}
