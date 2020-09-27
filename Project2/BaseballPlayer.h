// John Ingram|September 26 2020|CS 221
// This header file defines a BaseballPlayer object to handle data about baseball players.

#include <iostream>
#include <string>

class BaseballPlayer
{
private:
    // Field variables
    std::string firstname, lastname;
    int statistics [8]; //integer statistics in this order: plateappearances atbats singles doubles triples homeruns walks hitbypitch


public:
    // Default constructor
    BaseballPlayer()
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
    void setData(std::istream &data) 
    {
        data >> this->firstname;
        data >> this->lastname;
        for (int i = 0; i < 8; i++)
        {
            data >> this->statistics[i];
        }
    }
    // getters for BaseballPlayer data. These will all be very similar
    std::string getFirstName()
    {
        return this->firstname;
    }
    
    std::string getLastName()
    {
        return this->lastname;
    }

    int getPlateAppearances()
    {
        return this->statistics[0];
    }
    
    int getAtBats()
    {
        return this->statistics[1];
    }

    int getSingles()
    {
        return this->statistics[2];
    }

    int getDoubles()
    {
        return this->statistics[3];
    }

    int getTriples()
    {
        return this->statistics[4];
    }

    int getHomeRuns()
    {
        return this->statistics[5];
    }

    int getWalks()
    {
        return this->statistics[6];
    }

    int getHitByPitch()
    {
        return this->statistics[7];
    }

    // This method is used by both getBattingAverage and getOnBasePercentage,
    // It does not technically need to be public, but I figured that it may be useful to a user.
    int getHits()
    {
        return this->getSingles() + this->getDoubles() + this->getTriples() + this->getHomeRuns();
    }
    // Calculate batting average
    float getBattingAverage()
    {
        //Handle a zero value for atbats before we try to divide by it
        float atBats = this->getAtBats();
    
        if (atBats == 0)
        {
            return 0;
        }
        
        return (float) this->getHits()/ atBats;
    }

    float getOnBasePercentage()
    {
        //Handle a zero value for plate appearences before we try to divide by it
        float pas = this->getPlateAppearances();
        if (pas == 0)
        {
            return 0;
        }
        
        return (float)(this->getHits()+this->getWalks()+this->getHitByPitch()) / pas;
    }

    float getSluggingPercentage()
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

    float getOPS()
    {
        return this->getOnBasePercentage() + this->getSluggingPercentage();
    }

};
