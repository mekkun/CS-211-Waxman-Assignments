#include <iostream>
using namespace std;

int main() {
   int b[8][8] = {1}, row, col = 0;

  nextColumn:
    col++;
    if ( col == 8){
      goto solution;
    }
    row = -1;
  
  nextRow:
  row++;
  if ( row == 8 ){
    goto backtrack;
  }

  //Row Test
  for ( int i = 0; i < col; i++){
    if ( b[row][i] == 1){
      goto nextRow;
    }
  }

  //Top Diagnol Test
  for ( int i = 1; row - i >= 0 && col - i >= 0; i++){
    if ( b[row - i][col - i] == 1){
      goto nextRow;
    }
  }

  //Bottom Diagnol test
  for ( int i = 1; row + i < 8 && col - i >= 0; i++){
    if ( b[row + i][col - i] == 1){
      goto nextRow;
    }
  }

  //Place Queen
  b[row][col] = 1;
  goto nextColumn;

  backtrack:
    col--;
    if (col < 0){
      return 0;
    }
    for ( row = 0; b[row][col] != 1; row++);
    b[row][col] = 0;
    goto nextRow;
  
  solution:
    static int count = 1;
    cout << "Solution #" << count++ << ":" << endl;
    for (int i = 0; i < 8; i++){
      for (int j = 0; j < 8; j++){
        cout << b[i][j];
      }
      cout << endl;
    }
    goto backtrack;


}
