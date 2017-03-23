#ifndef __adventurer_h__
#define __adventurer_h__



#include <string>

#define MAX_AGE_LESS_18  52
#define ADVENTURER_DEBUG false


class Adventurer{

    public:
            enum gender {
                MALE,
                FEMALE,
                ROBOT
            };
            
            enum occupation {
                ENGINEER,
                MEDIC,
                BIOLOGIST,
                GEOLOGIST,
                JOURNALIST,
                CELEBRITY,
                FARMER
            };
            
            // Properties	
            bool            selected;
            static int      adv_ovr;
            
            // Methods
            std::string     GetName();
            int             GetAge();
            std::string     GetGenderStr();
            std::string     GetOccupationStr();
            void            PrintID(bool);
            void            PrintStats();
            Adventurer(); // Constructor

    private:
            // Properties
            int             adv_id;
            std::string     adv_fstname;
            std::string     adv_surname;
            int             adv_age;
            enum gender     adv_gender;
            enum occupation adv_occupation;
            bool            alive;
            int             health;
            int             max_health;
            int             sanity;      
            int             max_sanity;      
            int             productivity;
            int             max_productivity;
            
            // Methods
            enum gender     RandomGender( bool );
            enum occupation RandomOccupation( );
            std::string     RandomFstname();
            std::string     RandomSurname();
            int             RandomAge();
            
            int             RandomHealth(int,enum gender);
            int             RandomSanity(int,enum gender);
            int             RandomProductivity(int, enum gender);
};



#endif // __adventurer_h__

