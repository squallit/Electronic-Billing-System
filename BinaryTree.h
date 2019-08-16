#ifndef BinaryTree_h
#define BinaryTree_h

#include <iostream>
using namespace std;


template <class T>
struct TreeNode
{
	T value;   //the data
	TreeNode* left;
	TreeNode* right;
};

template <class T>
class BinaryTree
{
private:
	TreeNode<T>* root;
	//private member functions
	void insert(TreeNode<T>* &, TreeNode<T>* &);
	void displayInOrder(TreeNode<T>*) const;
	void destroySubTree(TreeNode<T>*);
	void deleteNode(T, TreeNode<T>* &);
	void makeDeletion(TreeNode<T>* &);

public:
	//constructor
	BinaryTree() { root = nullptr; }
	//destructor
	~BinaryTree() { destroySubTree(root); }

	//operations
	void insertNode(T);
	void remove(T);
	void displayInOrder() const
	{
		displayInOrder(root);
	}
	bool searchNode(T&);
};






template <class T>
void BinaryTree<T>::insertNode(T num)
{
	TreeNode<T>* newNode = nullptr;  //ptr to new node
									 //create new node and store num
	newNode = new TreeNode<T>;
	newNode->value = num;
	newNode->left = nullptr;
	newNode->right = nullptr;

	//call private member function to insert the node
	insert(root, newNode);  //insert this node in tree starting at root
}

//recursive function to insert into tree that starts at nodePtr
//takes pointer to "subtree" and pointer to new node as parameters

template <class T>
void BinaryTree<T>::insert(TreeNode<T>* &nodePtr, TreeNode<T>* &newNode)
{

	if (nodePtr == nullptr) //"empty tree or subtree", insert value
		nodePtr = newNode;   //that's why must be passed by ref

	else if (newNode->value < nodePtr->value)  //goes in left branch
		insert(nodePtr->left, newNode);

	else //goes in right branch
		insert(nodePtr->right, newNode);
}


template <class T>
void BinaryTree<T>::displayInOrder(TreeNode<T>* nodePtr) const
{

	if (nodePtr)   //not null, there is something to print
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}

}


template <class T>
bool BinaryTree<T>::searchNode(T &num)
{
	TreeNode<T>* nodePtr = root;  //start at root
	while (nodePtr)  //still something to search
	{
		//if found it
		if (nodePtr->value == num)
		{
			//use reference to assign value for num
			num = nodePtr->value;
			return true;
		}
		else if (num < nodePtr->value)
			nodePtr = nodePtr->left;  // look in left branch
		else
			nodePtr = nodePtr->right;  // look in right branch
	}
	//searched everything, it's not there
	return false;
}


template <class T>
void BinaryTree<T>::destroySubTree(TreeNode<T>* nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left) //has a left branch
			destroySubTree(nodePtr->left);
		if (nodePtr->right) //has a right branch
			destroySubTree(nodePtr->right);
		//no children so you can delete
		delete nodePtr;
	}
}


template <class T>
void BinaryTree<T>::remove(T num)
{
	deleteNode(num, root);  //call private function
}


template <class T>
void BinaryTree<T>::deleteNode(T num, TreeNode<T>* &nodePtr)
{
	if (num < nodePtr->value)  //look on left branch
		deleteNode(num, nodePtr->left);
	else if (num > nodePtr->value) //look on right branch
		deleteNode(num, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

template <class T>
void BinaryTree<T>::makeDeletion(TreeNode<T>* &nodePtr)
{
	//define a temporary pointer to use
	//in reattaching left subtree
	TreeNode<T>* tempNodePtr = nullptr;

	if (nodePtr == nullptr)
		cout << "Cannot delete empty node" << endl;  //not found
	else if (nodePtr->right == nullptr) //no node on the right
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;  //reattach left child
		delete tempNodePtr;
		cout << "deleted" << endl;
	}
	else if (nodePtr->left == nullptr) //no node on the left
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
		cout << "deleted" << endl;
	}
	else  //there are two children
	{
		//move one node to the right
		tempNodePtr = nodePtr->right;
		//go to end left node
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		//reattach left subtree
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		//reattach right subtree
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

#endif /* BinaryTree_h */
