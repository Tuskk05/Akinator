#include <iostream>
#include "node.h"

using namespace std;

class akinatorTree
{
public:
	akinatorTree();
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

	void printTree();
private:
	Node* m_root;
	int m_treeSize;
	Node* m_currentNode;
};