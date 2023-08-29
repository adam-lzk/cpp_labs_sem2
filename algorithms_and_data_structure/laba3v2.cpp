// g++ -std=c++11 laba3.cpp -o laba3 (not my code)

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


class Graph
{
    public:
        Graph(int size)
        {
            _size = size;
            this->_adjacencyMatrix.resize(size);
            for(auto it = this->_adjacencyMatrix.begin(); it != this->_adjacencyMatrix.end(); it++ )
            {
                (*it).resize(size);
            }
        }

        ~Graph()
        {
            _adjacencyMatrix.clear();
            _sources.clear();
            _drains.clear();
        }

        void FillTheGraph(Graph &graph)
        {
            cout << "fill 3X3 matrix:\n";

            for(auto i = 0; i < graph._size; i++)
            {
                for(auto j = 0; j < graph._size; j++)
                {
                    int temp;
                    cin >> temp;
                    graph._adjacencyMatrix[i][j] = temp;
                }
            }
        }

        void AddVertex(Graph &graph)
        {
            cout << "how many vertices to add?\n";
            int numberOfNewVertex;
            cin >> numberOfNewVertex;

            _size += numberOfNewVertex;

            this->_adjacencyMatrix.resize(_size);
            for(auto it = this->_adjacencyMatrix.begin(); it != this->_adjacencyMatrix.end(); it++ )
            {
                (*it).resize(_size);
            }

            for(auto newVertex = 0; newVertex < numberOfNewVertex; newVertex++) {
                for (auto i = 0; i < _size; i++) {
                    cout << "Is the new vertex adjacent to " << i + 1 << "?\n"
                         << "1 - yes\n"
                         << "2 - no\n\n";
                    int answer;
                    cin >> answer;

                    answer == 1 ? this->_adjacencyMatrix[_size - 1][i] = 1 : this->_adjacencyMatrix[_size - 1][i] = 0;

                    cout << "Is the " << i + 1 << " vertex adjacent to " << _size << "?\n"
                         << "1 - yes\n"
                         << "2 - no\n\n";
                    cin >> answer;

                    answer == 1 ? this->_adjacencyMatrix[i][_size - 1] = 1 : this->_adjacencyMatrix[i][_size - 1] = 0;
                }
            }

            graph._sources.clear();
            graph._drains.clear();
        }

        void PrintTheMatrix()
        {
            cout << "\nThe adjacency matrix: \n";

            for(auto i = 0; i < this->_size; i++)
            {
                for(auto j = 0; j < this->_size; j++)
                {
                    cout << setw(this->_size) << this->_adjacencyMatrix[i][j] << " ";
                }
                cout << endl;
            }

            cout << endl << endl;
        }

        void FindTheSources(Graph graph)
        {
            for(auto i = 0; i < graph._size; i++)
            {
                for(auto j = 0; j < graph._size; j++)
                {
                    if(graph._adjacencyMatrix[i][j] == 0)
                        break;

                    if(j == graph._size - 1)
                    {
                        _sources.push_back(i+1);
                    }
                }
            }
        }

        void FindDrains(Graph graph)
        {
            for(auto j = 0; j < graph._size; j++)
            {
                for(auto i = 0; i < graph._size; i++)
                {
                    if(graph._adjacencyMatrix[i][j] == 0)
                        break;

                    if(i == graph._size - 1)
                    {
                        _drains.push_back(j+1);
                    }
                }
            }
        }

        void PrintSources()
        {
            cout << "Source peaks: " << endl;

            for(auto source : this->_sources)
                cout << source << " ";

            cout << endl << endl;
        }

        void PrintDrains()
        {
            cout << "Drains peaks: " << endl;

            for(auto drain : this->_drains)
                cout << drain << " ";

            cout << endl << endl;
        }


    private:
        vector<vector<int> > _adjacencyMatrix;
        vector<int> _sources;
        vector<int> _drains;
        int _size;
};




int main()
{
    Graph newGraph(3);

    newGraph.FillTheGraph(newGraph);

    newGraph.PrintTheMatrix();

    newGraph.FindTheSources(newGraph);
    newGraph.PrintSources();

    newGraph.FindDrains(newGraph);
    newGraph.PrintDrains();

    newGraph.AddVertex(newGraph);

    newGraph.FindTheSources(newGraph);
    newGraph.PrintSources();

    newGraph.FindDrains(newGraph);
    newGraph.PrintDrains();

    newGraph.PrintTheMatrix();

    return 0;
}
