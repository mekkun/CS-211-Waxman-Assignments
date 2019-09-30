#include <iostream>
using namespace std;

int main() {
  int b[8] = {0}, col = 0;

  nextColumn:
  col++;
  if (col == 8) {
    goto solution;
  }
  b[col] = -1;

  nextRow:
  b[col]++;
  if(b[col] == 8){ 
    goto backtrack;
  }

  //Checks Queens to the left
  for ( int i = 1; i < col+1; i++){
    if( b[col-i] == b[col]){
      goto nextRow;
    }
  }

  //Checks Upper left
  for (int i = 1; i <= col; i++){
    if ( b[col-i] == b[col]-i){
      goto nextRow;
    }
  }

  //Checks Lower left
  for( int i = 1; i <= col; i++){
    if ( b[col-i] == b[col]+i){
      goto nextRow;
    }
  }

  goto nextColumn;

  backtrack:
  col--;
  if( col < 0 ){
    return 0;
  }
  goto nextRow;

  solution:
  static int count = 1;
  cout << "Solution#" << count++ << ":" << endl;
  for( int i = 0; i < 8; i++){
    cout << b[i];
  }
  cout << endl << endl;

  goto backtrack;
}