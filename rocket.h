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
        
        const Adventurer * getAdv(int i_mem) {return &adventurers_on_rocket[i_mem];};
        const Rover      * getRov(int i_mem) {return &rovers_on_rocket[i_mem];};
        const Suit       * getSut(int i_mem) {return &suits_on_rocket[i_mem];};
        const Module     * getMod(int i_mem) {return &modules_on_rocket[i_mem];};
        
    private:
        
        Adventurer adventurers_on_rocket [SIZE_OF_ROCKET];
        Rover      rovers_on_rocket      [NO_OF_ROVERS];
        Suit       suits_on_rocket       [NO_OF_SUITS];
        Module     modules_on_rocket     [NO_OF_MODULES];
    
};

#endif // __rocket_h__
