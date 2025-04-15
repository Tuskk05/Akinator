#include <iostream>

using namespace std;

class Node
{
public:

	Node(const string& data, bool isQuestion) : m_data(data), m_yes(nullptr), m_no(nullptr), m_isQuestion(isQuestion) {}
	bool isLeaf();

private:
	string m_data;	// la pregunta o resposta del node en el que estem
	Node* m_yes;	// branca per la resposta si
	Node* m_no;	// branca per la resposta no
	bool m_isQuestion;
};