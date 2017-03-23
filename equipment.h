#ifndef __equipment_h__
#define __equipment_h__

class Equipment{

public:
	Equipment();
	Equipment( int );
	
	int GetHealth(bool);
	
private:
    int health;
    int health_max;

};

#endif //__equipment_h__
