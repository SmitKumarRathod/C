#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define V 5
//Define graph
int G[V][V] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}
};

int main() {
	int noEdge; //no of edges
	int selected[V] = {0}; //declare an array as selected which checks at ith vertex is visited or not, 0 visited else 1
	noEdge =0; // no of edges in the staring is 0
	selected[0]=1;	// select 0 as source and mark it as visited
	int x, y;// x for row and y for column
	cout<<"Edge : Weight"<<endl;
	while(noEdge < V-1) { //No of edges in any MST is always less than V-1
		int min = INT_MAX; //Greedy approch 
		x=y=0;
		for(int i=0; i<V; i++) { //outer loop
			if(selected[i]) { // source is there hence it will go in inner loop 
				for(int j = 0; j<V; j++ ){ // inner loop
					if(!selected[j] && G[i][j]) { //if selected vertex is not already visited and is connected with the current selected vertex then only check condition
						if(min > G[i][j]){ // greedu=y method, if weight is less than minimum  
							min = G[i][j]; // mnimun will be the weight
							x=i; // for printing give value of ith row in x row
							y=j; // jth row in y row
						}
					}
				}
			}
		}
		cout<< x <<" - " << y << " : "<<G[x][y]<<endl; // print edge	
		selected[y]=1; //mark that node as selected 
		noEdge++; // no of edges is incremented
	}
	return 0;
}