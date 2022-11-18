#include <iostream>
#include <string>
#include <fstream>
#include "graph_head.hpp"

std::map<int, std::set<int>> input_from_file() {
    std::string str;
    std::cout << "Enter the file name: ";
    std::cin >> str;
    std::ifstream gif(str);
    if (!gif) exit(7);
    std::map<int, set<int>> a_l;
    int i = 0;
    gif.clear();
    gif.seekg(0, ios::beg);
    while (std::getline(gif, str)) {
        str = str.substr(3);
        while ((str.find(" ")) != std::string::npos) {
            str.erase(0, str.find(" ") + 1);
            std::string token = str.substr(0, str.find(" "));
            a_l[i].insert(std::stoi(token));
        }
        i++;
    }
    return a_l; // copy elision?
}

int main() {
	std::cout << std::boolalpha;
    Graph g(input_from_file());
    g.is_tree() ?
        std::cout << "This graph from the file is a tree :)" << std::endl :
        std::cout << "This graph from the file is not a tree :(" << std::endl;

    Graph g1;
    g1.add_vertex$edge(0, 1);
    g1.add_vertex$edge(0, 2);
    g1.add_vertex$edge(0, 3);
    g1.add_vertex$edge(3, 4);
    g1.is_tree() ?
        std::cout << "This graph is a tree :)" << std::endl :
        std::cout << "This graph is not a tree :(" << std::endl;

    Graph g2;
    g2.add_vertex$edge(1, 0);
    g2.add_vertex$edge(0, 2);
    g2.add_vertex$edge(2, 1);
    g2.add_vertex$edge(0, 3);
    g2.add_vertex$edge(3, 4);
    g2.is_tree() ?
        std::cout << "This graph is a tree :)" << std::endl :
        std::cout << "This graph is not a tree :(" << std::endl;
}
