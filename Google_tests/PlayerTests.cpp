//
// Created by Ivan Yakovenko on 15/08/2020.
//

#include "gtest/gtest.h"
#include "../player/player.hpp"


TEST(PlayerTestSuite, MaxDamage){ // 20 attack => hp<0
    Player testPlayer;
    int hp = testPlayer.getHp();
    int def = testPlayer.getDef();
    testPlayer.takeDamage(hp + def + 5);

    EXPECT_EQ(testPlayer.isAlive(), false);
}


