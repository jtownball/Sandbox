#ifndef TYPE_SUDOKU_H
#define TYPE_SUDOKU_H

class typeSudoku 
{
public:
	typeSudoku();
	~typeSudoku();
	void printPuzzle();
	bool isPuzzleValid();
private:
	short grid[9][9];
	void randomPopulation();
	void makeGridZero();
	bool gridIsZeroed;
	short findLegalNumRowCol(int i, int j);
	short findWithinSubSquare(int i, int j, short *legalBins);
	typedef struct {int row; int col;} coordinates;
	coordinates findSubSquare(int i, int j);
};

#endif
