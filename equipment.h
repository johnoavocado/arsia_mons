#ifndef __equipment_h__
#define __equipment_h__

class Equipment{

public:
	Equipment();
	Equipment( int, string, int, bool );
	
	const void PrintID(  );
	
	int     GetID();
	int     GetHealth(bool);
	string  GetName();
	string  GetStatus();
	
	void    SetName(string);
	void    SetStatus(bool);
	
	
private:
    int     equipment_id;
    int     health;
    int     health_max;
    string  equipment_name;
    bool    status;

};

#endif //__equipment_h__
