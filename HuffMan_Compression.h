#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
struct Huffman_Node
{
	int frequancy;
	char str;
	Huffman_Node * right;
	Huffman_Node * left;
};
class compare //  to compare the the higest frequqncy
{
public:
	bool operator()(Huffman_Node * left, Huffman_Node * right)
	{
		return (left->frequancy > right->frequancy);
	}
};
class HuffMan_Compression
{

private:
	Huffman_Node * root;
protected:
	Huffman_Node * get_node(char,int, Huffman_Node*,Huffman_Node*);
	void encoding(Huffman_Node*, string, unordered_map<char, string>&);
	void decoding(Huffman_Node *, int &, string);
public:
	HuffMan_Compression(string);
	void encode(string);
	void decode(string);
};

