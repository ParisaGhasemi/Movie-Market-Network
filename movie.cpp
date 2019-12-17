#include "movie.h"

Movie::Movie(Information init_info)
{
    edit_information(init_info);
}

void Movie::edit_information(Information new_info)
{
    id = new_info.init_id;
    name = new_info.init_name;
    year = new_info.init_year;
    lenght = new_info.init_length;
    price = new_info.init_price;
    summery = new_info.init_summary;
    director = new_info.init_director;
}

void Movie::recieve_comment(std::string comment_content)
{
    Comment new_comment;
    new_comment.comment_id = comments.size() + 1;
    new_comment.comment_content = comment_content;
    comments.push_back(new_comment);
}

void Movie::recieve_reply(int comment_id, std::string reply_content)
{
    comments[comment_id - 1].replies.push_back(reply_content);
}

void Movie::delete_comment(int comment_id)
{
    comments.erase(comments.begin() + comment_id);
}

Information Movie::set_information()
{
    Information current_info;

    current_info.init_id = id;
    current_info.init_name = name;
    current_info.init_year = year;
    current_info.init_length = lenght;
    current_info.init_price = price;
    current_info.init_summary = summery;
    current_info.init_director = director;

    return current_info;
}

void Movie::show_movie_information()
{
    std::cout << MOVIE_NAME << name << std::endl;
    std::cout << ID << id << std::endl;
    std::cout << MOVIE_DIRECTOR << director << std::endl;
    std::cout << MOVIE_LENGTH << lenght << std::endl;
    std::cout << MOVIE_YEAR << year << std::endl;
    std::cout << MOVIE_SUMMERY << summery << std::endl;
    std::cout << MOVIE_RATE << average(rates) << std::endl;
    std::cout << MOVIE_PRICE << price << std::endl;
}

void Movie::show_movie_comments()
{
    std::cout << std::endl << COMMENT_HEADER << std::endl;
    for(int i = 0; i < comments.size(); i++)
    {
        std::cout << COMMENT << i << DOT 
            << comments[i].comment_content << std::endl;
        for(int j = 0; j < comments[i].replies.size(); j++)
            std::cout << COMMENT << i << DOT << j << DOT 
                << comments[i].comment_content << std::endl;
    }
}

double average(std::vector <int> rates)
{
    int sum = 0;
    for(int i = 0; i < rates.size(); i++)
        sum += rates[i];
    
    return sum/rates.size();
}

void Movie::show_quick_information()
{
    std::cout << name << SPACE;
    std::cout << id << SPACE;
    std::cout << director << SPACE;
    std::cout << lenght << SPACE;
    std::cout << year << SPACE;
    std::cout << summery << SPACE;
    std::cout << average(rates) << SPACE;
    std::cout << price << std::endl;
}