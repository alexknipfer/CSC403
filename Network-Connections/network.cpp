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
        network.createGraph();
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

void MyNetwork::createGraph(){
        //Receives - nothing
        //Task - creates adjacency matrix of nodes in network
        //Returns - nothing

    int iterate = 0;

        //go through all x and y coordinates of current network
    for(int y = 0; y < xCoordinates.size(); y++){
        for(int x = iterate; x < xCoordinates.size() - 1; x++){

                //calculate the distance between two nodes
            double currDistance = calcDistance(xCoordinates[iterate], xCoordinates[x + 1], yCoordinates[iterate], yCoordinates[x + 1]);
            data myData;
            myData.distance = currDistance;

                //add the node to the matrix
            myGraph[iterate][x + 1] = myData;
        }
        iterate++;
    }

        //add coordinates to graph
    for(int x = 0; x < xCoordinates.size(); x++){
        for(int y = 0; y < yCoordinates.size(); y++){
            myGraph[x][y].x1 = xCoordinates[y];
            myGraph[x][y].y1 = yCoordinates[y];
        }
    }

    /*for(int x = 0; x < xCoordinates.size(); x++){
        for(int y = 0; y < yCoordinates.size(); y++){
            cout << myGraph[x][y].x1 << " ";
        }
        cout << endl;
    }*/
}

//******************************************************************************

void MyNetwork::calcShortest(){
    for(int x = 0; x < xCoordinates.size(); x++){
        for(int y = 0; y < yCoordinates.size(); y++){
            cout << myGraph[x][y].distance << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;

    int position = 0;
    int x1, y1;
    double smallest;

    /*for(int x = 0; x < xCoordinates.size(); x++){
        smallest = 500.0;
        for(int y = 0; y < yCoordinates.size(); y++){
            if(myGraph[x][y].distance > 0){
                if(myGraph[x][y].distance < smallest){
                    //cout << "HELLO" << endl;
                    smallest = myGraph[x][y].distance;
                    x1 = myGraph[x][y].x1;
                    y1 = myGraph[x][y].y1;
                }
            } 
        }
        cout << smallest << " " << x1 << " " << y1 << endl;
    }*/
        
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


