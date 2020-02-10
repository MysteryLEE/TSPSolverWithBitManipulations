#include "proj1.hpp"
#include <iostream> // for debug purposes, see project description for a suggestion.
#include <limits> // for UINT_MAX
#include <vector>

using namespace std;

// Solve TSP exactly, using dynamic programming.
// The grading script will use this exact function signature, so do not change it!
// The graph is given as an adjacency matrix, HOWEVER, no edges have a cost of '0'.
// The value graph[i][j] tells you the cost of an edge from i TO j.  This graph is directed.
// 		However, if graph[i][j]==0, this means there is no edge from i to j, instead of having one of that cost.

#define INF UINT16_MAX

long calculation_of_cost(std::vector<std::vector<long>> g,unsigned N) {

    const long states = 1 << (N-1); //the number of the subset of vertices of all vertices
    vector<vector<long>> dp(N,vector<long>(states,0)); //stands for the shortes path of 'I start from a vertex i to i, passing through all the vertices in this state.'
    for (int i = 0; i < N; i++) {
        dp[i][0] = g[i][0]; //if this state is empty.
    }

    for (long j = 1; j < states; j++) { // in this state, I try all vertices to select one with least cost.
        for (int i = 0; i < N; i++) {
            dp[i][j] = INF;
            //if state j contains i, continue
            if (((j >> (i - 1)) & 1) == 1) {
                continue;
            }
            for (int k = 1; k < N; k++) {
                if (((j >> (k - 1)) & 1) == 0) {
                    continue;
                }
                if (dp[i][j] > g[i][k] + dp[k][j ^ (1 << (k - 1))]) {
                    dp[i][j] = g[i][k] + dp[k][j ^ (1 << (k - 1))];
                }
            }
        }
    }
    return dp[0][states-1];
}

std::vector<unsigned> path_solver(std::vector<std::vector<long>>& g, unsigned N) {

    std::vector<unsigned> journey;
    const int states = 1 << (N - 1);
    vector<vector<long>> dp(N, vector<long>(states,0));
    vector<vector<long>> path(N, vector<long>(states, 0));
    for (int i = 0; i < N; i++) {
        dp[i][0] = g[i][0];
    }

    for (long j = 1; j < states; j++) {
        for (int i = 0; i < N; i++) {
            dp[i][j] = INF;

            if (i != 0 && ((j >> (i - 1)) & 1) == 1) {
                continue;
            }
            for (int k = 1; k < N; k++) {
                if (((j >> (k - 1)) & 1) == 0) {
                    continue;
                }
                if (dp[i][j] > g[i][k] + dp[k][j ^ (1 << (k - 1))]) {
                    dp[i][j] = g[i][k] + dp[k][j ^ (1 << (k - 1))];
                    path[i][j] = k;
                }
            }
        } // above is the same dp method.
    }
    long state = states - 1, start = 0;
    //cout << "output path: " << endl;
    //cout << start << "==>";
    journey.push_back(start);
    long cur = path[start][state];
    while (state > 0) {
        //cout << cur << "==>";
        journey.push_back(cur);
        state -= (1 << (cur - 1));
        cur = path[cur][state];
    }
    //cout << start << endl;
    return journey;
}

//I need to handle 0s that are not located at diagonal line of the matrix
std::vector<std::vector<long>> processing_Graph(const std::vector<std::vector<long>> & graph,unsigned n){
    std::vector<std::vector<long>> graph_processed=graph;
    for (unsigned i=0;i<n;i++){
        for (unsigned j=0;j<n;j++){
            if ((i!=j)&&(graph_processed[i][j]==0)){
                graph_processed[i][j]=INF;
            }
        }
    }
    return graph_processed;
}

std::vector<unsigned> tsp_dynamic_program(const std::vector<std::vector<long>> & graph, unsigned n)
{
	std::vector<unsigned> journey;
    std::vector<std::vector<long>> new_graph=processing_Graph(graph,n);
    journey=path_solver(new_graph,n);
    return journey; 
}


// Returns the cost of the journey described here.
long costOfJourney(const std::vector<std::vector<long>> & graph, const std::vector<unsigned> & journey)
{
	std::vector<std::vector<long>> new_graph=processing_Graph(graph,journey.size());
    return calculation_of_cost(new_graph,journey.size());
}
