#include "publisher.h"

void Publisher::submit_movie(Movie* &movie)
{
    movies.push_back(movie);
}

void Publisher::edit_movie(Information new_info)
{
    for(int i = 0; i < movies.size(); i++)
    {
        if(new_info.init_id == movies[i]->get_id())
        {
            movies[i]->edit_information(new_info);
            break;
        }
    }
}

void Publisher::delete_movie(int movie_id)
{
    bool check = false; 
    for(int i = 0; i < movies.size(); i++)
    {
        if(movie_id == movies[i]->get_id())
        {
            check = true;
            delete movies[i];
            break;
        }
    }
    if(check == false)
        throw Not_found();
}


void Publisher::pay_money()
{
    std::cout << OK << std::endl;
    money = 0;
}

void Publisher::print_movies()
{
    Information info;
    std::cout << MOVIES_HEADER << std::endl;
    for(int i = 0; i < movies.size(); i++)
    {
        info = movies[i]->set_information();
        std::cout << info.init_id << SEPRATION << info.init_name 
            << SEPRATION << info.init_length << info.init_price 
            << SEPRATION << info.init_year << SEPRATION 
                << info.init_director << std::endl;
    }
}

void Publisher::delete_comment(int movie_id, int comment_id)
{
    for(int i = 0; i < movies.size(); i++)
    {
        if(movie_id == movies[i]->get_id())
        {
            movies[i]->delete_comment(comment_id);
            break;
        }
    }
}

// void Publisher::add_follower(Customer* &follower)
// {
//     followers.push_back(follower);
// }

// void Publisher::show_followers()
// {
//     std::cout << FOLLOWERS_HEADER << std::endl;
//     for(int i = 0; i <followers.size(); i++)
//         std::cout << i << DOT << followers[i]->get_id() << SEPRATION 
//             << followers[i]->get_username() 
//             << SEPRATION << followers[i]->get_email() << std::endl;
// }