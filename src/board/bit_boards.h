#ifndef BIT_BOARDS_H
#define BIT_BOARDS_H

#include <bitset>

struct Bit_boards {
  enum class Evaluation { WIN, ILLEGAL, OKAY };

  Bit_boards();
  Bit_boards(Bit_boards* adversary);

  Evaluation evaluate_column(int col);
  void push_to_column(int col);

  void set_adversary(Bit_boards* other) { adversary = other; }
  private:
  const int ROWS = 6;
  const int COLS = 7;

  std::bitset<42> half_board; // locations of all the pieces of one color
  std::bitset<42> two_degree_board; // locations that would result in two in a row for one color
  std::bitset<42> three_degree_board; // locations that would result in three in a row for one color
  std::bitset<42> four_degree_board; // locations that would result in a win for one color 

  Bit_boards* adversary; // bit boards for the opposing color

  int board_column_offset(int col) { return ROWS * col; }
  bool check_legal(int col);
  bool check_win(int col);
  int entry_pos(int col); // returns the index of the first empty position in a column, -1 if full column
};

#endif // BIT_BOARDS_H
