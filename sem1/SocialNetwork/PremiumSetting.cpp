#include "PremiumSetting.h"

PremiumSetting::PremiumSetting(string subscriptionLevel): Setting(0)
{
    this->subscriptionLevel = subscriptionLevel;
}
string PremiumSetting::getLevel()
{
    return subscriptionLevel; 
}
void PremiumSetting::setLevel(string newLevel)
{
    subscriptionLevel = newLevel; 
}