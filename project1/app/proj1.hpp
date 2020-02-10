#ifndef __PROJ_1_HPP
#define __PROJ_1_HPP

#include <vector>

// Solve TSP exactly, using dynamic programming.
// The grading script will use this exact function signature, so do not change it!
// The graph is given as an adjacency matrix, HOWEVER, no edges have a cost of '0'.
// The value graph[i][j] tells you the cost of an edge from i TO j.  This graph is directed and might not be symmetric. 
// 		However, if graph[i][j]==0, this means there is no edge from i to j, instead of having one of that cost.
// One requirement that was NOT present in project 0:  the vector you return must start at vertex 0.
//		You are allowed to solve in any other fashion, but your returned journey must begin at 0.
//		See proj1.cpp for an example of how we use this.
std::vector<unsigned> tsp_dynamic_program(const std::vector<std::vector<long>> & graph, unsigned n);


// Returns the cost of the journey described here.
// If the journey is invalid, such as traversing an edge of "cost" 0, the behavior is undefined. 
// That means you get to decide what to do in that case.
// No test cases I provide will have that situation _unless_ it is as a return value from 
// your tsp_dynamic_program (see the sample cases for an example)
long costOfJourney(const std::vector<std::vector<long>> & graph, const std::vector<unsigned> & journey);



#endif
