#include <iostream>

using namespace std;

class Node
{
public:

	Node(const string& data, bool isQuestion) : m_data(data), m_yes(nullptr), m_no(nullptr), m_isQuestion(isQuestion) {}
	bool isLeaf();

	Node* getYes() { return m_yes; }
	void setYes(Node* yes) { m_yes = yes; }
	Node* getNo() { return m_no; }
	void setNo(Node* no) { m_no = no; }
	bool getIsQuestion() { return m_isQuestion; }
	void setIsQuestion(bool isQuestion) { m_isQuestion = isQuestion; }
	string getData() { return m_data; }
	void setData(string data) { m_data = data; }

private:
	string m_data;	// la pregunta o resposta del node en el que estem
	Node* m_yes;	// branca per la resposta si
	Node* m_no;	// branca per la resposta no
	bool m_isQuestion;
};