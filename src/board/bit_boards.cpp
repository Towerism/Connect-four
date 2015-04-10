#include <algorithm>
#include "bit_boards.h"

Bit_boards::Bit_boards() : Bit_boards(nullptr) { }

Bit_boards::Bit_boards(Bit_boards* adversary) : adversary(adversary) { }

Bit_boards::Evaluation Bit_boards::evaluate_column(int col) {
  if (!check_legal(col)) {
    return Evaluation::ILLEGAL;
  }
  if (check_win(col)) {
    return Evaluation::WIN;
  }
  return Evaluation::OKAY;
}

void Bit_boards::push_to_column(int col) {
  int entry = entry_pos(col);
  if (entry == -1) {
    return;
  }
}

bool Bit_boards::check_legal(int col) {
  int offset = board_column_offset(col);
  if (half_board.test(offset) || adversary->half_board.test(offset)) {
    return false;
  }
  return true;
}

bool Bit_boards::check_win(int col) {
  int entry = entry_pos(col);
  return four_degree_board.test(entry);
}

int Bit_boards::entry_pos(int col) {
  int offset = board_column_offset(col);
  int boundary = board_column_offset(col + 1);
  int my_offset = -1;
  int adversary_offset = -1;
  // can simplify by bitset and the two half_boards
  for (int i = offset; i < boundary; ++i) {
    if (!half_board.test(i) && my_offset == -1) {
      my_offset = i;
    }
    if (!adversary->half_board.test(i) && adversary_offset == -1) {
      adversary_offset = i;
    }
    if (my_offset != -1 && adversary_offset != -1) {
      break;
    }
  }
  return std::min(my_offset, adversary_offset);
}
