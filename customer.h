#ifndef __CUSTOMER__
#define __CUSTOMER__

#include "user.h"
#include "movie.h"
#include "publisher.h"

class Customer : public User
{
    public:
        Customer(std::string init_email, std::string init_username, 
            int init_password, int init_age, bool init_is_publisher)
            : User(init_email, init_username, init_password, init_age, init_is_publisher) 
                { credit = 0; unread_index = 0; }
        Customer(std::string init_email, std::string init_username, 
            int init_password, int init_age)
            : User(init_email, init_username, init_password, init_age) 
            { credit = 0; unread_index = 0; }
        
        void increase_credit(int amount);
        void buy_movie(const std::vector <Movie*>& all_movies, int movie_id);
        void rate_movie(const std::vector <Movie*>& all_movies, int movie_id, int score);
        void comment(const std::vector <Movie*>& all_movies, int movie_id, std::string content);
        void show_bought_movies();
        void show_unread_messages();
        void show_all_messages();
        int get_credit() { return credit; };
        std::vector <int> get_bought_movie_ids();
        void show_money() { std::cout << credit << std::endl;};
        // void follow(Publisher* &following) { followings.push_back(following); };

        
    private:
        std::vector <Movie*> movies;
        std::vector <User*> followings;
        int credit;
        int unread_index;
};

#define NOTIFICATION "#. Notification Message"
#define RATING_RESULT "POST comments ? "

#endif