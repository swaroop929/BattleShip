#include <cstdlib>
#include "ConsoleView.h"
//#include "sampletests.h"
#include "AllTests.h"

using namespace std;

// Main program
int main() {

	//part1tests();


    // Test GridPosition
    /*GridPosition posA('A', 5); //crct
    GridPosition posB('B', 10); //crct
    GridPosition invalidPos('Z', 30);  // Assume this is outside your grid

    cout << "Position A is valid: " << posA.isValid() << endl;
    cout << "Position B is valid: " << posB.isValid() << endl;
    cout << "Invalid Position is valid: " << invalidPos.isValid() << endl;

    // Test Ship
    Ship validShipH(posA, GridPosition('A', 8));  // Horizontal ship
    Ship validShipV(posA, GridPosition('D', 5));  // Vertical ship
    Ship invalidShip(posA, posB);  // Invalid ship

    cout << "Horizontal Ship is valid: " << validShipH.isValid() << endl;
    cout << "Vertical Ship is valid: " << validShipV.isValid() << endl;
    cout << "Invalid Ship is valid: " << invalidShip.isValid() << endl;

    // Test Ship Length
    cout << "Length of Horizontal Ship: " << validShipH.length() << endl;
    cout << "Length of Vertical Ship: " << validShipV.length() << endl;

    // Test Occupied Area
    set<GridPosition> occupiedH = validShipH.occupiedArea();
    cout << "Occupied area of Horizontal Ship: ";
    for (const auto& pos : occupiedH) {
        cout << static_cast<string>(pos) << " ";
    }
    cout << endl;

    set<GridPosition> occupiedV = validShipV.occupiedArea();
    cout << "Occupied area of Vertical Ship: ";
    for (const auto& pos : occupiedV) {
        cout << static_cast<string>(pos) << " ";
    }
    cout << endl;*/

//	Board board(10,10);
//
//	OwnGrid& myGrid = board.getOwnGrid();
//	OpponentGrid& OppGrid = board.getOpponentGrid();
//
//	//string b = GridPosition("B4");
//
//	Ship s1(GridPosition("B4"),GridPosition("B1")); //4
//	Ship s2(GridPosition("G4"),GridPosition("D4")); //4
//	Ship s3(GridPosition("F7"),GridPosition("F9")); //3
//	Ship s4(GridPosition("H10"),GridPosition("H6")); //5
//	Ship s5(GridPosition("D10"),GridPosition("C10")); //2
//	Ship s6(GridPosition("J6"),GridPosition("J8")); //3
//	//Ship s7(GridPosition("E6"),GridPosition("E9")); //4
//	Ship s8(GridPosition("D6"),GridPosition("D7")); //2
//	Ship s9(GridPosition("D1"),GridPosition("D2")); //2
//	Ship s10(GridPosition("A6"),GridPosition("A8")); //3
//	Ship s11(GridPosition("H1"),GridPosition("H2")); //2
//
//	/*set<GridPosition> Grid;
//	Grid = s10.blockedArea();
//
//	for(auto i:Grid){
//		cout<<i.getRow()<<i.getColumn()<<endl;
//	}*/
//
//	myGrid.placeShip(s1);
//	myGrid.placeShip(s2);
//	myGrid.placeShip(s3);
//	myGrid.placeShip(s4);
//	myGrid.placeShip(s5);
//	myGrid.placeShip(s6);
//	//myGrid.placeShip(s7);
//	myGrid.placeShip(s8);
//	myGrid.placeShip(s9);
//	myGrid.placeShip(s10);
//	myGrid.placeShip(s11);
//
//	myGrid.takeBlow(GridPosition("A7"));
//	myGrid.takeBlow(GridPosition("A6"));
//	myGrid.takeBlow(GridPosition("A8"));
//	myGrid.takeBlow(GridPosition("A9")); //miss
//	myGrid.takeBlow(GridPosition("H1"));
//	myGrid.takeBlow(GridPosition("H2"));
//	myGrid.takeBlow(GridPosition("B1"));
//	myGrid.takeBlow(GridPosition("B2"));
//	myGrid.takeBlow(GridPosition("B3"));
//	myGrid.takeBlow(GridPosition("B4"));
//	myGrid.takeBlow(GridPosition("B5")); //miss
//	myGrid.takeBlow(GridPosition("I1"));
//	myGrid.takeBlow(GridPosition("J7"));
//	myGrid.takeBlow(GridPosition("D1"));
//	//myGrid.takeBlow(GridPosition("D2"));
//
//
//	OppGrid.shotResult(GridPosition("C2"),Shot::Impact::NONE);
//	OppGrid.shotResult(GridPosition("F5"),Shot::Impact::NONE);
//	OppGrid.shotResult(GridPosition("G4"),Shot::Impact::NONE);
//	OppGrid.shotResult(GridPosition("G5"),Shot::Impact::HIT);
//	OppGrid.shotResult(GridPosition("G6"),Shot::Impact::HIT);
//	OppGrid.shotResult(GridPosition("I5"),Shot::Impact::NONE);
//	OppGrid.shotResult(GridPosition("C3"),Shot::Impact::HIT);
//	OppGrid.shotResult(GridPosition("C4"),Shot::Impact::HIT);
//	OppGrid.shotResult(GridPosition("C5"),Shot::Impact::SUNKEN);
//
//	/*for(auto shot:OppGrid.getShotsAt())
//		cout<<shot.first.getRow()<<shot.first.getColumn()<<endl;*/
//
//	//C2 C3 C4 C5 F5 G4 G5 G6 I5
//
//
//
//
//
//	/*vector<Ship> v = myGrid.getShips();
//	set<GridPosition> OccupArea;
//	vector<GridPosition> ShipsPositions;
//
//	for (auto elem : v) {
//		OccupArea = (elem.occupiedArea());
//
//		for (auto i : OccupArea)
//			ShipsPositions.push_back(i);
//	}*/
//
//	/*map<GridPosition, char> gridMap;
//	    for (auto& ship : v) {
//	        for (auto& pos : ship.occupiedArea()) {
//	            gridMap[pos] = '#';
//	        }
//	    }
//
//	    // Print
//	    cout << "  "; // Top left corner spacing
//	    for (int col = 1; col <= 10; col++) { // Printing column numbers
//	        cout << col << " ";
//	    }
//	    cout << endl;
//
//	    for (int row = 1; row <= 10; row++) {
//	        cout << static_cast<char>('A' + row - 1) << " "; // Printing row letters
//	        for (int col = 1; col <= 10; col++) {
//	            GridPosition currentPos(static_cast<char>('A' + row - 1), col);
//	            if (gridMap.find(currentPos) != gridMap.end()) {
//	                cout << gridMap[currentPos] << " "; // Print ship
//	            } else {
//	                cout << "~ "; // Print water
//	            }
//	        }
//	        cout << endl;
//	    }*/
//
//	ConsoleView ViewBoard(&board);
//	ViewBoard.print();

	part1tests();
	part2tests();
	part3tests();







	return 0;
}

