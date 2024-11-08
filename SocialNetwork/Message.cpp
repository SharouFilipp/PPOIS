#include "Message.h"
#include <ctime>

Message::Message(int messageId, int senderId, int geterId, string content)
{
    this->messageId = messageId;
    this->sendId=senderId;
    this->geterId = geterId;
    this->content=content;
    this->status = false;

    time_t now = time(0);
    timeCreate = ctime(&now);
}

void Message::statusRead() {
    status = true;
}

void Message::deleteMessage() {
    content.clear();
    status = false;
}
int Message::getMessageId(){return messageId;}
int Message::getSenderId(){return sendId;}
int Message::getGetterId(){return geterId;}
string Message::getContent(){return content;}
bool Message::getStatus(){return status;}