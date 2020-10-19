// John Ingram|October 19 2020|CS 221
// This header file defines a BaseballPlayer object to handle data about baseball players.
#ifndef  __BASEBALLPLAYER_H_
#define __BASEBALLPLAYER_H_

#include <iostream>
#include <string>
class BaseballPlayer
{
private:
    std::string firstname, lastname;
    int statistics[8];
public:
    BaseballPlayer();
    void setData(std::istream &data);
    std::string getFirstName();
    std::string getLastName();
    int getPlateAppearances();
    int getAtBats();
    int getSingles();
    int getDoubles();
    int getTriples();
    int getHomeRuns();
    int getWalks();
    int getHitByPitch();
    int getHits();
    float getBattingAverage();
    float getOnBasePercentage();
    float getSluggingPercentage();
    float getOPS();
    bool operator <=(const BaseballPlayer& rightBP);
};
#endif