/*
 * OwnGrid.h
 *
 *  Created on: 27-Dec-2023
 *      Author: Sai Swaroop Maram
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_

#include "Ship.h"
#include "Shot.h"
#include<vector>
#include<algorithm>
#include<map>
#include<set>

class OwnGrid {
private:
	int rows;
	int columns;
	std::vector<Ship> ships;
	std::map<int,int> ShipsMap;
	std::set<GridPosition> shotAt;
public:
	/**
	 * @brief "This constructor will create Own and of the passed size"
	 * @param rows "Rows of the game grid"
	 * @param columns "Columns of the game grid"
	 */
	OwnGrid(int rows,int columns);
	/**
	 * @brief "Returns the number of rows of the grid"
	 * @return "The data member rows is returned"
	 */
	int getRows() const;
	/**
	* @brief "Retrns the number of cols of the grid"
	* @return "data member number of cols"
	*/
	int getColumns() const;
	/**
	 * @brief "Will check if the placement of ship is according to the rules
	 * and if yes then it will add the ship to the ships vector"
	 * @param ship "ship with bow and stern will be added to the grid"
	 * @return "True if ship is a right move else returns False"
	 */
	bool placeShip(const Ship& ship);
	/**
	 * @brief "This method gives the vector containing bow and stern
	 * coordinates of all the valid ships"
	 * @return "Data member ships which has all the ship bow and stern"
	 */
	std::vector<Ship> getShips() const;

	/**
	 * @brief "This method will tell if the fired shot is a HIT shot or NONE
	 * shot or a SUNKEN shot"
	 * @param shot "Fired shot on the OwnGrid from Opponent"
	 * @return "This method will return the Impact value of the fired shot"
	 */
	Shot::Impact takeBlow(const Shot& shot);

	/**
	 * @brief "This method will return all the fired shots be it miss or HIT"
	 * @return "The data member shotAt is returned"
	 */
	std::set<GridPosition> getShotAt() const;
};

#endif /* OWNGRID_H_ */
