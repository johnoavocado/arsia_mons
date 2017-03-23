#include <iostream>
#include <fstream>
using namespace std;

#include "glbl_settings.h"

// #include "glbl_settings.h"

void PrintBanner(void);
void PrintCredits(void);

int main()
{
	srand(time(NULL));
    
    char cmd;
    	
    Game        arsia;    
    
    if(SIZE_OF_ROCKET > SIZE_OF_SELECTION_LIST){
        cout << "GLBL ERR: SIZE_OF_ROCKET > SIZE_OF_SELECTION_LIST" << endl;
        exit(EXIT_FAILURE);
    }
    
    PrintBanner();
    /*cout << "Fancy a game? [y/n]" << endl;
    cin >> cmd;
    
    if(cmd == 'y'|cmd == 'Y')*/ arsia.RunGamestate();
    cout << endl << "Au revoir, Arsia Mons!" << endl << endl;
    
    PrintCredits();
	return 0;
}

void PrintBanner(){
    ifstream f("assets/arsia_mons_banner.txt");    
    if (f.is_open())
        std::cout << f.rdbuf();
    f.close();
        
    cout << endl;
    cout << "Arsia Mons V0.1" << endl;
    cout << "A game designed by John O'Donnell" << endl;
    cout << endl;
}

void PrintCredits(){
    cout << "This was a game designed by John O'Donnell" << endl << endl;
}