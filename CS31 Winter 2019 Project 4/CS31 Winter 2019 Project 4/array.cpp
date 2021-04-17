#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;


bool hasDuplicates( const string array[ ],  int size );
int  countAllDigits( const string array[ ] , int size );
bool isInDecreasingOrder( const string array[ ], int size );
int  shiftRight( string array[ ], int size, int amount, string placeholder );
int  find( const string array[ ], int size, string match );
int  replaceAllCharacters( string array[ ], int size, char findLetter, char replaceLetter );

int main()
{
    //string array examples from the spec
    string folks[8] = {
        "samwell", "jon", "margaery", "daenerys",
        "tyrion", "sansa", "howard123", "jon"
    };
    
    string people[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
    
    string duplicates[5] = { "duplicate" , "duplicate" , "duplicate" , "duplicate" , "duplicate" };
    
    string empty[10] = { "", "", "", "", "" ,"" ,"", "", "", "" };
    string EMPTY[0] = {};
    // string arrays for testing countAllDigits
    string digits[3] = { "123", "456", "789" };
    string digits1[3] = { "13", "4536", "782sdda29" };
    string digits2[6] = { "13", "4536", "782sdda29", "", "dsa4g", "123s6" };
    string digits3[10] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "0" };
    string digits4[10] = { "9", "8", "7", "6", "5", "4", "3", "2", "1", "0" };
    
    string small[1] = { "small "}; // isInDecreasingOrder base case array test
    string people1[2] = { "Stahl", "Smallberg" }; //replaceAllCharacters test array
    string pokemon[8] = {"pikachu", "charmander", "squirtle" , "bulbasaur",
                        "charmeleon", "wartortle", "ivysaur", "charizard"
                        }; // shiftRight test
    
    //isInDecreasingOrder lexicographical tests
    string notdecreasing[5] = { "ABCDE", "FGHIJ", "KLMNO", "PQRST", "UVWXYZ" };
    string decreasing[5] = { "ZYXWVU", "TSRQP", "ONMLK", "JIHGF", "EDCBA" };
    string decreasing1[5] = { "Abcde", "ABcde","ABCde", "ABCDe", "ABCDE" };
    string decreasing2[5] = { "Abcde", "ABcde","ABCDe", "ABCde", "ABCDE" };
    
    
    string breakingbad[7] = { "Walter", "Jesse", "Mike", "Gus", "Saul", "Hank", "Gomez" }; //shiftRight test array
    string array[5] = { "1", "2" , "3" , "4" , "5" };
    
    //string arrays for testing hasDuplicates
    string dups1[6] = { "alpha", "beta", "gamma", "delta", "epsilon", "lambda" };
    string dups2[6] = { "alpha", "beta", "gamma", "delta", "epsilon", "epsilon" };
    string dups3[6] = { "alpha", "beta", "gamma", "delta", "epsilon", "alpha" };
    string dups4[6] = { "alpha", "beta", "gamma", "delta", "epsilon", "beta" };
    
    assert( !hasDuplicates(dups1, 6) );
    assert( hasDuplicates(dups2, 6) );
    assert( hasDuplicates(dups3, 6) ); // various cases for dups
    assert( hasDuplicates(dups4, 6) );
    assert( !hasDuplicates(folks, -1) ); // no duplicates
    
    assert( countAllDigits(folks, 8) == 3); // spec example see if can get the digits in howard123 element
    assert( countAllDigits(digits2, 6) == 16 ); // random number of digits and nondigits in array
    assert( countAllDigits(empty, 10) == 0 ); // array of empty strings
    assert( countAllDigits(digits3, 10) == 10 ); // array of single digits of size 10
   
    
    assert( !isInDecreasingOrder(digits3, 10) ); // an array that is not in decreasing order
    assert( isInDecreasingOrder(digits4, 10) ); // an array that is in decreasing order
    assert( !isInDecreasingOrder(notdecreasing, 5) ); // more decreasing order tests
    assert( isInDecreasingOrder(decreasing, 5) );
    assert( isInDecreasingOrder(decreasing1, 5) );
    assert( !isInDecreasingOrder(decreasing2, 5) );
    
    assert( !hasDuplicates(folks, 5) ); // more dups tests
    assert( hasDuplicates(folks, 8) );
    assert( hasDuplicates(duplicates, 5) );
    assert( countAllDigits(digits, 3) == 9);
    assert( countAllDigits(digits1, 3) == 11 );
    assert( !isInDecreasingOrder(people, 5) ); // isInDecreasingOrder test on example from spec
    assert( isInDecreasingOrder(small, 1) ); // base case for isInDecreasingOrder, size 1 array
    assert( isInDecreasingOrder(EMPTY, 0) ); // base case for isInDecreasingOrder, size 0 array
    assert( find(folks, 8, "foo") == -1 );
    assert( find(digits , 3, "456") == 1 );
    assert( find(folks , 8, "jon") == 1 );
    assert( replaceAllCharacters( people, 5, 'a', '_' ) == 4 ); // replaceAllCharacters tests
    assert( replaceAllCharacters( people, 5, 'z', 'a' ) == 0 ); //
    assert( replaceAllCharacters( people1, 2, 'a', '4' ) == 2 );
    assert( replaceAllCharacters( people, -5, 'z', 'a' ) == -1 );
    assert( find( folks, 5, "foo" ) == -1 ); // trying to find an element that is not there
    assert( find( folks, -500, "foo" ) == -1 );
    assert( shiftRight(people, 5, 0, "foo") == 0 ); // amount value of 0
    assert( shiftRight(EMPTY, 0, 3, "foo") == 0 ); // an empty array
    assert( shiftRight(EMPTY, 0, 0, "foo") == 0 ); // an empty array
    assert( shiftRight(people, 5, 3, "foo") == 3 ); // amount value of 3
    assert( shiftRight(folks, 8, 4, "foo") == 4 ); // amount value of 4
    assert( shiftRight(pokemon, 8, 5, "meowth") == 5 ); // amount value of 5
    assert( shiftRight(breakingbad, 7, 1, "foo") == 1 ); // amount value of 1
    assert( shiftRight(digits4, 10, 0, "foo") == 0 ); // amount value of 0
    assert( shiftRight(array, 3, 1, "placeholder") == 1 ); // case Howard talked about on ccle discussion board
   
    cerr << people1[0] << endl << people1[1] << endl << endl;
    for (size_t i = 0; i < 5; i++) {
        cerr << people[i] << endl;
    }
    
    cerr << endl;
    
    for (size_t i = 0; i < 8; i++) {
        cerr << folks[i] << endl;
    }
    
    cerr << endl;
    
    for (size_t i = 0; i < 8; i++) {
        cerr << pokemon[i] << endl;
    }
    
    cerr << endl;
    
    for (size_t i = 0; i < 7; i++) {
        cerr << breakingbad[i] << endl;
    }
    
    cerr << endl;
    
    for (size_t i = 0; i < 10; i++) {
        cerr << digits4[i] << endl;
    }
    
    cerr << endl;
    
    for (size_t i = 0; i < 5; i++) {
        cerr << array[i] << endl;
    }
   
    
    cerr << endl;
    
    cout << "all tests succeeded" << endl;
 
    return ( 0 );
}


bool hasDuplicates( const string array[ ],  int size )
{
    if ( size <= 0 )
        return ( false );
    
    if ( size == 1 )
        return ( false );
    

    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = i + 1; j < size; j++) // nested for loop to compare the ith array element to every other element
        {
            if ( array[i] == array[j] )
                return ( true );
        }
    }
    
    return ( false ); // if no duplicates were found return false
}

int  countAllDigits( const string array[ ] , int size )
{
    if (size <= 0 )
        return ( -1 );
    
    int count = 0; // counter to keep track of the digits
    
    for (size_t i = 0; i < size; i++)
    {
        size_t k = 0;
        
        while (k != array[i].size() ) // while loop to parse the kth string index in the ith index of the array
        {
        
            if ( isdigit(array[i][k]) ) // when we have found a digit
                count++;
        
            k++;
        }
    }
    
    return ( count );
}

bool isInDecreasingOrder( const string array[ ], int size )
{
    if ( size < 0 )
        return ( false );
    
    if ( size == 0 || size == 1 )
        return ( true );
    
    size_t i = 1;
    
    
    while ( i != size )
    {
        if ( array[i-1] <= array[i] ) // compare the previous index to the current index, return false if it is not bigger
            return ( false );
        
        i++;
    }
    
    return ( true );
}

int  shiftRight( string array[ ], int size, int amount, string placeholder )
{
    if ( size < 0 || amount < 0 )
        return ( -1 );
    
    if ( size == 0 || amount == 0 )
        return ( 0 );
    
    if ( amount > size )
        amount = size;
    
    
    for (size_t k = 1; k <= size - amount; k++) // take the difference of the size of the amount for the constraint of the loop
    {
        array[size - k] = array[size - amount - k]; // as indices are reassigned, subtract k as well to account for increment
    }
    
    for (size_t i = 0; i < amount; i++) // now replace the amount number of indices with placeholder
    {
        array[i] = placeholder;
    }
    
    return ( amount ); // return amount because that is always the number of indices that were assigned placeholder
}

int  find( const string array[ ], int size, string match )
{
    if ( size <= 0 )
        return ( -1 );
    
    
    for (size_t i = 0; i != size; i++) {
        if ( array[i] == match ) // when we've found what we are looking for
        {
            int k = static_cast<int>(i); // make it an int so we can return it
            
            return ( k );
        }
    }
    
    return ( -1 ); // if we could not find it, return -1
}

int  replaceAllCharacters( string array[ ], int size, char findLetter, char replaceLetter )
{
    
    if ( size <= 0 )
        return ( -1 );
    
    int count = 0; // counter for replaced letters
    
    for (size_t i = 0; i < size; i++)
    {
        size_t k = 0;
        
        while (k != array[i].size() ) // while loop to parse the kth string index of the ith array element
        {
        
            if ( array[i][k] == findLetter ) // when we have found the letter we are looking for
            {
                count++; // increment the counter because we are going to replace it with our replaceLetter
                array[i][k] = replaceLetter;
            }
        
        k++;
            
        }
    }
    
    return ( count );
}
