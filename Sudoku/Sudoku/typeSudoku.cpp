#include "stdafx.h"
#include "typeSudoku.h"
#include <iostream>
#include <stdlib.h>


////////////////////////////////////////////////////////////////
typeSudoku::typeSudoku() : gridIsZeroed(false)
{
	makeGridZero();
	randomPopulation();
}

////////////////////////////////////////////////////////////////
typeSudoku::~typeSudoku()
{
}

////////////////////////////////////////////////////////////////
void typeSudoku::makeGridZero()
{
	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
		{
			grid[i][j] = 0;
		}
	}
	gridIsZeroed = true;
}

////////////////////////////////////////////////////////////////
short typeSudoku::findLegalNumRowCol(int i, int j)
{
	short legals[] = {1,2,3,4,5,6,7,8,9};
	short legalBin[] = {1,1,1,1,1,1,1,1,1};	
	for(int k = 0; k < 9; ++k)
	{
		for(int l = 0; l < 9; ++l)
		{
			if(grid[i][k] == legals[l])
			{
				legalBin[l] = 0;
			}
		}
	}
	for(int k = 0; k < 9; ++k)
	{
		for(int l = 0; l < 9; ++l)
		{
			if(grid[k][j] == legals[l])
			{
				legalBin[l] = 0;
			}
		}
	}

	short *passedOnLegals = new short[9];
	for(int k = 0; k < 9; ++k)
	{
		passedOnLegals[k] = legalBin[k];
	}
	short retValue = findWithinSubSquare(i, j, passedOnLegals);
	if(passedOnLegals != NULL)
	{
		delete [] passedOnLegals;
		passedOnLegals = NULL;
	}
	return retValue;
}

////////////////////////////////////////////////////////////////
typeSudoku::coordinates typeSudoku::findSubSquare(int i, int j)
{
	/*
		The comments subscript (0,0), or (0,3),..
		are all the upper right hand corner of the
		subsquare. There are nine subsquares, and hence
		there are nine corrdinates.
	*/
	typeSudoku::coordinates position;
	if(i < 3 && j < 3) // (0,0)
	{
		position.row = 0;
		position.col = 0;
	}
	else if(i < 3 && j < 6) // (0,3)
	{
		position.row = 0;
		position.col = 3;
	}
	else if(i < 3 && j >= 6) // (0,6)
	{
		position.row = 0;
		position.col = 6;
	}
	else if( 3 <= i && i < 6 && j < 3) // (3,0)
	{
		position.row = 3;
		position.col = 0;
	}
	else if( 3 <= i && i < 6 && j < 6) // (3,3)
	{
		position.row = 3;
		position.col = 3;
	}
	else if( 3 <= i && i < 6 && j >= 6) // (3,6)
	{
		position.row = 3;
		position.col = 6;
	}
	else if( i >= 6 && j < 3) // (6,0)
	{
		position.row = 6;
		position.col = 0;
	}
	else if( i >= 6 && j < 6) // (6,3)
	{
		position.row = 6;
		position.col = 3;
	}
	else if( i >= 6 && j >= 6) // (6,6)
	{
		position.row = 6;
		position.col = 6;
	}

	//error handling...not very good yet.
	if(position.row < 0 || position.row > 8)
	{
		position.row = 0;
	}
	if(position.col< 0 || position.col > 8)
	{
		position.col = 0;
	}
	return position;
}

////////////////////////////////////////////////////////////////
bool typeSudoku::isPuzzleValid()
{
	bool isValid = true;
	for(int k = 0; k < 9; ++k)
	{
		for(int l = 0; l < 9; ++l)
		{
			if(grid[k][l] == 0)
			{
				isValid = false;
			}
		}
	}
	return isValid;
}

////////////////////////////////////////////////////////////////
short typeSudoku::findWithinSubSquare(int i, int j, short *legalBins)
{
	short legals[9] = {1,2,3,4,5,6,7,8,9};
	short legalBin[9] = {1};	
	for(int k = 0; k < 9; ++k)
	{
		legalBin[k] = legalBins[k];
	}
	typeSudoku::coordinates position = findSubSquare(i,j);
	for(int m = position.row; m < (position.row+3); ++m)
	{
		for(int n = position.col; n < (position.col+3); ++n)
		{
			for(int l = 0; l < 9; ++l)
			{
				if(grid[m][n] == legals[l])
				{
					legalBin[l] = 0;
				}
			}
		}
	}
	short sum = 0;
	for(int k = 0; k < 9; k++)
	{
		sum += legalBin[k];
	}
	short *options = new short[sum];
	int steper = 0;
	for(int k = 0; k < 9; k++)
	{
		if(legalBin[k] == 1)
		{
			options[steper++] = legals[k];
		}
	}
	short retValue = 0;
	if(sum > 0)
	{
		retValue = options[rand() % sum];
	}
	delete [] options;
	options = NULL;
	return retValue;
}

////////////////////////////////////////////////////////////////
void typeSudoku::randomPopulation()
{
	if(gridIsZeroed == false)
	{
		makeGridZero();
	}

	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
		{
			grid[i][j] = findLegalNumRowCol(i, j);
		}
	}

}

////////////////////////////////////////////////////////////////
void typeSudoku::printPuzzle()
{
	using std::cout;
	using std::endl;
	cout << "===================" << endl;
	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
		{
			cout << "|" << grid[i][j];
			if(j == 8)
			{
				cout << "|" << endl;
			}
		}
	}
	cout << "===================" << endl;
}

