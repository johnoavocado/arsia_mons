#ifndef __game_h__
#define __game_h__


class Game{

public:
	enum gamestate {
	    NOT_IN_GAME,
	    TMBLDNG,
	    ROCKET,
	    SIM_WEEK,
	    RVW_WEEK,
	    FINALE
	};
    
    Game(); // Constructor
    int RunGamestate();
    
    std::string GamestateStr( gamestate );
    
    // Phase classes - one for each gamestate?
    TeamBuilder tmbldr;
    Rocket      rocket;
    Mission     mission;
    
private:

    bool debug_mode;
    bool end_game;
    bool quit_game;
    
    int cash;
    int dead_adventurers;
    gamestate curr_gamestate;
    gamestate next_gamestate;
    void UpdateGamestate();
    void UpdateNextGamestate( gamestate );
    
    // The game states
    // Can be developed individually
    int Phase_NotInGame();
    int Phase_Tmbldng();
    int Phase_Rocket();
    int Phase_SimWeek();
    int Phase_RvwWeek();
    int Phase_Finale();
    
};

#endif //__game_h__
