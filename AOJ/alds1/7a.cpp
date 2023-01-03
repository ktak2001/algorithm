#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vct;
struct S {
	int	node;
	int	parent;
	int	depth;
	string	type;
	vector<int> arr;	
};
int	IDX = 0;

int	main() {
	int	n, id, k;
	scanf("%d", &n);
	struct S	S_arr[n];
	for (int i = 0; i < n; i++) {
		int	tmp = 0;
		scanf("%d%d", &id, &k);
		S_arr[i].node = id;
		if (k) {
			for (int j = 0; j < k; j++) {
				scanf("%d", &tmp);
				S_arr[i].arr.push_back(tmp);
			}
			for (; IDX < tmp + 1; IDX++)
				vct.push_back(-1);
			for (int s = 0; s < S_arr[i].arr.size(); s++)
				vct[S_arr[i].arr[s]] = S_arr[i].node;
		}
		if (!S_arr[i].node) {
			S_arr[i].depth = 0;
			S_arr[i].parent = -1;
			S_arr[i].type = "root";
		}
		else {
			S_arr[i].type = S_arr[i].arr.size() ? "internal node" : "leaf";
			S_arr[i].parent = vct[i];
			S_arr[i].depth = S_arr[S_arr[i].parent].depth + 1;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("node %d: parent = %d, depth = %d, %s, [", S_arr[i].node, S_arr[i].parent, S_arr[i].depth, S_arr[i].type.c_str());
		if (S_arr[i].arr.size()) {
			for (int j = 0; j < S_arr[i].arr.size() - 1; j++)
				printf("%d, ", S_arr[i].arr[j]);
			printf("%d]\n", S_arr[i].arr.back());
		}
		else
			printf("]\n");
	}
	return 0;
}