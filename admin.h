#ifndef __ADMIN__
#define __ADMIN__

#include <iostream>
#include <vector>
#include <string>

class Admin
{
    public:
        Admin(std::string init_un, std::string init_p) : username(init_un), password(init_p) {}
        void show_net_money();
    private:
        std::string username;
        std::string password;
};


#endif