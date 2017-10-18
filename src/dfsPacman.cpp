#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
//#include <fstream>
#include "pacSearch.hpp"

using namespace std;
//void dfs( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid){
    //your logic here
//}



void readInput(int &r, int &c, int &pacman_r, int &pacman_c, int &food_r, int &food_c, vector<string> &grid);
int main(void) {

    int r,c, pacman_r, pacman_c, food_r, food_c;

    //cin >> pacman_r >> pacman_c;
    //cin >> food_r >> food_c;
    //cin >> r >> c;

    vector <string> grid;
    readInput( r, c, pacman_r, pacman_c, food_r, food_c, grid);

    pacSearch pac;

    pac.dfs( r, c, pacman_r, pacman_c, food_r, food_c, grid);

    //for(int i=0; i<r; i++) {
    //    string s; cin >> s;
    //    grid.push_back(s);
    //}

    return 0;
}


void readInput(int &r, int &c, int &pacman_r, int &pacman_c, int &food_r, int &food_c, vector<string> &grid)
{
	fstream fileInput;
	fileInput.open ("input.txt",fstream::in);
	string s;
	fileInput>>s;
	pacman_r=stoi(s);

	fileInput>>s;
	pacman_c=stoi(s);

	fileInput>>s;
	food_r=stoi(s);

	fileInput>>s;
	food_c=stoi(s);

	fileInput>>s;
	r=stoi(s);

	fileInput>>s;
	c=stoi(s);

	for (int i = 0; i < r; i++)
	{
		fileInput>>s;
		grid.push_back(s);
	}
	fileInput.close();
}
