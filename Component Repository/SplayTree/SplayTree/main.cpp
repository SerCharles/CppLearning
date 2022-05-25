#include <iostream>
#include <cmath>
using namespace std;

#include "NBinaryTree.hpp"
#include "NBinarySortTree.hpp"
#include "NSplayTree.hpp"

int main()
{
	int n;
	cin >> n;
	NSplayTree<int>* the_tree = new NSplayTree<int>();
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		NBinaryNode<int>* new_num = new NBinaryNode<int>(a);
		the_tree->m_InsertNewNode(new_num);
	}
	the_tree->m_OutPut(the_tree->m_Root);
	delete(the_tree);
	while (1);
	return 0;
}