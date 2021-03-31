#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

double prob() {
    return (static_cast<double>(rand())/RAND_MAX);
}

int main(void) {
    int size = 15; // default size
    double density;
    std::cout << "graph density(0,1)?" << std::endl;
    std::cin >> density;
    bool** graph;
    int** color;
    int** cost;
    srand(time(0)); //seed random number generator
    
    // construct the graph
    graph = new bool*[size];
    color = new int*[size];
    cost = new int*[size];
    for (int i = 0; i < size ; ++i){
        graph[i] = new bool[size];
        color[i] = new int[size];
        cost[i] = new int[size];
    }

    for (int i = 0; i < size; ++i) // generate undirected edges
        for(int j = i; j < size; ++j)
            if(i == j) graph[i][j]=false; //no loops
            else graph[i][j] = graph[j][i] = (prob()<density);

    for (int i = 0; i < size; ++i) // generate costs and color
        for(int j = i; j < size; ++j)
            if (graph[i][j]){
                color[i][j] = color[j][i] = rand()%3; // 3colors: 0,1,2
                cost[i][j] = cost[j][i] = prob()*30; // 0 ~ 29
            }

    std::ofstream outp("test/graph_data.txt");
    outp << size << "\n";
    for (int i = 0; i < size; ++i)
        for(int j = 0; j<size;++j){
            if (graph [i][j])
                outp << "("<< i << "," << j << "):" <<
                    cost[i][j]
                    << "," << color[i][j] << ";";
        }
}