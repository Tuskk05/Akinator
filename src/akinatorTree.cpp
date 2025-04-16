#include "../include/akinatorTree.h"

void akinatorTree::deleteTree(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	deleteTree(node->getYes());
	deleteTree(node->getNo());

	delete node;
}

akinatorTree::~akinatorTree()
{
	deleteTree(m_root);
}

void akinatorTree::clear()
{
	deleteTree(m_root);
	m_root = nullptr;
	m_currentNode = nullptr;
	m_treeSize = 0;
}

void akinatorTree::print(Node* node, int spaces)
{
	if (node == nullptr)
	{
		return;
	}

	for (int i = 0; i < spaces; i++)
	{
		cout << " ";	//prints spaces between nodes
	}

	if (node->getIsQuestion())
	{
		cout << "Q: ";
	}
	else
	{
		cout << "A: ";
	}

	cout << node->getData() << endl;

	if (node->getIsQuestion())
	{
		print(node->getYes(), spaces + 1);	//everytime it is called, node becomes the next node
		print(node->getNo(), spaces + 1);
	}
}

void akinatorTree::printTree()
{
	print(m_root, 0);
}

void main()
{
	akinatorTree tree;

	Node* root = new Node("Es un pokemon?", true);
	Node* yes = new Node("Es de tipus terra?", true);
	Node* no = new Node("Coquito", false);
	Node* yes2 = new Node("Ryhorn", false);
	Node* no2 = new Node("Charmander", false);

	root->setYes(yes);
	root->setNo(no);
	yes->setYes(yes2);
	yes->setNo(no2);

	tree.setRoot(root);
	tree.setTreeSize(4);
	tree.setCurrentNode(root);

	cout << "L'arbre inicial es:" << endl;
	tree.printTree();
	tree.clear();

	cout << "L'arbre netejat es:" << endl;
	if ((tree.getRoot() == nullptr) && (tree.getCurrentNode() == nullptr) && (tree.getTreeSize() == 0))
	{
		cout << "La neteja ha estat un exit!" << endl;
	}
	else
	{
		cout << "El clear() ha fallat en algun lloc" << endl;
	}
}