#include "OwnGrid.h"

using namespace std;

OwnGrid::OwnGrid(int rows, int columns) :
		rows(rows), columns(columns) {
	ShipsMap = { { 5, 1 }, { 4, 2 }, { 3, 3 }, { 2, 4 } };
}

int OwnGrid::getRows() const {
	return this->rows;
}

int OwnGrid::getColumns() const {
	return this->columns;
}

//< and not <= because ships should not be placed at corners i.e ship
//bow cannot be at 1 or 10 (as they are the corners of the board)
bool OwnGrid::placeShip(const Ship &ship) {
	bool flag = false;

	map<int, int>::iterator it_map;

	if (((ship.getBow().getColumn() <= columns && ship.getBow().getColumn()>=1)
			&& (ship.getStern().getColumn() <= columns
					&& ship.getStern().getColumn() >= 1))
			&& (((ship.getBow().getRow() >= ('A')
					&& ship.getBow().getRow() <= ((char) ('A' + rows - 1))
					&& (ship.getStern().getRow() >= ('A')
							&& ship.getStern().getRow()
									<= ((char) ('A' + rows - 1)))))) //Guard
			&& (ship.isValid()) && (ships.size() <= 10)) //total ships <=10
			{
		set<GridPosition> OccupArea;
		set<GridPosition> BlockArea;
		vector<GridPosition> Intersec_vector;
		vector<GridPosition>::iterator itr_intersection;

		BlockArea = ship.blockedArea();

		//Create Occupied Area set
		for (auto i : ships) {
			for (auto j : i.occupiedArea()) {
				OccupArea.insert(GridPosition(j));
			}
		}

		//Check for common grids between Occup Area and Blocked Area
		for (auto itr_blockPos : BlockArea) {
			for (auto itr_OccupPos : OccupArea) {
				if (itr_blockPos == itr_OccupPos)
					Intersec_vector.push_back(itr_blockPos);
			}

		}

		/*Intersec_vector.resize(std::min(OccupArea.size(), BlockArea.size()));
		 itr_intersection = set_intersection(OccupArea.begin(),
		 OccupArea.end(),BlockArea.begin(),BlockArea.end(),
		 Intersec_vector.begin());
		 Intersec_vector.resize(std::distance(Intersec_vector.begin(),
		 itr_intersection));*/

		int ship_len = ship.length();
		it_map = ShipsMap.find(ship_len);
		if ((it_map->second > 0) && (Intersec_vector.empty())) {
			//When ship of that length is allowed
			//and when there are no common grids between blocked and occupied
			it_map->second--;
			ships.push_back(ship);
			flag = true;
		}

	}
	return flag;
}

std::vector<Ship> OwnGrid::getShips() const {
	return ships;
}

/*Shot::Impact OwnGrid::takeBlow(const Shot &shot) {
 Shot::Impact ResultOfShot = Shot::NONE;

 GridPosition ShotAtGrid = shot.getTargetPosition();
 set<GridPosition> AllShipsOccupiedFields;
 set<GridPosition> AllTakenBlows;
 static set<GridPosition> HitsOnThisShip; //TODO: Check the implementation

 for(auto ship:ships){ //All ships grids
 for(auto grid: ship.occupiedArea()){
 AllShipsOccupiedFields.insert(grid);
 }
 }

 for(auto ShipGrid:AllShipsOccupiedFields){
 for(auto shotGrid:shotAt){
 if(ShipGrid == shotGrid) //If ship posn is shot then put it in set
 AllTakenBlows.insert(ShipGrid);
 }
 }

 //int len = AllTakenBlows.size();
 //int len2 = HitsOnThisShip.size();

 vector<GridPosition> CheckForSunken;

 for (auto ship : ships) {

 //if(ship.occupiedArea().find(ShotAtGrid)!=ship.occupiedArea().end()){
 for (auto ShipOccupiedGrid : ship.occupiedArea()) {
 if (ShipOccupiedGrid == ShotAtGrid) { //Ship occupied Grid ==
 CheckForSunken.push_back(ShipOccupiedGrid);
 if (CheckForSunken.size()
 == ((ship.occupiedArea().size()) - 1)) {
 ResultOfShot = Shot::SUNKEN;
 HitsOnThisShip.clear();
 } else {
 ResultOfShot = Shot::HIT;
 HitsOnThisShip.insert(ShotAtGrid);
 }
 }
 }
 }



 shotAt.insert(ShotAtGrid); //Inserting all shots into a set

 return ResultOfShot;
 }*/

Shot::Impact OwnGrid::takeBlow(const Shot &shot) {

	shotAt.insert(shot.getTargetPosition());

	Shot::Impact ResultOfShot = Shot::Impact::NONE;

	set<GridPosition> AllShipsGrids;
	static set<GridPosition> AllTakenBlows;
	set<GridPosition> IntersectionSet;
	set<GridPosition> ThatShipOccupArea;
	vector<Ship> AllShips = getShips();

	for (auto ship : AllShips) {
		for (auto grid : ship.occupiedArea()) {
			AllShipsGrids.insert(grid);
			if (shot.getTargetPosition() == grid) {
				ThatShipOccupArea = ship.occupiedArea();
			}
		}
	}

	for (auto grid : ThatShipOccupArea) {
		for (auto TakenShot : AllTakenBlows) {
			if (grid == TakenShot) {
				IntersectionSet.insert(grid);
			}
		}
	}

	/*int len = IntersectionSet.size();
	 int len2 = ThatShipOccupArea.size();
	 int len3 = AllTakenBlows.size();*/

	for (auto ship : ships) {
		for (auto shipGrid : ship.occupiedArea()) {
			if (shot.getTargetPosition() == shipGrid) {
				ResultOfShot = Shot::Impact::HIT;
				if (IntersectionSet.size() == ThatShipOccupArea.size() - 1) {
					ResultOfShot = Shot::Impact::SUNKEN;
				}
			}

		}
	}

	for (auto shipGrid : AllShipsGrids) {
		if (shipGrid == shot.getTargetPosition())
			AllTakenBlows.insert(shipGrid);
	}

	return ResultOfShot;
}

std::set<GridPosition> OwnGrid::getShotAt() const {
	return shotAt;
}
