#ifndef weightedGraphlib_h
#define weightedGraphlib_h
#endif

#define INFINITIVE_VALUE 10000000

#include "jrb.h"
#include "dllist.h"


//DFS, BFS, Dijkstra done
//Cay to mau done -> xem lai
//Cay bao trum


typedef struct ADT
{
    int id;
    double wei;
}*ADT;

typedef struct _detailVertex{
	char *name;
	int color;
	double wei;
	int parent;
	int stt;
	JRB detail;
	JRB indegreeTree;
	JRB linethong;
} *detailVertex;

typedef struct _Graph{
	JRB edges;
	JRB vertices;
} *Graph;


Graph createGraph();
void addVertex(Graph graph, int id, char* name);
char *getVertex(Graph graph, int id);
void addEdge(Graph graph, int v1, int v2, double weight);
double getEdgeValue(Graph graph, int v1, int v2);
void setEdgeValue(Graph graph, int v1, int v2, double new_wei);
int hasEdge(Graph graph, int v1, int v2);
int indegree(Graph graph, int v, int* output);
int outdegree(Graph graph, int v, int* output);
int find_id( Graph graph, char *name);
//int getComponents(Graph graph);
void dropGraph(Graph graph);

//BFS
int BFS( Graph graph, int start, int stop, int size, int *bfs, int *length);

// Lien Thong Manh
int DFSmanh( Graph graph, Graph h, Graph LT, int size);
JRB getLienthong( Graph graph, int v);
void addLienthong( Graph graph, int v1, int v2);
void printfLTManh( Graph LT, Graph g, int id);
Graph revGraph( Graph g, int size);
Graph copyGraph( Graph g, int size);
Graph copyGraph_noWei( Graph g, int size);

//Dijkstra
Dllist extractMin( Dllist priQ);
Dllist extractMax( Dllist priQ);
double Dijkstra(Graph graph, int s, int t, int *path, int *length, int size);
double Dijkstra_Max(Graph graph, int s, int t, int *path, int *length, int size);
double getWeiVertex(Graph graph, int id);
int getParentVertex(Graph graph, int id);
void setWeiVertex( Graph graph, int id, double wei);
void setParentVertex( Graph graph, int id, int parent);

//DFS
int DFS( Graph graph, int start, int stop, int size, int *dfs, int *length);
int DFS_num( Graph graph, int size);

//To Mau
void setColorVertex( Graph graph, int id, int color);
int getColorVertex(Graph graph, int id);
void coloring( Graph graph, int size);
void RGB( int i, char *s);
void printf_dot( Graph graph, int size, char name[]);

//MST
Graph MST( Graph graph, int size);


void addDetail( Graph g, int id, void *detail);
JRB getDetail( Graph g, int id);
int getSTT( Graph g, int id);