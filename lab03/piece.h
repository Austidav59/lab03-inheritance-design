/***********************************************************************
 * Header File:
 *    PIECE
 * Author:
 *    <your name here>
 * Summary:
 *    The Piece base class and all the derived classes:
 *       SPACE, KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN
 ************************************************************************/

#pragma once
#include "position.h"
#include "pieceType.h"

class Piece
{
public:
    Piece() : fWhite(true) {}
    virtual ~Piece() {}
    bool fWhite;
};

class Space : public Piece
{
public:
    Space() : Piece() {}
};

class PieceDummy : public Piece
{
public:
    PieceDummy() : Piece() {}
};
