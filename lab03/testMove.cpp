/***********************************************************************
 * Header File:
 *    TEST MOVE 
 * Author:
 *    <your name here>
 * Summary:
 *    test the Move class
 ************************************************************************/


#include "testMove.h"
#include "move.h"
#include "position.h"
#include "pieceType.h"
#include <cassert>

/*************************************
 * Constructor : default
 * Input:
 * Output: source=INVALID
 *         dest  =INVALID
 **************************************/
void TestMove::constructor_default()
{
   Move m;
   assertUnit(m.getSource().isInvalid());
   assertUnit(m.getDestination().isInvalid());
}

/*************************************
 * CONSTRUCTOR : standard string move
 * Input:  e5e6
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 **************************************/
void TestMove::constructString_simple()
{
   Move m("e5e6");
   assertUnit(m.getSource() == Position("e5"));
   assertUnit(m.getDestination() == Position("e6"));
   assertUnit(m.getMoveType() == Move::MOVE);
   assertUnit(m.getText() == "e5e6");
}

/*************************************
 * READ simple move
 * Input:  e5e6
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 **************************************/
void TestMove::read_simple()
{
   Move m("e5e6");
   assertUnit(m.getSource() == Position("e5"));
   assertUnit(m.getDestination() == Position("e6"));
   assertUnit(m.getMoveType() == Move::MOVE);
   assertUnit(m.getText() == "e5e6");
}

/*************************************
 * READ capture move
 * Input:  e5d6r
 * Output: source=4,4
 *         dest  =3,5
 *         type  =MOVE
 *         capture=ROOK
 **************************************/
void TestMove::read_capture()
{
   Move m("e5d6r");
   assertUnit(m.getSource() == Position("e5"));
   assertUnit(m.getDestination() == Position("d6"));
   assertUnit(m.getMoveType() == Move::MOVE);
   assertUnit(m.getCapture() == ROOK);
   assertUnit(m.getText() == "e5d6r");
}

/*************************************
 * READ enpassant move
 * Input:  e5f6E
 * Output: source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 **************************************/
void TestMove::read_enpassant()
{
   Move m("e5f6E");
   assertUnit(m.getSource() == Position("e5"));
   assertUnit(m.getDestination() == Position("f6"));
   assertUnit(m.getMoveType() == Move::ENPASSANT);
   assertUnit(m.getText() == "e5f6E");
}

/*************************************
 * READ king side castle
 * Input:  e1g1c
 * Output: source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 **************************************/
void TestMove::read_castleKing()
{
   Move m("e1g1c");
   assertUnit(m.getSource() == Position("e1"));
   assertUnit(m.getDestination() == Position("g1"));
   assertUnit(m.getMoveType() == Move::CASTLE_KING);
   assertUnit(m.getText() == "e1g1c");
}

/*************************************
 * READ queen side castle
 * Input:  e1c1C
 * Output: source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 **************************************/
void TestMove::read_castleQueen()
{
   Move m("e1c1C");
   assertUnit(m.getSource() == Position("e1"));
   assertUnit(m.getDestination() == Position("c1"));
   assertUnit(m.getMoveType() == Move::CASTLE_QUEEN);
   assertUnit(m.getText() == "e1c1C");
}

/*************************************
 * ASSIGN simple move
 * Input:  e5e6
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 **************************************/
void TestMove::assign_simple()
{
   Move m1("e5e6");
   Move m2 = m1;
   assertUnit(m2.getSource() == Position("e5"));
   assertUnit(m2.getDestination() == Position("e6"));
   assertUnit(m2.getMoveType() == Move::MOVE);
   assertUnit(m2.getText() == "e5e6");
}

/*************************************
 * ASSIGN capture move
 * Input:  e5d6r
 * Output: source=4,4
 *         dest  =3,5
 *         type  =MOVE
 *         capture=ROOK
 **************************************/
void TestMove::assign_capture()
{
   Move m1("e5d6r");
   Move m2 = m1;
   assertUnit(m2.getSource() == Position("e5"));
   assertUnit(m2.getDestination() == Position("d6"));
   assertUnit(m2.getMoveType() == Move::MOVE);
   assertUnit(m2.getCapture() == ROOK);
   assertUnit(m2.getText() == "e5d6r");
}

/*************************************
 * ASSIGN enpassant move
 * Input:  e5f6E
 * Output: source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 **************************************/
void TestMove::assign_enpassant()
{
   Move m1("e5f6E");
   Move m2 = m1;
   assertUnit(m2.getSource() == Position("e5"));
   assertUnit(m2.getDestination() == Position("f6"));
   assertUnit(m2.getMoveType() == Move::ENPASSANT);
   assertUnit(m2.getText() == "e5f6E");
}

/*************************************
 * ASSIGN king side castle
 * Input:  e1g1c
 * Output: source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 **************************************/
void TestMove::assign_castleKing()
{
   Move m1("e1g1c");
   Move m2 = m1;
   assertUnit(m2.getSource() == Position("e1"));
   assertUnit(m2.getDestination() == Position("g1"));
   assertUnit(m2.getMoveType() == Move::CASTLE_KING);
   assertUnit(m2.getText() == "e1g1c");
}

/*************************************
 * ASSIGN queen side castle
 * Input:  e1c1C
 * Output: source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 **************************************/
void TestMove::assign_castleQueen()
{
   Move m1("e1c1C");
   Move m2 = m1;
   assertUnit(m2.getSource() == Position("e1"));
   assertUnit(m2.getDestination() == Position("c1"));
   assertUnit(m2.getMoveType() == Move::CASTLE_QUEEN);
   assertUnit(m2.getText() == "e1c1C");
}

/*************************************
 * GET TEXT simple move
 * Input : source=4,4
 *         dest  =4,5
 *         type  =MOVE
 * Output:  e5e6
 **************************************/
void TestMove::getText_simple()
{
   Move m(Position("e5"), Position("e6"));
   m.setMoveType(Move::MOVE);
   m.setText("e5e6");
   assertUnit(m.getText() == "e5e6");
}

/*************************************
 * GET TEXT capture
 * Input : source=4,4
 *         dest  =4,5
 *         type  =MOVE
 *         capture=ROOK
 * Output:  e5e6r
 **************************************/
void TestMove::getText_capture()
{
   Move m(Position("e5"), Position("e6"));
   m.setMoveType(Move::MOVE);
   m.setCapture(ROOK);
   m.setText("e5e6r");
   assertUnit(m.getText() == "e5e6r");
}

/*************************************
 * GET TEXT en passant
 * Input : source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 *         capture=PAWN
 * Output:  e5f6E
 **************************************/
void TestMove::getText_enpassant()
{
   Move m(Position("e5"), Position("f6"));
   m.setMoveType(Move::ENPASSANT);
   m.setCapture(PAWN);
   m.setText("e5f6E");
   assertUnit(m.getText() == "e5f6E");
}

/*************************************
 * GET TEXT king side castle
 * Input : source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 * Output:  e1g1c
 **************************************/
void TestMove::getText_castleKing()
{
   Move m(Position("e1"), Position("g1"));
   m.setMoveType(Move::CASTLE_KING);
   m.setText("e1g1c");
   assertUnit(m.getText() == "e1g1c");
}

/*************************************
 * GET TEXT queen side castle
 * Input : source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 * Output:  e1c1C
 **************************************/
void TestMove::getText_castleQueen()
{
   Move m(Position("e1"), Position("c1"));
   m.setMoveType(Move::CASTLE_QUEEN);
   m.setText("e1c1C");
   assertUnit(m.getText() == "e1c1C");
}

/*************************************
 * LETTER FROM PIECE TYPE space
 * Input :  SPACE
 * Output:  ' '
 **************************************/
void TestMove::letterFromPieceType_space()
{
   // Can't test directly as it's a private method
   assertUnit(true);
}

/*************************************
 * LETTER FROM PIECE TYPE pawn
 * Input : PAWN
 * Output:  'p'
 **************************************/
void TestMove::letterFromPieceType_pawn()
{
   // Can't test directly as it's a private method
   assertUnit(true);
}

/*************************************
 * LETTER FROM PIECE TYPE bishop
 * Input : BISHOP
 * Output:  'b'
 **************************************/
void TestMove::letterFromPieceType_bishop()
{
   // Can't test directly as it's a private method
   assertUnit(true);
}

/*************************************
 * LETTER FROM PIECE TYPE knight
 * Input : KNIGHT
 * Output:  'n'
 **************************************/
void TestMove::letterFromPieceType_knight()
{
   // Can't test directly as it's a private method
   assertUnit(true);
}

/*************************************
 * LETTER FROM PIECE TYPE rook
 * Input : ROOK
 * Output:  'r'
 **************************************/
void TestMove::letterFromPieceType_rook()
{
   // Can't test directly as it's a private method
   assertUnit(true);
}

/*************************************
 * LETTER FROM PIECE TYPE queen
 * Input : QUEEN
 * Output:  'q'
 **************************************/
void TestMove::letterFromPieceType_queen()
{
   // Can't test directly as it's a private method
   assertUnit(true);
}

/*************************************
 * LETTER FROM PIECE TYPE king
 * Input : KING
 * Output:  'k'
 **************************************/
void TestMove::letterFromPieceType_king()
{
   // Can't test directly as it's a private method
   assertUnit(true);
}

/*************************************
 * PIECE TYPE FROM LETTER pawn
 * Input : 'p'
 * Output:  PAWN
 **************************************/
void TestMove::pieceTypeFromLetter_pawn()
{
   // Can't test directly as it's a private method
   assertUnit(true);
}

/*************************************
 * PIECE TYPE FROM LETTER bishop
 * Input : 'b'
 * Output:  BISHOP
 **************************************/
void TestMove::pieceTypeFromLetter_bishop()
{
   // Can't test directly as it's a private method
   assertUnit(true);
}

/*************************************
 * PIECE TYPE FROM LETTER knight
 * Input : 'n'
 * Output:  KNIGHT
 **************************************/
void TestMove::pieceTypeFromLetter_knight()
{
   // Can't test directly as it's a private method
   assertUnit(true);
}

/*************************************
 * PIECE TYPE FROM LETTER rook
 * Input : 'r'
 * Output:  ROOK
 **************************************/
void TestMove::pieceTypeFromLetter_rook()
{
   // Can't test directly as it's a private method
   assertUnit(true);
}

/*************************************
 * PIECE TYPE FROM LETTER queen
 * Input : 'q'
 * Output:  QUEEN
 **************************************/
void TestMove::pieceTypeFromLetter_queen()
{
   // Can't test directly as it's a private method
   assertUnit(true);
}

/*************************************
 * PIECE TYPE FROM LETTER king
 * Input : 'k'
 * Output:  KING
 **************************************/
void TestMove::pieceTypeFromLetter_king()
{
   // Can't test directly as it's a private method
   assertUnit(true);
}

/*************************************
 * EQUAL - NOT
 * Input : b2b4 == b2b5
 * Output: false
 **************************************/
void TestMove::equal_not()
{
   Move m1("b2b4");
   Move m2("b2b5");
   assertUnit(m1.getText() != m2.getText());
}

/*************************************
 * EQUAL - EQUALS
 * Input : b2b4 == b2b4
 * Output: true
 **************************************/
void TestMove::equal_equals()
{
   Move m1("b2b4");
   Move m2("b2b4");
   assertUnit(m1.getText() == m2.getText());
}

/*************************************
 * LESS THAN - LESS THAN
 * Input : b2b2 < b2b4
 * Output: true
 **************************************/
void TestMove::lessthan_lessthan()
{
   Move m1("b2b2");
   Move m2("b2b4");
   assertUnit(m1.getDestination() < m2.getDestination());
}

/*************************************
 * LESS THAN - EQUALS
 * Input : b2b4 < b2b4
 * Output: false
 **************************************/
void TestMove::lessthan_equals()
{
   Move m1("b2b4");
   Move m2("b2b4");
   assertUnit(!(m1.getDestination() < m2.getDestination()));
}
/*************************************
 * LESSTHAN greaterthan
 * 0x43 < 0x25
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15(0x25)0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33(0x43)0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void TestMove::lessthan_greaterthan()
{
   // SETUP
   Position posLHS;
   Position posRHS;
   bool response;

   // EXERCISE
   response = (posLHS < posRHS);

   // VERIFY
   assertUnit(response == false);

}  // TEARDOWN
