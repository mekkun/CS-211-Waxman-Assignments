#include <iostream>
using namespace std;

bool ok(int q[], int c) {
   static int mp[3][3] = { 
     {0,2,1},  // Man #0
     {0,2,1},  // #1
     {1,2,0}}; // #2
   static int wp[3][3] = { 
     {2,1,0},  // woman #0 
     {0,1,2},  // #1
     {2,0,1}}; // #2
                     
   
   for (int i = 0; i < c; ++i) {
      if ( q[i] == q[c] // Test 1
        || ( mp[i][q[c]] < mp[i][q[i]]  && wp[q[c]][i] < wp[q[c]][c] ) //Test 2
        || ( mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) )
         return false; 
   }
   return true;
}

void print(int q[]) {
   static int solution = 1;
   cout << "Solution #" << ++solution << ":" << endl 
   << "Man"<< "\t" << "Woman" << endl;
   for (int i = 0; i < 3; i++)
      cout << i << "\t" << q[i] << endl;
   cout << endl;
}

int main() {
   int q[3] = {};
   int c = 0;
   while (c >= 0) {
      if (c == 2) {
         print(q);
         c--;
      }
      else
         q[++c] = -1;
      while (c >= 0) {
         q[c]++;
         if (q[c] == 3) 
            c--;
         else if (ok(q, c))
            break;
      }
   }
   return 0;
}