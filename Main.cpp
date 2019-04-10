#include <windows.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<string> PyramidSplitString(string str, char delim)
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

void Execute(string script) {
if (script.find("print") != -1) { // script containts print
	if (script.find("(") != -1) { // script contains (
		vector<string>printone = PyramidSplitString(script.c_str(), '('); // split (
		if (printone.at(1).find('"') != -1) { // script containts "
			vector<string>printtwo = PyramidSplitString(printone.at(1).c_str(), '"'); // split "
		PyramidGetglobal(PyramidLua, "print");
		PyramidPushstring(PyramidLua, printtwo.at(1).c_str());
		PyramidPCall(PyramidLua, 1, 0, 0);
			}
		}
	}
	if (script.find("warn") != -1) { // script containts print
	if (script.find("(") != -1) { // script contains (
		vector<string>printone = PyramidSplitString(script.c_str(), '('); // split (
		if (printone.at(1).find('"') != -1) { // script containts "
			vector<string>printtwo = PyramidSplitString(printone.at(1).c_str(), '"'); // split "
		PyramidGetglobal(PyramidLua, "warn");
		PyramidPushstring(PyramidLua, printtwo.at(1).c_str());
		PyramidPCall(PyramidLua, 1, 0, 0);
			}
		}
	}
}
