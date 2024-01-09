/*
 * Shot.cpp
 *
 *  Created on: 03-Jan-2024
 *      Author: Sai Swaroop Maram
 */

#include "Shot.h"

Shot::Shot(GridPosition targetPosition) : targetPosition(targetPosition){
}

GridPosition Shot::getTargetPosition() const {
	return targetPosition;
}
