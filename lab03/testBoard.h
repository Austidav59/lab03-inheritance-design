/***********************************************************************
 * Header File:
 *    TEST BOARD
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for Board
 ************************************************************************/

#pragma once

#include "unitTest.h"
#include "board.h"

class TestBoard : public UnitTest
{
public:
    void run() override;

private:
    void construct_dummyBoard();
    void construct_emptyBoard();
    void getCurrentMove_initial();
    void getCurrentMove_second();
    void getCurrentMove_middleWhite();
    void getCurrentMove_middleBlack();
    void whiteTurn_initial();
    void whiteTurn_second();
    void whiteTurn_middleWhite();
    void whiteTurn_middleBlack();
    void fetch_a1();
    void set_a1();
    void fetch_h8();
    void set_h8();
    void fetch_a8();
    void set_a8();

    void createDummyBoard(Board& board);
};
