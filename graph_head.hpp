#pragma once

#include <map>
#include <set>
#include <deque>

class Graph {
    std::map<int, set<int>> adj_list;
public:
    Graph() = default;
    Graph(std::map<int, std::set<int>>);
    void add_vertex$edge(int, int);
    void add_vertex$edge(int);
    bool is_cyclic(int, int, std::deque<bool>&);
    bool is_tree();
    void print();
};