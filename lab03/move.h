/***********************************************************************
 * Header File:
 *    MOVE 
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/
#pragma once

#include "position.h"
#include "pieceType.h"
#include <string>

class Move
{
public:
    enum MoveType { MOVE, ENPASSANT, CASTLE_KING, CASTLE_QUEEN, MOVE_ERROR };

    Move();
    Move(const Position & source, const Position & dest);
    Move(const char * text);

    Position getSource() const { return source; }
    Position getDestination() const { return dest; }
    PieceType getPromotion() const { return promote; }
    PieceType getCapture() const { return capture; }
    MoveType getMoveType() const { return moveType; }
    bool isWhite() const { return fWhite; }
    std::string getText() const { return text; }

    void setSource(const Position & pos) { source = pos; }
    void setDestination(const Position & pos) { dest = pos; }
    void setPromotion(PieceType piece) { promote = piece; }
    void setCapture(PieceType piece);
    void setMoveType(MoveType type);
    void setWhite(bool white) { fWhite = white; }
    void setText(const std::string & moveText) { text = moveText; }

private:
    Position source;
    Position dest;
    PieceType promote;
    PieceType capture;
    MoveType moveType;
    bool fWhite;
    std::string text;

    char letterFromPieceType(PieceType pt) const;
    PieceType pieceTypeFromLetter(char letter) const;
};

