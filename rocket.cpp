#include "glbl_settings.h"



// Constructor
Rocket::Rocket()
{
	quit_rocket = false;
	
}

int Rocket::Greeting()
{
    cout << "BLAST OFF!" << endl;
    return 0;
}

void Rocket::Embark( TeamBuilder i_tmbldr )
{
    cout << "Embarking with the following team" << endl;
    i_tmbldr.Finalise();
    
    for(int j=0; j<SIZE_OF_ROCKET; j++){
        adventurers_on_rocket[j] = *i_tmbldr.getSel(j);
        adventurers_on_rocket[j].PrintID(true);
    }
    
}

void Rocket::Journey( bool i_long = false )
{
    if(i_long){
        cout << "This is the long version of the story" << endl;
        cout << "Your team of lemmings travels to Mars" << endl;
        cout << "They enter their cryogenic sleep in the facility on Earth" << endl;
        wait_for_user();
        cout << "Tah dah! They wake up after landing on Mars" << endl;
        wait_for_user();
    }else{
        cout << "This is the short version of the story" << endl;
        cout << "Your travels to Mars. Nothing eventful happens." << endl;
        wait_for_user();
    }
}
