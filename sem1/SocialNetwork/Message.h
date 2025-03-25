#pragma once
#include <string>
using namespace std;
class Message {
public:
    Message(int messageId, int senderId, int geterId, string content);
    
    void statusRead();
    void deleteMessage();
    int getMessageId();
    int getSenderId();
    int getGetterId();
    string getContent();
    bool getStatus();
protected:
    int messageId;
    int sendId;
    int geterId;
    string content;
    string timeCreate;
    bool status;
};
