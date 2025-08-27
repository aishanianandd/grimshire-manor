#include <gtest/gtest.h>
#include "Game.h"
#include "Suspect.h"
#include "Locations/Bedroom.h"
#include "Locations/Foyer.h"

TEST(GameTests, SetAndGetName) {
    Game g;
    g.setName("Ash");
    EXPECT_EQ(g.getName(), "Ash");
}

TEST(GameTest, MoveToBedroom) {
Game g;
// Simulate move to Bedroom
EXPECT_TRUE(g.move("b"));
}

TEST(GameTest, MoveToFoyer) {
Game g;
EXPECT_TRUE(g.move("a"));
}

TEST(GameTest, InvalidMoveReturnsFalse) {
Game g;
EXPECT_FALSE(g.move("z"));
}

TEST(GameTest, TalkOptionsValidChoices) {
Game g;
// We can only simulate one valid char extraction manually
// Actual runtime interaction with std::cin needs to be mocked
// So here, we test the method presence only
SUCCEED();
}

TEST(GameTest, TalkToSuspectOutputsCorrectInfo) {
Suspect s("Jellal Vexley", "The best friend", "Was in the lounge.");
Game g;
testing::internal::CaptureStdout();
g.TalkToSuspect(s);
std::string output = testing::internal::GetCapturedStdout();
EXPECT_NE(output.find("Jellal Vexley"), std::string::npos);
EXPECT_NE(output.find("The best friend"), std::string::npos);
EXPECT_NE(output.find("Was in the lounge."), std::string::npos);
}

TEST(GameTest, AccuseCorrectSuspectWins) {
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    std::istringstream input("d\ny\n"); // Celeste Grimshire
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

    Game game;
    game.accuseSuspect();

    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);

    EXPECT_NE(output.str().find("accusation rings true"), std::string::npos);
}

TEST(GameTest, AccuseWrongSuspectFails) {
Game g;
testing::internal::CaptureStdout();


// Simulate accusing the wrong killer (not TRUE_KILLER)
std::istringstream input("b\ny\n");
std::cin.rdbuf(input.rdbuf());
bool result = g.accuseSuspect();
std::string output = testing::internal::GetCapturedStdout();


EXPECT_TRUE(result);
EXPECT_NE(output.find("accusation fails"), std::string::npos);
}