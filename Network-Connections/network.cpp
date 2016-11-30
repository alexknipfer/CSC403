#include <iostream>
#include <cmath>
#include <fstream>
#include "MyNetwork.hpp"

using namespace std;

int main(){
    ifstream inputFile("input.txt");

    int numOfComputers;
    int xCoord, yCoord;

        //read in number of computers in network
    inputFile >> numOfComputers;

        //continue reading until invalid number of computers
    while(numOfComputers != 0){

            //initialize network
        MyNetwork network;

            //get x and y coordinates for each computer
        for(int x = 0; x < numOfComputers; x++){
            inputFile >> xCoord >> yCoord;

                //read the data into vectors
            network.loadData(xCoord, yCoord);
        }

        network.printVector();
        network.calcShortest();

            //get next network
        inputFile >> numOfComputers;
    }
    

    return 0;
}

//******************************************************************************

void MyNetwork::loadData(int x, int y){
        //Receives - x point and y point
        //Task - adds x and y points to vectors
        //Returns - nothing

    xCoordinates.push_back(x);
    yCoordinates.push_back(y);
}

//******************************************************************************

void MyNetwork::calcShortest(){
    int iterate = 0;
    int maxSize = xCoordinates.size();

    //double smallest = calcDistance(xCoordinates[0], xCoordinates[1], yCoordinates[0], yCoordinates[1]);
    for(int y = 0; y < xCoordinates.size(); y++){
        for(int x = iterate; x < xCoordinates.size() - 1; x++){
            double currDistance = calcDistance(xCoordinates[iterate], xCoordinates[x + 1], yCoordinates[iterate], yCoordinates[x + 1]);
            data myData;
            myData.x1 = xCoordinates[iterate];
            myData.x2 = xCoordinates[x + 1];
            myData.y1 = yCoordinates[iterate];
            myData.y2 = yCoordinates[x + 1]; 
            myData.distance = currDistance;
            myGraph[iterate][x] = myData;
        }
        iterate++;
    }

    for(int x = 0; x < xCoordinates.size(); x++){
        for(int y = 0; y < yCoordinates.size(); y++){
            cout << myGraph[x][y].distance << " ";
        }
        cout << endl;
    }
}

//******************************************************************************

double MyNetwork::calcDistance(int x1, int x2, int y1, int y2){
        //Receives - x and y coordinates
        //Task - calculate the distance between two points
        //Returns - nothing

    double distance = 0;
    int xDistance = (x2 - x1) * (x2 - x1);
    int yDistance = (y2 - y1) * (y2 - y1);
    distance = sqrt(xDistance + yDistance);

    return distance;
}

//******************************************************************************

    //just make sure data is being read in properly
void MyNetwork::printVector()
{
    for(int x = 0; x < xCoordinates.size(); x++){
        cout << xCoordinates[x] << " " << yCoordinates[x] << endl;
    }

    cout << "********" << endl;
}
//******************************************************************************


