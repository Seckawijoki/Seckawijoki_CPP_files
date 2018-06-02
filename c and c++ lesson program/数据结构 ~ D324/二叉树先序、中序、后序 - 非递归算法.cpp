# include <iostream>
# include <string>
# include <stack>
using namespace std;
class BiTreeNode
{
public:
	char datum;
	BiTreeNode *LeftChild;
	BiTreeNode *RightChild;
	BiTreeNode()
	{
		LeftChild = NULL;
		RightChild = NULL;
	}
	~BiTreeNode()
	{
		if ( LeftChild != NULL )delete LeftChild;
		if ( RightChild != NULL )delete RightChild;
	}
};
class BiTree
{
private:
	BiTreeNode *Root;
	int position;
	string strTree;
	BiTreeNode *CreateBiTree()
	{
		BiTreeNode *T;
		char ch;
		ch = strTree[position++];
		if ( ch == '0' )
			T = NULL;
		else
		{
			T = new BiTreeNode();
			T->datum = ch;
			T->LeftChild = CreateBiTree();
			T->RightChild = CreateBiTree();
		}
		return T;
	}
	void PreOrderUnrecursive1( BiTreeNode *t )
	{
		BiTreeNode *p;
		stack <BiTreeNode*> s;
	    p = t;
	    while ( p != NULL || !s.empty() )
	    {
	        while ( p != NULL ) //遍历左子树
	        {
	            cout<<p->datum;
	            s.push(p);
	            p = p->LeftChild;      
	        }	        
	        if ( !s.empty() )//通过下一次循环中的内嵌while实现右子树遍历
	        {
	        	p = s.top();
	            s.pop();
	            p = p->RightChild;        
	        }
	    }
	}
	void PreOrderUnrecursive2( BiTreeNode *t )
	{
	    if ( t == NULL )return;
	    stack <BiTreeNode*> s;
	    BiTreeNode *p = t;
	    s.push(t);
	    while ( !s.empty() )  //循环结束条件与前两种不一样
	    {
	        //这句表明p在循环中总是非空的
	        cout<<p->datum;
	        /*
	        栈的特点：先进后出
	        先被访问的根节点的右子树后被访问
	        */
	        if ( p->RightChild != NULL )
	            s.push(p->RightChild);
	        if ( p->LeftChild != NULL )
	            p = p->LeftChild;
	        else
	        {//左子树访问完了，访问右子树
	            p = s.top();
	            s.pop();
	        }
	    }
	}
	void InOrderUnrecursive1( BiTreeNode *t )
	{
		BiTreeNode *p;
	    stack <BiTreeNode*> s;
	    p = t;
	    while ( p != NULL || !s.empty() )
	    {
	        while ( p != NULL )//遍历左子树
	        {
	            s.push(p);
	            p = p->LeftChild;
	        }
	        if ( !s.empty() )
	        {
	        	p = s.top();
	        	s.pop();
	            cout<<p->datum;//访问根结点
	            p = p->RightChild;//通过下一次循环实现右子树遍历
	        }
	    }
	}
	void InOrderUnrecursive2( BiTreeNode* t )
	{
	    //空树
	    if ( t == NULL )return;
	    //树非空
	    BTNode *p = t;
	    stack <BiTreeNode*> s;
	    while ( !s.empty() || p != NULL )
	    {
	        if ( p != NULL )
	        {
	            s.push(p);
	            p = p->LeftChild;
	        }
	        else
	        {
	            p = s.top();
	            s.pop();
	            cout<< p->datum;
	            p = p->RightChild;
	        }
	    }
	}
	void PostOrderUnrecursive1( BiTreeNode *t )
	{
		if ( t == NULL )return;
    	stack <BiTreeNode*> s;
	    //pCur:当前访问节点，pLastVisit:上次访问节点
	    BTNode* pCur, *pLastVisit;
	    //pCur = root;
	    pCur = root;
	    pLastVisit = NULL;
	    //先把pCur移动到左子树最下边
	    while (pCur)
	    {
	        s.push(pCur);
	        pCur = pCur->lchild;
	    }
	    while (!s.empty())
	    {
	        //走到这里，pCur都是空，并已经遍历到左子树底端(看成扩充二叉树，则空，亦是某棵树的左孩子)
	        pCur = s.top();
	        s.pop();
	        //一个根节点被访问的前提是：无右子树或右子树已被访问过
	        if (pCur->rchild == NULL || pCur->rchild == pLastVisit)
	        {
	            cout << setw(4) << pCur->data;
	            //修改最近被访问的节点
	            pLastVisit = pCur;
	        }
	        /*这里的else语句可换成带条件的else if:
	        else if (pCur->lchild == pLastVisit)//若左子树刚被访问过，则需先进入右子树(根节点需再次入栈)
	        因为：上面的条件没通过就一定是下面的条件满足。仔细想想！
	        */
	        else
	        {
	            //根节点再次入栈
	            s.push(pCur);
	            //进入右子树，且可肯定右子树一定不为空
	            pCur = pCur->rchild;
	            while (pCur)
	            {
	                s.push(pCur);
	                pCur = pCur->lchild;
	            }
	        }
	    }
	}
public:
	BiTree()
	{
		position = 0;
		Root = NULL;
	}
	~BiTree()
	{
		if ( Root != NULL ) delete Root;
	}
	void CreateTree( string TreeArray )
	{
		position = 0;
		strTree.assign(TreeArray);
		Root = CreateBiTree();
	}
	void PreOrderUnrecursive()
	{
		PreOrderUnrecursive1(Root);
		cout<<endl;
		PreOrderUnrecursive2(Root);
		cout<<endl;
	}
	void InOrderUnrecursive()
	{
		InOrderUnrecursive1(Root);
		cout<<endl;
		InOrderUnrecursive2(Root);
		cout<<endl;
	}
	void PostOrderUnrecursive()
	{
		PostOrderUnrecursive1(Root);
		cout<<endl;
	}
};
int main()
{
	int t;
	cin>>t;
	while ( t-- )
	{
		string binarytree;
		cin>>binarytree;
		BiTree nishinponoki;
		nishinponoki.CreateTree(binarytree);
		nishinponoki.PreOrder();
		cout<<endl;
		nishinponoki.InOrder();
		cout<<endl;
		nishinponoki.PostOrder();
		cout<<endl;
	}
	return 0;
}
/*
样例输入
2
AB0C00D00
AB00C00

样例输出
ABCD
BCAD
CBDA
ABC
BAC
BCA
*/
