#include "glbl_settings.h"

// Default Constructor
Mission::Mission()
{
	
}

// Parameterised constructor
Mission::Mission( int i_l_oxygen, int i_kg_food, int i_l_water, int i_rovers, int i_suits, int i_modules)
{
	
}

void Mission::Disembark( Rocket i_rocket, bool i_report_landing_party ) 
{    
    if( i_report_landing_party ) {
        cout << "Disembarking with the following team" << endl;
    
        for(int j=0; j<SIZE_OF_ROCKET; j++){
            adventurers_on_mars[j] = *i_rocket.getAdv(j);
            adventurers_on_mars[j].PrintID(true);
        }
        for(int j=0; j<NO_OF_MODULES; j++){
            modules_on_mars[j] = *i_rocket.getMod(j);
            modules_on_mars[j].PrintID( );
        }
    } else { //quiet - just copy the team
        for(int j=0; j<SIZE_OF_ROCKET; j++){
            adventurers_on_mars[j] = *i_rocket.getAdv(j);
        }
        for(int j=0; j<NO_OF_MODULES; j++){
            modules_on_mars[j] = *i_rocket.getMod(j);
        }
    }
}

void Mission::PrintModules()
{
    for(int j=0; j<NO_OF_MODULES; j++){
        modules_on_mars[j].PrintID( );
    }
}