/***********************************************************************
 * Source File:
 *    BOARD
 * Author:
 *    <your name here>
 * Summary:
 *    A collection of pieces and the state of the board
 ************************************************************************/
#include "board.h"
#include <cassert>
#include "position.h"

Board::Board() : numMoves(0)
{
    for (int r = 0; r < 8; r++)
        for (int c = 0; c < 8; c++)
            board[c][r] = nullptr;
}

Board::~Board()
{
    for (int r = 0; r < 8; r++)
        for (int c = 0; c < 8; c++)
            delete board[c][r];
}

const Piece & Board::operator [] (const Position & pos) const
{
    static Space emptySpace;  // Static empty space to return for invalid positions
    if (!pos.isValid())
    {
        return emptySpace;
    }
    Piece * p = board[pos.getCol()][pos.getRow()];
    return p ? *p : emptySpace;
}

Piece & Board::operator [] (const Position & pos)
{
    static Space emptySpace;  // Static empty space to return for invalid positions
    if (!pos.isValid())
    {
        return emptySpace;
    }
    Piece * p = board[pos.getCol()][pos.getRow()];
    return p ? *p : emptySpace;
}

void Board::move(const Move & move)
{
    Position src = move.getSource();
    Position dst = move.getDestination();

    if (src.isValid() && dst.isValid())
    {
        Piece* p = board[src.getCol()][src.getRow()];
        if (p)
        {
            // Move the piece to the new position
            board[dst.getCol()][dst.getRow()] = p;
            board[src.getCol()][src.getRow()] = nullptr;
            numMoves++;
            
            // If the Piece class has a method to update its position, call it here
            // For example: p->setPosition(dst);
        }
    }
}


