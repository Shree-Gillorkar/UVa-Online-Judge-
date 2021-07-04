/* Algorithm:

●There are n people who are friends or hostile to each other.
●There are 4 operations:
1set a, b set a for a friend,
2set a for a friend, b for a hostile 3 ask if a, b is a friend
4 ask if a, b is hostile.
For query operation, output 1 if it is, otherwise output 0.
For the setting operation, if it contradicts the known relationship, -1 is output, and the operation is invalid; the valid setting is not output.

●There are inter-relationships and collections. If the relationship between two people is known, whether they are friends or hostility, put them in a set.

●Use an array to represent the relationship between the element and the parent element. Both search and merge involve changes in relational arrays. When writing, you must be clear-headed and understand how it works.

●Then in the Find() process, that is, the process of finding the root node, the relationship between the current node and the parent node is judged through path compression.

●The formula is offset[x]=(offset[x]+offset[father[x]])%2
The offset between the x node and the new parent node is equal to the offset between the previous x and the parent node plus the parent The sum of the offset between the node and the grandfather node, the purpose of modulo 2 is because there are only two states, that is, friend and enemy. If you do not use modulo operation, you have to use if to judge, which is more troublesome.*/


#include <stdio.h>
 #include <set>
 #include <vector>


 using namespace std;

 #define REP(i,a,b) \
 	for(int i = int(a); i <= int(b); i++)

vector<int> pSet(1000);
void initSet(int _size) { pSet.resize(_size); REP(i,0,_size-1) pSet[i] = i; }
int findSet(int i) { return pSet[i] == i ? i : (pSet[i] = findSet(pSet[i]));}
void unionSets(int i , int j) { pSet[findSet(i)] = findSet(j); }
bool isSameSet(int i , int j) { return findSet(i) == findSet(j); }

vector<int> enemies(10000);

bool setEnemies(int i, int j);

bool areFriends(int i, int j){
	if(i==j) return true;
	return isSameSet(i,j);
}

bool areEnemies(int i, int j){
	return enemies[findSet(i)] == findSet(j) || enemies[findSet(j)] == findSet(i);
}

bool setFriends(int i, int j){
	if(areFriends(i,j)) return true;
	if(areEnemies(i,j)) return false;

	int rooti = findSet(i);
	int rootj = findSet(j);

	unionSets(i,j);

	int ni = findSet(i);
	int nj = findSet(j);

	if(rooti != ni && enemies[rooti] != -1){
		if(enemies[ni] != -1){
			setFriends(enemies[ni], enemies[rooti]);
		}
		enemies[ni] = findSet(enemies[rooti]);
		enemies[rooti] = -1;
	}

	if(rootj != ni && enemies[rootj] != -1){
		if(enemies[nj] != -1){
			setFriends(enemies[nj], enemies[rootj]);
		}
		enemies[nj] = findSet(enemies[rootj]);
		enemies[rootj] = -1;
	}

	return true;
}

bool setEnemies(int i, int j){
	if(areFriends(i,j)) return false;

	if(enemies[findSet(i)] != -1){
		setFriends(enemies[findSet(i)],j);
	}

	if(enemies[findSet(j)] != -1){
		setFriends(enemies[findSet(j)],i);
	}

	enemies[findSet(i)] = findSet(j);
	enemies[findSet(j)] = findSet(i);

	return true;
}



int main() {
	//freopen("input.txt", "r", stdin);
	int people = 0;

	scanf("%d", &people);
	initSet(people);

	REP(i,0,people-1){
		enemies.resize(people);
		enemies[i] = -1;
	}

	int op(0), p1(0), p2(0);

	bool result = false;
	int testcase = 0;
	int m = 0;

	while(scanf("%d %d %d", &op, &p1, &p2) == 3 && op > 0){
		
		if(op < 1 || op > 4 || p1 < 0 || p1 >= people || p2 < 0 || p2 >= people){
			printf("-1\n");
			continue;
		}

		if(op == 1){
			if(!setFriends(p1,p2)){
				printf("-1\n");
			}
		}else if(op == 2){
			if(!setEnemies(p1,p2)){
				printf("-1\n");
			}
		}else if(op == 3){
			if(areFriends(p1,p2)){
				printf("1\n");
			}else{
				printf("0\n");
			}
		}else if(op == 4){
			if(areEnemies(p1,p2)){
				printf("1\n");
			}else{
				printf("0\n");
			}
		}
	}
	return 0;
}
