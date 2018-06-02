# include <iostream>
using namespace std;

class BinaryTree
{
private:
	int *TreeNode;
	int length;
	void PreOrder( int index )
	{
		if ( index <= length && TreeNode[index] != 0 )
		{
			cout<<TreeNode[index]<<' ';
			PreOrder( 2 * index );
			PreOrder( 2 * index + 1 );		
		}
	}
public:
	BinaryTree()
	{
		TreeNode = NULL;
	}
	~BinaryTree()
	{
		delete [] TreeNode;
	}
	BinaryTree( int size, int *array )
	{
		int i;
		length = size;
		TreeNode = new int [length+1];
		for ( i = 0 ; i < length ; ++i )
			TreeNode[i+1] = array[i];
	}
	void PreOrder()
	{
		PreOrder(1);
		cout<<endl; 
	}
	friend int mapTree(int (*f)(int), BinaryTree tree);
	friend int reduce(int (*f)(int, int), BinaryTree tree);
};
int addOne(int x){
	return x+1;
}
int mapTree(int (*f)(int), BinaryTree tree){
	for (int i = 1; i <= tree.length; ++i){
		if (i*2 > tree.length && i*2+1 > tree.length)
		  tree.TreeNode[i] = f(tree.TreeNode[i]);
	}
}
int sum(int x, int y){
	return x+y;
}
int reduce(int (*f)(int, int), BinaryTree tree){
	if (tree.length <= 0) return 0;
	int r = 0;
	for (int i = 1; i <= tree.length; ++i){
		if (i*2 > tree.length && i*2+1 > tree.length)
		  r = f(r, tree.TreeNode[i]);
	}
	return r;
}
int main()
{
	int tree[] = {6,3,3,1,2};
	BinaryTree biTree(sizeof(tree)/sizeof(int), tree);
	cout<<"前序遍历：\n"; 
	biTree.PreOrder();
	cout<<"前序遍历（使用map函数后）：\n"; 
	mapTree(addOne, biTree);
	biTree.PreOrder();
	cout<<"叶子求和："; 
	cout<<reduce(sum, biTree)<<endl;
	return 0;
}
