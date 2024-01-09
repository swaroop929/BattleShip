#include "GridPosition.h"

using namespace std;

GridPosition::GridPosition(char row, int column) {
	this->row = row;
	this->column = column;
}

GridPosition::GridPosition(std::string position) {
	this->row = position.at(0);
	this->column = (stoi)(position.erase(0, 1));
}

bool GridPosition::isValid() const {
	if (((row >= 65 && row <= 90)) && (column >= 1 && column <= 26))
		return true;
	else
		return false;
}

char GridPosition::getRow() const{
	return this->row;
}

int GridPosition::getColumn() const{
	return this->column;
}

GridPosition::operator std::string()const{
	 return string(1,row) + to_string(column);
}

bool GridPosition::operator ==(GridPosition other) const{
		return (this->row == other.row && this->column == other.column);

}

//Use: When inserting into a set just by overloading < operator the set can \
if element exists in it or not
bool GridPosition::operator <(GridPosition other) const{
	if((row==other.row))
		return column<other.column;
	else
		return row<other.row;

}
