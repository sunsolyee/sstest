#ifndef MISSION_H
#define MISSION_H

class Mission
{
public:
    Mission();
    bool lenghtMission;
    bool growthMission;
    bool poisonMission;
    bool gateMission;
    bool speedMission;

    bool clearLengthMission(int n);
    bool clearGrowthMission(int n);
    bool clearPoisonMission(int n);
    bool clearGateMission(int n);
    bool clearSpeedMission(int n);
};

#endif