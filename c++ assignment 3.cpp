#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;


int main(){
	
}
class Vertex(){
	public:
		int index;
		double distance;
		int prevIndex; //index of previous vertex in the shortest path from source. 
		explicit Vertex(int index):index(index), distance(INT32_MAX), prevIndex(-1){}
		
	
}

struct GreaterByDist{
	bool operator(Vertex const & v1, Vertex const & v2){
		return v1.distance>v2.distance;
	}
}
class Graph{
	private:
		vector<vector<Double>> matrix;
		int numVertices;
		vector<Vertex> vertices;
	public:
		Graph(int numVertices, double edgeDensity, double minDist, double maxDist){
			this->numVertices=numVertices;
			for(int i = ; i < numVertices; i++){
				vertices.push_back(new Vertex(i));
			}

			srand(time(0));
			matrix = vector<vector<Double>>(numVertices, vector<Double>(numVertices));
			for(int row = 0; row<numVertices; row++){
				for(int col = 0; col<row; col++){ //we only need to fill in half of the matrix. The other half is symmetric
					
					if(double(rand())/RAND_MAX<edgeDensity){
						int weight = double(rand())/RAND_MAX*(maxDist-minDist)+minDist;
						matrix[row][col] = weight;
						matrix[col][row] = weight;
					}
				}
			}

		}
}
void Graph::computeShortestPath(int destIndex){
	priority_queue<Vertex,vector<Vertex>,GreaterByDist> pq;
	vertices[0].setDistance(0);
	for(Vertex v:vertices){
		pq.push(v);
	}
	while(!pq.empty()){
		Vertex current = pq.pop();

		for(int i = 0; i <numVertices; i++){
			double altLength = vertices[i].distance+matrix[i,current,index];
			if(altLength < current.distance){
				current.distance = altLength;
				current.prevIndex = i;
			}
			
		}
	}
}
