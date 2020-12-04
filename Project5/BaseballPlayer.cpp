// John Ingram|October 19 2020|CS 221
// This header file implements the Baseball player object.
// Additional comments added Deccember 3 2020

#include "BaseballPlayer.h"
#include <stdio.h>
#include <string.h>
using namespace std;

// Default constructor
BaseballPlayer::BaseballPlayer()
{
    this->firstname = "unknown";
    this->lastname = "unknown";
    // set all statistics to zero
    for (int i = 0; i < 8; i++)
    {
        this->statistics[0] = 0;
    }
}

// Set Data about the BaseballPlayer from 'data'
// expected input format is: firstname lastname plateappearances atbats singles doubles triples homeruns walks hitbypitch
void BaseballPlayer::setData(istream &data) 
{
    data >> this->firstname;
    data >> this->lastname;
    for (int i = 0; i < 8; i++)
    {
        data >> this->statistics[i];
    }
}
// getters for BaseballPlayer data. These will all be very similar


// returns the player's first name
string BaseballPlayer::getFirstName()
{
    return this->firstname;
}

// returns the player's last name
string BaseballPlayer::getLastName()
{
    return lastname;
}

// returns the player's plate appearances
int BaseballPlayer::getPlateAppearances()
{
    return statistics[0];
}

// returns the player's at bats
int BaseballPlayer::getAtBats()
{
    return this->statistics[1];
}

// returns the player's singles
int BaseballPlayer::getSingles()
{
    return this->statistics[2];
}

// returns the player's doubles
int BaseballPlayer::getDoubles()
{
    return this->statistics[3];
}

// returns the player's Triples
int BaseballPlayer::getTriples()
{
    return this->statistics[4];
}

// returns the player's home runs
int BaseballPlayer::getHomeRuns()
{
    return this->statistics[5];
}

// returns the player's walks
int BaseballPlayer::getWalks()
{
    return this->statistics[6];
}

// returns the player's hit by pitch
int BaseballPlayer::getHitByPitch()
{
    return this->statistics[7];
}

// This method is used by both getBattingAverage and getOnBasePercentage,
// It does not technically need to be public, but I figured that it may be useful to a user.
// returns the player's hits
int BaseballPlayer::getHits()
{
    return this->getSingles() + this->getDoubles() + this->getTriples() + this->getHomeRuns();
}

// returns the player's batting average
float BaseballPlayer::getBattingAverage()
{
    //Handle a zero value for atbats before we try to divide by it
    float atBats = this->getAtBats();

    if (atBats == 0)
    {
        return 0;
    }
    
    return (float) this->getHits()/ atBats;
}

// returns the player's On Base Percentage
float BaseballPlayer::getOnBasePercentage()
{
    //Handle a zero value for plate appearences before we try to divide by it
    float pas = this->getPlateAppearances();
    if (pas == 0)
    {
        return 0;
    }
    
    return (float)(this->getHits()+this->getWalks()+this->getHitByPitch()) / pas;
}

// returns the player's SluggingPercentage
float BaseballPlayer::getSluggingPercentage()
{
    //Handle a zero value for atbats before we try to divide by it
    float atBats = this->getAtBats();

    if (atBats == 0)
    {
        return 0;
    }

    return (float)(this->getSingles() + (2 * this->getDoubles()) + 
        (3 * this->getTriples()) + (4 * this->getHomeRuns())) / atBats;
}

// returns the player's OPS
float BaseballPlayer::getOPS()
{
    return this->getOnBasePercentage() + this->getSluggingPercentage();
}

// compare BaseballPlayer objects by first and last name
// use as you would std::string::compare()
int BaseballPlayer::compare(const BaseballPlayer& rightBP) 
{
    string leftName = this->lastname + this->firstname;
    string rightName = rightBP.lastname + rightBP.firstname;
    
    return leftName.compare(rightName);
}
