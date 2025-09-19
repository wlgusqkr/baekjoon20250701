#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>

using namespace std;

int N, OneTeamGoalCount, TwoTeamGoalCount, teamNumber, OneTeamTimeHourResult, TwoTeamTimeSecondResult, TwoTeamTimeHourResult, OneTeamTimeSecondResult, prevHour, prevSecond;

string ITime, prevTime = "00:00";

int ITimeHour, ITimeSecond;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    cin >> teamNumber >> ITime;
    prevHour = stoi(ITime.substr(0, 2));
    prevSecond = stoi(ITime.substr(3, 2));
    
    if(teamNumber == 1) OneTeamGoalCount++;
    else TwoTeamGoalCount++;
    
    for(int i = 0 ; i < N - 1; i++) {
        cin >> teamNumber >> ITime;
        ITimeHour = stoi(ITime.substr(0, 2));
        ITimeSecond = stoi(ITime.substr(3, 2));
        
        if(teamNumber == 1) {
            OneTeamGoalCount++;
            
            if(OneTeamGoalCount - 1 > TwoTeamGoalCount) {
                OneTeamTimeHourResult += ITimeHour - prevHour;
                OneTeamTimeSecondResult += ITimeSecond - prevSecond;
            } else if (OneTeamGoalCount - 1 < TwoTeamGoalCount) {
                TwoTeamTimeHourResult += ITimeHour - prevHour;
                TwoTeamTimeSecondResult += ITimeSecond - prevSecond;
            }
            
        } else {
            TwoTeamGoalCount++;
            
            if(OneTeamGoalCount > TwoTeamGoalCount - 1) {
                OneTeamTimeHourResult += ITimeHour - prevHour;
                OneTeamTimeSecondResult += ITimeSecond - prevSecond;
            } else if(OneTeamGoalCount < TwoTeamGoalCount - 1) {
                TwoTeamTimeHourResult += ITimeHour - prevHour;
                TwoTeamTimeSecondResult += ITimeSecond - prevSecond;
            }
        }
        
        prevHour = ITimeHour;
        prevSecond = ITimeSecond;
        
    }
    ITimeHour = 48;
    ITimeSecond = 0;
    
    if(OneTeamGoalCount  > TwoTeamGoalCount) {
        OneTeamTimeHourResult += ITimeHour - prevHour;
        OneTeamTimeSecondResult += ITimeSecond - prevSecond;
    } else if (OneTeamGoalCount < TwoTeamGoalCount) {
        TwoTeamTimeHourResult += ITimeHour - prevHour;
        TwoTeamTimeSecondResult += ITimeSecond - prevSecond;
    }
        
    while(OneTeamTimeSecondResult < 0) {
        OneTeamTimeHourResult--;
        OneTeamTimeSecondResult += 60;
    }
    
    while(TwoTeamTimeSecondResult < 0) {
        TwoTeamTimeHourResult--;
        TwoTeamTimeSecondResult += 60;
    }
    
    
    while(OneTeamTimeSecondResult >= 60) {
        OneTeamTimeHourResult++;
        OneTeamTimeSecondResult -= 60;
    }

    while(TwoTeamTimeSecondResult >= 60) {
        TwoTeamTimeHourResult++;
        TwoTeamTimeSecondResult -= 60;
    }
    
    printf("%02d:%02d\n", OneTeamTimeHourResult, OneTeamTimeSecondResult);
    printf("%02d:%02d\n", TwoTeamTimeHourResult, TwoTeamTimeSecondResult);
    
}
