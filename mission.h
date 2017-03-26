#ifndef __mission_h__
#define __mission_h__

class Mission{

public:
	Mission(); // constuctor
	void Setup(int, int, int, int, int, int, int); // Parameterised
	
	void Disembark( Rocket , bool );
	
	void PrintMissionStatus();
	
	void PrintModules();
	void PrintRovers();
	void PrintSuits();
	
	const Adventurer * getAdv(int i_mem) {return &adventurers_on_mars[i_mem];};
    const Rover      * getRov(int i_mem) {return &rovers_on_mars[i_mem];};
    const Suit       * getSut(int i_mem) {return &suits_on_mars[i_mem];};
    const Module     * getMod(int i_mem) {return &modules_on_mars[i_mem];};
	
	void SimWeek();
	void SimDay();
	bool ReviewWeek();
	
	int OxygenConsumption();
	int EnergyConsumption();
	int WaterConsumption();
	int FoodConsumption();
	
	void SetOxygen( int );
	void SetOxygenMax( int );
	void SetFood( int );
	void SetFoodMax( int );
	void SetWater( int );
	void SetWaterMax( int );
	void SetMoney(int);
	
	int GetAdventurersAlive();
	int GetModulesOnline();
	
private:
    int kwh_energy;
    int kwh_energy_max;
    int l_oxygen_max;
    int l_oxygen;
    int kg_food_max;
    int kg_food;
    int l_water_max;
    int l_water;
    int money;
    
    int adventurers_alive;
    int modules_online;
    
    // !! This needs to be changed
    // There will be multiple deliveries of adv and equipment as the game goes on
    Adventurer adventurers_on_mars [SIZE_OF_ROCKET]; 
    Rover      rovers_on_mars      [NO_OF_ROVERS];
    Suit       suits_on_mars       [NO_OF_SUITS];
    Module     modules_on_mars     [NO_OF_MODULES];
    
};

#endif //__mission_h__
