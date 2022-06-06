#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include "MyDataStructures.h"

using namespace std;

struct HTreeNode
{
	char symbol;
	int freq;
	string code;
	HTreeNode *left;	
	HTreeNode *right;		
};

HTreeNode* HuffmanTree(HTreeNode *data, int n)
{
	MinHeap<HTreeNode*> Q; //Min-Priority Queue
	HeapData<HTreeNode*> t;  //Min-Priority Queue Data
	
	
	for(int i=0;i<n;i++)
	{
		t.Data = &data[i];
		t.Key = data[i].freq;
	
		Q.MinHeapInsert(t);
	}
	
	HTreeNode *tn;
	HeapData<HTreeNode*> x,y;
	 
	for(int i=0;i<n-1;i++)
	{
		Q.show();
		
		Q.HeapExtractMin(x);
		Q.HeapExtractMin(y);
	
		tn = new HTreeNode;
		tn->left = x.Data;
		tn->right = y.Data;		
		tn->freq = x.Key + y.Key;
		

		t.Data = tn;
		t.Key = tn->freq;
		Q.MinHeapInsert(t); 			
	}

	Q.show();
	
	Q.HeapExtractMin(x);

	return x.Data;
}

void AssignCode(HTreeNode *hTree,string code)
{
	if(hTree->left==NULL && hTree->right==NULL)
	{		
		hTree->code = code;
		code="";
	}		
	if(hTree->left!=NULL)
		AssignCode(hTree->left,code+"1"); 
	
	if(hTree->right!=NULL)
		AssignCode(hTree->right,code+"0");
}
void GenerateHuffmanCode(HTreeNode *data, int n)
{
		HTreeNode *hTree;
		
		hTree = HuffmanTree(data,n);
	
		string code="";
		AssignCode(hTree,code);
}


int main()
{

		HTreeNode *data;
		
		int n;
		
		n=8;
		
		data = new HTreeNode[n];
		
		for(int i=0;i<n;i++)
		{
			data[i].symbol = 65+i;
			data[i].freq = (rand()%(n+50))+1;
			data[i].code = "";
			data[i].left = NULL;
			data[i].right = NULL;
		} 
		
		cout<<"Input for the Huffman Code Generation:";
		cout<<"\n"<<"Symbol | "<<"Frequency | "<<"Huffman Code | ";
		cout<<"\n*************************************************************************";
	
		for(int i=0;i<n;i++)
		{
			cout<<"\n"<<setw(6)<<data[i].symbol<<" | "<<setw(9)<<data[i].freq<<" | "<<setw(12)<<data[i].code<<" | ";
		}
		cout<<"\n*************************************************************************";
	
		cout<<"\n\nSteps in Generating Huffman Code:";
		GenerateHuffmanCode(data,n);
		
		cout<<"\n\nGenerated Huffman Code:";
		cout<<"\n"<<"Symbol | "<<"Frequency | "<<"Huffman Code | ";
		cout<<"\n*************************************************************************";
	
		for(int i=0;i<n;i++)
		{
			cout<<"\n"<<setw(6)<<data[i].symbol<<" | "<<setw(9)<<data[i].freq<<" | "<<setw(12)<<data[i].code<<" | ";
		}
		cout<<"\n*************************************************************************";
}
