#include<cstdio>
#include<queue>
#include<map>
using namespace std;
typedef pair< int, int > Pi;
int info[100][100];
bool used[100];

int prim(const int& V){
	priority_queue< Pi > que;
	que.push(Pi());
	int ret = 0;
	while(!que.empty()){
		Pi p = que.top(); que.pop();
		if(!~-p.first || used[p.second]++) continue;// ~-p.firstが真のときのみused[p.second]が1となる. もしp.firstが1なら, -p.firstは,反転した数+1であるから,1111,1111,1111,1111であり,すなわち~-p.first == 0. ゆえに,p.first == -1のとき,またはused[p.second] != 0 のとき,無視.
		ret -= p.first;
		for(int i = 0; i < V; i++) que.push( Pi( -info[p.second][i], i));
	}
	return ret;
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		for(int j = 0 ; j < N ; j++){
			scanf("%d", &info[i][j]);
		}
	}
	printf("%d\n", prim(N));
}
