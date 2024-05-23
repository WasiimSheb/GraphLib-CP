#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
using namespace ariel;
TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.getAdjacencyMatrix() == expectedGraph);
    CHECK(Algorithms::isConnected(g3) == true);

    ariel::Graph g4, g5, result;
    // Create the graph
    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g4.loadGraph(graph4);

    // Expected result after addition
    vector<vector<int>> expectedGraph1 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};

    // Perform addition
    result = g4 + g4;
    CHECK(result.getAdjacencyMatrix() == expectedGraph1);
    CHECK(Algorithms::isBipartite(result) == "The graph is bipartite: A={0, 2}, B={1}");
    vector<vector<int>> expectedGraph2 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g5.loadGraph(expectedGraph2);
    CHECK(result + g5 == result);

    vector<vector<int>> expectedGraph3 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    ariel::Graph g10;
    g10.loadGraph(expectedGraph3);
    CHECK(g10 == ++g5);

    vector<vector<int>> expectedGraph4 = {
        {3, 3, 3},
        {3, 3, 3},
        {3, 3, 3}};
    ariel::Graph g11;
    g11.loadGraph(expectedGraph4);
    CHECK(g11 == ++g5++);

    vector<vector<int>> expectedGraph5 = {
        {4, 4, 4},
        {4, 4, 4},
        {4, 4, 4}};
    ariel::Graph g12;
    g12.loadGraph(expectedGraph5);
    CHECK(g12 == ++g5);
    CHECK(Algorithms::isConnected(g12) == true);
    CHECK(Algorithms::shortestPath(g12, 0, 1) == "0->1");
    CHECK(Algorithms::isContainsCycle(g12) == true);
    CHECK(Algorithms::negativeCycle(g12) == "The graph does not contain a negative cycle.");

    vector<vector<int>> expectedGraph6 = {
        {8, 8, 8},
        {8, 8, 8},
        {8, 8, 8}};
    ariel::Graph g13, g14, g15;
    g13.loadGraph(expectedGraph6);
    g14 = g5+=g5;
    CHECK(g13 == g14);
    g15 = g13-=g12;
    CHECK(g15 == g12);
}

TEST_CASE("Test graph multiplication and division")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    CHECK(g4.getAdjacencyMatrix() == expectedGraph);

    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g5.loadGraph(graph5);
    ariel::Graph g6 = g5 * g5;
    vector<vector<int>> expectedGraph2 = {
        {1, 0, 1},
        {0, 2, 0},
        {1, 0, 1}};
    CHECK(g6.getAdjacencyMatrix() == expectedGraph2);
    CHECK(Algorithms::shortestPath(g6, 0, 1) == "-1");
    CHECK(Algorithms::shortestPath(g6, 2, 0) == "2->0");
    CHECK(Algorithms::isContainsCycle(g6) == true);
    CHECK(Algorithms::negativeCycle(g6) == "The graph does not contain a negative cycle.");

    ariel::Graph g7, g8;
    vector<vector<int>> graph6 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g7.loadGraph(graph6);

    vector<vector<int>> graph7 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g8.loadGraph(graph7);

    vector<vector<int>> expectedGraph3 = {
        {2, 0, 2},
        {0, 4, 0},
        {2, 0, 2}};
    ariel::Graph g9;
    g9.loadGraph(expectedGraph3);
    CHECK(g9 == g8 * g7);
    CHECK(g7 * 2 == g8);
    CHECK(Algorithms::isConnected(g9) == false);
    CHECK(Algorithms::shortestPath(g9, 0, 2) == "0->2");
    CHECK(Algorithms::shortestPath(g9, 0, 1) == "-1");

    vector<vector<int>> expectedGraph4 = {
        {1, 0, 1},
        {0, 2, 0},
        {1, 0, 1}};
    ariel::Graph g10;
    g10.loadGraph(expectedGraph4);
    CHECK(g10 == g9 / 2);
}

TEST_CASE("operators relations")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g3.loadGraph(graph3);

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g4.loadGraph(graph4);

    // Test operator <
    CHECK(g1 < g2);
    CHECK(!(g1 < g3));

    // Test operator <=
    CHECK(g1 <= g2);
    CHECK(g1 <= g3);
    // Test operator >
    CHECK(g2 > g1); //
    CHECK(!(g1 > g3));

    // Test operator >=
    CHECK(g2 >= g1);
    CHECK(g1 >= g3);

    // Test operator ==
    CHECK(g1 == g3);
    CHECK(!(g1 == g2));

    // Test operator !=
    CHECK(g1 != g2);
    CHECK(!(g1 != g3));
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    CHECK_THROWS(g2.loadGraph(weightedGraph));

    //        {{0, 1, 1, 1},
    //        {1, 0, 2, 1},
    //        {1, 2, 0, 1},
    //        {1, 2, 3, 4}};
    //    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}