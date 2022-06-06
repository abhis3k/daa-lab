#include<iostream>
#include<iomanip>

//Refer only SList<T> - Needed to store the adjacency list for the vertices
//In SLizt<T>, Functions to be refered: ElementAt(), InsertEnd() and GetSize()
#include "MyDataStructures.h"

#define MAX 20

using namespace std;

struct Vertex
{
	SList<int> AdjList; //To store the indices of vertex
	int Value; //For easy understanding, the index will be stored as vertex value
	int Parent; //Index of the parent vertex in the resultant BFS tree
	int Distance; //Minimum cost from the curent vertex to the starting vertex
};

class Graph
{
	Vertex *V;
	int size;
	
	
	void Relax(int, int, int [][MAX]);
	
	public:
	
		//Initialize the size and the vertex' Indexs
		Graph(int);
		
		//Adding an edge between two vertices. index of 'from' and 'to' given as input
		//3rd arg - directed edge (true) or undirected edge (false)
		void AddEdge(int,int);
		
		//weight matrix and starting vertex index is input
		bool BellmanFord(int [][MAX],int);
		
	
		void ShowGraph();
};

void Graph::Relax(int u, int v, int w[][MAX])
{
	if(V[v].Distance>V[u].Distance+w[u][v])
	{
		V[v].Distance = V[u].Distance+w[u][v];
		V[v].Parent = u;
	}
	
}
Graph::Graph(int n)
{
	size = n;
	V = new Vertex[n];
	for(int i=0;i<n;i++)
	{
		V[i].Value = i;
		V[i].Parent = -1;
		V[i].Distance = 9999;
	}
	
}


void Graph::ShowGraph()
{
	int mincost=0;
	cout<<"\n"<<"Vertex | "<<"Parent | "<<"Distance | ";
	cout<<"\n********************************************";

	for(int i=0;i<size;i++)
	{
		cout<<"\n";
		if(V[i].Parent==-1)
			cout<<setw(6)<<V[i].Value<<" | "<<"Source"<<" | "<<setw(8)<<V[i].Distance<<" | ";
		else
			cout<<setw(6)<<V[i].Value<<" | "<<setw(6)<<V[i].Parent<<" | "<<setw(8)<<V[i].Distance<<" | ";
		
	}
	cout<<"\n********************************************";

}

bool Graph::BellmanFord(int w[][MAX],int s)
{
	//Initialize Single Source. By default, Distance is infinity for all vertices.
	V[s].Distance=0;

	int u,v,p,i;
	
	for(i=0;i<size-1;i++)
	{

		for(u=0;u<size;u++)
		{
			for(int p=1;p<=V[u].AdjList.GetSize();p++)
			{
				if(V[u].AdjList.ElementAt(p,v))
				{
					if(w[u][v]!=0)
					{
						Relax(u,v,w);
					}
					
				}
			}
		}	
	}
	
	for(u=0;u<size;u++)
	{
		for(p=1;p<=V[u].AdjList.GetSize();p++)
		{
			if(V[u].AdjList.ElementAt(p,v))
			{				
				if(V[v].Distance>V[u].Distance+w[u][v])
				{
					return false;
				}
			}
		}
	}
	
	return true;
}

//from and to are the indices of nodes
void Graph::AddEdge(int from, int to)
{

	V[from].AdjList.insertEnd(to);
	
}



int main()
{

	int n;
	
	//Test Input-1
	n=5;
	//Cost Matrix for the input graph
	int b[][MAX]={	    {0,6,0,0,7},
						{0,0,5,-4,8},
						{0,-2,0,0,0},
						{2,0,7,0,0},
						{0,0,-3,9,0} };
	

	Graph g(n);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(b[i][j]!=0)
			{
				g.AddEdge(i,j);
			}
		}
	}
	
	int s=0;
	bool res;
	
	res = g.BellmanFord(b,s);
	
	if(res)
	{
		cout<<"\n\nSingle Source Shortest Path (Bellman-Ford Algorithm) Result:\n";
		g.ShowGraph();
	}
	else
	{
		cout<<"\nNegative Weight Cycle is Present. \nSo, Could Not find Shortest Path....";
	}
}
