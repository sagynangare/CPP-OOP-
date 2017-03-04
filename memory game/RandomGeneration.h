//#include "stdafx.h"
#include<time.h>
#include<iostream>
#include<conio.h>
/*
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif*/

using namespace std;
class RandomGeneration
{
    int Low,High;
public:
    RandomGeneration();
    void SetTimerSeed();
    int DrawRandomNumber();
    int GetHigh();
    int GetLow();

};
RandomGeneration ::RandomGeneration()
{
    Low = 1;
    High = 100;

}
void RandomGeneration :: SetTimerSeed()
{
    time_t SeedTime;
    struct tm SeedDate;
    SeedTime = time(0);
    SeedDate = *localtime(&SeedTime);
    int FinalSeed = SeedTime + SeedDate.tm_mday + (SeedDate.tm_mon+1) + (SeedDate.tm_year+1900);
    srand((unsigned int) FinalSeed);
}
int RandomGeneration :: DrawRandomNumber()
{
    int Interval = GetHigh() - GetLow() + 1;
    int RandomOffset = rand()%Interval;
    int RandomNumber = GetLow() + RandomOffset;
    return RandomNumber;
}
int RandomGeneration :: GetHigh()
{
    return High;

}
int RandomGeneration :: GetLow()
{
    return Low;
}
