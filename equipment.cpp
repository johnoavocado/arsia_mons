#include "glbl_settings.h"

Equipment::Equipment()
{
	health      = 100;
	health_max  = health;
}

Equipment::Equipment( int i_health )
{
	health      = i_health;
	health_max  = health;
}

int Equipment::GetHealth( bool i_ret_max = false ){
    if (i_ret_max) return health_max;
    else           return health;
} 