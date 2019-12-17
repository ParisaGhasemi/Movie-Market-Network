#ifndef __USER__
#define __USER__

#include <iostream>
#include <vector>
#include <string>


struct Message_pack
{
    int contact_id;
    std::string message;
};

class User
{
    public:
        User(std::string init_email, std::string init_username, 
            int init_password, int init_age, bool init_is_publisher);
        User(std::string init_email, std::string init_username, 
            int init_password, int init_age);
        std::string get_username() const { return username; };
        int get_password() const { return password; };
        int get_id() const { return id; };
        std::string get_email() const { return email; };
        void print_specification();
        void recieve_message(Message_pack msg) { inbox.push_back(msg); };
        void send_message(std::vector<User*> &users, Message_pack);
        int log_in(std::string);
        void log_out();
        
    protected:
        std::string username;
        int id;
        std::string email;
        int password;
        int age;
        bool is_publisher;
        std::vector <Message_pack> inbox;
        bool logged_in;

};


class Not_found : public std::exception {};
class Bad_request : public std::exception {};
class Permission_dinied : public std::exception {};

#define PRINT_SPECIFICATIONS id << " " << username << " " << email << endl

#endif