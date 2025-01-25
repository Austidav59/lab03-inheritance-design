/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#pragma once

#include <string>
#include <cstdint>

const int SIZE_SQUARE = 32;

struct Delta
{
    int dRow;
    int dCol;
};

const Delta ADD_R = { 1,  0};
const Delta ADD_C = { 0,  1};
const Delta SUB_R = {-1,  0};
const Delta SUB_C = { 0, -1};

class PositionTest;  // Forward declaration

class Position
{
public:
    Position();
    Position(const Position & rhs);
    Position(int col, int row);
    Position(const char * s);

    int getRow() const;
    int getCol() const;
    int getLocation() const;
    bool isValid() const;
    bool isInvalid() const;
    
    void setRow(int row);
    void setCol(int col);
    void set(int col, int row);
    void set(const char * s);
    void set(const std::string & s);
    void setInvalid();

    bool operator == (const Position & rhs) const;
    bool operator != (const Position & rhs) const;
    bool operator < (const Position & rhs) const;
    const Position & operator = (const Position & rhs);
    const Position & operator = (const char * rhs);

    int getX() const;
    int getY() const;
    static double getSquareWidth();
    static double getSquareHeight();
    static void setBoardWidthHeight(int width, int height);
    void setXY(double x, double y);

    std::string getText() const;
    const Position & operator += (const Delta & rhs);
    Position operator + (const Delta & rhs) const;

private:
    uint8_t colRow;
    static double squareWidth;
    static double squareHeight;

    friend class PositionTest;
};

std::ostream & operator << (std::ostream & out, const Position & rhs);
std::istream & operator >> (std::istream & in,  Position & rhs);
