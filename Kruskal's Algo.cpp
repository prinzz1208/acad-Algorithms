#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
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
};

unordered_map<char, char> PARENT;
unordered_map<char, int> RANK;

char find(char vertex) {
	if (PARENT[vertex] == vertex)
		return PARENT[vertex];
	else
		return find(PARENT[vertex]);
}

void Union( char root1, char root2 ) {
	if(RANK[root1]>RANK[root2]){
		PARENT[root2]=root1;
	}
	else if (RANK[root2]> RANK[root1]) {
		PARENT[root1]=root2;
	}
	else{
		PARENT[root1]=root2;
		RANK[root2]++;
	}
}
void MST(Graph& g) {
	vector<Edge> res;

	for (auto c : g.vertice) {
		PARENT[c] = c;
		RANK[c] = 0;
	}

	sort(g.edges.begin(), g.edges.end(), [](Edge x, Edge y) {return x.weight < y.weight;});   // O(E*log(E))
	//for ( auto itr = g.edges.begin(); itr!=g.edges.end(); itr++)
	//{
			//cout<<(*itr).vertex1<<"\t";
			//cout<<(*itr).vertex2<<"\t";
			//cout<<(*itr).weight<<"\t";
			//cout<<"\n";
	//}

	 //for (auto i : PARENT)
        //cout << i.first << "   " << i.second
             //<< endl;

	for (Edge e : g.edges) {         // O(E)
		//cout<<"\nvertex1:"<<e.vertex1<<"\tvertex2:"<<e.vertex2;
		if(e.weight!=0){
			char root1 = find(e.vertex1);  // O(E) worst case
			char root2 = find(e.vertex2);
			cout<<"\nroot1:"<<root1<<"\troot2:"<<root2;
			if (root1 != root2) {
				res.push_back(e);
				Union(root1,root2);
		}
	}
	}
	 for (auto i : PARENT)
        cout << i.first << "   " << i.second
             << endl;
	 for (auto i : RANK)
        cout << i.first << "   " << i.second
             << endl;

	for (Edge e : res) {
		cout << e.vertex1 << " -- " << e.vertex2 << "  " << e.weight << endl;
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


	MST(g);

	return 0;
}
