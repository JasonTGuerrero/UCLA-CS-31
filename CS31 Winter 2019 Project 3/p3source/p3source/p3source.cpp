#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
using namespace std;

bool isValidRowerString(string rowerString);
int number(string s, int& startingposition);
int totalDistance(string rowerString);
int heartRate(string rowerString);
int strokesPerMinute(string rowerString);
int elapsedMinutes(string rowerString);
int elapsedSeconds(string rowerString);
int number1(string s, int& startingposition); // helper function for elapsedSeconds
int number2(string s, int& startingposition);






int main()
{
    assert( !isValidRowerString("") );
    assert( !isValidRowerString("544") );
    assert( !isValidRowerString("59") );
    assert( !isValidRowerString("59:599 "));
    assert( !isValidRowerString("9:59 "));
    assert( !isValidRowerString(":59") );
    assert( !isValidRowerString("1:59") );
    assert( !isValidRowerString(":599") );
    assert( !isValidRowerString("0:59") );
    assert( !isValidRowerString("00:59") );
    assert( !isValidRowerString("15:9") );
    assert( !isValidRowerString("15:") );
    assert( !isValidRowerString(":"));
    assert( isValidRowerString("59:59    999 s/m   42 m    1") );
    assert( isValidRowerString(":04    28 s/m     42 m    110") );
    assert( isValidRowerString("          :14         28 s/m         42 m      110") );
    assert( isValidRowerString("          :14         28 s/m         42 m      110") );
    assert( isValidRowerString("1:14    28 s/m     42 m    110") );
    assert( isValidRowerString("  59:14     28 s/m     42 m    110") );
    assert( isValidRowerString(" 59:59    28 s/m     42 m    110") );
    assert( isValidRowerString("  59:59    999 s/m     42 m    110") );
    assert( isValidRowerString(" 59:59    999 s/m     42 m    999") );
    assert( !isValidRowerString(" 59:59    999 s/m     42    m    999") );
    assert( !isValidRowerString("asdf:14    28 s/m     42 m    110") );
    assert( !isValidRowerString(":14    28 s/m     42 m    110 asdf ") );
    assert( !isValidRowerString(":14     28       s/m    42 m    110") );
    assert( !isValidRowerString("0:14    28 s/m     42 m    110") );
    assert( !isValidRowerString("0000:14    00028 s/m     00042 m   000110") );
    assert( !isValidRowerString(":-14    -28 s/m     -42 m   -110") );
    assert( !isValidRowerString("555:14    28 s/m    42 m   110") );
    assert( !isValidRowerString(":555      28 s/m      42 m  110 ") );
    assert( !isValidRowerString(":14    99123 s/m    42 m   110") );
    assert( !isValidRowerString(":14    0 s/m            42 m   110") );
    assert( !isValidRowerString(":14    28 s/m         42 m   99123") );
    assert( !isValidRowerString(":14    28 s/m       42 m   0") );
    assert( !isValidRowerString("  59:14     28 s/m     42     110") );
    assert( !isValidRowerString("  59:14     28 /m     42 m    110") );
    assert( !isValidRowerString("  5914     28 s/m     42 m    110") );
    assert( isValidRowerString("59:59 999 s/m 42 m 1") );
    assert( isValidRowerString(":01 1 s/m 1 m 1") );
    assert( !isValidRowerString(":01s/m 1 m 1") );
    assert( !isValidRowerString("01 1 s/m 1 m 1") );
    assert( !isValidRowerString("59:59999 s/m 42 m 1") );
    assert( isValidRowerString(":00    1 s/m            42 m   110") );
    assert( !isValidRowerString(":00    1 s/a            42 m   110") );
    assert( !isValidRowerString(":32    1 sm    42 m   110") );
    assert( !isValidRowerString(":03    1 s/m42 m   110") );
    assert( !isValidRowerString(":03    1 s/m 42m   110") );
    assert( !isValidRowerString(":03    1 s/m 42 m110") );
    assert( !isValidRowerString(":03    1s/m 42 m   110") );
    assert( !isValidRowerString("2:56    132 s/m   543 m   110      ") );
    
    
    
    
    assert( totalDistance(" 59:59    999 s/m     42 m    999") == 42 );
    assert( totalDistance(" 59:59    999 s/m     412351 m    999") == 412351 );
    assert( totalDistance(" 59:59    999 s/m     412983859 m    999") == 412983859 );
    assert( totalDistance(" 59:59    999 s/m     999999999 m    999") == 999999999 );
    
    assert( heartRate("59:59    999 s/m     42 m    999") == 999 );
    assert( heartRate("59:59    999 s/m   42 m    1") == 1 );
    assert( heartRate("59:59    999 s/m   42 m    12314") == -1 );
    assert( heartRate("59:59    999 s/m   42 m    0") == -1 );
    assert( heartRate("59:59    999 s/m   42 m    726") == 726 );
    assert( heartRate("  59:59    999 s/m     42 m    110") == 110 );
    assert( heartRate(":04 28 s/m 42 m 87") == 87);
    
    assert( strokesPerMinute( "59:59    999 s/m   42 m    726") == 999 );
    assert( strokesPerMinute( "59:59    9999 s/m   42 m    726") == -1 );
    assert( strokesPerMinute( "59:59    123 s/m   42 m    726") == 123 );
    assert( strokesPerMinute( "59:59    1 s/m   42 m    726") == 1 );
    assert( strokesPerMinute( "59:59    14 s/m   42 m    726") == 14 );
    assert( strokesPerMinute(":04 28 s/m 42 m 110") == 28 );
    
    assert( elapsedMinutes("59:59    14 s/m   42 m    726") == 59 );
    assert( elapsedMinutes("5:59    14 s/m   42 m    726") == 5 );
    assert( elapsedMinutes("9:59    14 s/m   42 m    726") == 9 );
    assert( elapsedMinutes(":59    14 s/m   42 m    726") == 0 );
    assert( elapsedMinutes("519:59    14 s/m   42 m    726") == -1 );
    assert( elapsedMinutes(":04 28 s/m 42 m 110") == 0 );
    
    assert( elapsedSeconds(":59    14 s/m   42 m    726") == 59 );
    assert( elapsedSeconds("1:14    28 s/m     42 m    110") == 14 );
    assert( elapsedSeconds(":32    14 s/m   42 m    726") == 32 );
    assert( elapsedSeconds(":01    14 s/m   42 m    726") == 1 );
    assert( elapsedSeconds(":00    14 s/m   42 m    726") == 0 );
    assert( elapsedSeconds(":0    14 s/m   42 m    726") == -1 );
    assert( elapsedSeconds("59:59    14 s/m   42 m    726") == 59 );
    assert( elapsedSeconds("9:59    14 s/m   42 m    726") == 59 );
    assert( elapsedSeconds("5:59    14 s/m   42 m    726") == 59 );
    assert( elapsedSeconds(":04 28 s/m 42 m 110") == 4 );
    
    
    
    cerr << "all tests succeeded" << endl;
    
    return ( 0 );
}


bool isValidRowerString(string rowerString)
{
    if (rowerString.size() == 0) // return false for the empty string
        return false;
    
    if (rowerString.size() < 15) // the smallest possible valid rower string is 15 characters long
    {
        return false;
    }
    
    int k = 0; // the starting index of our rower string
    
    if ( number(rowerString, k) > 59) // if the minutes part of the rower string is more than 59 minutes, return false
    {
        return false;
    }
    
    if (rowerString[k] == ':') // if the character following the minutes part of the rower string is a ':'...
    {
        k++; // move forward through the rower string
        
        if ( number2(rowerString, k) > 59 ||              /// if the seconds are more than 59
            !(isdigit(rowerString[k-1]) && isdigit(rowerString[k-2])) ) // or the 2 characters after the : are nondigit
        {
            return false;  // then return false
        }
    }
    else // ... otherwise return false
    {
        return false;
    }
    
    // we've made it past the stopwatch part of the rower string
    
    while (k < rowerString.size() && isspace(rowerString[k])) // eat up any whitespace after the stopwatch part
    {
        k++;
    }
    
    if (number(rowerString, k) > 999) // if the stroke rate is more than 999 then not a valid rower string
    {
        return false;
    }
    
    if ( isspace(rowerString[k]) ) // if there is a space following directly after the the heart rate...
    {
        k++; // ... go to the next index
        
        while (isalpha(rowerString[k]) || rowerString[k] == '/') // while the next characters are alpha or a '/'
        {
            k++; // move along
        }
    }
    else // otherwise not a valid rower string
        return false;
    
    if (!isspace(rowerString[k])) // if the last alpha character is not followed by a space, return false
    {
        return false;
    }
    
    
    string rate = rowerString.substr(k-3, 3); // take a substring of the last 3 characters
    
    if (rate != "s/m") // if that substring is not the stroke rate in s/m, return false
    {
        return false;
    }
    
    while (k < rowerString.size() && isspace(rowerString[k])) // eat up any following whitespace
    {
        k++;
    }
    
    number(rowerString, k); // use the number function to get the distance traveled
    
    if ( !isspace(rowerString[k]) ) // if the following character after the distance traveled is not a space ...
    {
        return false;  // ... then not a valid rower string
    }
    
    k++; // move to the next index
    
    if (rowerString[k] != 'm') // if that index is not an 'm' ...
    {
        return false; // ... then not a valid rower string
    }
    
    k++; // move to the next index
    
    if (!isspace(rowerString[k])) // if that next character is not a space after the 'm'
    {
        return false; // not a valid rower string, there must be at least one space before the heart rate
    }
    
    while (k < rowerString.size() && isspace(rowerString[k])) // eat up any following white space
    {
        k++;
    }
    
    int heartrate = number(rowerString, k); // use the number function to get the heart rate
    
    if (heartrate < 1 || heartrate > 999) // if the heart rate is not in this range, then not a valid rower string
    {
        return false;
    }
    
    
    if ( k != rowerString.size() ) // there should not be any following characters after the heartrate, if there are...
    {
        return false; // ... return false
    }
    
    return true; // we raised no flags, we have a valid rower string, return true.
}





// This is the number function Howard provided for us for this particular project

int number(string s, int& startingposition)

{
    int result = 0;
    
    // ignore leading whitespace
    while (startingposition < s.size() &&  isspace(s[startingposition]))
    {
        startingposition = startingposition + 1;
    }
    // no leading zeros
    if (startingposition < s.size())
    {
        
        if (s[startingposition] >= '1' &&
            s[startingposition] <= '9')
            
        {
            while (startingposition < s.size() &&
                   s[startingposition] >= '0' &&
                   s[startingposition] <= '9')
            {
                int value = s[startingposition] - '0';
                result = (result * 10) + value;
                
                /// move on down the road
                startingposition = startingposition + 1;
                
            }
        }
    }
    else
    {
        result = -1;
    }
    
    return(result);
}

// The total distance function

int totalDistance(string rowerString)
{
    if ( !isValidRowerString(rowerString) ) // return -1 for invalid rower strings
    {
        return -1;
    }
    
    int i = 0;
    
    while (i != rowerString.size() ) // loop through the rower string
    {
        if ( rowerString[i] == 'm' ) // as soon as we see the first 'm' in the string
        {
            i++; // increment to the following space character
            break; // then break out of the loop
        }
        
        i++;
    }
    
    int distance = number(rowerString, i); // use the number function to get the distance traveled in meters
    
    
    
    return distance; // return the value of distance traveled
}

// The heart rate function

int heartRate(string rowerString)
{
    if ( !isValidRowerString(rowerString) ) // return -1 for invalid rower strings
    {
        return -1;
    }
    
    int i = 0;
    
    while (i != rowerString.size() ) // loop through the rower string
    {
        if (rowerString[i] == 'm') // as soon as we see the FIRST 'm' in the rower string
        {
            i++; // increment to the following space character
            break; // then break out of the loop
        }
        i++;
    }
    
    while (i != rowerString.size() ) // loop through the rower string from where the last loop left off
    {
        if (rowerString[i] == 'm') // as soon as we see the SECOND 'm' in the rower string
        {
            i++; // increment to the following space character
            break; // then break out of the loop
        }
        i++;
        
    }
    
    int heartbeat = number(rowerString, i); // use the number function to get the heart rate
    
    return heartbeat; // return the value for the heart rate
}

// The s/m function

int strokesPerMinute(string rowerString)
{
    if ( !isValidRowerString(rowerString) ) // return -1 for invalid rower strings
    {
        return -1;
    }
    
    int i = 0;
    
    while (i < rowerString.size() && isspace(rowerString[i]))
    {
        i++;
    }
    
    while (i != rowerString.size() )
    {
        if ( !(isdigit(rowerString[i]) || rowerString[i] == ':') )
        {
            break;
        }
        
        i++;
        
    }
    
    int strokeRate = number(rowerString, i);
    
    return strokeRate;
}

int elapsedMinutes(string rowerString)
{
    if ( !isValidRowerString(rowerString) )
    {
        return -1;
    }
    
    int i = 0;
    
    while (i < rowerString.size() && isspace(rowerString[i]))
    {
        i++;
    }
    
    const int zero_minutes = 0;
    
    if (rowerString[i] == ':')
    {
        return zero_minutes;
    }
    
    int minutes = number(rowerString, i);
    
    return minutes;
}

int elapsedSeconds(string rowerString)
{
    if (!isValidRowerString(rowerString))
    {
        return -1;
    }
    
    int i = 0;
    
    while (i != rowerString.size() )
    {
        
        if (rowerString[i] == ':')
        {
            i++;
            break;
        }
        
        i++;
    }
    
    int seconds = number1(rowerString, i);
    
    return seconds;
}


int number1(string s, int& startingposition)

{
    int result = 0;
    
    // ignore leading whitespace
    while (startingposition < s.size() &&  isspace(s[startingposition]))
    {
        startingposition = startingposition + 1;
    }
    // no leading zeros
    if (startingposition < s.size())
    {
        
        if (s[startingposition] >= '0' &&
            s[startingposition] <= '5')
            
        {
            while (startingposition < s.size() &&
                   s[startingposition] >= '0' &&
                   s[startingposition] <= '9')
            {
                int value = s[startingposition] - '0';
                result = (result * 10) + value;
                
                /// move on down the road
                startingposition = startingposition + 1;
                
            }
        }
    }
    else
    {
        result = -1;
    }
    
    return(result);
}

int number2(string s, int& startingposition)

{
    int result = 0;
    
    // ignore leading whitespace
    while (startingposition < s.size() &&  isspace(s[startingposition]))
    {
        startingposition = startingposition + 1;
    }
    // no leading zeros
    if (startingposition < s.size())
    {
        
        if (s[startingposition] >= '0' &&
            s[startingposition] <= '5')
            
        {
            while (startingposition < s.size() &&
                   s[startingposition] >= '0' &&
                   s[startingposition] <= '9')
            {
                int value = s[startingposition] - '0';
                result = (result * 10) + value;
                
                /// move on down the road
                startingposition = startingposition + 1;
                
            }
        }
    }
    else
    {
        result = -1;
    }
    
    return(result);
}


