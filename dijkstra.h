#include <queue>

typedef std::pair<int, float> graphPair;
typedef std::vector<std::vector<graphPair> > dijkstraGraph;

class Dijkstra {
private:
    // variables
    dijkstraGraph graph;

    std::vector<float> distance;
    std::vector<int> parent;
    std::vector<int> path;
    
    unsigned counter;
    
    // methods
    void program(int argc, char * argv[]);
    
    void license();
    
    void readTGF(const std::string & filename);
    
    void initialization(const int & source);
    
    void computeDistances(const int & target);
    
    bool createPath(const int & source, const int & target);
    
    void printPath(const int & target);
    
    // comperator
    struct Comperator {
        int operator() (const graphPair & pair1, const graphPair & pair2) {
            return pair1.second > pair2.second;
        }
    };
    
    std::priority_queue<graphPair, std::vector<graphPair>, Comperator> priorityQueue;
    
public:
    Dijkstra(int argc, char * argv[]) {
        program(argc, argv);
    }
};