#include <gtest/gtest.h>
#include "Suspect.h"

TEST(SuspectTests, ConstructorWorks) {
    Suspect s("Lenora", "Elegant", "Reading");
    EXPECT_EQ(s.getName(), "Lenora");
    EXPECT_EQ(s.getDescription(), "Elegant");
    EXPECT_EQ(s.getAlibi(), "Reading");
}