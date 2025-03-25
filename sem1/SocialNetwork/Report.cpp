#include "Report.h"
#include <iostream>
#include <ctime> 


Report::Report(int reportId, int reportedUserId, string reason)
{
    this->reportId = reportId;
    this->reportedUserId = reportedUserId;
    this->reason = reason;
    this->status = "Pending";   

    time_t now = time(0);
    timeCreate = ctime(&now);
}

void Report::fileReport(string details) {
    cout << "Report filed: " << details << endl;
    status = "Filed";
}

int Report::getReportId(){return reportId; }
int Report::getReportedUserId()  { return reportedUserId; }
string Report::getReason()  { return reason; }
string Report::getStatus()  { return status; }
string Report::getTimeCreate()  { return timeCreate; }