/*
 * ConsoleView.h
 *
 *  Created on: 28-Dec-2023
 *      Author: Sai Swaroop Maram
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#include"Board.h"

class ConsoleView {
private:
	Board* board;
public:
	/**
	 * @brief Constructor for the ConsoleView class which takes in board
	 * @param *board "This will be the pointer to the board that
	 * needs to be printed"
	 */
	ConsoleView(Board *board);
	/**
	 * @brief "Used to Print the board on the console
	 * This will print both the OwnGrid and OpponentGrid on the screen next to
	 * each other"
	 */
	void print();
};

#endif /* CONSOLEVIEW_H_ */
