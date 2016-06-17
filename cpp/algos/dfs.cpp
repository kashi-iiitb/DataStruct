#include <iostream>
#include <queue>
#include <list>
#include <stack>

using namespace std;

class Graph
{
  int numOfVertices;
  list<int> *adj;
  public:
	Graph(int vertices);
	void addEdge(int u, int v);
	void bfsTrav(int s);
	void dfsTrav(int s);
};

Graph::Graph(int vertices)
{
  numOfVertices = vertices;
  adj = new list<int>[numOfVertices];
}

void Graph::addEdge(int u, int v)
{
  adj[u].push_back(v);
}

void Graph::dfsTrav(int s)
{
	stack<int> stk;
	stk.push(s);
	//list<int> *temp=s;
	int trv;
	bool *visited = new bool[numOfVertices];
	for(int i=0; i<numOfVertices; i++)
		visited[i] = false;
	visited[s] = true;
	
	while(!stk.empty())
	{
		trv = stk.top();
		cout << trv;
		stk.pop();
		for(list<int>::const_iterator i = adj[trv].begin(); i!= adj[trv].end(); i++)
			if(visited[*i] != true)
			{
				visited[*i]= true;
				stk.push(*i);
			}
	}
}

void Graph::bfsTrav(int s)
{
  bool *visited = new bool[numOfVertices];
  for(int i=0; i<numOfVertices; i++)
  {
	visited[i] = false;
  }
  queue<int> q;
  q.push(s);
  int trv=s;
  visited[trv] = true;
  while(!q.empty())
  {
	trv = q.front();
	cout << trv << endl;
	q.pop();
	for(list<int>::iterator j=adj[trv].begin(); j!= adj[trv].end(); j++)
	{
		if(visited[*j]!=true)
		{
			visited[*j]=true;
			q.push(*j);
		}
	}
  }

}

int main()
{
  Graph g(6);
  g.addEdge(1,0);
  g.addEdge(0,2);
  g.addEdge(1,3);
  g.addEdge(2,1);
  g.addEdge(3,4);
  g.addEdge(2,4);
  g.addEdge(3,5);
  g.addEdge(4,5);
  g.bfsTrav(0);
  g.dfsTrav(0);}
