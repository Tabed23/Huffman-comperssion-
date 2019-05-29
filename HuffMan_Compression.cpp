#include "HuffMan_Compression.h"


HuffMan_Compression::HuffMan_Compression(string text)
{
	unordered_map<char, int>frequancy;
	for (char str : text) 
	{
		frequancy[str]++; // will make pair and set each char freq 
	}
	priority_queue<Huffman_Node *, vector<Huffman_Node*>, compare>huffman;
	for (auto node : frequancy)
	{
		huffman.push(get_node(node.first, node.second, NULL, NULL)); //  node enter in a queue
	}
	while (huffman.size() != 1)
	{
		//  make tow node to store right and left child;
		Huffman_Node * left = huffman.top();
		huffman.pop(); //  remove the node from the queue;
		Huffman_Node * right = huffman.top();
		huffman.pop();
		int sum = left->frequancy + right->frequancy;
		huffman.push(get_node('\0', sum, left, right));
	}
	this->root = huffman.top(); //  now it will become a tree so we can set root equal to it

}
Huffman_Node *HuffMan_Compression::get_node(char str, int freq, Huffman_Node* left, Huffman_Node* right)
{
	Huffman_Node * node = new Huffman_Node;
	node->str = str;
	node->frequancy = freq;
	node->left = left;
	node->right = right;
	return node;
}
void HuffMan_Compression::encoding(Huffman_Node * root, string str, unordered_map<char, string>&Huffman)
{
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL)
	{
		Huffman[root->str] = str;
	}
	encoding(root->left, str + "0", Huffman);
	encoding(root->right, str + "1", Huffman);
}
void HuffMan_Compression::encode(string text)
{
	string str = "";
	unordered_map<char, string>Huffman;
	encoding(root, " ",Huffman);
	for (char ch : text)
	{
		str += Huffman[ch];
	}
	cout << str << endl;
}
void HuffMan_Compression::decoding(Huffman_Node * root, int &index, string str)
{
	if (root == NULL)
	{
		return;
	}
	if (root->left ==  NULL && root->right == NULL)
	{
		cout << root->str;
		return;
	}
	index++;
	if (index == str.size() - 2)
	{
		return;
	}
	if (str[index] == '0')
	{
		decoding(root->left, index, str);
	}
	else
	{
		decoding(root->right, index, str);
	}
}
void HuffMan_Compression::decode(string text)
{
	int index = -1;
	while (index < (int)text.size() - 2)
	{
		decoding(root, index, text);
	}
	cout <<endl;
}