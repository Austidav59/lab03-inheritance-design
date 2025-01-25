/***********************************************************************
 * Source File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

// position.cpp
#include "position.h"
#include <cassert>
#include <string>
#include <cmath>
#include "iostream"

double Position::squareWidth = SIZE_SQUARE;
double Position::squareHeight = SIZE_SQUARE;

Position::Position() : colRow(0xFF) {}

Position::Position(const Position & rhs) : colRow(rhs.colRow) {}

Position::Position(int col, int row) : colRow(0)
{
    set(col, row);
}

Position::Position(const char * s) : colRow(0)
{
    set(s);
}

int Position::getRow() const
{
    return isValid() ? (colRow & 0x07) : -1;
}

int Position::getCol() const
{
    return isValid() ? ((colRow & 0x70) >> 4) : -1;
}

int Position::getLocation() const
{
    return isValid() ? (getRow() * 8 + getCol()) : -1;
}

bool Position::isValid() const
{
    return (colRow & 0x88) == 0;
}

bool Position::isInvalid() const
{
    return !isValid();
}

void Position::setRow(int row)
{
    set(getCol(), row);
}

void Position::setCol(int col)
{
    set(col, getRow());
}

void Position::set(int col, int row)
{
    if (col >= 0 && col < 8 && row >= 0 && row < 8)
        colRow = (col << 4) | row;
    else
        setInvalid();
}

void Position::set(const char * s)
{
    if (s[0] >= 'a' && s[0] <= 'h' && s[1] >= '1' && s[1] <= '8')
        set(s[0] - 'a', s[1] - '1');
    else
        setInvalid();
}

void Position::set(const std::string & s)
{
    set(s.c_str());
}

void Position::setInvalid()
{
    colRow = 0xFF;
}

bool Position::operator == (const Position & rhs) const
{
    return this->colRow == rhs.colRow;
}

bool Position::operator != (const Position & rhs) const
{
    return !(*this == rhs);
}

bool Position::operator < (const Position & rhs) const
{
    return this->colRow < rhs.colRow;
}

const Position & Position::operator = (const Position & rhs)
{
    colRow = rhs.colRow;
    return *this;
}

const Position & Position::operator = (const char * rhs)
{
    set(rhs);
    return *this;
}

int Position::getX() const
{
    return getCol() * SIZE_SQUARE;
}

int Position::getY() const
{
    return (7 - getRow()) * SIZE_SQUARE;
}

double Position::getSquareWidth()
{
    return squareWidth;
}

double Position::getSquareHeight()
{
    return squareHeight;
}

void Position::setBoardWidthHeight(int width, int height)
{
    squareWidth = static_cast<double>(width) / 8.0;
    squareHeight = static_cast<double>(height) / 8.0;
}

void Position::setXY(double x, double y)
{
    int col = static_cast<int>(x / squareWidth);
    int row = 7 - static_cast<int>(y / squareHeight);
    if (col < 0 || col > 7 || row < 0 || row > 7)
    {
        setInvalid();
    }
    else
    {
        colRow = (col << 4) | row;
    }
}

std::string Position::getText() const
{
    if (!isValid())
        return "??";
    char col = 'a' + getCol();
    char row = '1' + getRow();
    return std::string(1, col) + std::string(1, row);
}

const Position & Position::operator += (const Delta & rhs)
{
    if (isValid())
    {
        int newCol = getCol() + rhs.dCol;
        int newRow = getRow() + rhs.dRow;
        set(newCol, newRow);
    }
    return *this;
}

Position Position::operator + (const Delta & rhs) const
{
    Position result(*this);
    result += rhs;
    return result;
}

std::ostream & operator << (std::ostream & out, const Position & rhs)
{
    out << rhs.getText();
    return out;
}

std::istream & operator >> (std::istream & in, Position & rhs)
{
    std::string text;
    in >> text;
    rhs.set(text);
    return in;
}
