// John Ingram|September 26 2020|CS 221
// This header file implements the Baseball player object.

#include "BaseballPlayer.h"

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
string BaseballPlayer::getFirstName()
{
    return this->firstname;
}

string BaseballPlayer::getLastName()
{
    return lastname;
}

int BaseballPlayer::getPlateAppearances()
{
    return statistics[0];
}

int BaseballPlayer::getAtBats()
{
    return this->statistics[1];
}

int BaseballPlayer::getSingles()
{
    return this->statistics[2];
}

int BaseballPlayer::getDoubles()
{
    return this->statistics[3];
}

int BaseballPlayer::getTriples()
{
    return this->statistics[4];
}

int BaseballPlayer::getHomeRuns()
{
    return this->statistics[5];
}

int BaseballPlayer::getWalks()
{
    return this->statistics[6];
}

int BaseballPlayer::getHitByPitch()
{
    return this->statistics[7];
}

// This method is used by both getBattingAverage and getOnBasePercentage,
// It does not technically need to be public, but I figured that it may be useful to a user.
int BaseballPlayer::getHits()
{
    return this->getSingles() + this->getDoubles() + this->getTriples() + this->getHomeRuns();
}
// Calculate batting average
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

float BaseballPlayer::getOPS()
{
    return this->getOnBasePercentage() + this->getSluggingPercentage();
}

bool BaseballPlayer::operator <=(const BaseballPlayer& rightBP)
{
    return (this->lastname < rightBP.lastname || 
            (this->lastname == rightBP.lastname && this->firstname < rightBP.firstname));
}
