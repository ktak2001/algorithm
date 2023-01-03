#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int key;
	node *left, *right, *p;
	node() {}
	node(int key) : key(key) { left = right = p = NULL; };
};
node *root;
void insert(node z)
{
	node *y = NULL;
	node *x = root;
	while (x != NULL)
	{
		y = x;
		if (z.key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z.p = y;
	if (y == NULL)
		root = new node(z);
	else if (z.key < y->key)
		y->left = new node(z);
	else
		y->right = new node(z);
}
void inorderTreeWalk(node *v)
{
	if (v == NULL)
		return;
	inorderTreeWalk(v->left);
	cout << " " << v->key;
	inorderTreeWalk(v->right);
}
void preorderTreeWalk(node *v)
{
	if (v == NULL)
		return;
	cout << " " << v->key;
	preorderTreeWalk(v->left);
	preorderTreeWalk(v->right);
}
signed main()
{
	int n;
	cin >> n;
	root = NULL;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		// cout<<(root==NULL?-1:root->key)<<endl;
		if (s == "print")
		{
			inorderTreeWalk(root);
			cout << endl;
			preorderTreeWalk(root);
			cout << endl;
			continue;
		}
		int x;
		cin >> x;
		insert(node(x));
	}
	return 0;
}