#include<iostream>
#include<iomanip>

//We need to use SList<T> for maintaining the adjacency list and the topological order of vertices.
//So only refer the SList<T> data structure from MyDataStructures.h
//In SList<T>, Functions to be refered: InsertFront(), ElementAt() and GetSize()
#include "MyDataStructures.h"

using namespace std;

//W - Not Visited, G - Visited, but adjacent vertices needs to be visited, B - Completely visited, including the adjacent nodes
enum MyColor {W,G,B};

struct Vertex
{
	SList<int> AdjList; //To store the indices of vertex
	int Value; //For easy understanding, the index will be stored as vertex value
	MyColor Color; //Flag used to represent a vertex is visited or not
	int Parent; //Index of the parent vertex in the resultant BFS tree
	int st; //To record the starting visiting time
	int end; //To record the finishing visiting time
};

class Graph
{
	Vertex *V;
	int size;
	
	public:
	
		//Initialize the size and the vertex' values
		Graph(int,int[]);
		
		//Adding an edge between two vertices. index of 'from' and 'to' are given as input
		void AddEdge(int,int);
		
		//To perform the DFS on input graph and to obtain the topological order. 
		void DFS(SList<Vertex> &);
		void DFS_Visit(int,int&,SList<Vertex> &);
		
		//To display the final graph
		void ShowGraph();
		
		//To return the topological order
		SList<Vertex> TopologicalOrder();
};

SList<Vertex> Graph::TopologicalOrder()
{
	SList<Vertex> TopOrder;
	
	//Optain Topological order by Performing DFS on Graph
	DFS(TopOrder);
	
	//We may view the graph content after DFS
	cout<<"\n\nGraph After DFS:";
	ShowGraph();

	return TopOrder;
		
}

Graph::Graph(int n,int a[])
{
	size = n;
	V = new Vertex[n];
	for(int i=0;i<n;i++)
	{
		V[i].Value = a[i];
		V[i].Color = W;
		V[i].Parent = -1;
		V[i].st = V[i].end = 0;
	}
	
}

void Graph::ShowGraph()
{
	cout<<"\n***************************************************";
	cout<<"\nParent | Vertex Value | Color | Start | Finish";
	cout<<"\n***************************************************";
	for(int i=0;i<size;i++)
	{
		cout<<"\n";
		if(V[i].Parent==-1)
			cout<<setw(6)<<"NULL";
		else		
			cout<<setw(6)<<V[i].Parent;
			
		cout<<" | ";
		cout<<setw(12)<<V[i].Value;
		
		cout<<" | ";
		cout<<setw(5)<<V[i].Color;
		
		cout<<" | ";
		cout<<setw(5)<<V[i].st;
		
		cout<<" | ";
		cout<<setw(6)<<V[i].end;
		
	}
	cout<<"\n***************************************************";

}
void Graph::DFS(SList<Vertex> &TopOrder)
{
	
	int time=0;
	for(int i=0;i<size;i++)
	{
		if(V[i].Color==W)
		{
			V[i].Parent = -1;
			DFS_Visit(i,time,TopOrder);
		}
	}
}

//Input is the starting vertex's index
void Graph::DFS_Visit(int i, int &time,SList<Vertex> &TopOrder)
{
	
	int u;
	
	//Visit the starting vertex
	V[i].Color = G;
	V[i].st = ++time;

	for(int p=1;p<=V[i].AdjList.GetSize();p++)
	{
		if(V[i].AdjList.ElementAt(p,u))
		{
			if(V[u].Color==W)
			{
				V[u].Parent = i;
				//cout<<"\n\t"<<V[u].Parent<<"-->"<<V[u].Value;
				DFS_Visit(u,time,TopOrder);
				
			}
		}
	}
	
	V[i].end = ++time;
	V[i].Color = B;
	TopOrder.insertFront(V[i]);
	
	
}


//from and to are the indices of nodes
void Graph::AddEdge(int from, int to)
{

	V[from].AdjList.insertEnd(to);
		
}



int main()
{
	
	//In this example, we considered a graph with 8 vertices. (0,1,...7) 
	//If you want to test for other graphs, need to give appropriate details.
	//The index are considered as the VALUE of the vertices.	

	//Test Input-1 (Size-5)
	int a[] = {0,1,2,3,4};
		
	Graph g(5,a);
	
	int b[][5]	= {			{0,1,1,1,0},
							{0,0,1,1,0},
							{0,0,0,0,1},
							{0,0,0,0,1},
							{0,0,0,0,0}	};
	
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(b[i][j]!=0)
			{
				g.AddEdge(i,j);
			}
		}
	}
	SList<Vertex> TopOrder;
	
	TopOrder = g.TopologicalOrder();
	
	int topsize = TopOrder.GetSize();
	Vertex v;
	
	cout<<"\n\nTopological Order of Vertices: ";
	for(int i=1;i<=topsize;i++)
	{
		if(TopOrder.ElementAt(i,v))
		{
			cout<<setw(5)<<v.Value;
		}
	}
	
	cout<<"\n\n";
}
