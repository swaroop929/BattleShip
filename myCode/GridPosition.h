#include<iostream>
#include<string.h>
#include<cstdlib>
#include<sstream>

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

class GridPosition {
private:
	char row; //Should be between A to Z only
	int column; //should be >= 1
public:
	/**
	 * @brief "Constructor for the GridPosition class which takes in
	 * the row as a char and the column as integer"
	 * @param row	 "row coordinate of the Grid"
	 * @param column "Col coordinate of the grid"
	 */
	GridPosition(char row, int column);
	/**
	 * @brief "Constructor for the class GridPositon that takes in String input"
	 * @param position "Position coordinates which has both Row and column"
	 */
	GridPosition(std::string position);
	/**
	 * @brief "Checks validity of given GridPosition A<=row<=Z and if column>=1"
	 * @return bool True if it passes else False
	 */
	bool isValid() const;
	/**
	 * @brief "Used to get the row coordinate of the GridPosition"
	 * @return "The data member row of the GridPositon"
	 */
	char getRow() const;
	/**
	 * @brief "Used to get the col coordinate of the GridPosition"
	 * @return "The data member column of the GridPositon"
	 */
	int getColumn() const;

	/**
	 * @brief "Used to concatenate the GridPosition into a string when
	 * entered as seperate Character, integer"
	 */
	operator std::string() const;

	/*
	 * @brief "Operator overlaoding for == to compare 2 GridPositon objects"
	 */
	bool operator==(GridPosition other) const;

	/*
	 * @brief "Used when inserting GridPositon in sets or Maps as they take in unique
	 * elements and for comaprison we need to overload the < operator."
	 */
	bool operator<(GridPosition other) const;
};

#endif /* GRIDPOSITION_H_ */
