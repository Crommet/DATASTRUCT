// The 0/1 Knapsack Problem is a classic problem in computer science and optimization. 
// Given a set of items, each with a weight and a profit, the goal is to determine the 
// maximum profit that can be obtained by selecting a subset of the items such that the total 
// weight does not exceed a given capacity. The constraint is that each item can either be included
// in the knapsack or not, hence the name 0/1 Knapsack.

// The problem:
// Input: a set of S = { s1, …, sn } of n items where each si has value vi and weight wi, 
// and a knapsack capacity W.
// Required solution: choose a subset O of S such that the total weight of the items chosen does
// not exceed W and the sum of items vi in O is maximal with respect to any other subset that meets 
// the constraint.
// Compare to the fractional knapsack problem:
// • In fractional knapsack, we’re allowed to add a fraction xi of each item to the knapsack
// • This one called 0/1 knapsack because same as requiring each xi to be either 0.0 or 1.0.
// • Recall we found optimal solution for fractional knapsack when our greedy choice 
// function picked as much as possible of the next item with the highest value-to-weight ratio.
#include <iostream>
using namespace std;