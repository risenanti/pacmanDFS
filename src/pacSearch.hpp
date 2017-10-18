#include <bits/stdc++.h>
using namespace std;
#define Max 40

class point
{
public:
	int x,y;
	point();
	point(int r, int c);
	bool operator == (const point& a);
};

class pacSearch
{
public:
	pacSearch();

	point source, destination;
	vector <point> nodeExpand, path;
	stack < point > Stack;

	int directionX[4];
	int directionY[4];
	int visited[Max][Max];
	point parent[Max][Max], nothing;

	bool found;
	int row, col, nodeExplored, totalPath;

	bool isValid(int x, int y, vector <string> grid);

	void dfsHelper(point node, vector <string> grid);
	void dfs( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid);
};

bool pacSearch::isValid(int x, int y, vector <string> grid) {
    return x >= 0 and y >= 0 and x < row and y < col and grid[x][y] != '%';
}

void pacSearch::dfsHelper(point node, vector <string> grid)
{
    ++nodeExplored;
    nodeExpand.push_back(node);
    if(destination == node) {
        found = true;
        return;
    }
    point poped = node, neighbour;
    for(int i = 0, n = sizeof(directionX) / sizeof(directionX[0]); i < n; ++i) {
        int x = node.x + directionX[i], y = node.y + directionY[i];
        neighbour = point(x, y);
        if( isValid(x, y, grid) and !visited[x][y] ) {
            Stack.push(neighbour);
            parent[x][y] = node;
            visited[x][y] = true;
        }
    }
    while( !Stack.empty() ) {
        poped = Stack.top();
        Stack.pop();
        dfsHelper(poped, grid);
        if(found) return;
    }
}

void pacSearch::dfs( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid)
{
	source = point(pacman_r, pacman_c);
    destination = point(food_r, food_c);
    row = r, col = c;
    visited[pacman_r][pacman_c] = true;
    parent[pacman_r][pacman_c] = nothing;
    dfsHelper(source, grid);
    cout << nodeExplored << endl;
    for(int i = 0, n = nodeExpand.size(); i < n; ++i) {
        cout << nodeExpand[i].x << " " << nodeExpand[i].y << endl;
    }

    point curr = destination;
    while(!(curr == nothing)) {
       ++totalPath;
       path.push_back(curr);
        curr = parent[curr.x][curr.y];
    }
    int distance = totalPath - 1;
    cout << distance << endl;
    for(int i = path.size() - 1; i >= 0; --i) {
        cout << path[i].x << " " << path[i].y << endl;
    }
}

pacSearch::pacSearch()
{
	nothing.x =-1;
	nothing.y = -1;
	directionX[0] = -1;
	directionX[1] =  0;
	directionX[2] =  0;
	directionX[3] =  1;

	directionY[0] =  0;
	directionY[1] = -1;
    directionY[2] =  1;
    directionY[3] =  0;

	found = false;
	nodeExplored = 0;
	totalPath = 0;

	row = 0;
	col = 0;
	nodeExplored = 0;
	totalPath = 0;
}


bool point::operator == (const point& a)
{
    return x == a.x and y == a.y;
}

point::point()
{
	x = 0;
	y = 0;
}

point::point(int r, int c)
{
	x = r;
	y = c;
}
