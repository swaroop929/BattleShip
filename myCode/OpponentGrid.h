/*
 * OpponentGrid.h
 *
 *  Created on: 28-Dec-2023
 *      Author: Sai Swaroop Maram
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include "Ship.h"
#include "Shot.h"
#include<vector>
#include<set>
#include<map>

class OpponentGrid {
private:
	int rows;
	int columns;
	std::map<GridPosition,Shot::Impact> shots;
	std::vector<Ship> sunkenShips;
public:
	/**
	 * @brief "Constructor for the OpponentGrid class that takes in rows and col
	 * that is the size of board which comes in from the board class"
	 * @param rows "Desired rows of the Opponent chart"
	 * @param columns "Desired cols of the Opponent chart"
	 */
	OpponentGrid(int rows, int columns);
	/**
	 * @brief "Used to get the rows of the OpponentGrid"
	 * @return "Returns the data member rows"
	 */
	int getRows() const;
	/**
	 * @brief "Used to get the cols of the OpponentGrid"
	 * @return "Returns the data member columns"
	 */
	int getColumns() const;
	/**
	 * @brief "This method will add the shot and its result to the data member
	 * shots and will update the vector sunkenShips"
	 */
	void shotResult(const Shot& shot, Shot::Impact impact);
	/**
	 * @brief "This method will return the shots map"
	 * @return "Returns the data member shots"
	 */
	const std::map<GridPosition,Shot::Impact> getShotsAt() const;
	/**
	 * @brief "This method will return the vector sunkenShips"
	 * @return "Returns the data member sunkenShips"
	 */
	std::vector<Ship> getSunkenShips() const;
};

#endif /* OPPONENTGRID_H_ */
