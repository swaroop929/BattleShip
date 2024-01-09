#include "ConsoleView.h"

using namespace std;

ConsoleView::ConsoleView(Board *board) :
		board(board) {
}

void ConsoleView::print() {
	//Decleartions
	OwnGrid myGrid = board->getOwnGrid();
	OpponentGrid OppGrid = board->getOpponentGrid();

	set<GridPosition> AllShipGrids;
	set<GridPosition> AllShotGrids;

	for (auto ship : myGrid.getShips()) {
		for (auto grid : ship.occupiedArea()) {
			AllShipGrids.insert(grid);
		}
	}

	for (auto shot : myGrid.getShotAt()) {
		AllShotGrids.insert(shot);
	}

	map<pair<int, int>, string> OwnChart;
	map<pair<int, int>, string> OppChart;
	int rows = myGrid.getRows();
	int cols = myGrid.getColumns();

	//OwnChart.first.first=rows; //TODO: Get clarification

	cout << "  "; //Top corner

	for (int col = 1; col <= cols; col++) { //Own Grid
		cout << col << " ";
	}

	cout << "    ";

	for (int col = 1; col <= cols; col++) { //Opponent Grid
		cout << col << " ";
	}

	cout << endl; //next row to print rows

	for (int row = 1; row <= rows; row++) {
		//cout << (char) ('A' + row - 1) <<" ";
		for (int col = 1; col <= cols; col++) {
			OwnChart[pair<int, int>(row, col)] = "~ ";
			for (auto ShipGrid : AllShipGrids) { //Ships
				if (ShipGrid.getColumn() == col
						&& ShipGrid.getRow() == (char) (row + 'A' - 1)) {
					OwnChart[pair<int, int>(row, col)] = "# ";
				}
			}
			for (auto shotGrid : AllShotGrids) { //shots
				if (shotGrid.getColumn() == col
						&& (shotGrid.getRow() == (char) (row + 'A' - 1))) {
					if (myGrid.takeBlow(shotGrid) == Shot::Impact::HIT
							|| myGrid.takeBlow(shotGrid)
									== Shot::Impact::SUNKEN)
						OwnChart[pair<int, int>(row, col)] = "O ";
					else if (myGrid.takeBlow(shotGrid) == Shot::Impact::NONE)
						OwnChart[pair<int, int>(row, col)] = "^ ";
				}
			}
			//cout<<OwnChart[pair<int,int>(row,col)];
		}
		//cout<<endl;//next row
	}

	map<GridPosition, Shot::Impact> AllShotsOnOpponent = OppGrid.getShotsAt();
	set<GridPosition> AllSunkenShipsGridPos;

	for (auto Ship : OppGrid.getSunkenShips()) {
		for (auto ShipGrid : Ship.occupiedArea()) {
			AllSunkenShipsGridPos.insert(ShipGrid);
		}
	}

	for (int row = 1; row <= rows; row++) {
		for (int col = 1; col <= cols; col++) {
			OppChart[pair<int, int>(row, col)] = "~ ";

			for (auto shot : AllShotsOnOpponent) {
				if (shot.first.getColumn() == col
						&& (shot.first.getRow() == (char) (row + 'A' - 1))) {
					if (shot.second == Shot::Impact::HIT)
						OppChart[pair<int, int>(row, col)] = "O ";
				}
			}
			for (auto shot : AllShotsOnOpponent) {
				if (shot.first.getColumn() == col
						&& (shot.first.getRow() == (char) (row + 'A' - 1))) {
					if (shot.second == Shot::Impact::NONE)
						OppChart[pair<int, int>(row, col)] = "^ ";
				}
			}
			for (auto shot : AllShotsOnOpponent) {
				//if (shot.first.getColumn() == col
				//&& (shot.first.getRow() == (char) (row + 'A' - 1))) {
				if (shot.second == Shot::Impact::SUNKEN) {
					for (auto SunkenshipGrid : AllSunkenShipsGridPos) {
						OppChart[pair<int, int>(
								(int) (SunkenshipGrid.getRow() - 64),
								SunkenshipGrid.getColumn())] = "# ";
						//}

					}
				}
			}

		}
	}

	for (int row = 1; row <= rows; row++) {
		cout << (char) ('A' + row - 1) << " "; //Own Grid A B C D
		for (int col = 1; col <= cols; col++) {
			cout << OwnChart[pair<int, int>(row, col)];
		}

		cout << "   "; //Gap between 2 grids

		cout << (char) ('A' + row - 1) << " "; //Opp Grid A B C D
		for (int col = 1; col <= cols; col++) {
			cout << OppChart[pair<int, int>(row, col)];
		}
		cout << endl;
	}

}
