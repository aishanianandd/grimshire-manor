#include "gtest/gtest.h"
#include "Location.h"

// Test fixture for Location-derived classes
class LocationTest : public ::testing::Test {
protected:
    Foyer foyer;
    Bedroom bedroom;
    Kitchen kitchen;
    Library library;
    Office office;
};

// Test that constructors set the correct names
TEST_F(LocationTest, NameInitialization) {
    EXPECT_EQ(foyer.name, "Foyer");
    EXPECT_EQ(bedroom.name, "Bedroom");
    EXPECT_EQ(kitchen.name, "Kitchen");
    EXPECT_EQ(library.name, "Library");
    EXPECT_EQ(office.name, "Office");
}

// Test that constructors set the correct descriptions
TEST_F(LocationTest, DescriptionInitialization) {
    EXPECT_FALSE(foyer.description.empty());
    EXPECT_FALSE(bedroom.description.empty());
    EXPECT_FALSE(kitchen.description.empty());
    EXPECT_FALSE(library.description.empty());
    EXPECT_FALSE(office.description.empty());
}

// Test that options are initialized properly
TEST_F(LocationTest, InitialOptions) {
    EXPECT_FALSE(foyer.options.empty());
    EXPECT_FALSE(bedroom.options.empty());
    EXPECT_FALSE(kitchen.options.empty());
    EXPECT_FALSE(library.options.empty());
    EXPECT_FALSE(office.options.empty());
}

// Test adding an option
TEST_F(LocationTest, AddOption) {
    foyer.addOption("Test Option");
    EXPECT_EQ(foyer.options.back(), "Test Option");
}

// Test manual menuChoice setting (simulating input)
TEST_F(LocationTest, ManualMenuChoice) {
    bedroom.menuChoice = "a";
    EXPECT_EQ(bedroom.menuChoice, "a");

    bedroom.menuChoice = "x";
    EXPECT_EQ(bedroom.menuChoice, "x");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
