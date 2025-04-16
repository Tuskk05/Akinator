#include "../include/akinatorTree.h"
#include <windows.h>

using namespace std;

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

bool akinatorTree::isCurrentLeaf()
{
	return m_currentNode && m_currentNode->isLeaf();
}

void akinatorTree::resetCurrentNode()
{
	m_currentNode = m_root;
}

void akinatorTree::moveToYes()
{
	if (m_currentNode)	//m_currentNode != nullptr
	{
		m_currentNode = m_currentNode->getYes();
	}
}

void akinatorTree::moveToNo()
{
	if (m_currentNode)	//m_currentNode != nullptr
	{
		m_currentNode = m_currentNode->getNo();
	}
}

void akinatorTree::askQuestion(Node* node)
{
	cout << node->getData() << endl;
}

void akinatorTree::findNextNode(bool answer)
{
	if (answer)
	{
		m_currentNode = m_currentNode->getYes();
	}
	else
	{
		m_currentNode = m_currentNode->getNo();
	}
}

void akinatorTree::saveNodes(Node* node, ostream& out)
{
	if (node != nullptr)
	{
		if (node->getIsQuestion())
		{
			out << "Q:" << node->getData() << endl;
			saveNodes(node->getYes(), out);
			saveNodes(node->getNo(), out);
		}
		else
		{
			out << "A:" << node->getData() << endl;
		}
	}
}

void akinatorTree::saveToFile(const string& filename)
{
	ofstream file;

	file.open(filename);
	
	if (file.is_open())
	{
		saveNodes(m_root, file);
		file.close();
		cout << "L'arbre s'ha guardat correctament" << endl;
	}
	else
	{
		cout << "Hi ha algun probelama a l'hora de guardar l'arbre" << endl;
	}
}

Node* akinatorTree::loadNodes(istream& in)
{
	string line;

	if (getline(in, line))
	{
		bool isQuestion = (line.substr(0, 2) == "Q:");		// mira els dos primers elements
		string data = line.substr(2);	  // agafa tota la linea menys els priemrs dos elements

		Node* node = new Node(data, isQuestion);

		if (isQuestion)
		{
			node->setYes(loadNodes(in));
			node->setNo(loadNodes(in));
		}

		return node;
	}
	else
	{
		return nullptr;
	}
}

void akinatorTree::loadFromFile(const string& filename)
{
	ifstream file;
	file.open(filename);

	if (file.is_open())
	{
		clear();
		m_root = loadNodes(file);
		m_currentNode = m_root;

		file.close();
		cout << "Informacio carregada amb exit" << endl;
	}
	else
	{
		cout << "Error al carregar la informacio" << endl;
	}
}

void akinatorTree::learn(Node*& node) 
{
	if (!node->getIsQuestion()) 
	{
		cout << "He fallat! No coneixia aquest personatge... Quin es el personatge en el que estaves pensant?" << endl;
		string newData;
		getline(cin, newData);

		cout << "Dona'm una pregunta que em permeti diferenciar entre " << node->getData() << " i " << newData << " : ";
		string question;
		getline(cin, question);

		Node* newQuestion = new Node(question, true);

		cout << "La resposta a '" << question << "' per " << newData << " es (1 = si, 0 = no): ";
		bool answerYes;
		cin >> answerYes;
		cin.ignore();

		Node* yesNode = new Node(newData, false);
		Node* noNode = new Node(node->getData(), false);

		if (answerYes == 1) 
		{
			newQuestion->setYes(yesNode);
			newQuestion->setNo(noNode);
		}
		else 
		{
			newQuestion->setYes(noNode);
			newQuestion->setNo(yesNode);
		}

		node = newQuestion;
	}
}