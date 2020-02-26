#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;
struct Edge {
	char vertex1;
	char vertex2;
	int weight;
	Edge(char v1, char v2, int w):vertex1(v1), vertex2(v2), weight(w) {}
};

struct Graph {
	vector<char> vertice;
	vector<Edge> edges;
	vector< pair<char, Edge> > adjacent(char u) {
		vector< pair<char, Edge> > res;
		for (Edge e : edges) {
			if (e.vertex1 == u) {
				res.push_back( make_pair(e.vertex2, e));
			} else if (e.vertex2 == u) {
				res.push_back( make_pair(e.vertex1, e));
			}
		}
		return res;
	}
};

void prim(Graph& g, char root) {
	unordered_map<char, char> res;
	unordered_map<char, char> PARENT;
	unordered_map<char, int> KEY;

	for (auto c : g.vertice) {
		PARENT[c] = '\0';
		KEY[c] = INT_MAX;
	}
	KEY[root] = 0;
	vector<char> Q = g.vertice;

	while (!Q.empty()) {    // O(V)
		char u = *(min_element(Q.begin(), Q.end(), [&](char x, char y) {return KEY[x] < KEY[y];}));  // O(v) returns an iterator to the element

    vector<char>::iterator itr = remove(Q.begin(), Q.end(), u);  // O(V) retruns an iterator to the element which was following the removed eleAment

    Q.erase(itr, Q.end());  // erase() following remove()

		if (PARENT[u] != '\0') {

			res[u] = PARENT[u];   // This is one edge of MST
			//cout<<"\nres[u]:"<<res[u]<<"\tPARENT[u]:"<<PARENT[u];
		}
		vector< pair<char, Edge> > adj = g.adjacent(u);   // O(E)
		for (pair<char, Edge> v : adj) {
			if (find(Q.begin(), Q.end(), v.first) != Q.end()) {   // O(V)
				//cout<<"\nv:"<<v.first;
				if (v.second.weight < KEY[v.first]) {
					PARENT[v.first] = u;
					KEY[v.first] = v.second.weight;
				}
			}
		}
	}

	for (auto e : res) {
		cout << e.first << " -- " << e.second << endl;
	}
}

int main() {

  int nodes;

	cout<<"Enter no. of nodes: ";
	cin>>nodes;
  int matrix[nodes][nodes];
  int ascii=97;
	char t[nodes];
  int k=0;
  for ( char i =ascii; i <ascii+nodes; i++) {
      t[k++]=i;
  }
	Graph g;
	g.vertice = vector<char>(t, t + sizeof(t)/sizeof(t[0]));

  for(int i=0;i<nodes;i++)
  {
    for(int j=0;j<nodes;j++)
      matrix[i][j]=-1;
  }

  cout<<"Enter the connections into the Adjacency Matrix: ";
  for(int i=0; i<nodes; i++)
  {
    for(int j=i; j<nodes; j++)
    {
      cout<<endl<<t[i]<<","<<t[j]<<": ";
      if(i==j)
        matrix[i][j]=0;

      else if(matrix[i][j]==-1)
      {
        cin>>matrix[i][j];
        if(matrix[i][j]!=0)
			g.edges.push_back(Edge(t[i],t[j], matrix[i][j]));
        matrix[j][i]=matrix[i][j]; 		//Setting the equal value to the transpose of the value inputted
      }
    }
  }

	for ( auto itr = g.edges.begin(); itr!=g.edges.end(); itr++)
	{
			cout<<(*itr).vertex1<<"\t";
			cout<<(*itr).vertex2<<"\t";
			cout<<(*itr).weight<<"\t";
			cout<<"\n";
	}


  prim(g,'a');

	return 0;
}
