#include <gtest/gtest.h>
#include "Game.h"

TEST(GameTests, SetAndGetName) {
    Game g;
    g.setName("Ash");
    EXPECT_EQ(g.getName(), "Ash");
}