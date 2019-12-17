#include "admin.h"

void Admin::show_net_money()
{
    int total_credit = 0;

    for (int i = 0; i < publishers.size(); i++)
        total_credit += publishers[i]->get_credit();

    for (int i = 0; i < customers.size(); i++)
        total_credit += customers[i]->get_credit();

    std::cout << total_credit << std::endl;
}