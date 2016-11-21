#include <iostream>
#include <cmath>
#include "MyNetwork.hpp"

using namespace std;

int main(){
    MyNetwork network;

    return 0;
}

//******************************************************************************

void MyNetwork::calcDistance(int x1, int x2, int y1, int y2){
        //Receives - x and y coordinates
        //Task - calculate the distance between two points
        //Returns - nothing

    double distance = 0;
    int xDistance = (x2 - x1) * (x2 - x1);
    int yDistance = (y2 - y1) * (y2 - y1);
    distance = sqrt(xDistance + yDistance);
}

//******************************************************************************


