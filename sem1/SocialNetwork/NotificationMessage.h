#pragma once
#include <string>
#include "Message.h"
using namespace std;

class NotificationMessage : public Message {
public:
    NotificationMessage(int notificationId, int userId,string сontent);
    string getType();
    int getNotificationId();
private:
    int notificationId;
    string type;
};
