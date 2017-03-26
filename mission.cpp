#include "glbl_settings.h"

// Default Constructor
Mission::Mission()
{
    // Not going to be used
}

// Parameterised constructor
void Mission::Setup( int i_kwh_energy, int i_l_oxygen, int i_kg_food, int i_l_water, int i_money, int i_suits, int i_modules)
{
    kwh_energy      =   i_kwh_energy;
    kwh_energy_max  =   i_kwh_energy;
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
    wait_for_user();
}

int Mission::GetAdventurersAlive()
{
    int alive_count = 0;
    
    for(int j = 0; j<SIZE_OF_ROCKET; j++){
        if(adventurers_on_mars[j].GetAlive() ) alive_count++;
    }
    
    adventurers_alive = alive_count;
    
    return adventurers_alive;
}

int Mission::GetModulesOnline()
{
    int online_count = 0;
    
    for(int j = 0; j<NO_OF_MODULES; j++){
        if(modules_on_mars[j].GetStatus() ) online_count++;
    }
    
    modules_online = online_count;
    
    return modules_online;
}

void Mission::PrintMissionStatus()
{
    cout << "-----------------------------------------" << endl;
    cout << "   MISSION STATUS" << endl;
    cout << "-----------------------------------------" << endl;

    cout << "-----------------------------------------" << endl;
    cout << " Adventurers alive:\t"     << GetAdventurersAlive() << "\\" << SIZE_OF_ROCKET  << endl;
    cout << " Modules Online: \t"       << GetModulesOnline()    << "\\" << NO_OF_MODULES   << endl;
    cout << " Energy:\t\t"              << kwh_energy << "\\" << kwh_energy_max  << "kWh"   << endl;
    cout << " Oxygen:\t\t"              << l_oxygen << "\\" << l_oxygen_max  << "L"         << endl;
    cout << " Water:\t\t\t"             << l_water  << "\\" << l_water_max   << "L"         << endl;
    cout << " Food:\t\t\t"              << kg_food  << "\\" << kg_food_max   << "kg"        << endl;
    cout << " Money:\t\t\t"             << "€" << money                                     << endl;
    cout << " Mars Explored:\t\t"       << "0%"                                             << endl;
    cout << "-----------------------------------------" << endl;

}

void Mission::PrintModules()
{
    cout << "-----------------------------------------" << endl;
    cout << "   MODULES" << endl;
    cout << "-----------------------------------------" << endl;
    for(int j=0; j<NO_OF_MODULES; j++){
        modules_on_mars[j].PrintID( );
    }
}

void Mission::PrintRovers()
{
    cout << "-----------------------------------------" << endl;
    cout << "   ROVERS" << endl;
    cout << "-----------------------------------------" << endl;
    for(int j=0; j<NO_OF_ROVERS; j++){
        rovers_on_mars[j].PrintID( );
    }
}

int Mission::OxygenConsumption()
{
    int l_consumed;
    
        l_consumed = adventurers_alive * NORMAL_BREATHING * 7;
    
    return l_consumed;
}

int Mission::EnergyConsumption()
{
    int kWh_consumed;
        
        kWh_consumed = modules_online * MODULE_ENERGY_REQ * 7;
        
    return kWh_consumed;
}

int Mission::WaterConsumption()
{
    int l_consumed;
    
        l_consumed = adventurers_alive * NORMAL_WATER_USAGE * 7;
    
    return l_consumed;
}

int Mission::FoodConsumption()
{
    int kg_consumed;
        
        kg_consumed = adventurers_alive * NORMAL_EATING * 7;
        
    return kg_consumed;
}

void Mission::SimWeek()
{
    l_oxygen    = l_oxygen      - OxygenConsumption();
    kwh_energy  = kwh_energy    - EnergyConsumption();
    l_water     = l_water       - WaterConsumption();
    kg_food     = kg_food       - FoodConsumption();
}

bool Mission::ReviewWeek()
{
    char   cmd;
    
    PrintMissionStatus();
    
    cout << "Start new week? Y/N (Q to quit.)" << endl;
        
    cin >> cmd;
    cin.clear();
    if( cmd == 'q' || cmd == 'Q' || cmd == 'n' || cmd == 'N' ) {
        return false;
    }else{
        return true;
    }
    
}