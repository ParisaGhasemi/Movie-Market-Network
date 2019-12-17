#include "management.h"

void Management::start_managing()
{
    std::string command;
    std::cout << ENTER_COMMAND << std::endl;

    while(getline(std::cin, command))
        run_command(command);
}


void Management::run_command(std::string command)
{
    std::vector <std::string> splited_command = split(command, DELIMITER);

    if(splited_command[1] == SIGNUP_COMMAND)
        create_new_user(splited_command);
    else if(splited_command[1] == LOGIN_COMMAND)
        enter_user(splited_command);
    else if(splited_command[1] == LOGOUT_COMMAND)
        logout_user(splited_command);
    else if(splited_command[1] == FILM_COMMAND)
        run_film_command(splited_command);
    else if(splited_command[1] == SUBMIT_KIND)
        create_new_user(splited_command);
    if(splited_command[1] == DELETE_KIND)
        delete_movie(splited_command);
    else if(splited_command[1] == FOLLOWER_COMMAND)
        run_follower_command(splited_command);
    else if(splited_command[1] == MONEY_COMMAND)
        run_money_command(splited_command);
    else if(splited_command[1] == BUY_COMMAND)
        buy_movie(splited_command);   
    else if(splited_command[1] == RATE_COMMAND)
        rate_movie(splited_command);
    else if(splited_command[1] == COMMENTS_COMMAND)
        submit_comment(splited_command);
    else if(splited_command[1] == DELETE_COMMENT)
        delete_comment(splited_command);
    else if(splited_command[1] == PURCHASED_COMMAND)
        show_purchased_movies(splited_command);
    else if(splited_command[1] == NOTIFICATION_COMMAND)
        show_messages(splited_command);

}

void Management::create_admin()
{
    admin = new Admin(ADMIN_USERNAME, ADMIN_PASS);
    is_admin = true;
    is_publisher = false;
}

std::vector <std::string> split(std::string command, std::string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector <std::string> res;

    while ((pos_end = command.find (delimiter, pos_start)) != std::string::npos) 
    {
        token = command.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (command.substr (pos_start));
    return res;
}

void Management::run_film_command(std::vector <std::string> splited_command)
{
    if(splited_command[0] == POST_KIND_COMMAND)
        submit_movie(splited_command);
    if(splited_command[0] == GET_KIND_COMMAND)
        show_movie_details(splited_command);
}

void Management::run_follower_command(std::vector <std::string> splited_command)
{
    if(splited_command[0] == POST_KIND_COMMAND)
        follow_publisher(splited_command);
    if(splited_command[0] == GET_KIND_COMMAND)
        show_publisher_followers(splited_command);
}

void Management::run_money_command(std::vector <std::string> splited_command)
{
    if(splited_command[0] == POST_KIND_COMMAND)
        give_money(splited_command);
    else if(splited_command[0] == GET_KIND_COMMAND && is_admin == true)
        admin->show_net_money();
    else if(splited_command[0] == GET_KIND_COMMAND && is_publisher == false)
        increase_credit(splited_command);
    else if(splited_command[0] == GET_KIND_COMMAND && is_publisher == true)
        increase_credit(splited_command);
}

void Management::create_new_user(std::vector <std::string> splited_command)
{
    if(is_there_same_username(splited_command[USERNAME_ELEMENT]))
        throw Bad_request();

    if(splited_command.size() == INCLUDE_PUBLISHER)
    {
        Publisher *publisher = new Publisher(EMAIL, SIGNUP_USERNAME, PASSWORD, AGE, IS_PUBLISHER);
        publishers.push_back(publisher);
    }
    else
    {
        Customer *customer = new Customer(EMAIL, SIGNUP_USERNAME, PASSWORD, AGE);
        customers.push_back(customer);
    }
}

void Management::enter_user(std::vector <std::string> splited_command)
{
    if(SIGNUP_USERNAME == ADMIN_USERNAME)
        create_admin();
    else
    {
        for (int i = 0; i < publishers.size(); i++)
        {
            if(publishers[i]->get_username() == splited_command[LOGIN_USERNAME])
            {
                online_id = publishers[i]->log_in(splited_command[LOGIN_PASSWORD]);
                is_publisher = true;
                return;
            }
        }
        for (int i = 0; i < customers.size(); i++)
        {
            if(customers[i]->get_username() == splited_command[LOGIN_USERNAME])
            {
                online_id = customers[i]->log_in(splited_command[LOGIN_PASSWORD]);
                is_publisher = false;
                return;
            }
        }
    }
}

void Management::logout_user(std::vector <std::string> splited_command)
{
    if(is_publisher == true)
    {
        for (int i = 0; i < publishers.size() + customers.size(); i++)
        {
            if(publishers[i]->get_username() == splited_command[LOGIN_USERNAME])
                publishers[i]->log_out();
        }
    }
    else
    {
        for (int i = 0; i < customers.size() + customers.size(); i++)
        {
            if(customers[i]->get_username() == splited_command[LOGIN_USERNAME])
                customers[i]->log_out();
        }
    }
}

void Management::submit_movie(std::vector <std::string> splited_command)
{
    if(!is_publisher)
        throw Permission_dinied();

    Information new_info = set_information(movies.size(), splited_command);

    Movie *movie = new Movie(new_info);
    movies.push_back(movie);
    publishers[online_id]->submit_movie(movie);
    recomendation_graph->add_new_node();
}

void Management::edit_movie(std::vector <std::string> splited_command)
{
    if(!is_publisher)
        throw Permission_dinied();

    Information new_info = set_information(movies.size(), splited_command);

    for (int i = 0; i < movies.size(); i++)
    {
        if(movies[i]->get_id() == std::stoi(splited_command[MOVIE_EDIT_ID]))
            movies[i]->edit_information(new_info);
    }
}

void Management::delete_movie(std::vector <std::string> splited_command)
{
    if(!is_publisher)
        throw Permission_dinied();

    for (int i = 0; i < movies.size(); i++)
    {
        if(movies[i]->get_id() == std::stoi(splited_command[MOVIE_EDIT_ID]))
        {
            delete movies[i];
            std::cout << OK << std::endl;
            break;
        }
    }
}

void Management::show_movie_details(std::vector <std::string> splited_command)
{
    if(is_publisher)
        throw Permission_dinied();

    for (int i = 0; i < movies.size(); i++)
    {
        if(movies[i]->get_id() == std::stoi(splited_command[MOVIE_ID]))
            movies[i]->show_movie_information();
            movies[i]->show_movie_comments();
    }
    std::vector <int> recomendation_ids = recomendation_graph->find_top_movies(MOVIE_ID);
    std::cout << RECOMENDATION;
    for (int i = 0; i < REQUESTED_NUMBER; i++)
        movies[recomendation_ids[i]]->show_quick_information();    
}

void Management::follow_publisher(std::vector <std::string> splited_command)
{
    if(is_publisher)
        throw Permission_dinied();

    Message_pack msg;
    msg.contact_id = online_id;
    msg.message = FOLLOWED_MESSAGE;
    publishers[USER_ID]->recieve_message(msg);
    publishers[USER_ID]->add_follower(customers[online_id]);
    customers[online_id]->follow(publishers[USER_ID]);
}

void Management::show_publisher_followers(std::vector <std::string> splited_command)
{
    if(!is_publisher)
        throw Permission_dinied();

    publishers[online_id]->show_followers();
}

void Management::give_money(std::vector <std::string> splited_command)
{
    if(is_publisher)
        throw Permission_dinied();

    publishers[online_id]->pay_money();
}

void Management::increase_credit(std::vector <std::string> splited_command)
{
    if(is_publisher)
        throw Permission_dinied();

    customers[online_id]->increase_credit(AMOUNT);
}

void Management::buy_movie(std::vector <std::string> splited_command)
{
    if(is_publisher)
        throw Permission_dinied();

    customers[online_id]->buy_movie(movies, MOVIE_ID);
    std::cout << OK;
    publishers[movies[MOVIE_ID]->get_publisher()]->increase_money(movies[MOVIE_ID]->get_price());
    recomendation_graph->update_edge(MOVIE_ID, customers[online_id]->get_bought_movie_ids());
}

void Management::rate_movie(std::vector <std::string> splited_command)
{
    if(is_publisher)
        throw Permission_dinied();

    customers[online_id]->rate_movie(movies, MOVIE_ID, SCORE);
}

void Management::submit_comment(std::vector <std::string> splited_command)
{
    if(is_publisher)
        throw Permission_dinied();

    customers[online_id]->comment(movies, MOVIE_ID, COMMENT_CONTENT);
}

void Management::delete_comment(std::vector <std::string> splited_command)
{
    if(!is_publisher)
        throw Permission_dinied();

    for(int i = 0; i < movies.size(); i++)
    {
        if(movies[i]->get_id() == MOVIE_ID)
            movies[i]->delete_comment(COMMENT_ID);
    }
}



void Management::show_purchased_movies(std::vector <std::string> splited_command)
{
    if(is_publisher)
        throw Permission_dinied();

    customers[online_id]->show_bought_movies();
}

void Management::show_messages(std::vector <std::string> splited_command)
{
    customers[online_id]->show_all_messages();
}

bool Management::is_there_same_username(std::string input_username)
{
    for(int i = 0; i < publishers.size(); i++)
    {
        if(publishers[i]->get_username() == input_username)
            return true;
    }
    for(int i = 0; i < customers.size(); i++)
    {
        if(customers[i]->get_username() == input_username)
            return true;
    }
    return false;
}

Information Management::set_information(int id, std::vector <std::string> splited_command)
{
    Information new_info;
    new_info.init_id = id;
    new_info.init_name = MOVIE_SUBMIT_NAME;
    new_info.init_year = MOVIE_SUBMIT_YEAR;
    new_info.init_length = MOVIE_SUBMIT_LENGTH;
    new_info.init_price = MOVIE_SUBMIT_PRICE;
    new_info.init_summary = MOVIE_SUBMIT_SUMMERY;
    new_info.init_director = MOVIE_SUBMIT_DIRECTOR;
    new_info.init_publlisher = online_id; 

    return new_info;
}

