#include <iostream>
#include <string>
using namespace std;

int main()
{
    double price;
    
    cout.setf( ios::fixed );
    cout.setf( ios::showpoint );
    cout.precision( 2 ); // magic formula for two decimal places
    
    cout << "Ticket or BruinCard? "; // prompts user for Ticket or BruinCard
    string payment;
    getline(cin, payment);
    
    if (payment == "BruinCard") // If payment method is BruinCard do this
    {
        cout << "Breakfast, Lunch or Dinner? "; // prompts user for meal type
        string mealType;
        getline(cin, mealType);
        
        if (mealType == "Breakfast") // if user selects Breakfast do this
        {
            cout << "Student or Staff? "; // prompts user for diner type
            string diner;
            getline(cin, diner);
            
            if (diner == "Student") // if user selects Student, do this
            {
                cout << "Resident? "; // verify residence
                string resident;
                getline(cin, resident);
                
                if (resident == "Yes") // if a Resident, output this
                {
                    price = 9.75;
                    
                    cout << "Thank you for eating at UCLA today.  Your meal cost is $" << price << "." << endl;
                }
                
                else if (resident == "No") // if not, output this
                {
                    price = 10.00;
                    
                    cout << "Thank you for eating at UCLA today.  Your meal cost is $" << price << "." << endl;
                }
                
                else // if anything else, output this error message
                {
                    cout << "The resident value must either be Yes or No." << endl;
                    return ( 1 );
                }
            }
            
            else if (diner == "Staff") // if user selects Staff, output this
            {
                price = 11.25;
                
                cout << "Thank you for eating at UCLA today.  Your meal cost is $" << price << "." << endl;
            }
            
            else // otherwise, output this error message
            {
                cout << "The type value must either be Student or Staff." << endl;
                return ( 1 );
            }
        }
        
        else if (mealType == "Lunch") // if user selects Lunch, do this
        {
            cout << "Student or Staff? "; // prompts user for diner type
            string diner;
            getline(cin, diner);
            
            if (diner == "Student") // if user selects Student, do this
            {
                cout << "Resident? "; // verify residence
                string resident;
                getline(cin, resident);
                
                if (resident == "Yes") // if a Resident, output this
                {
                    price = 11.25;
                    
                    cout << "Thank you for eating at UCLA today.  Your meal cost is $" << price << "." << endl;
                }
                
                else if (resident == "No") // if not, output this
                {
                    price = 11.75;
                    
                    cout << "Thank you for eating at UCLA today.  Your meal cost is $" << price << "." << endl;
                }
                
                else // if anything else, output this error message
                {
                    cout << "The resident value must either be Yes or No." << endl;
                    return ( 1 );
                }
            }
            
            else if (diner == "Staff") // if user selects Staff, output this
            {
                price = 12.75;
                
                cout << "Thank you for eating at UCLA today.  Your meal cost is $" << price << "." << endl;
            }
            
            else
            {
                cout << "The type value must either be Student or Staff." << endl; // otherwise, output this error message
                return ( 1 );
            }
        }
        
        else if (mealType == "Dinner") // if user selects Dinner, do this
        {
            cout << "Student or Staff? "; // prompts user for diner type
            string diner;
            getline(cin, diner);
            
            if (diner == "Student") // if user selects Student, do this
            {
                cout << "Resident? "; // verify residence
                string resident;
                getline(cin, resident);
                
                if (resident == "Yes") // if a Resident, output this
                {
                    price = 12.25;
                    
                    cout << "Thank you for eating at UCLA today.  Your meal cost is $" << price << "." << endl;
                }
                
                else if (resident == "No") // if not, output this
                {
                    price = 12.75;
                    
                    cout << "Thank you for eating at UCLA today.  Your meal cost is $" << price << "." << endl;
                }
                
                else // if anything else, output this error message
                {
                    cout << "The resident value must either be Yes or No." << endl;
                    return ( 1 );
                }
            }
            
            else if (diner == "Staff") // if user selects Staff, output this
            {
                price = 14.75;
                
                cout << "Thank you for eating at UCLA today.  Your meal cost is $" << price << "." << endl;
            }
            
            else // otherwise, output this error message
            {
                cout << "The type value must either be Student or Staff." << endl;
                return ( 1 );
            }
        }
        
        else // output this error message for bad meal type input
        {
            cout << "The meal value must either be Breakfast, Lunch or Dinner." << endl;
            return ( 1 );
        }
        
        
    }
    
    
    else if (payment == "Ticket") // If payment method is Ticket do this
    {
        cout << "Breakfast, Lunch or Dinner? "; // prompts user for meal type
        string mealType;
        getline(cin, mealType);
        
        if (mealType == "Breakfast") // if user selects Breakfast output this
        {
            price = 12.50;
            
            cout << "Thank you for eating at UCLA today.  Your meal cost is $" << price << "." << endl;
        }
        
        else if (mealType == "Lunch") // if user selects Lunch output this
        {
            price = 14.50;
            
            cout << "Thank you for eating at UCLA today.  Your meal cost is $" << price << "." << endl;
        }
        
        else if (mealType == "Dinner") // if user selects Dinner output this
            
        {
            price = 17.00;
            
            cout << "Thank you for eating at UCLA today.  Your meal cost is $" << price << "." << endl;
        }
        
        else // output this error message for bad meal type input
        {
            cout << "The meal value must either be Breakfast, Lunch or Dinner." << endl;
            return ( 1 );
        }
        
        
        
        
    }
    
    else // output this error message for bad payment method input
    {
        cout << "The kind value must either be Ticket or BruinCard." << endl;
        return ( 1 );
    }
    
    
}


