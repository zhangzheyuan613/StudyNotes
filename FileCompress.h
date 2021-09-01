#pragma once
#include<iostream>
#include<string>
#include"HuffmanTree.hpp"
using namespace std;

typedef unsigned char u_char;

struct ByteInfo
{
	u_char ch;//字节字符
	int appearCount;//ch字节出现次数
	string strCode;//ch字节对应编码

	ByteInfo(int count=0)
		:appearCount(count)
	{}	
	ByteInfo operator+(const ByteInfo& b )const
	{
		ByteInfo temp;
		temp.appearCount = appearCount + b.appearCount;	
		return temp;
	}
	bool operator>(const ByteInfo& b)const
	{
		return appearCount > b.appearCount;
	}
	bool operator!=(const ByteInfo& b)const
	{
		return appearCount != b.appearCount;
	}
	bool operator==(const ByteInfo& b)const
	{
		return appearCount == b.appearCount;
	}
};
class FileCompress
{
public:
	FileCompress();
	bool CompressFile(const string& filePath);
	bool UNCompressFile(const string& filePath);

private:
	void GetLine(FILE* fIn, string& strContent);
	void GenerateHuffmanCode(HuffmanTreeNode<ByteInfo>* root);
	void WriteHead(FILE* fOut,const string& filePath);

	ByteInfo fileByteInfo[256];//保存ch字节出现的频次信息 
};
