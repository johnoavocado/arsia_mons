// Bunch of settings for this instance of the game Arsia Mons

#ifndef __glbl_settings_h__
#define __glbl_settings_h__

    #include <iostream>
    #include <fstream>
    #include <vector>
    using namespace std;

    #define SIZE_OF_SELECTION_LIST  12
    #define SIZE_OF_ROCKET           5 // In terms of adventurers
    #define NO_OF_ROVERS             3
    #define NO_OF_SUITS              8
    #define NO_OF_MODULES           10

    #define NUMBER_OF_OCCUPATIONS    7 // Update this if list of occupations changes... jeasus
    #define NO_OF_ACTIVITIES        10 
    #define NUMBER_OF_MOD_FUNC       8 // Update this if list of module functions changes
    #define ALLOW_ROBOTS             false

    #define ADVENTURER_DEBUG         false
    #define TEAMBUILDER_DEBUG        true
    #define ROCKET_DEBUG             false
    #define GAME_DEBUG               false
    #define SINGLE_ROUND_DEBUG       false
    
    #define INCL_STORY               false

    // Define Realism here
    #define NORMAL_BREATHING        550
    #define HEAVY_BREATHING         800
    #define MODULE_ENERGY_REQ       7
    #define NORMAL_WATER_USAGE      20 
    #define HEAVY_WATER_USAGE       40
    #define NORMAL_EATING           3
    #define HEAVY_EATING            10
    
    // Starting values
    #define START_OXYGEN            500
    #define START_ENERGY            500000
    #define START_FOOD              1000
    #define START_WATER             20000
    #define START_MONEY             10000
    #define START_MODULES           0 // Not used
    #define START_SUITS             0 // Not used
        
    #include "adventurer.h"
    #include "equipment.h"
    #include "rover.h"
    #include "suit.h"
    #include "module.h"
    #include "teambuilder.h"
    #include "rocket.h"
    #include "mission.h"
    #include "game.h"

    #define wait_for_user() cout << "Press any key..." << endl; system("Read");


#endif
