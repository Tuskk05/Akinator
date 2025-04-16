#include <iostream>
#include "node.h"

using namespace std;

class akinatorTree
{
public:
	akinatorTree() : m_root(nullptr), m_currentNode(nullptr), m_treeSize(0) {}
	~akinatorTree();

	void play();
	void learn(Node*& node);
	void loadFromFile(const string& filename);
	void saveToFile(const string& filename);
	void clear();
	void deleteTree(Node* node);
	void saveNodes(Node* node, ostream& out);
	Node* loadNodes(istream& in);
	void playRound(Node*& currentNode);
	Node* findNextNode(Node* currentNode, bool answer);
	void askQuestion(Node* node);	//nomes es un cout

	void print(Node* node, int spaces);
	void printTree();

	Node* getRoot() { return m_root; }
	Node* getCurrentNode() { return m_currentNode; }
	int getTreeSize() { return m_treeSize; }

	void setRoot(Node* root) { m_root = root; }
	void setCurrentNode(Node* currentNode) { m_currentNode = currentNode; }
	void setTreeSize(int treeSize) { m_treeSize = treeSize; }

private:
	Node* m_root;
	int m_treeSize;
	Node* m_currentNode;
};