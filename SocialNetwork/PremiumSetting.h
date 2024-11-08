#pragma once
#include "Setting.h"
#include <vector>
#include <string>
using namespace std;

class PremiumSetting : public Setting {
public:
    PremiumSetting(string subscriptionLevel);
    string getLevel();
    void setLevel(string newLevel);
private:
    string subscriptionLevel;
};