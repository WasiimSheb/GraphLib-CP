#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
using namespace std;

namespace ariel
{
    class Graph
    {
    private:
        vector<vector<int>> adjacencymatrix;
        bool issquared(const Graph &other) const;
        bool containsGraph(const Graph &other) const;
        int numofedges(const Graph &other) const;

    public:
        Graph();
        Graph(int);
        ~Graph();
        void printGraph();
        void loadGraph(vector<vector<int>> adjmat);
        const vector<vector<int>> &getAdjacencyMatrix() const;
        size_t getNumVertices() const;
        Graph &operator++();
        Graph &operator+();
        Graph &operator-();
        Graph &operator++(int);
        Graph &operator--();
        Graph &operator--(int);
        Graph &operator-=(const Graph &mat);
        Graph &operator+=(const Graph &mat);
        Graph &operator*=(int scalar);
        Graph &operator/=(int scalar);
        Graph operator+(const Graph &mat);
        Graph operator-(const Graph &mat);
        Graph operator*(const Graph &mat);
        Graph &operator*(int);
        Graph &operator/(int);
        bool operator==(const Graph &mat) const;
        bool operator>=(const Graph &mat) const;
        bool operator<=(const Graph &mat) const;
        bool operator!=(const Graph &mat) const;
        bool operator<(const Graph &mat) const;
        bool operator>(const Graph &mat) const;

        friend ostream &operator<<(ostream &os, const Graph &graph)
        {
            const vector<vector<int>> &matrix = graph.getAdjacencyMatrix();
            for (size_t i = 0; i < matrix.size(); ++i)
            {
                os << "[";
                for (size_t j = 0; j < matrix[i].size(); ++j)
                {
                    os << matrix[i][j];
                    if (j != matrix[i].size() - 1)
                    {
                        os << ", ";
                    }
                }
                os << "]";
                if (i != matrix.size() - 1)
                {
                    os << ", ";
                }
            }
            return os;
        }
    };
}
#endif // GRAPH_HPP
