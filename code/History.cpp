#include "History.h"
#include "globals.h"
#include <iostream>
using namespace std;

History::History(int nRows, int nCols)
	: m_row(nRows), m_col(nCols)
{
	//We assume that a history object gets declared with the right
	//amount of rows and columns because we do MAX and MIN checks 
	//when we declare a Game and Arena object
	for(int i = 0; i < m_row; i++)
		for(int j = 0; j < m_col; j++)
			histGrid[i][j] = '.';
}

bool History::record(int r, int c)
{
	bool result = false;
	if(r < m_row && r >= 0 && c < m_col && c >= 0) 
	{
		result = true;
		char grid = histGrid[r][c];
		switch(grid)
		{
			case '.': 
				histGrid[r][c] = 'A'; 
				break;
			case 'Z': 
				break;
			default: 
				histGrid[r][c] += 0x1; //if A-Y
				break;
		}
	}
	return result;
}

void History::display() const 
{
	clearScreen();
	int r, c;
	for (int r = 0; r < m_row; r++) {
		for (int c = 0; c < m_col; c++) {
			cout << histGrid[r][c];
		}
		cout << endl;
	}
	cout << endl;
}
