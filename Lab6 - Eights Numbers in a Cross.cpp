#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {

   static int checklist[8][5] = { 
    {-1},                // 0 
    {0, -1},             // 1
    {0, 1, -1},          // 2 
    {0, 2, -1},          // 3  
    {1, 2, -1},          // 4  
    {1, 2, 3, 4, -1},    // 5 
    {2, 3, 5, -1},       // 6
    {4, 5, 6, -1}     }; // 7

   for (int i = 0; i < c; ++i) //Checks if number was already used
      if (q[i] == q[c]) 
         return false;

   for (int i = 0; checklist[c][i] != -1; ++i) // Checks Neighbors
      if (abs(q[c] - q[ checklist[c][i] ] ) == 1)
         return false;
   return true;
}

void print(int q[]) {
   static int solution = 1;
   cout << "Solution #" << solution++ << endl << endl;
   cout << " "  << q[1] << q[4] << endl;
   cout << q[0] << q[2] << q[5] << q[7] << endl;
   cout << " "  << q[3] << q[6] << endl << endl;
   cout << "----------------" << endl << endl;
}

void backtrack( int &c ){
c--;
if ( c<0 ) exit(0);
}

int main() {
  int q[8] = {};
  q[0]= 1;
  int c = 0;

  while ( c >= 0 ){
    c++;
    if ( c > 7 ){
      print(q);
      backtrack(c);
    }
    else q[c] = 0;
    while ( c >= 0 ){
      q[c]++;
      if ( q[c] > 8 ){
        q[c] = 0;
        backtrack(c);
      }
      else if ( ok(q,c) ) break;
    }
  }
return 0;
}
