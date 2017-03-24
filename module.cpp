#include "glbl_settings.h"

int Module::s_mod_id = 1;

void Module::PrintID()
{
    Equipment::PrintID( );
}

string Module::GetFunctionStr(void) {
    switch(module_function) {
        case SHELL          : return "SHELL";
        case KITCHEN        : return "KITCHEN";
        case GEOLOGY_LAB    : return "GEOLOGY_LAB";
        case BIOLOGY_LAB    : return "BIOLOGY_LAB";
        case INFIRMARY      : return "INFIRMARY";
        case GARAGE         : return "GARAGE";
        case DORMITORY      : return "DORMITORY";
        case CONSERVATORY   : return "CONSERVATORY";
        default             : return "Broken Occupation!";
    }
}

void Module::UpdateFunction( Module::m_function i_module_function)
{
    module_function = i_module_function;
    SetName( GetFunctionStr() );
}


