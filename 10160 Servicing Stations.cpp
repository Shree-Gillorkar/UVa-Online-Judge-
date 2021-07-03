#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
typedef bitset<35> bset;
int N;
bset allIncluded;
bset connections[35];
bset connectedAfter[35];
void dfs(int node, bset &included)
{
included[node] = true;
for (int i = 0; i < N; ++i)
if (connections[node][i] && !included[i])
dfs(i, included);
}
void FindLowestCost(bset connected, int currentNode, int currentCount, int &
bestCount)
{
if (connected == allIncluded)
{
bestCount = min(bestCount, currentCount);
return;
}
if (currentCount >= bestCount - 1)
return;
if (currentNode == N)
{
return;
}
bset whenAdded = connected | connections[currentNode];
if (connected != whenAdded)
{
FindLowestCost(whenAdded, currentNode + 1, currentCount + 1, bestCount);
}
if ((connected | connectedAfter[currentNode]) == allIncluded)
{
FindLowestCost(connected, currentNode + 1, currentCount, bestCount);
}
}
int main()
{
int M;
while (cin >> N >> M, N)
{
for (int i = 0; i < N; ++i)
{
connections[i].reset();
connections[i].set(i);
}
allIncluded.reset();
for (int i = 0; i < N; ++i)
allIncluded.set(i);
while (M--)
{
int i, j;
cin >> i >> j;
--i; --j;
connections[i].set(j);
connections[j].set(i);
}
connectedAfter[N - 1].reset();
for (int i = N - 2; i >= 0; --i)
connectedAfter[i] = connectedAfter[i + 1] | connections[i + 1];
bset overallIncluded;
int bestOverall = 0;
for (int i = 0; i < N; ++i)
{
if (!overallIncluded[i])
{
bset component;
dfs(i, component);
bset outsideComponent = allIncluded ^ component;
int componentBest = N;
FindLowestCost(outsideComponent, 0, 0, componentBest);
overallIncluded |= component;
bestOverall += componentBest;
}
}
cout << bestOverall << '\n';
}
}
