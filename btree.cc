#include<iostream>
#include<string>

//insert, delete, search
//order = t


struct btreeNode{

	struct oneVal{
	std::pair<int, std::string> keyVal;
	std::shared_ptr<btreeNode>left, right;
	};
	
	std::vector<oneVal>nodeData; //based on order, min ceil t-1/3, max t-1
};


