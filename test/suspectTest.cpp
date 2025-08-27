#include <gtest/gtest.h>
#include "Suspect.h"

TEST(SuspectTests, ConstructorWorks) {
    Suspect s("Lenora", "Elegant", "Reading");
    EXPECT_EQ(s.getName(), "Lenora");
    EXPECT_EQ(s.getDescription(), "Elegant");
    EXPECT_EQ(s.getAlibi(), "Reading");
}

TEST(SuspectTests, TalkToSuspectPrintsLenoraCorrectly) {
    Suspect lenora(
        "Lenora Grimshire",
        "is an elegant woman in her early 50s. She has smooth chestnut-brown hair pinned up neatly with sparkling diamond clips. Her blue silk gown matches her sharp green eyes, and she wears long satin gloves. She moves gracefully, always with perfect posture.",
        "Lenora recalls greeting guests in the ballroom, but feeling dizzy from champagne. Around 1:30, she went to her boudoir, poured wine, and read a book. She drifted asleep until about 2:45, when shouting in the hall woke her suddenly."
        "I bet it was Damian's best friend. He was even more upset than I was about what happened between my husband and his wife."
    );

    testing::internal::CaptureStdout();
    lenora.talkToSuspect(lenora);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Lenora Grimshire"), std::string::npos);
    EXPECT_NE(output.find("elegant woman in her early 50s"), std::string::npos);
    EXPECT_NE(output.find("greeting guests in the ballroom"), std::string::npos);
    EXPECT_NE(output.find("I bet it was Damian's best friend"), std::string::npos);
}