#include "glbl_settings.h"

// Default Constructor
Mission::Mission()
{
    // Not going to be used
}

// Parameterised constructor
void Mission::Setup( int i_l_oxygen, int i_kg_food, int i_l_water, int i_money, int i_suits, int i_modules)
{
	l_oxygen_max    =   i_l_oxygen;
    l_oxygen        =   i_l_oxygen;
    kg_food_max     =   i_kg_food;
    kg_food         =   i_kg_food;
    l_water_max     =   i_l_water;
    l_water         =   i_l_water;
    money           =   i_money;
}

void Mission::SetOxygen(    int i_val){ l_oxygen_max = i_val; }
void Mission::SetOxygenMax( int i_val){ l_oxygen     = i_val; }
void Mission::SetFood(      int i_val){ kg_food_max  = i_val; }
void Mission::SetFoodMax(   int i_val){ kg_food      = i_val; }
void Mission::SetWater(     int i_val){ l_water_max  = i_val; }
void Mission::SetWaterMax(  int i_val){ l_water      = i_val; }
void Mission::SetMoney(     int i_val){ money        = i_val; }

void Mission::Disembark( Rocket i_rocket, bool i_report ) 
{    
    if( i_report ) cout << "Disembarking with the following team" << endl;
    
        for(int j=0; j<SIZE_OF_ROCKET; j++){
            adventurers_on_mars[j] = *i_rocket.getAdv(j);
            if( i_report ) adventurers_on_mars[j].PrintID(true);
        }
        for(int j=0; j<NO_OF_MODULES; j++){
            modules_on_mars[j] = *i_rocket.getMod(j);
            if( i_report ) modules_on_mars[j].PrintID( );
        }
        for(int j=0; j<NO_OF_ROVERS; j++){
            rovers_on_mars[j] = *i_rocket.getRov(j);
            if( i_report ) rovers_on_mars[j].PrintID( );
        }
    
    cout << "Disembarking with the following modules" << endl;
    wait_for_user();
    PrintModules();
    cout << "Disembarking with the following equipment" << endl;
    wait_for_user();
    PrintRovers();
}

void Mission::PrintModules()
{
    cout << "-----------------------------------" << endl;
    cout << "   MODULES" << endl;
    cout << "-----------------------------------" << endl;
    for(int j=0; j<NO_OF_MODULES; j++){
        modules_on_mars[j].PrintID( );
    }
}

void Mission::PrintRovers()
{
    cout << "-----------------------------------" << endl;
    cout << "   ROVERS" << endl;
    cout << "-----------------------------------" << endl;
    for(int j=0; j<NO_OF_ROVERS; j++){
        rovers_on_mars[j].PrintID( );
    }
}

void Mission::ReviewWeek()
{
    
}