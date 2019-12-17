#ifndef __MOVIE__
#define __MOVIE__

#include <iostream>
#include <vector>
#include <string>

double average(std::vector <int> rates);

struct Information
{
    int init_id;
    std::string init_name;
    int init_year;
    int init_length;
    int init_price;
    std::string init_summary;
    std::string init_director;
    int init_publlisher;
};

struct Comment
{
    int comment_id;
    std::string comment_content;
    std::vector <std::string> replies;
};

class Movie
{
    public:
        Movie(Information init_info);
        Information set_information();
        int get_id() { return id; };
        int get_publisher() { return publisher; };
        int get_price() { return price; };
        void edit_information(Information new_info);
        void recieve_comment(std::string comment_content);
        void recieve_reply(int comment_id, std::string reply_content);
        void recieve_rate(int score) { rates.push_back(score); };
        void delete_comment(int comment_id);
        void show_movie_information();
        void show_movie_comments();
        void show_quick_information();

    private:
        int id;
        std::string name;
        int year;
        std::string director;
        std::string summery;
        int lenght;
        std::vector <int> rates;
        int price;
        std::vector <Comment> comments;
        int publisher;

};


#define COMMENT_HEADER "Comments"
#define COMMENT "comment"
#define DOT ". "
#define MOVIE_NAME "Details of Film"
#define ID "ID = "
#define MOVIE_DIRECTOR "DIRECTOR = "
#define MOVIE_LENGTH "Length = "
#define MOVIE_SUMMERY "Summery = "
#define MOVIE_YEAR "Year = "
#define MOVIE_RATE "Rate = "
#define MOVIE_PRICE "Price = "
#define SPACE " | "

#endif