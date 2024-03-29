#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
	for (int i = 0; i < c; ++i)
		if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
			return false;
	return true;
}

void print(int q[]) {
	static int solution = 0;
	int i, j, k, l;
	typedef char box[5][7];   // box is now a data type: a 5x7 2D array of characters
	static box bb, wb;
	box* board[8][8];
	// board is an 8x8 array of pointers to boxes (each element is a pointer, stores an address).							  
	
	// Fill in bb (black box) and wb (white box).  They each represent a square of the chessboard.
	char black = ' ';
	char white = char(219);
	for (i = 0; i < 5; i++)
		for (j = 0; j < 7; j++) {
			bb[i][j] = ' ';
			wb[i][j] = char(219);
		}

	// Fill in bb (black box) and wb (white box), each represent a square of the chessboard.
	static box bq = {{white, white, white, white, white, white, white},
					 {white, black, white, black, white, black, white},
					 {white, black, black, black, black, black, white},
					 {white, black, black, black, black, black, white},
					 {white, white, white, white, white, white, white} };

	static box wq = { {black, black, black, black, black, black, black},
					  {black, white, black, white, black, white, black},
					  {black, white, white, white, white, white, black},
					  {black, white, white, white, white, white, black},
					  {black, black, black, black, black, black, black} };


	/************************************************************************
	 * Fill board with pointers that stores the address of proper boxes. (Fill out this part.)
	 ************************************************************************/
	 // fill wb at ((i+j)%2 == 0), e.g. (0, 0), otherwise fill bb

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			if ((i + j) % 2 == 0)
				board[i][j] = &wb; 
			else
				board[i][j] = &bb;

	// Start printing to the console:
	cout << "Solution #" << ++solution << ": " << endl;

	for (int i = 0; i < 8; i++) {
		if (board[i][q[i]] == &wb) board[i][q[i]] = &bq; //You check the board to see if its a white board spot and then replace that address with a black queen address.
		if (board[i][q[i]] == &bb) board[i][q[i]] = &wq;
	}

	// Print upper border
	for (i = 0; i < 7 * 8; i++)
		cout << '_';
	cout << endl;

	// Print the board
	for (i = 0; i < 8; i++)          // for each board row
		for (k = 0; k < 5; k++) {     // for each box row
			cout << char(179);		  // left boarder
			for (j = 0; j < 8; j++)    // for each board column
				for (l = 0; l < 7; l++) // for each box column
					cout << (*board[i][j])[k][l];
			// board[i][j] = Address of wb (or bb, wq, bq)
			// *board[i][j] = Dereference to get that wb.
			// (*board[i][j])[k][l] = wb[k][l] 
			cout << char(179) << endl; // right boarder
		}

 // Print lower border
	cout << " ";
	for (i = 0; i < 7 * 8; i++)
		cout << char(196);
	cout << endl << endl;
}

void next(int q[], int c) {
	if (c == 8)
		print(q);
	else for (q[c] = 0; q[c] < 8; ++q[c])
		if (ok(q, c))
			next(q, c + 1);
}
int main() {
	int q[8] = {}, c = 0;
	q[0] = 0;

	while (c >= 0) {  // NEXT COL:
		c++;                // Move to the next column
		if (c > 7) {          // If you have passed the last column, a solution is found
			print(q);      // Call the print function and backtrack
			c--;
		}
		else q[c] = -1;   // set to -1 so in inner loop you can start q[c] from 0
		while (c >= 0) {  // NEXT ROW:
			q[c]++;           // Move to the next row
			if (q[c] > 7) c--;  // If you have passed the end of the row, backtrack
			else              // Otherwise, call the ok function.
				if (ok(q, c)) break; // If ok (returns true), a queen is filled in the row
		}
	}
	return 0;
}
