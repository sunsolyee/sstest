#include "Mission.h"

#define clearLength 6 
#define clearGrowth 1
#define clearPoison 1
#define clearGate 1 
#define clearSpeed 210

Mission::Mission() : lenghtMission(false), growthMission(false), poisonMission(false), gateMission(false)
{

}

bool Mission::clearLengthMission(int n) {
    lenghtMission = n >= clearLength;
    return lenghtMission;
}
bool Mission::clearGrowthMission(int n) {
    growthMission = n >= clearGrowth;
    return growthMission;
}
bool Mission::clearPoisonMission(int n) {
    poisonMission = n >= clearPoison;
    return poisonMission;
}
bool Mission::clearGateMission(int n) {
    gateMission = n >= clearGate;
    return gateMission;
}
bool Mission::clearSpeedMission(int n) {
    speedMission = n >= clearSpeed;
    return speedMission;
}