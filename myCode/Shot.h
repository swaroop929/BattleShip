#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

class Shot {
private:
	GridPosition targetPosition;
public:
	typedef enum{
		NONE,
		HIT,
		SUNKEN
	}Impact;
	/**
	 * @brief "Constructor of Shot that it has to be fired at"
	 * @param targetPosition "Will be the coordinate at which the shot has to be fired"
	 */
	Shot(GridPosition targetPosition);
	/**
	 *@brief "This method returns the grid at which shot is fired"
	 *@return "Data member targetPosition is returned"
	 */
	GridPosition getTargetPosition() const;
};

#endif /* SHOT_H_ */
