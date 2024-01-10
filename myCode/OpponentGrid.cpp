/*
 * OpponentGrid.cpp
 *
 *  Created on: 28-Dec-2023
 *      Author: Sai Swaroop Maram
 */

#include "OpponentGrid.h"
using namespace std;

OpponentGrid::OpponentGrid(int rows, int columns) :
		rows(rows), columns(columns) {
}

int OpponentGrid::getRows() const {
	return rows;
}

int OpponentGrid::getColumns() const {
	return columns;
}

void OpponentGrid::shotResult(const Shot &shot, Shot::Impact impact) {
	static set<GridPosition> ShotsHit; //All Hit shots
	GridPosition ShotUnderConsideration = shot.getTargetPosition();

	shots.insert( { shot.getTargetPosition(), impact });

	if (impact == Shot::Impact::HIT) {
		ShotsHit.insert(shot.getTargetPosition());
	}

	set<GridPosition> SunkenShipOccupArea;
	//Has full occupied area of the shot ship

	int dir_row[4] = { 0, 0, 1, -1 }; //L, R, U, D
	int dir_col[4] = { -1, 1, 0, 0 }; //L, R, U, D

	char PrevRow = ShotUnderConsideration.getRow();
	char NextRow = PrevRow;
	int PrevCol = ShotUnderConsideration.getColumn();
	int NextCol = PrevCol;

	if (impact == Shot::Impact::SUNKEN) {
		SunkenShipOccupArea.insert(shot.getTargetPosition()); //A2
		//for sure one of the grid in interested ship
		for (int itr = 0; itr < 4; itr++) {
			NextRow = PrevRow + dir_row[itr]; //A1
			NextCol = PrevCol + dir_col[itr];
			if (NextRow >= 'A' && NextRow <= ('A' + rows - 1) && NextCol >= 1
					&& NextCol <= columns) {
				auto pos = ShotsHit.find(GridPosition(NextRow, NextCol));
				if (pos != ShotsHit.end()) {
					SunkenShipOccupArea.insert(*pos);
					//continue in that direction
					set<GridPosition>::iterator pos2;
					do {
						NextRow = NextRow + dir_row[itr];
						NextCol = NextCol + dir_col[itr];
						pos2 = ShotsHit.find(
								GridPosition(NextRow, NextCol));
						if (pos2 != ShotsHit.end())
							SunkenShipOccupArea.insert(*pos2);
					} while (pos2 != ShotsHit.end());


				}
			}
		}

		sunkenShips.push_back(
				Ship(*(SunkenShipOccupArea.begin()),
						*(SunkenShipOccupArea.rbegin())));
	}

	/*for (auto grid : SunkenShipOccupArea) {
		cout << grid.getRow() << grid.getColumn() << endl;
	}*/
}

vector<Ship> OpponentGrid::getSunkenShips() const {
	return sunkenShips;
}

const std::map<GridPosition, Shot::Impact> OpponentGrid::getShotsAt() const {
	return shots;
}
