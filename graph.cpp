#include "graph.h"

void Graph::add_new_node()
{
    for(int i = 0; i < movies_graph.size(); i++)
        movies_graph[i].push_back(0);
    std::vector <int> v(movies_graph[0].size(), 0);
    movies_graph.push_back(v);
}


std::vector <int> Graph::find_top_movies(int node_id)
{
    std::vector <int> sorted_movies_by_rewards;
    std::vector <int> request__movie_ids;
    
    sorted_movies_by_rewards = movies_graph[node_id];
    std::sort(sorted_movies_by_rewards.begin(), sorted_movies_by_rewards.end());
    
    for (int i = 1; i <= REQUESTED_NUMBER; i++) 
        request__movie_ids.push_back(sorted_movies_by_rewards[sorted_movies_by_rewards.size() - i]);
    
    return request__movie_ids;
}

void Graph::update_edge(int node_id, std::vector <int> related_nodes)
{
    for(int i = 0; i < related_nodes.size(); i++)
    {
        movies_graph[node_id][related_nodes[i]] += REWARD_QUANTOM;
        movies_graph[related_nodes[i]][node_id] += REWARD_QUANTOM;
    }
    movies_graph[node_id][node_id] = REWARDLESS;
}