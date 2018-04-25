#include <algorithm>
#include <iostream>
#include <vector>
#include<stack>
#include<fstream>
#include<string>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif
/*#ifdef _WIN32
#define SYSPAUSE system("pause")
#endif
*/

class Node;

class Node {
public:
	int key;
	Node *parent;
	std::vector<Node *> children;

	Node() {
		this->parent = NULL;
	}

	void setParent(Node *theParent) {
		parent = theParent;
		parent->children.push_back(this);
	}
};


void node_height(std::stack<int> *height,Node *p,int h) {
//	std::cout << p->key; //test
	(*height).push(h + 1);//store h
//	std::cout << height.top() << " "; //test
	for (int i = 0; i< (p->children.size()) ;++i)//while children !=null 
	{
		
		node_height(height, p->children[i], h + 1);//move to child
	

	}
	}




int main_with_large_stack_space() {
	
	
	//standerd input , submit
	std::ios_base::sync_with_stdio(0);//??
	int n;
	std::cin >> n;
	//construction of tree
	std::vector<Node> nodes;//vector
	nodes.resize(n);
	Node* root = NULL;
	for (int child_index = 0; child_index < n; child_index++) {
		int parent_index;
		std::cin >> parent_index;
		if (parent_index >= 0)
		{
			nodes[child_index].setParent(&nodes[parent_index]);
		}
		else
		{
			root = &nodes[child_index];
		}
		nodes[child_index].key = child_index;
	}
	
	




	
	// Replace this code with a faster implementation
	
	int maxHeight = 0;
	//create stack heights
	std::stack<int>heights;
	//call function nodes height 
	node_height(&heights, root, maxHeight);
	//search in stack and return maximum of it 
	while (heights.empty()==0) {
		//std::cout << heights.top() << " "; //test
		maxHeight = std::max(maxHeight, heights.top());
		heights.pop();
	}
	
	
		

	

	std::cout << maxHeight << std::endl;
	//SYSPAUSE;
	return 0;
}


int main(int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
	// Allow larger stack space
	const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
	struct rlimit rl;
	int result;

	result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0)
	{
		if (rl.rlim_cur < kStackSize)
		{
			rl.rlim_cur = kStackSize;
			result = setrlimit(RLIMIT_STACK, &rl);
			if (result != 0)
			{
				std::cerr << "setrlimit returned result = " << result << std::endl;
			}
		}
	}

#endif

return main_with_large_stack_space();
}
