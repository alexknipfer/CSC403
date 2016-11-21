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

    //just make sure data is being read in properly
void MyNetwork::printVector()
{
    for(int x = 0; x < xCoordinates.size(); x++){
        cout << xCoordinates[x] << " " << yCoordinates[x] << endl;
    }

    cout << "********" << endl;
}
//******************************************************************************


