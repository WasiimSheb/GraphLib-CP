#include <iostream>
#include "Graph.hpp"

using namespace std;
using namespace ariel;

// Define the member functions of the Graph class

Graph::Graph() {}  // An empty constructor
Graph::~Graph() {} // A destructor

Graph::Graph(int size) {
    adjacencymatrix = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
}
/**
 * @brief this function prints how many edges and vertices do exist in the graph
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

/** @brief Load the graph from the adjacency matrix
 *  @param adjmat an adjacency matrix representing the graph we would like to load into
 *  @details the function also checks whther the graph is legal or not and throws an exception if it's not
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

// Get the adjacency matrix of the graph
const vector<vector<int>> &Graph::getAdjacencyMatrix() const
{
    return adjacencymatrix;
}

// Get the number of vertices in the graph
size_t Graph::getNumVertices() const
{
    return adjacencymatrix.size();
}

bool Graph::issquared(const Graph &mat) const
{
    // Check if the dimensions match and matrices are square
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

Graph Graph::operator+(const Graph &mat)
{
    for (size_t i = 0; i < this->adjacencymatrix.size(); i++)
    {
        if (this->adjacencymatrix.size() != mat.adjacencymatrix.size() || this->adjacencymatrix.size() != mat.adjacencymatrix[i].size())
        {
            __throw_invalid_argument("dimentions do not correlate with each other!");
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

Graph &Graph::operator/=(int k)
{
    for (int i = 0; i < this->adjacencymatrix.size(); i++)
    {
        for (int j = 0; j < this -> adjacencymatrix.size(); j++)
        {
            this->adjacencymatrix[i][j] /= k;
        }
    }

    return *this;
}

Graph Graph::operator-(const Graph &mat)
{
    vector<vector<int>> newadj(this->getNumVertices(), vector<int>(this->getNumVertices(), 0));
    Graph g;
    for (size_t i = 0; i < this->adjacencymatrix.size(); i++)
    {
        if (this->adjacencymatrix.size() != mat.adjacencymatrix.size() || this->adjacencymatrix.size() != mat.adjacencymatrix[i].size())
        {
            __throw_invalid_argument("dimentions do not correlate with each other!");
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

Graph &Graph::operator+()
{
    return *this;
}

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

bool Graph::containsGraph(const Graph &other) const
{
    vector<vector<int>> thisMatrix = this->getAdjacencyMatrix();
    vector<vector<int>> otherMatrix = other.getAdjacencyMatrix();
    size_t thisSize = this->getNumVertices();
    size_t otherSize = other.getNumVertices();

    // Check if the other graph is larger than this graph
    if (thisSize < otherSize)
    {
        return false;
    }

    // Check if this graph contains the other graph's adjacency matrix as a sub-matrix
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
                return true; // Found a sub-matrix
            }
        }
    }

    return false; // Sub-matrix not found
}

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

bool Graph::operator>=(const Graph &mat) const
{
    return *this > mat || *this == mat;
}

bool Graph::operator<=(const Graph &mat) const
{
    return *this < mat || *this == mat;
}

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

bool Graph::operator!=(const Graph &mat) const
{
    return !(*this == mat);
}
