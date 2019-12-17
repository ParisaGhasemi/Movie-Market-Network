#ifndef __GRAPH__
#define __GRAPH__

#include <algorithm>
#include "movie.h"


class Graph
{
    public:
        void add_new_node();
        std::vector <int> find_top_movies(int node_id);
        void update_edge(int node_id, std::vector <int> related_nodes);

    private:
        std::vector <std::vector <int> > movies_graph;
};


#define REWARD_QUANTOM 1
#define REWARDLESS 0
#define REQUESTED_NUMBER 4
#endif