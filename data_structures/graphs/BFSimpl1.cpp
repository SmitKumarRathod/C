#include<iostream>
#include<stdlib.h>
using namespace std;
#define SIZE 20
struct Node {
	int vertex;
	struct Node* next;
};
struct Graph {
	int numVertices;
	struct Node** adjlists;
	int* visited;
};
struct Queue {
	int items[20];
	int front;
	int rear;
};
typedef struct Node N;
typedef struct Graph G;
typedef struct Queue Q;

N* createNode(int v) {
	N* newNode = (N*)malloc(sizeof(N));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

G* createGraph(int numVertices) {
	G* graph = (G*)malloc(sizeof(G));
	graph->numVertices = numVertices;
	graph->adjlists = (N**)malloc(numVertices*sizeof(N*));
	graph->visited = (int *)malloc(numVertices*sizeof(int));

	for(int i=0; i < numVertices; i++) {
		graph->adjlists[i] = NULL;
		graph->visited[i] = 0;
	}
	return graph;
}

void addEdge(G* graph, int src, int dest) {
	//Add edge from source to destination
	N* newNode = createNode(dest);
	newNode->next = graph->adjlists[src];
	graph->adjlists[src] = newNode;

	//add edge from destination to source
	newNode = createNode(src);
	newNode->next=graph->adjlists[dest];
	graph->adjlists[dest] = newNode;
}

int dequeue(Q* q);
Q* createQueue();
void enqueue(Q* q, int val);
void printQueue(Q* queue);

void bfs(G* graph, int startVertex) {
	Q* queue = createQueue();

	graph->visited[startVertex] = 1;
	enqueue(queue, startVertex);

	while(!queue) {
		printQueue(queue);
		int currVertex = dequeue(queue);
		std::cout<<"\n VISITED:- "<<currVertex;

		N* temp = graph->adjlists[currVertex];
		while(temp) {
			int adjVertex = temp->vertex;

			if(graph->visited[adjVertex] == 0) {
				graph->visited[adjVertex] = 1;
				enqueue(queue, adjVertex);
			}
			temp = temp->next;
		}
	}
}

Q* createQueue() {
	Q* queue =(Q*)malloc(sizeof(Q));
	queue->front = -1;
	queue->rear = -1;
	return queue;
}

void enqueue(Q* q, int val) {
		if(q->rear == SIZE - 1 )
			std::cout<<"\n QUEUE IS FULL";
		else {
			if(q->front == -1)
				q->front = 0;
			q->rear++;
			q->items[q->rear] = val;
		}
}

void printQueue(Q* queue) {
	if(!queue){
		std::cout<<"\n QUEUE IS EMPTY";
	}
	else {
		for(int i=queue->front; i < queue->rear; i++)
			cout<<"\t "<< queue->items[i];
	}
}

int dequeue(Q* queue) {
	int val;
	if(!queue) {
		cout<<"\n QUEUE IS EMPTY";
		val = -1;
	}
	else {
		val = queue->items[queue->front];
		queue->front++;
		if(queue->front > queue->rear)
			queue->front = queue->rear = -1;
	}
	return val;
}

int main() {
	G* graph = createGraph(6);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
	bfs(graph, 0);
	return 0;
}
