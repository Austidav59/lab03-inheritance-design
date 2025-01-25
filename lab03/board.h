/***********************************************************************
 * Header File:
 *    BOARD 
 * Author:
 *    <your name here>
 * Summary:
 *    A collection of pieces and the state of the board
 ************************************************************************/

#pragma once

#include "move.h"
#include "piece.h"
#include "position.h"

class TestBoard;

class Board
{
public:
    Board();
    virtual ~Board();

    virtual int getCurrentMove() const { return numMoves; }
    virtual bool whiteTurn() const { return numMoves % 2 == 0; }
    virtual void display(const Position & posHover, const Position & posSelect) const {}
    virtual const Piece & operator [] (const Position & pos) const;
    virtual Piece & operator [] (const Position & pos);

    virtual void move(const Move & move);

protected:
    int numMoves;
    Piece * board[8][8];

    friend class TestBoard;
};

class BoardDummy : public Board
{
public:
    BoardDummy() : Board() {}
};

class BoardEmpty : public Board
{
public:
    BoardEmpty() : Board() {}
};
