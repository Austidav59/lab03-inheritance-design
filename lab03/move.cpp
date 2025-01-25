/***********************************************************************
 * Source File:
 *    MOVE 
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/
#include "move.h"
#include <cassert>
#include <cstring>

Move::Move() : promote(SPACE), capture(SPACE), moveType(MOVE), fWhite(true) {}

Move::Move(const Position & source, const Position & dest)
    : source(source), dest(dest), promote(SPACE), capture(SPACE), moveType(MOVE), fWhite(true)
{
    text = source.getText() + dest.getText();
}

Move::Move(const char * moveText) : promote(SPACE), capture(SPACE), moveType(MOVE), fWhite(true)
{
    assert(moveText != nullptr);
    text = moveText;

    if (strlen(moveText) < 4)
    {
        moveType = MOVE_ERROR;
        return;
    }

    source = Position(moveText);
    dest = Position(moveText + 2);

    if (strlen(moveText) == 5)
    {
        char lastChar = moveText[4];
        if (lastChar == 'E' || lastChar == 'e')
        {
            moveType = ENPASSANT;
            capture = PAWN;
        }
        else if (lastChar == 'c')
            moveType = CASTLE_KING;
        else if (lastChar == 'C')
            moveType = CASTLE_QUEEN;
        else
            capture = pieceTypeFromLetter(lastChar);
    }
}

char Move::letterFromPieceType(PieceType pt) const
{
    switch (pt)
    {
        case KING:   return 'k';
        case QUEEN:  return 'q';
        case ROOK:   return 'r';
        case BISHOP: return 'b';
        case KNIGHT: return 'n';
        case PAWN:   return 'p';
        default:     return ' ';
    }
}

PieceType Move::pieceTypeFromLetter(char letter) const
{
    switch (tolower(letter))
    {
        case 'k': return KING;
        case 'q': return QUEEN;
        case 'r': return ROOK;
        case 'b': return BISHOP;
        case 'n': return KNIGHT;
        case 'p': return PAWN;
        default:  return SPACE;
    }
}

void Move::setCapture(PieceType piece)
{
    capture = piece;
    if (text.length() == 4)
    {
        text += letterFromPieceType(piece);
    }
}

void Move::setMoveType(MoveType type)
{
    moveType = type;
    if (type == ENPASSANT)
    {
        capture = PAWN;
        if (text.length() == 4)
        {
            text += 'E';
        }
    }
}

