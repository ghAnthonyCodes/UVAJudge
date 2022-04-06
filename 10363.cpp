#include <cstdio>
#include <iostream>
#include <string>
#include <set>

std::set<std::string> validBoards;

bool winner(std::string &S) {
  if (S[0] == S[3] && S[3] == S[6] && S[0] != '.')
    return true;
  if (S[1] == S[4] && S[4] == S[7] && S[1] != '.')
    return true;
  if (S[2] == S[5] && S[5] == S[8] && S[2] != '.')
    return true;
  if (S[0] == S[1] && S[1] == S[2] && S[0] != '.')
    return true;
  if (S[3] == S[4] && S[4] == S[5] && S[3] != '.')
    return true;
  if (S[6] == S[7] && S[7] == S[8] && S[6] != '.')
    return true;
  if (S[0] == S[4] && S[4] == S[8] && S[0] != '.')
    return true;
  if (S[2] == S[4] && S[4] == S[6] && S[2] != '.')
    return true;
  return false;
}

void makemove(std::string S, int move, char turn) {
  S[move] = turn;
  if (validBoards.find(S) != validBoards.end())
     return;
  validBoards.insert(S); 
  if (winner(S)) {
    return;
  }

  // Make next move
  if (turn == 'X')
    turn = 'O';
  else
    turn = 'X';
  for (int i=0; i<9; i++) {
    if (S[i] == '.') {
      makemove(S, i, turn);
    }
  }
}

int main() {
  int N;
  validBoards = std::set<std::string>();
  std::string boardS = ".........";
  validBoards.insert(boardS);
  for (int i=0; i<9; i++) {
    if (boardS[i] == '.') {
      makemove(boardS, i, 'X');
    }
  }
  scanf("%d", &N);
  getchar();
  char board[10];
  char C;
  std::string A;

  while (N--) {
    C = getchar();
    board[0] = C;
    C = getchar();
    board[1] = C;
    C = getchar();
    board[2] = C;
    C = getchar();

    C = getchar();
    board[3] = C;
    C = getchar();
    board[4] = C;
    C = getchar();
    board[5] = C;
    C = getchar();

    C = getchar();
    board[6] = C;
    C = getchar();
    board[7] = C;
    C = getchar();
    board[8] = C;
    C = getchar();
    C = getchar();

    board[9] = '\0';

    std::string bs = board;
    if (validBoards.find(bs) != validBoards.end())
      printf("yes\n");
    else
      printf("no\n");
  }
  
  return 0;
}
