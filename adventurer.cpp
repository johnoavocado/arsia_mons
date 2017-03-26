#include "glbl_settings.h"

int Adventurer::s_adv_id = 1; // initialise the overall number of adventurers


string Adventurer::GetName(void)  {
    return adv_fstname + ' ' + adv_surname;
}

int Adventurer::GetAge(void)    {
    return adv_age;
}

string Adventurer::GetGenderStr(void) {
    switch(adv_gender) {
        case MALE   : return "Male";
        case FEMALE : return "Female";
        case ROBOT  : return "Robot";
        default     : return "Broken Gender!";
    }
}

string Adventurer::GetOccupationStr(void) {
    switch(adv_occupation) {
        case ENGINEER       : return "Engineer";
        case MEDIC          : return "Medic";
        case BIOLOGIST      : return "Biologist";
        case GEOLOGIST      : return "Geologist";
        case PHYSIOLOGIST   : return "Physiologist";
        case JOURNALIST     : return "Journalist";
        case CELEBRITY      : return "Celebrity";
        default             : return "Broken Occupation!";
    }
}

Adventurer::occupation Adventurer::GetOccupation( ) {
    return adv_occupation;
}


void Adventurer::PrintID(bool print_in_team = false) {
    
    cout << "-----------------------------------" << endl;
    cout << " ID: \t\t"     << adv_id                 << endl;
    cout << " Name:\t\t"    << GetName()              << endl;
    cout << " Age:\t\t"     << adv_age                << endl;
    cout << " Gender:\t"    << GetGenderStr()         << endl;
    cout << " Job:\t\t"     << GetOccupationStr()     << endl;
    if(print_in_team) cout << " In team:\t"      << (selected?"Yes":"No")  << endl;
    cout << "-----------------------------------" << endl;
}

void Adventurer::PrintStats() {
    
    cout << "-----------------------------------" << endl;
    cout << " ID: \t\t"     << adv_id                 << endl;
    cout << " Name:\t\t"    << GetName()              << endl;
    cout << " Age:\t\t"     << adv_age                << endl;
    cout << " Gender:\t"    << GetGenderStr()         << endl;
    cout << " Job:\t\t"     << GetOccupationStr()     << endl;
    cout << " Alive:\t\t"   << (alive?"Yes":"No")     << endl;
    cout << " Health:\t"  << health                 << endl;
    cout << " Sanity:\t"  << sanity                 << endl;
    cout << " Productivity:\t"  << productivity       << endl;
    cout << "-----------------------------------" << endl;
}

void Adventurer::PrintAvailActivities() {
    cout << "-----------------------------------" << endl;
    
    for(int j = 0; j<NO_OF_ACTIVITIES; j++){
        if(avail_activities[j].act_available){
            cout << avail_activities[j].act_name << endl;
        }
    }
    cout << "-----------------------------------" << endl;
}

Adventurer::gender Adventurer::RandomGender( bool allow_robots = false) {
    
    int maxopts = allow_robots ? 3 : 2;
    int myrand = rand() % maxopts;
    
    return Adventurer::gender(myrand);
}

Adventurer::occupation Adventurer::RandomOccupation( ) {
    
    int maxopts = NUMBER_OF_OCCUPATIONS;
    int myrand  = rand() % maxopts;
    
    return Adventurer::occupation(myrand);
}

string GetStrFrmDict ( string i_filename = "NULL" ) {
    
    int randline;
    int file_len;
    int line_number;
    string o_name;
    string line;
    
    ifstream i_file (i_filename);
    
    // Get the length of the file to know the 
    // max rand int
    line_number = 0;
    if(i_file.is_open()){
        while(getline(i_file,line)){
        line_number++;
        }
    }
    
    file_len = line_number;
    randline = rand() % file_len;
    
    i_file.clear();
    i_file.seekg(0);
    
    line_number = 0;
    if(i_file.is_open()){
        while(getline(i_file,line)){
            if(line_number == randline){
                o_name = line;
            }
            line_number++;
        }
    }
    
    i_file.close();
    
    return o_name;
}

string Adventurer::RandomFstname() {

    string i_filename;
    
    switch(adv_gender) {
        case MALE   : i_filename = "assets/dict/male_names.txt"  ; break;
        case FEMALE : i_filename = "assets/dict/female_names.txt"; break;
        case ROBOT  : i_filename = "assets/dict/robot_names.txt" ; break;
        default     : i_filename = "assets/dict/robot_names.txt" ; // Error Handling!
    }
        
    return GetStrFrmDict(i_filename);
}

string Adventurer::RandomSurname() {
    
    string i_filename;
    
    i_filename = "assets/dict/surnames.txt";
    
    return GetStrFrmDict(i_filename);
}

int Adventurer::RandomAge() {
    
    int max_rand = MAX_AGE_LESS_18;
    
    return rand()%max_rand+18;
}

int Adventurer::RandomHealth( int i_age, Adventurer::gender i_gender){
    
    int floor_value;
    int gender_bonus;
    int max_rand = 20;
    
    switch(i_gender){
        case MALE   : gender_bonus = 10;
        case FEMALE : gender_bonus = 0;
        case ROBOT  : gender_bonus = 20;
    }
    //Bands
    if      (i_age <= 25)                   floor_value = 30;
    else if (i_age <= 45)                   floor_value = 20;
    else if (i_age <= 65)                   floor_value = 10;
    else if (i_age <= MAX_AGE_LESS_18 + 18) floor_value = 5;
    else                                    floor_value = 5;
    
    return rand() % max_rand + floor_value + gender_bonus;
}

int Adventurer::RandomSanity( int i_age, Adventurer::gender i_gender){
    
    int floor_value;
    int gender_bonus;
    int max_rand = 20;
    
    switch(i_gender){
        case MALE   : gender_bonus = 0;
        case FEMALE : gender_bonus = 10;
        case ROBOT  : gender_bonus = 20;
    }
    //Bands
    if      (i_age <= 25)                   floor_value = 5;
    else if (i_age <= 45)                   floor_value = 10;
    else if (i_age <= 65)                   floor_value = 20;
    else if (i_age <= MAX_AGE_LESS_18 + 18) floor_value = 30;
    else                                    floor_value = 5;
    
    return rand() % max_rand + floor_value + gender_bonus;
}

int Adventurer::RandomProductivity( int i_age , Adventurer::gender i_gender ){
    int floor_value;
    int gender_bonus;
    int max_rand = 20;
    
    switch(i_gender){
        case MALE   : gender_bonus = 0;
        case FEMALE : gender_bonus = 0;
        case ROBOT  : gender_bonus = 20;
    }
    //Bands
    if      (i_age <= 25)                   floor_value = 15;
    else if (i_age <= 45)                   floor_value = 30;
    else if (i_age <= 65)                   floor_value = 15;
    else if (i_age <= MAX_AGE_LESS_18 + 18) floor_value = 10;
    else                                    floor_value = 5;
    
    return rand() % max_rand + floor_value + gender_bonus;
}

Adventurer::Adventurer(void) {
    
    // Set all the variables
    adv_id         = s_adv_id;
    s_adv_id++; // Increment the overall number of adventureres
    adv_gender     = RandomGender( ALLOW_ROBOTS );
    adv_fstname    = RandomFstname();
    adv_surname    = RandomSurname();
    adv_age        = RandomAge();
    adv_occupation = RandomOccupation();
    selected       = false;
    
    // Stats
    alive          = true;
    health         = RandomHealth(adv_age,adv_gender);
    sanity         = RandomSanity(adv_age,adv_gender);
    productivity   = RandomProductivity(adv_age, adv_gender);
    
    max_health          = health;
    max_sanity          = sanity;
    max_productivity    = productivity;
     
    avail_activities[0].act_name = "MODULE_ENHC";   avail_activities[0].act_available = true;
    avail_activities[1].act_name = "MODULE_REPAIR"; avail_activities[1].act_available = false; // Only when there is a damaged module
    avail_activities[2].act_name = "EQUIP_ENHC";    avail_activities[2].act_available = true;
    avail_activities[3].act_name = "EQUIP_REPAIR";  avail_activities[3].act_available = false; // Only when there is a damaged suit/rover
    avail_activities[4].act_name = "SYSTEM_ENHC";   avail_activities[4].act_available = true;
    avail_activities[5].act_name = "SYSTEM_REPAIR"; avail_activities[5].act_available = false; // Only when there is a damaged system
    avail_activities[6].act_name = "EXPLORE";       avail_activities[6].act_available = true;
    avail_activities[7].act_name = "COOK";          avail_activities[7].act_available = false; // Only when there is a kitchen
    avail_activities[8].act_name = "DOCUMENT";      avail_activities[8].act_available = true;
    avail_activities[9].act_name = "RELAX";         avail_activities[9].act_available = true;
    
//     cout << "You just created an adventurer named : " << GetName() << endl;
    
}