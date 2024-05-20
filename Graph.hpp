#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
using namespace std;

namespace ariel{
    class Graph{
        private:
            vector<vector<int>> adjacencymatrix;
            bool issquared(const Graph& other) const;
            bool containsGraph(const Graph& other) const;
            int numofedges(const Graph& other) const;

        public:

            Graph();
            Graph(int);
            ~Graph();
            void printGraph();
            void loadGraph(vector<vector<int>> adjmat);
            const vector<vector<int>> &getAdjacencyMatrix() const;
            size_t getNumVertices() const;
            Graph& operator++();
            Graph& operator+();
            Graph& operator-();
            Graph& operator++(int);
            Graph& operator--();
            Graph& operator--(int);
            Graph& operator-=(const Graph& mat);
            Graph& operator+=(const Graph& mat);
            Graph operator+(const Graph& mat);
            Graph operator-(const Graph& mat);
            Graph operator*(const Graph& mat);
            Graph& operator*(int);
            Graph& operator/(int);
            bool operator==(const Graph& mat) const;
            bool operator>=(const Graph& mat) const;
            bool operator<=(const Graph& mat) const;
            bool operator!=(const Graph& mat) const;
            bool operator<(const Graph& mat) const;
            bool operator>(const Graph& mat) const;
    };
}
#endif // GRAPH_HPP