//
//  Player.cpp
//  Pig
//
//

#include "Player.h"

#include <iostream>

namespace cs31
{
    
    Player::Player() : mDie( 6 ), mScore( 0 ), mTotal( 0 )
    {
        
    }
    

    int Player::roll( int amount )
    {
        if (amount == 0) // when amount is zero
        {
            mDie.roll(); // roll the die
            amount = mDie.getValue();
            
            if (amount == 1) // no points if rolled 1
                mScore = 0;
            else
                mScore = mScore + amount;
            
            return( amount );
        }
        
        else if (amount == 1) { // when we cheat and say rolled a 1
            mScore = 0;
        }
        
        else
            mScore += amount; // when we cheat and rolled nonzero and not 1
        
        return( amount );
    }
    
    
    void Player::endTurn()
    {
        mTotal = mTotal + mScore;
        mScore = 0;
    }
    
 
    int Player::getTotal( ) const
    {
        return( mTotal );
    }
    

    int  Player::getScore( ) const
    {
        return( mScore );
    }
    

}
