#include<bits/stdc++.h>
using namespace std;

const int nMAX = 25;
vector<int> Block[nMAX];

void find_Block(int x,int n,int& p,int& h) {
	for(p = 0 ; p < n; p++){
		for(h = 0 ; h < Block[p].size() ; h++){
			if(Block[p][h] == x) return;
		}
	}
}

void clear(int p,int h) {
	for(int i=h+1 ; i < Block[p].size() ; i++){
		int t = Block[p][i];
		Block[t].push_back(t);
	}

	Block[p].resize(h+1);
}

void transport(int pa,int ha,int pb) {
	for(int i=ha ; i<Block[pa].size() ; i++){
		int t = Block[pa][i];
		Block[pb].push_back(t);
	}

	Block[pa].resize(ha);
}

void print(int n) {
	for(int i=0 ; i<n ; i++){
		cout << i << ":" ;
		for(int j=0 ; j<Block[i].size() ; j++) cout << " " << Block[i][j];
		cout << endl;
	}
}

int main(){
	int n;
	cin >> n;
	for(int i=0 ; i<n; i++){
		Block[i].push_back(i);
	}

	int a,b;
	string cmd1,cmd2;

	while(cin >> cmd1){
		if(cmd1 == "quit") break;
		cin >> a >> cmd2 >> b;

		int pa,pb,ha,hb;
		find_Block(a,n,pa,ha);
		find_Block(b,n,pb,hb);

		if(a==b || pa==pb) continue;
		if(cmd1 == "move") clear(pa,ha);
		if(cmd2 == "onto") clear(pb,hb);
		transport(pa,ha,pb);
	}
	print(n);

	return 0;
}
