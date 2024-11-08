#pragma once

#include <gtest/gtest.h>
#include "Report.h"

TEST(TestReport, TestReportCreation) {
    Report report(1, 100, "Spam");
    
    EXPECT_EQ(report.getReportId(), 1);
    EXPECT_EQ(report.getReportedUserId(), 100);
    EXPECT_EQ(report.getReason(), "Spam");
    EXPECT_EQ(report.getStatus(), "Pending");
    EXPECT_FALSE(report.getTimeCreate().empty());
}

TEST(TestReport, TestFileReport) {
    Report report(1, 100, "Spam");
    
    report.fileReport("Inappropriate content");
    
    EXPECT_EQ(report.getStatus(), "Filed");
}
TEST(TestReport, TestGetTimeCreate) {
    Report report(1, 100, "Inappropriate content");
    string timeCreated = report.getTimeCreate();
    EXPECT_EQ(timeCreated.length(), 25);
}