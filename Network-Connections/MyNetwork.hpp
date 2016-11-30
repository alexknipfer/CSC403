#ifndef MyNetwork_HPP
#define MyNetwork_HPP

#include <vector>

using namespace std;

class MyNetwork{
    public:
        void loadData(int, int);
        double calcDistance(int, int, int, int);
        void calcShortest();
        void printVector();

    private:
        vector<int> xCoordinates;
        vector<int> yCoordinates;
        struct data{
            int x1, x2;
            int y1, y2;
            double distance;
        };
        data myGraph[150][150];
        vector< vector<data> > graph;
};

#endif