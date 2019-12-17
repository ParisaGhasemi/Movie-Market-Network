#ifndef __PUBLISHER__
#define __PUBLISHER__

#include "user.h"
#include "movie.h"
#include "customer.h"

class Publisher : public User
{
    public:
        Publisher(std::string init_email, std::string init_username, 
            int init_password, int init_age, bool init_is_publisher)
            : User(init_email, init_username, init_password, init_age, 
                init_is_publisher) { money = 0; }

        void submit_movie(Movie* &movie);
        void edit_movie(Information new_info);
        void delete_movie(int movie_id);
        void pay_money();
        void print_movies();
        void delete_comment(int movie_id, int comment_id);
        // void add_follower(Customer* &follower);
        void increase_money(int sold_price) { money += sold_price; };
        void show_followers();
        int get_credit() { return money; };

    private:
        std::vector <Movie*> movies;
        std::vector <User*> followers;
        int money;
};


#define FOLLOWERS_HEADER "List of Followers" << std::endl << "#. User Id | User Username | User Email"
#define MOVIES_HEADER "#. Film Id | Film Name | Film Length | Film price | rate | Production Year | Film Director"
#define SEPRATION " | "
#define OK "OK"


#endif