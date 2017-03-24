#ifndef __module_h__
#define __module_h__

class Module:public Equipment{

public:
    
    enum m_function {
                SHELL,
                KITCHEN,
                GEOLOGY_LAB,
                BIOLOGY_LAB,
                INFIRMARY,
                GARAGE,
                DORMITORY,
                CONSERVATORY
            };
    
    Module()
        :Equipment( s_mod_id++, "MOD_NAME_ASSIGNED", 200+rand()%100, false )
    {
        module_function = SHELL;
    }; 

    void    PrintID();
    void    UpdateFunction( m_function );
    string  GetFunctionStr();
private:
    static int      s_mod_id;
    enum m_function module_function;
    
    
    
};

#endif //__module_h__

