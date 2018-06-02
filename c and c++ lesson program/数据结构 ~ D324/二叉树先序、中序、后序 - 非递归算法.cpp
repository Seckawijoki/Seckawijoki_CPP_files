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
	        while ( p != NULL ) //����������
	        {
	            cout<<p->datum;
	            s.push(p);
	            p = p->LeftChild;      
	        }	        
	        if ( !s.empty() )//ͨ����һ��ѭ���е���Ƕwhileʵ������������
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
	    while ( !s.empty() )  //ѭ������������ǰ���ֲ�һ��
	    {
	        //������p��ѭ�������Ƿǿյ�
	        cout<<p->datum;
	        /*
	        ջ���ص㣺�Ƚ����
	        �ȱ����ʵĸ��ڵ���������󱻷���
	        */
	        if ( p->RightChild != NULL )
	            s.push(p->RightChild);
	        if ( p->LeftChild != NULL )
	            p = p->LeftChild;
	        else
	        {//�������������ˣ�����������
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
	        while ( p != NULL )//����������
	        {
	            s.push(p);
	            p = p->LeftChild;
	        }
	        if ( !s.empty() )
	        {
	        	p = s.top();
	        	s.pop();
	            cout<<p->datum;//���ʸ����
	            p = p->RightChild;//ͨ����һ��ѭ��ʵ������������
	        }
	    }
	}
	void InOrderUnrecursive2( BiTreeNode* t )
	{
	    //����
	    if ( t == NULL )return;
	    //���ǿ�
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
	    //pCur:��ǰ���ʽڵ㣬pLastVisit:�ϴη��ʽڵ�
	    BTNode* pCur, *pLastVisit;
	    //pCur = root;
	    pCur = root;
	    pLastVisit = NULL;
	    //�Ȱ�pCur�ƶ������������±�
	    while (pCur)
	    {
	        s.push(pCur);
	        pCur = pCur->lchild;
	    }
	    while (!s.empty())
	    {
	        //�ߵ����pCur���ǿգ����Ѿ��������������׶�(�����������������գ�����ĳ����������)
	        pCur = s.top();
	        s.pop();
	        //һ�����ڵ㱻���ʵ�ǰ���ǣ������������������ѱ����ʹ�
	        if (pCur->rchild == NULL || pCur->rchild == pLastVisit)
	        {
	            cout << setw(4) << pCur->data;
	            //�޸���������ʵĽڵ�
	            pLastVisit = pCur;
	        }
	        /*�����else���ɻ��ɴ�������else if:
	        else if (pCur->lchild == pLastVisit)//���������ձ����ʹ��������Ƚ���������(���ڵ����ٴ���ջ)
	        ��Ϊ�����������ûͨ����һ����������������㡣��ϸ���룡
	        */
	        else
	        {
	            //���ڵ��ٴ���ջ
	            s.push(pCur);
	            //�������������ҿɿ϶�������һ����Ϊ��
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
��������
2
AB0C00D00
AB00C00

�������
ABCD
BCAD
CBDA
ABC
BAC
BCA
*/
