#include <windows.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<string> PyramidSplitString(string str, string delim) // splits a string based on the deliminator seperating them
{
	vector<string> finalstring;
	size_t start = 0, end = 0;
	while ((end = str.find(delim, start)) != string::npos)
	{
		finalstring.push_back(str.substr(start, end - start));
		start = end + 1;
	}
	finalstring.push_back(str.substr(start));
	return finalstring;
}
