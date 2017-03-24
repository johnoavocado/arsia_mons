#include "glbl_settings.h"



// Constructor
Rocket::Rocket()
{
	quit_rocket = false;
	
	// Don't know who is on tour yet - assign later
	bio_on_tour = 0;
    geo_on_tour = 0;
    phy_on_tour = 0;
	
}

int Rocket::Greeting()
{
    cout << "BLAST OFF!" << endl;
    return 0;
}

void Rocket::Embark( TeamBuilder i_tmbldr )
{
    cout << "Embarking with the following team" << endl;
    i_tmbldr.Finalise();
    
    for(int j=0; j<SIZE_OF_ROCKET; j++){
        adventurers_on_rocket[j] = *i_tmbldr.getSel(j);
        adventurers_on_rocket[j].PrintID(true);
    }
    
}

void Rocket::Journey( bool i_long = false )
{
    if(i_long){
        cout << "This is the long version of the story" << endl;
        cout << "Your team of lemmings travels to Mars" << endl;
        cout << "They enter their cryogenic sleep in the facility on Earth" << endl;
        wait_for_user();
        cout << "Tah dah! They wake up after landing on Mars" << endl;
        wait_for_user();
    }else{
        cout << "This is the short version of the story" << endl;
        cout << "Your travels to Mars. Nothing eventful happens." << endl;
        wait_for_user();
    }
}

void Rocket::PrintModules()
{
    cout << "These are the modules on the rocket:" << endl;
    for(int j=0; j<NO_OF_MODULES; j++){
        modules_on_rocket[j].PrintID( );
    }
}

void Rocket::UpdateTourFlags(){
    for(int j = 0; j<SIZE_OF_ROCKET; j++){
        if(adventurers_on_rocket[j].GetOccupation() == Adventurer::BIOLOGIST){
            bio_on_tour++;
        }else if(adventurers_on_rocket[j].GetOccupation() == Adventurer::GEOLOGIST){
            geo_on_tour++;
        }else if(adventurers_on_rocket[j].GetOccupation() == Adventurer::PHYSIOLOGIST){
            phy_on_tour++;
        }
    }
}

Module::m_function Rocket::WhichLab( ){
    cout << "Input: " << bio_on_tour << geo_on_tour << phy_on_tour << endl;
    if(bio_on_tour){bio_on_tour--; return Module::BIOLOGY_LAB;}
    if(geo_on_tour){geo_on_tour--; return Module::GEOLOGY_LAB;}
    if(phy_on_tour){phy_on_tour--; return Module::BIOLOGY_LAB;}
    return Module::CONSERVATORY; // No scientists
}

void Rocket::AssignSensibleModuleFuncs( int i_no_modules )
{
    const int max_prescribed  = 9;
    int modules_left    = i_no_modules - max_prescribed;
    
    // All extra Modules are assigned to SHELL
    if(modules_left>0){
        for(int j = max_prescribed; j < NO_OF_MODULES; j++){
            modules_on_rocket[j].UpdateFunction(Module::SHELL);
        }
    }
    
    if(i_no_modules > -1){
        switch(i_no_modules){
            default             :
            case max_prescribed : modules_on_rocket[8].UpdateFunction(Module::CONSERVATORY);
            case 8              : modules_on_rocket[7].UpdateFunction(Module::DORMITORY);
            case 7              : modules_on_rocket[6].UpdateFunction(WhichLab()); // Depends on the on scientists on tour
            case 6              : modules_on_rocket[5].UpdateFunction(WhichLab());
            case 5              : modules_on_rocket[4].UpdateFunction(Module::DORMITORY);
            case 4              : modules_on_rocket[3].UpdateFunction(Module::KITCHEN);
            case 3              : modules_on_rocket[2].UpdateFunction(Module::GARAGE);
            case 2              : modules_on_rocket[1].UpdateFunction(Module::INFIRMARY);
            case 1              : modules_on_rocket[0].UpdateFunction(Module::DORMITORY); break;
            case 0              : cout << "No modules? Your adventurers are DOOMED!" << endl;
            exit(0);
        }
    }
}
