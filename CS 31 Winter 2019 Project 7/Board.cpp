//
//  Board.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Board.h"


namespace cs31
{
    Board::Board() : mHumanScore( 0 ), mHumanTotal(0), mComputerScore(0), mComputerTotal(0),
                     mRolledValue(0), mIsHumanTurn(true), mGameOver(false), mHumanWon(false)
    {

    }
    
    // mutator for the gameOver boolean member
    void Board::setGameOver( bool value )
    {
        mGameOver = value;
    }
    
    // accessor for the gameOver boolean member
    bool Board::isGameOver( ) const
    {
        return( mGameOver );
    }

    // mutator for the humanWon boolean member
    void Board::markHumanAsWinner()
    {
        mHumanWon = true;
    }
    
    // mutator for the computerWon boolean member
    void Board::markComputerAsWinner()
    {
        mHumanWon = false;
    }
    
    // accessor for the humanWon boolean member
    bool Board::isHumanWinner() const
    {
        return( mHumanWon );
    }
    
    
    void Board::setHumanScore( int score )
    {
        if (isHumanTurn() && !isGameOver() ) {
            mHumanScore = score;
            
        }
    }
    
    
    int  Board::getHumanScore() const
    {
        return( mHumanScore );
    }
    
    
    void Board::setComputerScore( int score )
    {
        if ( !isHumanTurn() && !isGameOver() ) {
            mComputerScore = score;
            
        }
    }
    
    
    int  Board::getComputerScore() const
    {
        return( mComputerScore );
    }
    
    // mutator for the rolledValue data member
    void Board::setRolledValue( int amount )
    {
        if (!mGameOver)
            mRolledValue = amount;
    }
    
    // accessor for the rolledValue data member
    int  Board::getRolledValue() const
    {
        return( mRolledValue );
    }
    
    // mutator for the humanTurn member
    void Board::setHumanTurn( )
    {
        // it becomes the human's turn but only if the game isn't over
        if (!mGameOver)
            mIsHumanTurn = true;
    }
    
    // mutator for the computerTurn member
    void Board::setComputerTurn( )
    {
        // it become the computer's turn but only if the game isn't over
        if (!mGameOver)
            mIsHumanTurn = false;
    }
    
    // accessor for the humanTurn boolean member
    bool Board::isHumanTurn() const
    {
        return( mIsHumanTurn );
    }

    
    void Board::setHumanTotal( int total )
    {
        if ( isHumanTurn() && !isGameOver() ) {
            mHumanTotal = total;
        }
    }
    
   
    int  Board::getHumanTotal() const
    {
        return( mHumanTotal );
    }
    
    
    void Board::setComputerTotal( int total ) 
    {
        if ( !isHumanTurn() && !isGameOver() ) {
            mComputerTotal = total;
        }
    }
    
    
    int  Board::getComputerTotal() const
    {
        return( mComputerTotal );
    }
    
    // stringify the Board
    std::string Board::display( ) const
    {
        std::string s = "\t\t  --Pig Game-- \n\tHuman:\t";
        s += std::to_string( mHumanTotal );
        s += "\t\tComputer:\t";
        s += std::to_string( mComputerTotal );
        s += "\n";
        
        return( s );
    }
    


    
}
