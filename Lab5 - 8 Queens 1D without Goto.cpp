#include <iostream>
#include <cmath>
using namespace std;

bool ok( int b[], int col){
  for ( int i = 0; i < col; i++){
    if ( b[i] == b[col] || abs( b[i] - b[col]) == (col-i) ) return false;
  }
  return true;
}

void print( int b[] ){
  static int count = 1;
  cout << "Solution #" << count++ << ": ";
  for (int i  = 0; i < 8; i++){
    cout << b[i];
  }
  cout << endl << endl;
  int print[8][8] = {0};
  for (int i = 0; i < 8; i++){
    print[b[i]][i] = 1;
  }
  for( int i = 0; i < 8; i++){
    for( int j = 0; j < 8; j++){
      cout << print[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
   int b[8] = {0};   // Initialize the array to 0
   int col = 0;       // Start on the first column
   while (col >= 0) { // End the loop if you backtrack from the first column
      if (col == 7) { // If you are in the last column, print and backtrack
         print(b);
         col--;  
      }
      else b[++col] = -1;    // Otherwise, move to one before the first row of the next column
      while (col >= 0) {
         b[col]++;         //Move to the next row
         if (b[col] == 8)     // If you have passed the end of the column, backtrack
            col--;
         else if ( ok(b, col) ) break; // Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
      }
   }
   return 0;
}