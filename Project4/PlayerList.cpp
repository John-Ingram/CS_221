// John Ingram|November 14 2020|CS 221
// This file implements a sorted BinaryTree of BaseballPlayer objects.
#include "BaseballPlayer.h"
#include "PlayerList.h"
#include <iomanip>

//Private 

// returns the sum of batting averages under 'n'
float PlayerList::battingAverageSum(Node *n)
{
    if (n == NULL) return 0;
    return battingAverageSum(n->left) + battingAverageSum(n->right) + n->data.getBattingAverage();
}

// removes all nodes from the tree. 
// The parameter should only be used for recursion, hence the wrapper method free()
void PlayerList::deleteNodes(Node *n) 
{
    if (n == NULL) return; // if the tree is already empty

    // make sure left and right are cleared
    if (n->left != NULL)
    {
        deleteNodes(n->left);
    }
    if (n->right != NULL)
    {
        deleteNodes(n->right);
    }

    delete n;
    listSize = 0;
}

// private insert for recursion
int PlayerList::insertRecursive(Node *&n, BaseballPlayer &playerData)
{
    Node *temp;
    int compareValue;
    temp            = new Node;
    temp->data      = playerData;
    temp->right     = NULL;
    temp->left      = NULL;

    if(n == NULL)
    {
        n = temp;
        if(this->root == NULL) this->root = n;
        return 0;
    }

    compareValue = n->data.compare(playerData);

    if (compareValue == 0) 
    {
        return 1; // inserting players with the same name is not allowed
    }
    if (compareValue < 0 )
    {
        return insertRecursive(n->left, playerData);
    }else
    {
        return insertRecursive(n->right, playerData);
    }
}

// display for recursion
void PlayerList::displayRecursive(std::ostream &stream, Node *n, bool reverse)
{
    if(reverse)
    {
        if(n != NULL)
        {
            displayRecursive(stream, n->right, reverse);

            stream << std::setw(18) << (n->data.getLastName() +", " + n->data.getFirstName() + " ") << ":";
            stream << std::setw(11) << n->data.getBattingAverage() << std::setw(11) << n->data.getOPS() << std::endl;

            displayRecursive(stream, n->left, reverse);
        }

    }else
    {
        if(n != NULL)
        {
            displayRecursive(stream, n->left, reverse);

            stream << std::setw(18) << (n->data.getLastName() +", " + n->data.getFirstName() + " ") << ":";
            stream << std::setw(11) << n->data.getBattingAverage() << std::setw(11) << n->data.getOPS() << std::endl;

            displayRecursive(stream, n->right, reverse);
        }
    }
}

//Public
//default constructor
PlayerList::PlayerList()
{
    root        = NULL;
    listSize    = 0;
}

//default destructor
PlayerList::~PlayerList()
{
    free();
}

//Add a player to the tree
void PlayerList::insert(BaseballPlayer &playerData)
{
    listSize+= (-1 * insertRecursive(root, playerData)) + 1; //math should be quicker than an if statement
}

//check if the tree is empty
bool PlayerList::isEmpty()
{
    return root == NULL;
}

// returns size of the list
int PlayerList::count()
{
    return listSize;
}

// Returns the average off all batting averages in the list
float PlayerList::getTeamBattingAverage()
{
    return battingAverageSum(root) / (float) listSize;
}

// delete every node in the tree, and set the root to NULL
void PlayerList::free()
{
    deleteNodes(this->root);
    root = NULL;
    listSize = 0;
}

void PlayerList::display(std::ostream &stream, bool reverse)
{
    displayRecursive(stream, root, reverse);   
}
