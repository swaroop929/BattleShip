#ifndef BOARD_H_
#define BOARD_H_

#include "OwnGrid.h"
#include "OpponentGrid.h"
#include<memory>

class Board {
private:
	OwnGrid ownGrid;
	OpponentGrid opponentGrid;
public:
	/**
	 * @brief "Rows and columns for #OwnGrid and #OpponentGrid are set from
	 * here"
	 * @param rows "Desired rows for the game"
	 * @param columns "Desired columns for the game"
	 */
	Board(int rows, int columns);
	/**
	 * @brief "Used to get the rows of the game board"
	 * @return Rows of the game board
	 */
	int getRows() const;
	/**
	 * @brief "Used to get the cols of the game board"
	 * @return Returns the columns of the game board
	 */
	int getColumns() const;
	/**
	 * @brief "Used to get the Own Grid of the game board"
	 * @return Returns the data member OwnGrid
	 */
	OwnGrid& getOwnGrid();
	/**
	 * @brief "Used to get the OpponentGrid of the game board"
	 * @return Returns the data member OpponentGrid
	 */
	OpponentGrid& getOpponentGrid();
};

#endif /* BOARD_H_ */
