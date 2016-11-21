#ifndef MyNetwork_HPP
#define MyNetwork_HPP

#include <vector>

using namespace std;

class MyNetwork{
    public:
        void loadData(int, int);
        void calcDistance(int, int, int, int);
        void printVector();

    private:
        vector<int> xCoordinates;
        vector<int> yCoordinates;
};

#endif