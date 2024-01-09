#ifndef SHIP_H_
#define SHIP_H_

#include "GridPosition.h"
#include<set>

class Ship {
private:
	GridPosition bow;
	GridPosition stern;
public:
	Ship(const GridPosition &bow, const GridPosition &stern);
	/**
	 * @brief "This function checks 3 things
	 * 1. If the Bow and stern values are valid i.e. greater than 0
	 * 2. If the ship is placed either horizontally or vertically
	 * 3. If the ship length is within limits"
	 * @return "returns True if the above checks are satisfied else false"
	 */
	bool isValid() const;
	/**
	 * @brief "This method is used to get the Bow grid position"
	 * @return "Returns the data member bow"
	 */
	GridPosition getBow() const;
	/**
	 * @brief "Used to get the stern grid pos"
	 * @return "The data member stern is returned"
	 */
	GridPosition getStern() const;
	/**
	 * @brief "This method calculates the length of the ship"
	 * @return "length of the ship is returned"
	 */
	int length() const;
	/**
	 * @brief "This method calculates all the grids occupied by a ship"
	 * @return "All Occupied grids by a ship"
	 */
	std::set<GridPosition> occupiedArea() const;
	/**
	 * @brief "This method will calculate the area blocked by a ship"
	 * @return "A Set which will have the positions that are blocked"
	 */
	std::set<GridPosition> blockedArea() const; //TODO: This
};

#endif /* SHIP_H_ */
