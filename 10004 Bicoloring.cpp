#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
#include <climits>
using namespace std;
// Function of vector to push the element x at the end of the vector.
#define pb(x) push_back(x)
#define MAXNODE 210
#define INF INT_MAX
#define ff first
#define ss second
#define sz size()
typedef pair< int, int > pii;
// as we are doing this by BFS traversal we are using queue Data Structure. 
typedef queue <int> qi;
// to store adjacent vertices 
vector< int > g[MAXNODE];
int d[MAXNODE];
int bfs(int n, int src){
    // color array to check which color node is off.
    bool color[210];
   // to check if the node is colored or not.
    bool taken[210];
    for(int i=0;i<n;i++)
	    color[i] = false,taken[i]=false;
    int i,u,v;
    qi q;
    q.push(src);
    d[src]=0;
    while(!q.empty()){
        u = q.front();q.pop();
        for(i=0;i<g[u].sz;i++)
            {
                v = g[u][i];
               // assigning different color to adjacent nodes if it is privously not colored. 
                if(taken[v]==false) {
                    color[v] = !color[u];
                    taken[v] = true;
                    q.push(v);
                }
		// if two adjacent nodes are of same color than  
                else if(color[u]==color[v]){printf("NOT ");return 0;}
            }
    }
return 0;
}
int main () {
   // freopen("input.txt","r",stdin);
	int n, e, i, u, v;
	//input number of test cases
        while(scanf("%d",&n)&&n!=0){
	    // Number of edges to the nth graph
            scanf("%d",&e);
		for(i = 0; i < n; i++)
			g[i].clear(); // forget previous info
		for(i = 0; i < e; i++) {
			scanf("%d %d",&u,&v);
			g[u].pb(v);
                        g[v].pb(u);//if graph is undirected
		    }
        bfs(n,0);
        printf("BICOLORABLE.\n");

        }
	return 0;
	
}
