#include"AllTests.h"
void part3tests(){

//	Test TakeBlow
	Board board (10, 10);
//test Place Ship
	assertTrue(board.getOwnGrid().placeShip(Ship(GridPosition("A6"),
			GridPosition("A8"))), "Ship(A6 - A8) should be placed");

	assertTrue(board.getOwnGrid().placeShip(Ship(GridPosition("J6"),
			GridPosition("J8"))), "Ship(J6 - J8) should be placed");

	assertTrue(board.getOwnGrid().placeShip(Ship(GridPosition("D1"),
			GridPosition("D5"))), "Ship(D6 - D5) should be placed");

	assertTrue(!board.getOwnGrid().placeShip(Ship(GridPosition("F1"),
			GridPosition("F5"))),"Ship(F1 - F5) should have not been placed");

	assertTrue(!board.getOwnGrid().placeShip(Ship(GridPosition("M1"),
			GridPosition("M2"))), "Ship(M1 - M2) should have not been placed");
	assertTrue(board.getOwnGrid().placeShip(Ship(GridPosition("I10"),
			GridPosition("J10"))), "Ship(I10 - J10) should be placed");
	assertTrue(!board.getOwnGrid().placeShip(Ship(GridPosition("#1"),
			GridPosition("#5"))), "Ship(#1 - #5) should have not been placed");
	assertTrue(!board.getOwnGrid().placeShip(Ship(GridPosition("D6"),
			GridPosition("G6"))), "Ship(D6 - G6) should have not been placed");
	assertTrue(board.getOwnGrid().placeShip(Ship(GridPosition("I1"),
			GridPosition("J1"))), "Ship(I1 - J1) should be placed");
	assertTrue(board.getOwnGrid().placeShip(Ship(GridPosition("I3"),
			GridPosition("I4"))), "Ship(I3 - I4) should be placed");
	assertTrue(!board.getOwnGrid().placeShip(Ship(GridPosition("A6"),
			GridPosition("A7"))), "Ship(A6 - A7) should have not been placed");
	assertTrue(board.getOwnGrid().placeShip(Ship(GridPosition("C7"),
			GridPosition("E7"))), "Ship(C7- E7) should be placed");
	assertTrue(board.getOwnGrid().placeShip(Ship(GridPosition("F9"),
			GridPosition("F10"))), "Ship(F9- F10) should be placed");

//	Test TakeBlow
	assertTrue(board.getOwnGrid().takeBlow(GridPosition {"B1"}) ==
			Shot::Impact::NONE,
			"Blow should have been NONE(B1)");
	assertTrue(board.getOwnGrid().takeBlow(GridPosition {"A6"}) ==
			Shot::Impact::HIT,
			"Blow should have been NONE(B1)");
	assertTrue(board.getOwnGrid().takeBlow(GridPosition {"B2"}) ==
			Shot::Impact::NONE,
			"Blow should have been NONE(B2)");
	assertTrue(board.getOwnGrid().takeBlow(GridPosition {"A7"}) ==
			Shot::Impact::HIT,
			"Blow should have been NONE(B1)");
	assertTrue(board.getOwnGrid().takeBlow(GridPosition {"B3"}) ==
			Shot::Impact::NONE,
			"Blow should have been NONE(B3)");
	assertTrue(board.getOwnGrid().takeBlow(GridPosition {"B4"}) ==
			Shot::Impact::NONE,
			"Blow should have been NONE(B4)");

	assertTrue(board.getOwnGrid().takeBlow(GridPosition {"D2"}) ==
			Shot::Impact::HIT,
			"Blow should have been HIT(D2)");
	assertTrue(board.getOwnGrid().takeBlow(GridPosition {"I4"}) ==
			Shot::Impact::HIT, "Blow should have been HIT(I4)");
	assertTrue(board.getOwnGrid().takeBlow(GridPosition {"A10"}) ==
			Shot::Impact::NONE,
			"Blow should have been NONE(A10)");

//shotResult Test.

	board.getOpponentGrid().shotResult(Shot(GridPosition{"B2"}),
			Shot::Impact::NONE);

	board.getOpponentGrid().shotResult(Shot(GridPosition{"A1"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition{"A3"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition{"A4"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition{"A2"}),
			Shot::Impact::SUNKEN);

	board.getOpponentGrid().shotResult(Shot(GridPosition{"C1"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition{"F1"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition{"E1"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition{"D1"}),
			Shot::Impact::SUNKEN);

	board.getOpponentGrid().shotResult(Shot(GridPosition{"H1"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition{"J1"}),
			Shot::Impact::HIT);


	board.getOpponentGrid().shotResult(Shot(GridPosition{"I3"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition{"H3"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition{"E3"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition{"G3"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition{"F3"}),
			Shot::Impact::SUNKEN);
	board.getOpponentGrid().shotResult(Shot(GridPosition{"I1"}),
			Shot::Impact::SUNKEN);

	board.getOpponentGrid().shotResult(Shot(GridPosition{"E10"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition{"E9"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition{"E7"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition{"E5"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition{"E8"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition{"Z26"}),
			Shot::Impact::NONE);


	ConsoleView view (&board);
	view.print();

}



