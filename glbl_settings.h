// Bunch of settings for this instance of the game Arsia Mons

#ifndef __glbl_settings_h__
#define __glbl_settings_h__

    #include <iostream>
    #include <fstream>
    using namespace std;

    #define SIZE_OF_SELECTION_LIST  12
    #define SIZE_OF_ROCKET          5 // In terms of adventurers
    #define NO_OF_ROVERS            3
    #define NO_OF_SUITS             8
    #define NO_OF_MODULES           6

    #define NUMBER_OF_OCCUPATIONS 7 // Update this if list of occupations changes... jeasus
    #define ALLOW_ROBOTS          true

    #define TEAMBUILDER_DEBUG   false
    #define ROCKET_DEBUG        false
    #define GAME_DEBUG          false

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
