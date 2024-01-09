#include"AllTests.h"
#include <iostream>
using namespace std;
void part2tests(){
	//blocked area
	assertTrue(Ship{GridPosition{"B2"}, GridPosition{"B4"}}.blockedArea()
	    == set<GridPosition>{
	        GridPosition{"A1"}, GridPosition{"B1"}, GridPosition{"C1"},
	        GridPosition{"A2"}, GridPosition{"B2"}, GridPosition{"C2"},
	        GridPosition{"A3"}, GridPosition{"B3"}, GridPosition{"C3"},
	        GridPosition{"A4"}, GridPosition{"B4"}, GridPosition{"C4"},
	        GridPosition{"A5"}, GridPosition{"B5"}, GridPosition{"C5"},
	    },
	    "Blocked area not correct");

	//	Test OwnGrid constructor, getRows, GetColumns
	assertTrue(OwnGrid{10, 10}.getRows() == 10, "Row is not 10");
	assertTrue(!(OwnGrid{10, 10}.getRows() != 10), "Row should be 10");
	assertTrue(OwnGrid{10, 10}.getColumns() == 10, "Column is not 10");
	assertTrue(!(OwnGrid{10, 10}.getColumns() != 10), "Column should be 10");

	// Test Place Ships
	OwnGrid grid (10, 10);
	assertTrue(grid.placeShip(Ship(GridPosition("A1"), GridPosition("A5"))),
			"Ship should be placed");

	assertTrue(!grid.placeShip(Ship(GridPosition("I1"), GridPosition("I5"))),
			"Ship should not have been placed");

	assertTrue(!grid.placeShip(Ship(GridPosition("B4"), GridPosition("B5"))),
			"Ship should not have been placed");

	assertTrue(grid.placeShip(Ship(GridPosition("A7"), GridPosition("A8"))),
			"Ship should be placed");

	assertTrue(!grid.placeShip(Ship(GridPosition("@1"), GridPosition("@5"))),
			"Ship should have not been placed @");

	//std::cout<<grid.placeShip(Ship(GridPosition("K1"), GridPosition("K3")));

	assertTrue(!grid.placeShip(Ship(GridPosition("K1"), GridPosition("K3"))),
			"Ship should have not been placed K");

}


