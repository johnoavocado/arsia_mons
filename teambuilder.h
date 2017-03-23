#ifndef __teambuilder_h__
#define __teambuilder_h__

class TeamBuilder{
        
    public:
        // properties
        bool quit_tmbldr;

        
        int Greeting();
        void PrintAll();
        void PrintStillAvail();
        void PrintTeam();
        void PrintStats();
        void PrintPossibleInteractions();
        void LookForId(bool);
        void ConsumeInteraction();
        void HandleInteractions();
        // Interactions
        void IsTeamFull();
        
        TeamBuilder(); // Constructor
        void FillTeam();
        void Finalise();
        
        const Adventurer * getSel(int i_mem) {return &selected_list[i_mem];};        
        
    private:
        
        bool team_full;
        bool too_full;
        bool user_finished;
        int  array_len; 
        Adventurer selection_list [SIZE_OF_SELECTION_LIST];
        Adventurer selected_list [SIZE_OF_ROCKET];
    
};

#endif // __teambuilder_h__
