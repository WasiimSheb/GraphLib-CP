#include <iostream>
#include "Graph.hpp"

using namespace std;
using namespace ariel;


Graph::Graph() {}  // An empty constructor

Graph::~Graph() {} // A destructor

/**
 * @brief Constructs a Graph with a given number of vertices.
 * @param size The number of vertices in the graph.
 */
Graph::Graph(int size) {
    adjacencymatrix = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
}

/**
 * @brief Prints the number of edges and vertices in the graph.
 */
void Graph::printGraph()
{
    int numofedges = 0;
    for (size_t i = 0; i < this->adjacencymatrix.size(); ++i)
    {
        for (size_t j = 0; j < this->adjacencymatrix[i].size(); ++j)
        {
            if (adjacencymatrix[i][j] != 0)
            {
                numofedges++;
            }
        }
    }
    cout << "Graph with " << this->adjacencymatrix.size() << " vertices and " << numofedges << " edges." << endl;
}

/**
 * @brief Loads the graph from the adjacency matrix.
 * @param adjmat An adjacency matrix representing the graph to be loaded.
 * @details This function also checks whether the graph is a valid square matrix and throws an exception if it is not.
 */
void Graph::loadGraph(vector<vector<int>> adjmat)
{
    for (size_t i = 0; i < adjmat.size(); i++)
    {
        if (adjmat.size() != adjmat[i].size())
        {
            throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
    }
    adjacencymatrix = adjmat;
}

/**
 * @brief Gets the adjacency matrix of the graph.
 * @return A constant reference to the adjacency matrix of the graph.
 */
const vector<vector<int>> &Graph::getAdjacencyMatrix() const
{
    return adjacencymatrix;
}

/**
 * @brief Gets the number of vertices in the graph.
 * @return The number of vertices in the graph.
 */
size_t Graph::getNumVertices() const
{
    return adjacencymatrix.size();
}

/**
 * @brief Checks if the current graph and the given graph are both square matrices of the same size.
 * @param mat The graph to compare with.
 * @return True if both graphs are square matrices of the same size, false otherwise.
 */
bool Graph::issquared(const Graph &mat) const
{
    if (this->getNumVertices() != mat.adjacencymatrix.size())
    {
        return false;
    }

    int size = this->getNumVertices();
    for (int i = 0; i < size; ++i)
    {
        if (this->adjacencymatrix[i].size() != size || mat.adjacencymatrix[i].size() != size)
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Increments each element in the adjacency matrix by 1 (prefix increment).
 * @return A reference to the modified graph.
 */
Graph &Graph::operator++()
{
    int k = this->getNumVertices();
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            this->adjacencymatrix[i][j]++;
        }
    }
    return *this;
}

/**
 * @brief Increments each element in the adjacency matrix by 1 (postfix increment).
 * @return A reference to the modified graph.
 */
Graph &Graph::operator++(int)
{
    int k = this->getNumVertices();
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            this->adjacencymatrix[i][j]++;
        }
    }
    return *this;
}

/**
 * @brief Decrements each element in the adjacency matrix by 1 (postfix decrement).
 * @return A reference to the modified graph.
 */
Graph &Graph::operator--(int)
{
    int k = this->getNumVertices();
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            this->adjacencymatrix[i][j]--;
        }
    }
    return *this;
}

/**
 * @brief Decrements each element in the adjacency matrix by 1 (prefix decrement).
 * @return A reference to the modified graph.
 */
Graph &Graph::operator--()
{
    int k = this->getNumVertices();
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            this->adjacencymatrix[i][j]--;
        }
    }
    return *this;
}

/**
 * @brief Adds the adjacency matrix of another graph to this graph.
 * @param mat The graph to add.
 * @return A reference to the modified graph.
 * @throws invalid_argument If the dimensions of the matrices do not match.
 */
Graph &Graph::operator+=(const Graph &mat)
{
    int size = this->getNumVertices();
    for (int i = 0; i < size; i++)
    {
        if (size != mat.adjacencymatrix.size() || size != mat.adjacencymatrix[i].size())
        {
            __throw_invalid_argument("non compatible dimensions of the matrix");
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            this->adjacencymatrix[i][j] += mat.adjacencymatrix[i][j];
        }
    }

    return *this;
}

/**
 * @brief Subtracts the adjacency matrix of another graph from this graph.
 * @param mat The graph to subtract.
 * @return A reference to the modified graph.
 * @throws invalid_argument If the dimensions of the matrices do not match.
 */
Graph &Graph::operator-=(const Graph &mat)
{
    int size = this->getNumVertices();
    for (int i = 0; i < size; i++)
    {
        if (size != mat.adjacencymatrix.size() || size != mat.adjacencymatrix[i].size())
        {
            __throw_invalid_argument("non compatible dimensions of the matrix");
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            this->adjacencymatrix[i][j] -= mat.adjacencymatrix[i][j];
        }
    }

    return *this;
}

/**
 * @brief Adds the adjacency matrix of another graph to this graph and returns a new graph.
 * @param mat The graph to add.
 * @return A new graph with the result of the addition.
 * @throws invalid_argument If the dimensions of the matrices do not match.
 */
Graph Graph::operator+(const Graph &mat)
{
    for (size_t i = 0; i < this->adjacencymatrix.size(); i++)
    {
        if (this->adjacencymatrix.size() != mat.adjacencymatrix.size() || this->adjacencymatrix.size() != mat.adjacencymatrix[i].size())
        {
            __throw_invalid_argument("dimensions do not correlate with each other!");
        }
    }
    vector<vector<int>> newadj(this->getNumVertices(), vector<int>(this->getNumVertices(), 0));
    Graph g;

    for (size_t i = 0; i < this->adjacencymatrix.size(); i++)
    {
        for (size_t j = 0; j < this->adjacencymatrix.size(); j++)
        {
            newadj[i][j] = this->adjacencymatrix[i][j] + mat.adjacencymatrix[i][j];
        }
    }
    g.adjacencymatrix = newadj;
    return g;
}

/**
 * @brief Divides each element in the adjacency matrix by a scalar.
 * @param k The scalar to divide by.
 * @return A reference to the modified graph.
 */
Graph &Graph::operator/=(int k)
{
    for (int i = 0; i < this->adjacencymatrix.size(); i++)
    {
        for (int j = 0; j < this->adjacencymatrix.size(); j++)
        {
            this->adjacencymatrix[i][j] /= k;
        }
    }

    return *this;
}

/**
 * @brief Subtracts the adjacency matrix of another graph from this graph and returns a new graph.
 * @param mat The graph to subtract.
 * @return A new graph with the result of the subtraction.
 * @throws invalid_argument If the dimensions of the matrices do not match.
 */
Graph Graph::operator-(const Graph &mat)
{
    vector<vector<int>> newadj(this->getNumVertices(), vector<int>(this->getNumVertices(), 0));
    Graph g;
    for (size_t i = 0; i < this->adjacencymatrix.size(); i++)
    {
        if (this->adjacencymatrix.size() != mat.adjacencymatrix.size() || this->adjacencymatrix.size() != mat.adjacencymatrix[i].size())
        {
            __throw_invalid_argument("dimensions do not correlate with each other!");
        }
    }

    for (size_t i = 0; i < this->adjacencymatrix.size(); i++)
    {
        for (size_t j = 0; j < this->adjacencymatrix.size(); j++)
        {
            newadj[i][j] = this->adjacencymatrix[i][j] - mat.adjacencymatrix[i][j];
        }
    }
    g.adjacencymatrix = newadj;
    return g;
}

/**
 * @brief Unary plus operator, returns the graph as is.
 * @return A reference to the graph.
 */
Graph &Graph::operator+()
{
    return *this;
}

/**
 * @brief Unary minus operator, negates each element in the adjacency matrix.
 * @return A reference to the modified graph.
 */
Graph &Graph::operator-()
{
    for (size_t i = 0; i < this->adjacencymatrix.size(); i++)
    {
        for (size_t j = 0; j < this->adjacencymatrix.size(); j++)
        {
            this->adjacencymatrix[i][j] = -this->adjacencymatrix[i][j];
        }
    }
    return *this;
}

/**
 * @brief Multiplies the adjacency matrices of two graphs and returns the result as a new graph.
 * @param mat The graph to multiply with.
 * @return A new graph with the result of the multiplication.
 * @throws invalid_argument If the dimensions of the matrices do not match.
 */
Graph Graph::operator*(const Graph &mat)
{
    if (!issquared(mat))
    {
        __throw_invalid_argument("dimensions of the matrices do not correlate");
    }
    int size = this->adjacencymatrix.size();
    vector<vector<int>> newadj(this->getNumVertices(), vector<int>(this->getNumVertices(), 0));
    // Perform matrix multiplication
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            for (int k = 0; k < size; ++k)
            {
                newadj[i][j] += this->adjacencymatrix[i][k] * mat.adjacencymatrix[k][j];
            }
        }
    }
    Graph g;
    g.adjacencymatrix = newadj;
    return g;
}

/**
 * @brief Multiplies each element in the adjacency matrix by a scalar.
 * @param scalar The scalar to multiply by.
 * @return A reference to the modified graph.
 */
Graph& Graph::operator*=(int scalar)
{
    int size = this->adjacencymatrix.size();
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            this -> adjacencymatrix[i][j]*=scalar;
        }
    }
    return *this;
}

/**
 * @brief Multiplies each element in the adjacency matrix by a scalar and returns the result as a new graph.
 * @param k The scalar to multiply by.
 * @return A reference to the modified graph.
 */
Graph &Graph::operator*(int k)
{
    for (size_t i = 0; i < this->getNumVertices(); i++)
    {
        for (size_t j = 0; j < this->getNumVertices(); j++)
        {
            this->adjacencymatrix[i][j] = k * this->adjacencymatrix[i][j];
        }
    }
    return *this;
}

/**
 * @brief Divides each element in the adjacency matrix by a scalar and returns the result as a new graph.
 * @param k The scalar to divide by.
 * @return A reference to the modified graph.
 */
Graph &Graph::operator/(int k)
{
    double t = 1.0 / k;
    for (size_t i = 0; i < this->getNumVertices(); i++)
    {
        for (size_t j = 0; j < this->getNumVertices(); j++)
        {
            this->adjacencymatrix[i][j] = t * this->adjacencymatrix[i][j];
        }
    }
    return *this;
}

/**
 * @brief Checks if the graph contains another graph's adjacency matrix as a sub-matrix.
 * @param other The graph to check against.
 * @return True if this graph contains the other graph, false otherwise.
 */
bool Graph::containsGraph(const Graph &other) const
{
    vector<vector<int>> thisMatrix = this->getAdjacencyMatrix();
    vector<vector<int>> otherMatrix = other.getAdjacencyMatrix();
    size_t thisSize = this->getNumVertices();
    size_t otherSize = other.getNumVertices();

    if (thisSize < otherSize)
    {
        return false;
    }

    for (size_t i = 0; i <= thisSize - otherSize; ++i)
    {
        for (size_t j = 0; j <= thisSize - otherSize; ++j)
        {
            bool subMatrixFound = true;
            for (size_t m = 0; m < otherSize; ++m)
            {
                for (size_t n = 0; n < otherSize; ++n)
                {
                    if (thisMatrix[i + m][j + n] != otherMatrix[m][n])
                    {
                        subMatrixFound = false;
                        break;
                    }
                }
                if (!subMatrixFound)
                {
                    break;
                }
            }
            if (subMatrixFound)
            {
                return true;
            }
        }
    }

    return false;
}

/**
 * @brief Counts the number of edges in the graph.
 * @param other The graph to count edges for.
 * @return The number of edges in the graph.
 */
int Graph::numofedges(const Graph &other) const
{
    int count = 0;
    for (size_t i = 0; i < this->adjacencymatrix.size(); i++)
    {
        for (size_t j = 0; j < this->adjacencymatrix.size(); j++)
        {
            count += (this->adjacencymatrix[i][j]) ? 1 : 0;
        }
    }
    return count;
}

/**
 * @brief Checks if this graph is greater than or equal to another graph.
 * @param mat The graph to compare with.
 * @return True if this graph is greater than or equal to the other graph, false otherwise.
 */
bool Graph::operator>=(const Graph &mat) const
{
    return *this > mat || *this == mat;
}

/**
 * @brief Checks if this graph is less than or equal to another graph.
 * @param mat The graph to compare with.
 * @return True if this graph is less than or equal to the other graph, false otherwise.
 */
bool Graph::operator<=(const Graph &mat) const
{
    return *this < mat || *this == mat;
}

/**
 * @brief Checks if this graph is less than another graph.
 * @param mat The graph to compare with.
 * @return True if this graph is less than the other graph, false otherwise.
 */
bool Graph::operator<(const Graph &mat) const
{
    if (mat.containsGraph(*this))
    {
        if (containsGraph(mat))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    if (containsGraph(mat))
    {
        return false;
    }
    if (numofedges(*this) < mat.numofedges(mat))
    {
        return true;
    }
    if (numofedges(*this) == mat.numofedges(mat) && adjacencymatrix.size() < mat.adjacencymatrix.size())
    {
        return true;
    }
    return false;
}

/**
 * @brief Checks if this graph is greater than another graph.
 * @param mat The graph to compare with.
 * @return True if this graph is greater than the other graph, false otherwise.
 */
bool Graph::operator>(const Graph &mat) const
{
    if (containsGraph(mat))
    {
        if (mat.containsGraph(*this))
        {
            return false;
        }
        return true;
    }
    if (mat.containsGraph(*this))
    {
        return false;
    }
    if (numofedges(*this) > numofedges(mat))
    {
        return true;
    }
    if (numofedges(*this) == numofedges(mat) && adjacencymatrix.size() >= mat.adjacencymatrix.size())
    {
        return true;
    }
    return false;
}

/**
 * @brief Checks if this graph is equal to another graph.
 * @param mat The graph to compare with.
 * @return True if the graphs are equal, false otherwise.
 * @throws invalid_argument If the dimensions of the matrices do not match.
 */
bool Graph::operator==(const Graph &mat) const
{
    if (!issquared(mat))
    {
        __throw_invalid_argument("non compatible dimensions");
    }
    int size = this->adjacencymatrix.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (this->adjacencymatrix[i][j] != mat.adjacencymatrix[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief Checks if this graph is not equal to another graph.
 * @param mat The graph to compare with.
 * @return True if the graphs are not equal, false otherwise.
 */
bool Graph::operator!=(const Graph &mat) const
{
    return !(*this == mat);
}

