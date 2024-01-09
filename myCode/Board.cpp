#include "Board.h"

Board::Board(int rows, int columns) :
		ownGrid(rows, columns), opponentGrid(rows, columns) {
}

int Board::getRows() const {
	if (ownGrid.getRows() == opponentGrid.getRows())
		return ownGrid.getRows();
	else
		return 0;
}

int Board::getColumns() const {
	if (ownGrid.getColumns() == opponentGrid.getColumns())
		return ownGrid.getColumns();
	else
		return 0;
}

OwnGrid& Board::getOwnGrid() {
	return ownGrid;
}

OpponentGrid& Board::getOpponentGrid() {
	return opponentGrid;
}
