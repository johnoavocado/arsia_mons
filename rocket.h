#ifndef __rocket_h__
#define __rocket_h__

class Rocket{
        
    public:
        // properties
        bool quit_rocket;
        
        int Greeting();
        
        Rocket(); // Constructor
        void Embark( TeamBuilder );
        
        void Journey( bool ); // Bitta flavour text
        void PrintModules();
        
        void AssignSensibleModuleFuncs(int);
        
        const Adventurer * getAdv(int i_mem) {return &adventurers_on_rocket[i_mem];};
        const Rover      * getRov(int i_mem) {return &rovers_on_rocket[i_mem];};
        const Suit       * getSut(int i_mem) {return &suits_on_rocket[i_mem];};
        const Module     * getMod(int i_mem) {return &modules_on_rocket[i_mem];};
        
        void UpdateTourFlags();
        
    private:
        
        Adventurer adventurers_on_rocket [SIZE_OF_ROCKET];
        Rover      rovers_on_rocket      [NO_OF_ROVERS];
        Suit       suits_on_rocket       [NO_OF_SUITS];
        Module     modules_on_rocket     [NO_OF_MODULES];
        
        // Tour info
        int        bio_on_tour;
        int        geo_on_tour;
        int        phy_on_tour;
    
        Module::m_function WhichLab();
};

#endif // __rocket_h__
