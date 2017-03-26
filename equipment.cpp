#include "glbl_settings.h"

Equipment::Equipment()
{

}

// Parameterised Constructor
Equipment::Equipment( int i_equipment_id, string i_name, int i_health, bool i_status )
{
	health          = i_health;
	health_max      = health;
	
    equipment_id    =     i_equipment_id; 
	health          =           i_health;
	health_max      =             health;
	status          =           i_status;
	equipment_name  =             i_name;
}

// Getters
int Equipment::GetID(){return equipment_id;}

int Equipment::GetHealth( bool i_ret_max = false )
{
    if (i_ret_max) return health_max;
    else           return health;
} 

string Equipment::GetName(){return equipment_name;}

bool Equipment::GetStatus(){ return status; }

string Equipment::GetStatusStr()
{
    if(status){
        return "ONLINE";
    }else{
        return "OFFLINE";
    }
}

// Setters
void Equipment::SetName( string i_equipment_name ){equipment_name = i_equipment_name;}
void Equipment::SetStatus( bool i_status ){status = i_status;}

const void Equipment::PrintID( )
{
    
    cout << "-----------------------------------" << endl;
    cout << " ID: \t\t"   <<        GetID()       << endl;
    cout << " Name:\t\t"  <<      GetName()       << endl;
    cout << " Health:\t"  <<    GetHealth()       << endl;
    cout << " Status:\t"  << GetStatusStr()       << endl;
    cout << "-----------------------------------" << endl;

}