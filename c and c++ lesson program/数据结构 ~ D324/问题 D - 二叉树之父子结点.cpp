# include <iostream>
# include <string>
# include <queue>
# include <stack>
using namespace std;
int runningtimes = 0;
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
stack <BiTreeNode *> parent;
stack <BiTreeNode *> parent2;
stack <BiTreeNode *> child;
stack <BiTreeNode *> child2;
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
	void PreOrder( BiTreeNode *t )
	{
		if ( t != NULL )
		{
			cout<<t->datum;
			PreOrder(t->LeftChild);
			PreOrder(t->RightChild);
		}
	}	
	void InOrder( BiTreeNode *t )
	{
		if ( t != NULL )
		{
			InOrder(t->LeftChild);
			cout<<t->datum;
			InOrder(t->RightChild);
		}
	}
	void PostOrder( BiTreeNode *t )
	{
		if ( t != NULL )
		{
			PostOrder(t->LeftChild);
			PostOrder(t->RightChild);
			cout<<t->datum;
		}
	}
	void LevelOrder( BiTreeNode *t )
	{
		queue <BiTreeNode*> tq;
		BiTreeNode *p = t;
		if ( p != NULL )
		{
			tq.push(p);
			while ( !tq.empty() )
			{
				p = tq.front();
				tq.pop();
				cout<<p->datum;
				if ( p->LeftChild != NULL )tq.push(p->LeftChild);
				if ( p->RightChild != NULL )tq.push(p->RightChild);
			}
		}
	}
	void LeavesJudgement( BiTreeNode *ryoshin, BiTreeNode *kotomo )
	{
		++runningtimes;
		BiTreeNode *p = ryoshin, *q = kotomo;
		if ( ( p == NULL && q != NULL )  )
		{
			p = q;
			q = p->RightChild;
			LeavesJudgement(p,q);
			q = p->LeftChild;
			LeavesJudgement(p,q);
		}
		else
		{
			if ( q->LeftChild != NULL && q->RightChild != NULL )
			{
				p = q;
				q = q->RightChild;
				LeavesJudgement(p,q);
				q = q->LeftChild;
				LeavesJudgement(p,q);
			}
			else if ( q->LeftChild != NULL && q->RightChild == NULL )
			{
				p = q;
				q = q->LeftChild;
				LeavesJudgement(p,q);
			}
			else if ( q->LeftChild == NULL && q->RightChild != NULL )
			{
				p = q;
				q = q->RightChild;
				LeavesJudgement(p,q);
			}
			else if ( q->LeftChild == NULL && q->RightChild == NULL )
			{
				parent.push(p);
				child.push(q);
			}
		}
	}
	void LeavesJudgement2( BiTreeNode *t )
	{
		if ( t == NULL ) return;
		++runningtimes;
		if ( t->RightChild != NULL )
		{
			if ( t->RightChild->LeftChild == NULL && 
				t->RightChild->RightChild == NULL )
			{
				parent2.push(t);
				child2.push(t->RightChild);
			}
			else LeavesJudgement2(t->RightChild);
		}
		if ( t->LeftChild != NULL )
		{
			if ( t->LeftChild->LeftChild == NULL && 
				t->LeftChild->RightChild == NULL )
			{
				parent2.push(t);
				child2.push(t->LeftChild);
			}
			else LeavesJudgement2(t->LeftChild);
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
	void PreOrder()
	{
		PreOrder(Root);
	}
	void InOrder()
	{
		InOrder(Root);
	}
	void PostOrder()
	{
		PostOrder(Root);
	}
	void LevelOrder()
	{
		LevelOrder(Root);
	}
	void LeavesJudgement()
	{
		LeavesJudgement(NULL,Root);
	}
	void LeavesJudgement2()
	{
		LeavesJudgement2(Root);
	}
	void DisplayParentAndChildNodes()
	{
		while ( !child.empty() )
		{
			cout<<child.top()->datum<<' ';
			child.pop();
		}
		cout<<endl;
		while ( !parent.empty() )
		{
			cout<<parent.top()->datum<<' ';
			parent.pop();
		}
		cout<<endl;
	}
	void DisplayParentAndChildNodes2()
	{
		while ( !child2.empty() )
		{
			cout<<child2.top()->datum<<' ';
			child2.pop();
		}
		cout<<endl;
		while ( !parent2.empty() )
		{
			cout<<parent2.top()->datum<<' ';
			parent2.pop();
		}
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
		nishinponoki.LeavesJudgement();
		nishinponoki.DisplayParentAndChildNodes();
		nishinponoki.LeavesJudgement2();
		nishinponoki.DisplayParentAndChildNodes2();
		while ( !parent.empty()  )parent.pop();
		while ( !parent2.empty() )parent2.pop();
		while ( !child.empty() ) child.pop();
		while ( !child2.empty() )child2.pop();
		cout<<"Running times = "<<runningtimes<<endl;
		runningtimes = 0;
	}
	return 0;
}
/*
��Ŀ����

����һ�Ŷ��������߼��ṹ����ͼ��
����������Ľ�����������ַ���0����ʾ������AB0C00D00����
�����ö������Ķ�����ʽ�洢�ṹ��
��д�����������������Ҷ�ӽ������ǵĸ��׽��

����
��һ������һ������t����ʾ��t��������
�ڶ����𣬰�����Ŀ��ʾ�����뷽��������ÿ�������������������
��������t��

���
��һ�а���������������1��ʾ����Ҷ�ӽڵ�
�ڶ��������1��ʾ������Ҷ�����Ӧ�ĸ��׽ڵ�
�Դ������������ʾ���Ľ��

��������
3
AB0C00D00
AB00C00
ABCD0000EF000

�������
C D 
B A 
B C 
A A 
D F 
C E 
*/
