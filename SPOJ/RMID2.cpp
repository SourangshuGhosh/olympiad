// Ivan Carvalho
// Solution to https://www.spoj.com/problems/RMID2/
#include <bits/stdc++.h>
using namespace std;
multiset<int> tree1,tree2;
int tam;
void balance(){
	tam = tree1.size() + tree2.size();
	int alvo = (tam + 1)/2;
	while(tree1.size() > alvo){
		int last = *(tree1.rbegin());
		tree1.erase(tree1.find(last));
		tree2.insert(last);
	}
	while(tree1.size() < alvo){
		int last = *(tree2.begin());
		tree2.erase(tree2.find(last));
		tree1.insert(last);
	}
}
void insert(int k){
	if(tree1.empty()){
		tree1.insert(k);
	}
	else if(k > *(tree1.rbegin())){
		tree2.insert(k);
	}
	else{
		tree1.insert(k);
	}
	balance();
}
int query(){
	int resp = *(tree1.rbegin());
	tree1.erase(tree1.find(resp));
	balance();
	return resp;
}
int main(){
	int TC;
	scanf("%d",&TC);
	while(TC--){
		tam = 0;tree1.clear();tree2.clear();
		int n;
		while(scanf("%d",&n) && n){
			if(n == -1){
				printf("%d\n",query());
			}
			else{
				insert(n);
			}
		}
	}
	return 0;
}