#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string add(string a, string b){
  string Bigsum = "";
  int x = a.length();
  int y = b.length();
  
  if(x > y ){   
    swap(a,b);   
  } 
reverse(a.begin(), a.end() );
reverse(b.begin(), b.end() );

int carry = 0;
for (int i = 0; i < x; i++){
  int sum = ( (a[i]-'0') + (b[i]-'0') + carry );
  Bigsum.push_back(sum % 10 + '0');
  carry = sum/10;
}

for (int n = x; n < y; n++){
  int sum = ( (b[n]-'0') + carry);
  Bigsum.push_back(sum % 10+'0');
  carry = sum/10;
}

if(carry){
  Bigsum.push_back(carry+'0');
}

reverse(Bigsum.begin(), Bigsum.end() );

return Bigsum;
}


int main() {
 string x;
 string y;
 while (1){
  cout << "Enter two Integers: " << endl;
  cin >> x;
  if (x == "done"){
    break;
  }
  cin >> y;
  cout << "The Sum is: " << add(x,y) << endl;
  cout << "Type 'Done' to terminate or ";
}
 cout << "Program Termianted." << endl;
 return 0;
}
