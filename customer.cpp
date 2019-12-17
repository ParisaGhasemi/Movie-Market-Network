#include "customer.h"


void Customer::buy_movie(const std::vector <Movie*>& all_movies, int movie_id)
{
    for(int i = 0; i < all_movies.size(); i++)
    {
        if(all_movies[i]->get_id() == movie_id)
            movies.push_back(all_movies[i]);
    }
    std::cout << OK << std::endl;
}

void Customer::rate_movie(const std::vector <Movie*>& all_movies, int movie_id, int score)
{
    for(int i = 0; i < all_movies.size(); i++)
    {
        if(all_movies[i]->get_id() == movie_id)
            all_movies[i]->recieve_rate(score);
    }
    std::cout << OK << std::endl;
}

void Customer::comment(const std::vector <Movie*>& all_movies, int movie_id, std::string content)
{
    for(int i = 0; i < all_movies.size(); i++)
    {
        if(all_movies[i]->get_id() == movie_id)
            all_movies[i]->recieve_comment(content);
    }
    std::cout << RATING_RESULT << movie_id << content << std::endl;
}

void Customer::show_bought_movies()
{
    std::cout << MOVIES_HEADER << std::endl;
    for(int i = 0; i < movies.size(); i++)
    {
        std::cout << i  << DOT << std::endl;
        movies[i]->show_quick_information();
    }
}

void Customer::show_unread_messages()
{
    std::cout << NOTIFICATION << std::endl;
    for(int i = unread_index; i < inbox.size(); i++)
        std::cout << i - unread_index << DOT << inbox[i].message << std::endl;
}

void Customer::show_all_messages()
{
    std::cout << NOTIFICATION << std::endl;
    for(int i = 0; i < inbox.size(); i++)
        std::cout << i << DOT << inbox[i].message << std::endl;
}

void Customer::increase_credit(int amount)
{
    credit += amount;
    std::cout << OK << std::endl;
}

std::vector <int> Customer::get_bought_movie_ids()
{
    std::vector <int> ids;
    for (int i = 0; i < movies.size(); i++)
        ids.push_back(movies[i]->get_id());
    return ids;
}