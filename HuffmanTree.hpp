#pragma once
#include<queue>
#include<vector>
using namespace std;

template<class W>
struct HuffmanTreeNode
{
	HuffmanTreeNode<W>* left;
	HuffmanTreeNode<W>*	right;
	HuffmanTreeNode<W>* parent;
	W weight;//权值

	HuffmanTreeNode(const W& w)
		:left(nullptr)
		,right(nullptr)
		,parent(nullptr)
		,weight(w)
	{}
};

template<class W>
struct com//优先级队列比较方法
{
	typedef HuffmanTreeNode<W> Node;
	bool operator()(const Node* left, const Node* right)
	{
		return left->weight > right->weight;
	}
};

template<class W>
class HuffmanTree
{
	typedef HuffmanTreeNode<W> Node;
public:
	HuffmanTree()
		:root(nullptr)
	{}
	~HuffmanTree()
	{
		Destory(root);
	}
	void CreateHuffmanTree(const W array[], size_t size,const W& invalid)
	{ 
		//创建一个小堆优先级队列，保存Huffman树节点,需要重写比较方法
		priority_queue<Node*, vector<Node*>,com<W>> q;
		//1.先使用所给权值创建只有根节点的二叉树森林
		for (size_t i = 0; i < size; i++)
		{
			if (array[i]!=invalid)
			{
				q.push(new Node(array[i]));
			}
		}
		//2.重复以下步骤，直到队列中只剩下一棵树
		while (q.size()>1)
		{
			/*q中选取两棵根节点权值最小的二叉树，作为左右子树构造一棵新的二叉树,新二叉树
			根结点权值是其左右子树根节点权值之和*/
			Node* left = q.top();
			q.pop();
			Node* right = q.top();
			q.pop();
			Node* parent = new Node(left->weight + right->weight);
			parent->left = left;
			parent->right = right;
			left->parent = parent;
			right->parent = parent;
			//将新二叉树加入到q队列中
			q.push(parent);
		}
		root = q.top();
	}
	Node* GetRoot()
	{
		return root;
	}
	
	void Destory(Node* root)
	{
		if (root)
		{
			Destory(root->left);
			Destory(root->right);
			delete root;
			root = nullptr;
		}
	}
private:
	Node* root;
};
