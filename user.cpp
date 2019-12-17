#include "user.h"


User::User(std::string init_email, std::string init_username, int init_password, int init_age, bool init_is_publisher)
{
    email = init_email;
    username = init_username;
    password = init_password;
    age = init_age;
    is_publisher = init_is_publisher;
}

User::User(std::string init_email, std::string init_username, int init_password, int init_age)
{
    email = init_email;
    username = init_username;
    password = init_password;
    age = init_age;
    is_publisher = false;
}

void User::print_specification()
{
    std::cout << id << " " << username << " " << email << std::endl;
}

void User::send_message(std::vector<User*> &users, Message_pack msg)
{
    for(int i = 0; i < users.size(); i++)
    {
        if(msg.contact_id == users[i]->get_id())
        {   
            msg.contact_id = id;
            users[i]->recieve_message(msg);
        }
    }
}

int User::log_in(std::string PW)
{
    if (std::stoi(PW) == password)
    {
        logged_in = true;
        std::cout << "you are in" << std::endl;
    }

    else
        throw Bad_request();
    
    return id;
}

void User::log_out()
{
    logged_in = false;
}