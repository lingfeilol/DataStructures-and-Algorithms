
#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

#include "AVLTree.h"


void TestAVLTree1()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
		//cout << t.IsBalance() << endl;
	}
	t.InOrder();
	cout << t.IsBalance() << endl;
}
void TestAVLTree2()
{
	AVLTree<int, int> avl;
	vector<int> v;
	int n = 100000;
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		v.push_back(rand());
	}
	for (auto e : v)
	{
		avl.Insert({ e, e });
	}
	//avl.InOrder();
	cout << avl.IsBalance() << endl;
}
int main()
{
	TestAVLTree2();
	return 0;
}