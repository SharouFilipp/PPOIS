
#include "NotificationMessage.h"

NotificationMessage::NotificationMessage(int notificationId,int userId, string content): Message(notificationId, userId, userId, content)
{
    this->notificationId = notificationId;   
    this->content=content;
    this->type = "Notification";
}

string NotificationMessage::getType(){return type;}
int NotificationMessage::getNotificationId(){return notificationId;}