#include<iostream>
#include<stdlib.h>
#include<cstdio>
using namespace std;
#define MAXN 102

	int P[MAXN], Rank[MAXN];
	int Node, edg, Cost;
struct edge {
	int u, v;
	int cost;
};
	edge Edge[MAXN*MAXN];
	edge Path[MAXN];
int com(const void *xy, const void *xz)
{
	edge *x = (edge*)xy;
	edge *y = (edge*)xz;
	return (x->cost - y->cost);
}

void In()
{ // initializing parent and rank for each node
  	  int i;
	  for(i = 1; i<= Node; i++)
	  {
	  P[i] = i;
	  Rank[i] = 1;
	  }
}

int Find(int n) { // find the parent of a node
	if(P[n] != n)
	P[n] = Find(P[n]);
	return P[n];
}

void Link(int x, int y) { // joining the nodes
	if(Rank[x] > Rank[y]) {
	P[y] = x;
	}
	else
        {
	P[x] = y;
	if(Rank[x] == Rank[y])
	Rank[y]++;
	}
}

void Kruscal()
{
	    int x, y, total = 0;
            Cost = 0;
	    for(int i = 0; i<edg; i++)
	     {
	      x = Find(Edge[i].u);
	      y = Find(Edge[i].v);
  	      if(x != y)
          { // if not cycle
	         Path[total++] = Edge[i];
	         Link(x,y); // join those node
	         Cost += Edge[i].cost;
	         if(total == Node - 1) break; // already taken all nodes ?
	      }
	     }
}

void Cal()
{
	  qsort(Edge,edg,sizeof(edge),com); // sorting the edges respect to cost
	  Kruscal();
	  cout<<"Total Cast :"<<Cost<<endl;
 	  for(int i = 0; i<Node-1; i++) // printing the path
	  cout<<Path[i].u<<" "<<Path[i].v<<" "<<Path[i].cost<<endl;
}

int main()
{
	int i;
	while(cin>>Node>>edg) { // reading number of node and edge
	In();
	for(i = 0; i<edg; i++)  // reading each edge with cost
	cin>>Edge[i].u>>Edge[i].v>>Edge[i].cost;
	Cal();
	}
	return 0;
}
