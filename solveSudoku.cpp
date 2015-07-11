#include <iostream>
#include <vector>
using namespace std;
void print_board(vector<vector<char> >& v) {
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			cout<<v[i][j];
		}
		cout<<endl;		
	}
	cout<<endl;
}
int isSloved(vector<vector<char> >& board){
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			if(board[i][j]=='.') return 0;
	return 1;
}
int isValid(vector<vector<char> >& board){
	int used1[9][9]={0}, used2[9][9]={0}, used3[9][9]={0};
	for (int i = 0; i < board.size(); ++i)
		for (int j = 0; j < board[i].size(); ++j) {
			int num = board[i][j]-'0'-1, k =i/3*3+j/3;
			if(board[i][j]!='.') {
				if(used1[i][num] || used2[j][num] || used3[k][num]) return 0;
				else {
					used1[i][num]=1, used2[j][num]=1, used3[k][num]=1;				
				}
			}
		}
	return 1;
}
void backtracking(vector<vector<char> >& board, int row, int col) {
	if(isSloved(board)) return;
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
		{
			if(board[i][j]=='.') {
				// vector<vector<char> >v(board.begin(),board.end());
				for (int num = 1; num <= 9; ++num)
				{
					board[i][j] = num+'0';
					print_board(board);
					if(isValid(board)) backtracking(board,i,j);
					else {
						board[i][j] = '.';		
					}
				}
			}	
		}
	return;	
}
void solveSudoku(vector<vector<char> >& board) {
	backtracking(board);
}

int main() {
	string a[] = {"...2...63","3....54.1","..1..398.",".......9.","...538...",".3.......",".263..5..","5.37....8","47...1..."};
	vector<vector<char> >v(9);
	for (int i = 0; i < 9; ++i)
		// cout<<a[i]<<endl;
		for (int j = 0; j < 9; ++j)
		{
			v[i].push_back(a[i][j]);
		}
	solveSudoku(v);
	print_board(v);
	return 0;
}
