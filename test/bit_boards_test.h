#include <gtest/gtest.h>

struct BitBoardsTest : public ::testing::Test {
  protected:
    BitBoardsTest() {
      white_bb.set_adversary(black_bb);
      black_bb.set_adversary(white_bb);
    }

    Bit_boards white_bb;
    Bit_boards black_bb;
}
