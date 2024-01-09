#include "Ship.h"

using namespace std;

Ship::Ship(const GridPosition &bow, const GridPosition &stern) :
		bow(bow), stern(stern) {
}

bool Ship::isValid() const {
	int length_of_ship = this->length();
	bool flag = false;

	if (length_of_ship >= 2 && length_of_ship <= 5) { //length check
		if ((bow.getRow() == stern.getRow())
				|| (bow.getColumn() == stern.getColumn())) {
			//Horizontal or vertical placement check
			flag = true;
		}
	} else {
		flag = false;
	}

	return flag;
}

GridPosition Ship::getBow() const {
	return this->bow;
}

GridPosition Ship::getStern() const {
	return this->stern;
}

int Ship::length() const {
	int length = 0;

	if ((bow.getRow() >= 'A' && bow.getRow() <= 'Z' && bow.getColumn() >= 1
			&& bow.getColumn() <= 26 && stern.getRow() >= 'A'
			&& stern.getRow() <= 'Z' && stern.getColumn() >= 1
			&& stern.getColumn() <= 26)) {
		if (bow.getRow() == stern.getRow()) {
			length = 1 + abs(stern.getColumn() - bow.getColumn());
		} else {
			length = 1 + abs(stern.getRow() - bow.getRow());
		}
	}

	return length;
}

std::set<GridPosition> Ship::occupiedArea() const {

	set<GridPosition> OccupiedGrids;
	char start_row;
	int start_col;
	int len = length();

	//Vertical start position check
	if (bow.getRow() > stern.getRow()
			&& (bow.getColumn() == stern.getColumn())) {
		start_row = stern.getRow();
		start_col = stern.getColumn();
	} else if (bow.getRow() < stern.getRow()
			&& (bow.getColumn() == stern.getColumn())) {
		start_row = bow.getRow();
		start_col = bow.getColumn();
	}

	//Horizontal start  positions
	if (bow.getColumn() > stern.getColumn()
			&& (bow.getRow() == stern.getRow())) {
		start_col = stern.getColumn();
		start_row = stern.getRow();
	} else if (bow.getColumn() < stern.getColumn()
			&& (bow.getRow() == stern.getRow())) {
		start_col = bow.getColumn();
		start_row = bow.getRow();
	}

	//Horizontal orientation
	if (bow.getRow() == stern.getRow()) {
		/*if (bow.getColumn() > stern.getColumn()) {
		 for (int i = 0; i < len; i++) {
		 OccupiedGrids.insert(GridPosition(start_row, start_col - i));
		 }*/
		//if(bow.getColumn()<stern.getColumn())
		for (int i = 0; i < len; i++) {
			OccupiedGrids.insert(GridPosition(start_row, start_col + i));
		}
	}

	//Vertical orientation
	else if (bow.getColumn() == stern.getColumn()) {
		for (int i = 0; i < len; i++) {
			OccupiedGrids.insert(GridPosition(start_row + i, start_col));
		}
	} else {
		//Error, should not come here
	}

	return OccupiedGrids;
}

std::set<GridPosition> Ship::blockedArea() const {
	set<GridPosition> OccipedGrids = occupiedArea();
	set<GridPosition> BlockedGrids;

	for (auto i : OccipedGrids) {
		if (i.getRow() <= 'Z' && i.getRow() >= 'A') {
			if (i.getColumn() >= 1 && i.getColumn() <= 26) {
				BlockedGrids.insert(
						GridPosition(i.getRow(), i.getColumn() - 1)); //left
				BlockedGrids.insert(
						GridPosition(i.getRow() + 1, i.getColumn())); //Down
				BlockedGrids.insert(
						GridPosition(i.getRow() - 1, i.getColumn())); //Up
				BlockedGrids.insert(
						GridPosition(i.getRow(), i.getColumn() + 1)); //Right
				BlockedGrids.insert(
						GridPosition(i.getRow() - 1, i.getColumn() - 1)); //UL
				BlockedGrids.insert(
						GridPosition(i.getRow() - 1, i.getColumn() + 1)); //UR
				BlockedGrids.insert(
						GridPosition(i.getRow() + 1, i.getColumn() - 1)); //BL
				BlockedGrids.insert(
						GridPosition(i.getRow() + 1, i.getColumn() + 1)); //BR
				BlockedGrids.insert(GridPosition(i.getRow(), i.getColumn()));
			}
		}
	}

	return BlockedGrids;
}
