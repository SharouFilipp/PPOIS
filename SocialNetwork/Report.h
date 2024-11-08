#pragma once
#include <string>
using namespace std;

class Report {
public:
    Report(int reportId, int reportedUserId, string reason);
    
    void fileReport(string details);
    int getReportId();
    int getReportedUserId();
    string getReason();
    string getStatus();  
    string getTimeCreate();
private:
    int reportId;     
    int reportedUserId; 
    string reason;
    string status; 
    string timeCreate; 
};