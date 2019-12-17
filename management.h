#ifndef __MANAGEMENT__
#define __MANAGEMENT__

#include "movie.h"
#include "customer.h"
#include "publisher.h"
#include "admin.h"

#include "graph.h"

std::vector <std::string> split(std::string command, std::string delimiter);
 

class Management
{
    public:
        void start_managing();
        void run_command(std::string command);

        void create_admin();
        void create_new_user(std::vector <std::string> splited_command);
        void enter_user(std::vector <std::string> splited_command);
        void logout_user(std::vector <std::string> splited_command);
        void submit_movie(std::vector <std::string> splited_command);
        void edit_movie(std::vector <std::string> splited_command);
        void delete_movie(std::vector <std::string> splited_command);
        void show_movie_details(std::vector <std::string> splited_command);
        void follow_publisher(std::vector <std::string> splited_command);
        void show_publisher_followers(std::vector <std::string> splited_command);
        void give_money(std::vector <std::string> splited_command);
        void increase_credit(std::vector <std::string> splited_command);
        void buy_movie(std::vector <std::string> splited_command);
        void search(int film_id, std::string name, int min_rate, 
            int min_year, int price, int max_year, std::string director);
        void rate_movie(std::vector <std::string> splited_command);
        void submit_comment(std::vector <std::string> splited_command);
        void delete_comment(std::vector <std::string> splited_command);
        void show_purchased_movies(std::vector <std::string> splited_command);
        void show_messages(std::vector <std::string> splited_command);
        void run_film_command(std::vector <std::string> splited_command);
        void run_follower_command(std::vector <std::string> splited_command);
        void run_money_command(std::vector <std::string> splited_command);
        friend void Admin::show_net_money();
        bool is_there_same_username(std::string input_username);
        Information set_information(int id, std::vector <std::string> splited_command);

    private:
        std::vector <Publisher*> publishers;
        std::vector <Customer*> customers;
        Admin* admin;
        std::vector <Movie*> movies;
        Graph* recomendation_graph;;
        int online_id;
        bool is_publisher;
        bool is_admin;
};
 
#define ENTER_MESSAGE "please enter your message and your contact id"
#define ENTER_COMMAND "please enter your command"
#define RECOMENDATION "Recommendation Film" << std::endl << "#. Film Id | Film Name | Film Length | Film Director" << std::endl

#define ADMIN_USERNAME "admin"
#define ADMIN_PASS "admin"

#define POST_KIND_COMMAND "POST"
#define PUT_KIND_COMMAND "PUT"
#define DELETE_KIND_COMMAND "DELETE"
#define GET_KIND_COMMAND "GET"
#define SIGNUP_COMMAND "signup"
#define LOGIN_COMMAND "login"
#define LOGOUT_COMMAND "logout"
#define FILM_COMMAND "films"
#define FOLLOWER_COMMAND "followers"
#define MONEY_COMMAND "money"
#define REPLY_COMMAND "replies"
#define COMMENTS_COMMAND "comments"
#define BUY_COMMAND "buy"
#define RATE_COMMAND "rate"
#define PURCHASED_COMMAND "purchased"
#define NOTIFICATION_COMMAND "notifications"
#define READ_COMMAND "read"
#define SUBMIT_KIND "put_films"
#define DELETE_KIND "delete_films"
#define DELETE_COMMENT "delete_comment"

#define USERNAME_ELEMENT 6
#define INCLUDE_PUBLISHER 13
#define LOGIN_USERNAME 4
#define LOGIN_PASSWORD 6

#define MOVIE_SUBMIT_NAME splited_command[4].substr(1, splited_command[4].size() - 2)
#define MOVIE_SUBMIT_YEAR std::stoi(splited_command[6].substr(1, splited_command[6].size() - 2))
#define MOVIE_SUBMIT_LENGTH std::stoi(splited_command[8].substr(1, splited_command[8].size() - 2))
#define MOVIE_SUBMIT_PRICE std::stoi(splited_command[10].substr(1, splited_command[10].size() - 2))
#define MOVIE_SUBMIT_SUMMERY splited_command[12].substr(1, splited_command[12].size() - 2)
#define MOVIE_SUBMIT_DIRECTOR splited_command[14].substr(1, splited_command[14].size() - 2)

#define MOVIE_EDIT_ID std::stoi(splited_command[4].substr(1, splited_command[4].size() - 2))
#define MOVIE_EDIT_NAME splited_command[6].substr(1, splited_command[6].size() - 3)
#define MOVIE_EDIT_YEAR std::stoi(splited_command[8].substr(1, splited_command[8].size() - 3))
#define MOVIE_EDIT_LENGTH std::stoi(splited_command[10].substr(1, splited_command[10].size() - 3))
#define MOVIE_EDIT_SUMMERY splited_command[12].substr(1, splited_command[12].size() - 3)
#define MOVIE_EDIT_DIRECTOR splited_command[14].substr(1, splited_command[14].size() - 3)

#define MOVIE_ID std::stoi(splited_command[4].substr(1, splited_command[4].size() - 2))
#define SCORE std::stoi(splited_command[6].substr(1, splited_command[6].size() - 2))
#define AMOUNT std::stoi(splited_command[4].substr(1, splited_command[4].size() - 2))
#define COMMENT_CONTENT splited_command[6].substr(1, splited_command[6].size() - 2)
#define COMMENT_ID std::stoi(splited_command[6].substr(1, splited_command[6].size() - 2))

#define EMAIL splited_command[4].substr(1, splited_command[4].size() - 2)
#define SIGNUP_USERNAME splited_command[6].substr(1, splited_command[6].size() - 2)
#define PASSWORD std::stoi(splited_command[8].substr(1, splited_command[8].size() - 2))
#define AGE std::stoi(splited_command[10].substr(1, splited_command[10].size() - 2))
#define IS_PUBLISHER std::stoi(splited_command[12].substr(1, splited_command[12].size() - 3))

#define USER_ID std::stoi(splited_command[4].substr(1, splited_command[4].size() - 2))
#define FOLLOWERS_HEADER "List of Followers" << std::endl << "#. User Id | User Username | User Email"
#define FOLLOWED_MESSAGE "you are followed by the mentioned contact"
#define DELIMITER " "


#endif