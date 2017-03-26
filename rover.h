#ifndef __rover_h__
#define __rover_h__

class Rover : public Equipment{

public:    
    Rover()
        :Equipment( s_rov_id, "ROVER_"+to_string(s_rov_id), 100+rand()%100, false )
    {
        s_rov_id++;
    }; 
    
    void PrintID();
    
private:
    static int s_rov_id;

};

#endif //__rover_h__

