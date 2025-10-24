#include <gtest/gtest.h>
#include "domain/user.h"   // Beispiel: Header aus deinem Projekt
#include "domain/client.h"

// Dummy Test Fixture für User/Client
class UserTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Optional: Setup-Code vor jedem Test
    }

    void TearDown() override {
        // Optional: Aufräumarbeiten nach jedem Test
    }
};



// Ein weiterer einfacher Test
TEST(DummyTest, SimpleCheck) {
    int a = 1;
    int b = 2;
    EXPECT_LT(a, b);  // a < b
}
