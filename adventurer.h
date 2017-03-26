#ifndef __adventurer_h__
#define __adventurer_h__



#include <string>

#define MAX_AGE_LESS_18  52


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
                PHYSIOLOGIST,
                JOURNALIST,
                CELEBRITY
            };
            
            enum e_activity {
                MODULE_ENHC,
                MODULE_REPAIR,
                EQUIP_ENHC,
                EQUIP_REPAIR,
                SYSTEM_ENHC,
                SYSTEM_REPAIR,
                EXPLORE,
                COOK,
                DOCUMENT,
                RELAX
            };
            
            struct s_Activity {
                string      act_name;
                bool        act_available;
            };
            
            
            // Properties	
            bool            selected;
            
            // Methods
            std::string     GetName();
            int             GetAge();
            std::string     GetGenderStr();
            std::string     GetOccupationStr();
            enum occupation GetOccupation();
            bool            GetAlive();
            
            void            PrintID(bool);
            void            PrintStats();
            void            PrintAvailActivities();
            Adventurer(); // Constructor

    private:
            // Properties
            static int      s_adv_id;
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
            s_Activity      curr_activity;
            s_Activity      avail_activities[NO_OF_ACTIVITIES];
            
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

