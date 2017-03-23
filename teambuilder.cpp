#include "glbl_settings.h"

void TeamBuilder::PrintPossibleInteractions() {
    cout << "Please choose from one of the following options: " << endl;
    cout << "--[L]ist all adventurers" << endl;
    cout << "--List [A]vailable adventurers" << endl;
    cout << "--List [T]eam already selected" << endl;
    cout << "--[S]elect an adventurer   (Id) for your team" << endl;
    cout << "--[U]nselect an adventurer (Id) for your team" << endl;
    cout << "--[D]one! Shoot off your adventurers if your team is full." << endl;
    cout << "--Print the possible [O]ptions." << endl;
}

int TeamBuilder::Greeting()
{
    cout << "Good morrow to thee fair entrepreneur!" << endl;
    cout << "I see you are building a team to travel to Mars." << endl;
    cout << "There are some adventurers looking to be part of your expedition!" << endl;
    wait_for_user();
    PrintPossibleInteractions();

    return 0;
}

void TeamBuilder::PrintAll() {
    cout << "Please choose " << SIZE_OF_ROCKET << " from these " << SIZE_OF_SELECTION_LIST << " adventurers." << endl;

    for( int j = 0; j < array_len; j++) {
            selection_list[j].PrintID(true);
    }
}  

void TeamBuilder::PrintStillAvail() {    
    for( int j = 0; j < array_len; j++) {
        if(!selection_list[j].selected){
            selection_list[j].PrintID(false);
        }
    }
}   

void TeamBuilder::PrintTeam() {
    bool empty = true;
    
    for( int j = 0; j < array_len; j++) {
        if(selection_list[j].selected){
            selection_list[j].PrintID(false);
            empty = false;
        }
    }
    
    if(empty)cout << "There are no adventurers in your party!" << endl;
}

void TeamBuilder::PrintStats() {
    cout << "Please choose " << SIZE_OF_ROCKET << " from these " << SIZE_OF_SELECTION_LIST << " adventurers." << endl;

    for( int j = 0; j < array_len; j++) {
            selection_list[j].PrintStats();
    }
} 

void TeamBuilder::Finalise(){
    int x_check = SIZE_OF_ROCKET;
    
    int k = 0;
    
    for( int j = 0; j < array_len; j++) {
        if(selection_list[j].selected){
            selected_list[k] = selection_list[j];
            k++;
        }
    }
    if(k != x_check) cout << "ERROR FINALISING!" << endl;
}

void TeamBuilder::IsTeamFull() {
    
    int count_selected  = 0;
    int rocket_size     = SIZE_OF_ROCKET;
    
    for( int j = 0; j < array_len; j++) {
        if(selection_list[j].selected){
            count_selected++;
        }
    }
    
    if(count_selected >= rocket_size) team_full = true;
    else team_full = false;
    
    if(count_selected > rocket_size) {
        too_full = true; 
        cout << "THIS IS NOT GOOD! YOU HAVE SELECTED TOO MANY ADVENTURERS!" << endl;
        cout << "PLEASE REMOVE SOME ADVENTURERS." << endl;
        }
    else too_full = false;
    
    cout << "Currently you have selected " << count_selected << " out of " << rocket_size << " adventurers." << endl ;
    
    if(team_full && !too_full && !user_finished) cout << "Your team is full. Type [D]one to shoot them off in a rocket." << endl ;
}

void TeamBuilder::LookForId( bool i_select = true){
    
    int sel_id;    
    
    cout << "Which adventurer would you like to " << (i_select ? " select" : " unselect")  << "?" << endl;
    cin >> sel_id;
    cin.clear();
    
    cout << "sel_id " << sel_id << endl;
    
    if( (sel_id <= 0) || (sel_id > SIZE_OF_SELECTION_LIST) ) {
        cout << "Bad JUJU in Teambuilder::LookForID" << endl;
        cout << "You entered " << to_string(sel_id) << ". Silly brain!" << endl;
        cout << "Please enter the valid ID of an adventurer" << endl;
        cout << "Press [L] to list all adventurers." << endl;
        }
    else{    
        if(i_select == selection_list[sel_id-1].selected) cout << selection_list[sel_id-1].GetName() << " is already" << (i_select ? " part" : " NOT part") << " of your team!" << endl;
        else{    
            selection_list[sel_id-1].selected = i_select;
            cout << selection_list[sel_id-1].GetName() << " has been" << (i_select ? " added" : " removed") << " from your team." << endl;
        }
    }
}


void TeamBuilder::FillTeam() {
    cout << "Filling team" << endl;
    
    for( int k = 0; k < SIZE_OF_ROCKET; k ++) {
        selection_list[k].selected = true;
    }

}

void TeamBuilder::ConsumeInteraction() {
    
    char   cmd;
    //string response;
    //getline(cin,response);
    cin >> cmd;
    cin.clear();
//     cout << "response : " << response << endl ;
    
    switch(cmd) {
        case('l'): case('L'): PrintAll(); break;
        case('a'): case('A'): PrintStillAvail(); break;
        case('t'): case('T'): PrintTeam(); break;
        case('s'): case('S'): LookForId(true); break;
        case('u'): case('U'): LookForId(false); break;
        case('d'): case('D'): if(team_full && !too_full) user_finished = true;
                              else if(!team_full) cout << "Your team is not full. Please select more adventurers." << endl;
                              else if(too_full)   cout << "Your team is TOO full. Please unselect some adventurers." << endl;
                              break;
        case('o'): case('O'): PrintPossibleInteractions(); break;
        case('q'): case('Q'): quit_tmbldr = true; cout << "Quitting TeamBuilder" << endl; break;
        case('x'): case('X'): if(TEAMBUILDER_DEBUG) {FillTeam(); break;}
        default             : cout << "Invalid command. Enter 'O' or 'o' for Options." << endl;
    }
    cout << "-----------------------------------------" << endl;
}


void TeamBuilder::HandleInteractions(){
    
    do{
        ConsumeInteraction();
        if(quit_tmbldr) break;
        IsTeamFull();
    }while (!team_full || !user_finished );
    
}

TeamBuilder::TeamBuilder(){
    quit_tmbldr     = false;
    team_full       = false;
    too_full        = false;
    user_finished   = false;
    array_len       = sizeof(selection_list)/sizeof(selection_list[0]);
}
