#include "glbl_settings.h"

string Game::GamestateStr( Game::gamestate i_updt_next_game_state ){
    switch( i_updt_next_game_state ) {
        case NOT_IN_GAME    :   return "NOT_IN_GAME";
	    case TMBLDNG        :   return "TEAMBUILDING";
	    case ROCKET         :   return "ROCKET";
	    case SIM_WEEK       :   return "SIMULATE_WEEK";
	    case RVW_WEEK       :   return "REVIEW_WEEK";
	    case FINALE         :   return "FINALE";
	    default             :   return "NOT DEFINED!";
    }
}

void Game::UpdateGamestate( ) {
    
    if (debug_mode) cout << "Updating game state from " << GamestateStr(curr_gamestate) << " to " << GamestateStr(next_gamestate) << endl;
    curr_gamestate = next_gamestate;
    
    // Assign the next_gamestate
    switch(curr_gamestate) {
        case NOT_IN_GAME    :   next_gamestate = TMBLDNG;
                                break;
	    case TMBLDNG        :   next_gamestate = ROCKET;
	                            break;
	    case ROCKET         :   next_gamestate = SIM_WEEK;
	                            break;
	    case SIM_WEEK       :   next_gamestate = RVW_WEEK;
	                            break;
	    case RVW_WEEK       :   if(end_game) {next_gamestate = FINALE;}
	                            else         {next_gamestate = SIM_WEEK;}
	                            break;
	    case FINALE         :   next_gamestate = NOT_IN_GAME;
	                            break;
	    default             :   next_gamestate = NOT_IN_GAME;
    }
}

void Game::UpdateNextGamestate( Game::gamestate i_updt_next_game_state ) {
    next_gamestate = i_updt_next_game_state;
}

// Public - called from main to start the craic
int Game::RunGamestate () {
    
    while(!quit_game) {
        switch(curr_gamestate) {
            case NOT_IN_GAME    :   Phase_NotInGame();  break;
            case TMBLDNG        :   Phase_Tmbldng();    break;
            case ROCKET         :   Phase_Rocket();     break;
            case SIM_WEEK       :   Phase_SimWeek();    break;
            case RVW_WEEK       :   Phase_RvwWeek();    break;
            case FINALE         :   Phase_Finale();     break;
            default             :   return -1;
        }
    
        UpdateGamestate();
    }
    
    return 0;
}

Game::Game() {
    debug_mode = GAME_DEBUG;
    curr_gamestate = Game::gamestate(0);    
    next_gamestate = Game::gamestate(1);    
    cash                = 0;
    dead_adventurers    = 0;
    end_game            = true;
    quit_game           = false;
}

int Game::Phase_NotInGame(){
    if(debug_mode) cout << "Phase_NotInGame" << endl;
    return 0;
}

int Game::Phase_Tmbldng(){
    if(debug_mode) cout << "Phase_Tmbldng" << endl;
    
    tmbldr.Greeting();
    tmbldr.HandleInteractions();
    if(tmbldr.quit_tmbldr) {
        quit_game = true; UpdateNextGamestate(NOT_IN_GAME);
    }
    return 0;
}

int Game::Phase_Rocket(){
    if(debug_mode) cout << "Phase_Rocket" << endl;
    tmbldr.Finalise(); // Moves selected adventurers to rocket
    
    rocket.Embark(tmbldr);
    
    rocket.Journey(true);
    
    mission.Disembark(rocket);
    
    return 0;
}
    
int Game::Phase_SimWeek(){
    if(debug_mode) cout << "Phase_SimWeek" << endl;
    return 0;
}
    
int Game::Phase_RvwWeek(){
    if(debug_mode) cout << "Phase_RvwWeek" << endl;
    return 0;
}

int Game::Phase_Finale(){
    if(debug_mode) cout << "Phase_Finale" << endl;
    quit_game = true;
    return 0;
}







