#include<iostream>

using namespace std;

template<typename T>
struct Node
{
	T data;
	Node *next;	
};

template<typename T>
struct TreeNode
{
	T data;
	TreeNode *left;	
	TreeNode *right;		
};

template<typename T>
struct HeapData
{
	int Key;
	T Data;
};

template<typename T>
class MinHeap
{
	HeapData<T> A[100];
	int HeapSize;
	
	public:
		MinHeap()	
		{
			HeapSize = 0;
		}
		void MinHeapInsert(HeapData<T>);
		void HeapDecreaseKey(int, int);
		bool HeapExtractMin(HeapData<T> &);
		void MinHeapify(int);
		bool isHeapEmpty();	
		void show()
		{
			cout<<"\n";
			for(int i=1;i<=HeapSize;i++)
				cout<<"\t"<<A[i].Key;
		}
};

template<typename T>
bool MinHeap<T>::isHeapEmpty()
{
	return (HeapSize==0)?true:false;
}

template<typename T>
void MinHeap<T>::MinHeapInsert(HeapData<T> x)
{
	HeapSize++;
	A[HeapSize].Key = 9999;
	A[HeapSize].Data = x.Data;
	HeapDecreaseKey(HeapSize,x.Key);
}

template<typename T>
void MinHeap<T>::HeapDecreaseKey(int i, int newkey)
{
	if(i>HeapSize)
	{
		return;
	}
	
	if(A[i].Key<=newkey)
	{
		return;
	}
	
	int p;
	HeapData<T> t;
	
	A[i].Key = newkey;
	p = i/2;
	while(i!=1 && A[p].Key>newkey)
	{
		t = A[p];	
		A[p] = A[i];
		A[i] = t;
		
		i = p;
		p = i/2;
	}	
}

template<typename T>
bool MinHeap<T>::HeapExtractMin(HeapData<T> &x)
{
	if(HeapSize<1)
		return false;
		
	x = A[1];
	A[1] = A[HeapSize];
	HeapSize--;
	MinHeapify(1);
	return true;
}

template<typename T>
void MinHeap<T>::MinHeapify(int i)
{
	int l,r;
	l = 2*i;
	r = 2*i+1;
	
	int min;
	
	if(l<=HeapSize && A[l].Key<A[i].Key)
		min = l;
	else
		min = i;
	
	if(r<=HeapSize && A[r].Key<A[min].Key)
		min = r;
	
	if(min!=i)
	{
		HeapData<T> t = A[min];
		A[min] = A[i];
		A[i] = t;
		
		MinHeapify(min);
	}
}
template<typename T>
class Stack
{
	private:
		Node<T> *a;
		int size;
	
	public:
		Stack();
		bool Push(T);
		bool Pop(T&);
		bool Peek(T&);
		bool isStackEmpty();
};


template<typename T>
Stack<T>::Stack()
{
	a = NULL;
	size = 0;
}

template<typename T>
bool Stack<T>::isStackEmpty()
{
	return (a==NULL)?true:false;
}

//Insert at front - Push
template<typename T>
bool Stack<T>::Push(T x)
{
	//New Node Creation
	Node<T> *n;
 	n = new Node<T>;
	
	if(n==NULL)
	{
		return false;
	}
	
	//Initialization
	n->data = x;
	n->next = NULL;
		
	//Link the New Node in the proper position	
	n->next = a;
	a = n;
	
	//Increase the size of the list
	size++;
	
	return true;

}

//Delete front is pop
template<typename T>
bool Stack<T>::Pop(T &x)
{
	//Initialize output parameter
	x = -1;
	
	//If list is empty, return failure
	if(a==NULL)
	{
		return false;
	}
	
	//Retrieve the data to be deleted
	x = a->data;
	
	//Back up the current first node address for releasing memory
	Node<T> *t=a;
	
	//Update the new first node as the 2nd node, if it has
	a = a->next;
		
	//Release the memory of deleted node
	delete(t);
	
	//Decrease the size of the list
	size--;
	
	return true;

}

//Delete front is pop
template<typename T>
bool Stack<T>::Peek(T &x)
{
	//Initialize output parameter
	x = -1;
	
	//If list is empty, return failure
	if(a==NULL)
	{
		return false;
	}
	
	//Retrieve the data to be deleted
	x = a->data;
	
	return true;

}

template<typename T>
class Queue
{
	private:
		Node<T> *a;
		int size;
	
	public:
		Queue();
		bool EnQ(T);
		bool DeQ(T&);
		bool GetFront(T&);
		bool isQueueEmpty();
};

template<typename T>
Queue<T>::Queue()
{
	a = NULL;
	size = 0;
}

template<typename T>
bool Queue<T>::isQueueEmpty()
{
	return (a==NULL)?true:false;
}

//Insert at end as EnQ
template<typename T>
bool Queue<T>::EnQ(T x)
{
	Node<T> *n;
 	n = new Node<T>;
	
	if(n==NULL)
	{
		return false;
	}
	
	n->data = x;
	n->next = NULL;
	
	if(a==NULL)
	{
		a = n;
		size++;
		return true;
	}
	
	Node<T> *t;
	t = a;
	while(t!=NULL)
	{
		if(t->next==NULL)
		{
			t->next = n;
			size++;
			return true;
		}
		t = t->next;
	}
	return false;
}

template<typename T>
bool Queue<T>::DeQ(T &x)
{
	//Initialize output parameter
	x = -1;
	
	//If list is empty, return failure
	if(a==NULL)
	{
		return false;
	}
	
	//Retrieve the data to be deleted
	x = a->data;
	
	//Back up the current first node address for releasing memory
	Node<T> *t=a;
	
	//Update the new first node as the 2nd node, if it has
	a = a->next;
		
	//Release the memory of deleted node
	delete(t);
	
	//Decrease the size of the list
	size--;
	
	return true;

}

template<typename T>
bool Queue<T>::GetFront(T &x)
{
	//Initialize output parameter
	x = -1;
	
	//If list is empty, return failure
	if(a==NULL)
	{
		return false;
	}
	
	//Retrieve the data to be deleted
	x = a->data;
	
	
	return true;

}


template<typename T>
class SList
{
	private:
		Node<T> *a;
		int size;
	
	public:
		SList();
		bool insertEnd(T);
		bool insertFront(T);
		bool insertAt(T,int);
		bool deleteFront(T&);
		bool deleteEnd(T&);
		bool deleteData(T);
		bool ElementAt(int,T&);
		void ReverseList();
		bool PrintLots(SList<int>);
		int GetSize()	{	return size;		} 
		void display();
		void Sort();
};

template<typename T>
void SList<T>::ReverseList()
{
	if(a==NULL || a->next==NULL)
		return;
		
	Node<T> *t, *p, *r, *s;
	
	p=a;
	t=a->next;
	
	while(t!=NULL)
	{
		r = a;
		s = t->next;
		
		a = t;
		t->next = r;
		p->next = s;
		
		t = s;
	}
	
	
}

template<typename T>
void SList<T>::Sort()
{
	Node<T> *i,*j;
	double t;
	
	i = a;
	for(i=a;i!=NULL;i=i->next)
	{
		for(j = i->next;j!=NULL;j=j->next)
		{
			if(j->data<i->data)
			{
				t = i->data;
				i->data = j->data;
				j->data = t;
			}
		}
	}
	
}

template<typename T>
bool SList<T>::PrintLots(SList<int> p)
{
	Node<int> *t;
	T x;
	for(t=p.a;t!=NULL;t=t->next)
	{
		if(ElementAt(t->data,x))
		{
			cout<<"\t"<<x;
		}
	}
}
template<typename T>
bool SList<T>::ElementAt(int p, T &x)
{
	
	Node<T> *t = a;
	int c=1;
	while(t!=NULL)
	{
		if(c==p)
		{
			x = t->data;
			return true;
		}
		
		t = t->next;
		c++;
	}
	
	return false;
}

template<typename T>
SList<T>::SList()
{
	a = NULL;
	size = 0;
}

template<typename T>
bool SList<T>::insertEnd(T x)
{
	Node<T> *n;
 	n = new Node<T>;
	
	if(n==NULL)
	{
		return false;
	}
	
	n->data = x;
	n->next = NULL;
	
	if(a==NULL)
	{
		a = n;
		size++;
		return true;
	}
	
	Node<T> *t;
	t = a;
	while(t!=NULL)
	{
		if(t->next==NULL)
		{
			t->next = n;
			size++;
			return true;
		}
		t = t->next;
	}
	return false;
}

template<typename T>
bool SList<T>::insertFront(T x)
{
	//New Node Creation
	Node<T> *n;
 	n = new Node<T>;
	
	if(n==NULL)
	{
		return false;
	}
	
	//Initialization
	n->data = x;
	n->next = NULL;
		
	//Link the New Node in the proper position	
	n->next = a;
	a = n;
	
	//Increase the size of the list
	size++;
	
	return true;

}

template<typename T>
bool SList<T>::insertAt(T x,int p)
{
	//New Node Creation
	Node<T> *n;
 	n = new Node<T>;
	
	if(n==NULL)
	{
		return false;
	}
	
	//Initialization
	n->data = x;
	n->next = NULL;
		
	//Link the New Node in the proper position	
	n->next = a;
	a = n;
	
	//Increase the size of the list
	size++;
	
	return true;

}

template<typename T>
bool SList<T>::deleteFront(T &x)
{
	//Initialize output parameter
	x = -1;
	
	//If list is empty, return failure
	if(a==NULL)
	{
		return false;
	}
	
	//Retrieve the data to be deleted
	x = a->data;
	
	//Back up the current first node address for releasing memory
	Node<T> *t=a;
	
	//Update the new first node as the 2nd node, if it has
	a = a->next;
		
	//Release the memory of deleted node
	delete(t);
	
	//Decrease the size of the list
	size--;
	
	return true;

}

template<typename T>
bool SList<T>::deleteEnd(T &x)
{
	//Initialize output parameter
	x = -1;
	
	//If list is empty, return failure
	if(a==NULL)
	{
		return false;
	}
	
	//Searching the last node
	Node<T> *p=NULL;
	Node<T> *t=a;
	while(t->next!=NULL)
	{
		p = t;
		t = t->next;
	}
	
	//Retrieve the data to be deleted
	x = t->data;
	
	//If t is the first node
	if(p==NULL)
		a = t->next;
	else //if t is not a first node
		p->next = t->next;
		
	//Release the memory of deleted node
	delete(t);
	
	//Decrease the size of the list
	size--;
	
	return true;

}

template<typename T>
bool SList<T>::deleteData(T x)
{
	
	//If list is empty, return failure
	if(a==NULL)
	{
		return false;
	}
	
	//If x is found at first node
	if(a->data==x)
		return deleteFront(x);
	
	//Searching the last node
	Node<T> *p=NULL;
	Node<T> *t=a;
	while(t!=NULL)
	{
		if(t->data==x)
		{
			p->next = t->next;
			delete(t);
			size--;
			return true;
		}
		
		p = t;
		t = t->next;
	}
		
	return false;

}

template<typename T>
void SList<T>::display()
{
	cout<<"\nList is: ";
	if(a==NULL)
	{	
		cout<<"Empty\n\n";
		return;
	}
	Node<T> *t;
	t = a;
	
	while(t!=NULL)
	{
		cout<<t->data<<"->";
		t = t->next;
	}
	cout<<"NULL\n\n";
}

