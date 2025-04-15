#include "../include/node.h"

bool Node::isLeaf()
{
	bool isLeaf = false;

	if ((m_yes == nullptr) && (m_no == nullptr))
	{
		isLeaf = true;
	}

	return isLeaf;
}
