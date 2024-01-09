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
	char NextRow = ShotUnderConsideration.getRow();
	int PrevCol = ShotUnderConsideration.getColumn();
	int NextCol = ShotUnderConsideration.getColumn();

	if (impact == Shot::Impact::SUNKEN) {
		SunkenShipOccupArea.insert(shot.getTargetPosition());
		//for sure one of the grid in interested ship
		for (int itr = 0; itr < 4; itr++) {
			for (auto MatchinHits : ShotsHit) { //search in whole array for A4
				/*PrevRow = NextRow; //A
				 PrevCol = NextCol; //5*/
				if (GridPosition(PrevRow + dir_row[itr], PrevCol + dir_col[itr])
						== MatchinHits) {
					int correct_dir = itr; //left ani telsindi
					for (auto MatchinHitss : ShotsHit) {
						NextRow = PrevRow + dir_row[correct_dir]; //A
						NextCol = PrevCol + dir_col[correct_dir]; //4
						for (auto MatchinHits_itr : ShotsHit) {
							if (GridPosition(NextRow, NextCol)
									== MatchinHits_itr) {
								if (NextRow >= 'A'
										&& NextRow <= (char) ('A' + rows - 1)
										&& NextCol >= 1 && NextCol <= columns) {
									SunkenShipOccupArea.insert(MatchinHits_itr);
									PrevCol = NextCol;
									PrevRow = NextRow;
								}
							}
						}
					}

				}
			}

		}
		sunkenShips.push_back(
				Ship(*(SunkenShipOccupArea.begin()),
						*(SunkenShipOccupArea.rbegin())));
	}

	/*for(auto grid:SunkenShipOccupArea){
	 cout<<grid.getRow()<<grid.getColumn()<<endl;
	 }*/
}

vector<Ship> OpponentGrid::getSunkenShips() const {
	return sunkenShips;
}

const std::map<GridPosition, Shot::Impact> OpponentGrid::getShotsAt() const {
	return shots;
}
