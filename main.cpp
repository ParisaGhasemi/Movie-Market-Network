#include "main.h"

int main()
{
    Management management_system;

    try{management_system.start_managing();}
    
    catch(Not_found nf){ std::cout << "Not Found" << std::endl; }
    catch(Bad_request br){ std::cout << "Bad Request" << std::endl;}
    catch(Permission_dinied pd){ std::cout << "Permission Denied" << std::endl;}
}