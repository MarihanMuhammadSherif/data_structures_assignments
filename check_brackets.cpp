#include <iostream>
#include <stack>
#include <string>
#include<fstream>

class Bracket {

	
public:
	char type;
	int position;
	Bracket(char type, int position) :
		type(type),
		position(position)
	{}

	
	bool Matchc(char c) {
		if (type == '[' && c == ']')
			return true;
		if (type == '{' && c == '}')
			return true;
		if (type == '(' && c == ')')
			return true;
		return false;
	}

	
};

int ismatched(std:: string text, std::stack <Bracket> opening_brackets_stack) {



	for (int position = 0; position < text.length(); ++position) {
		char next = text[position];

		if (next == '(' || next == '[' || next == '{') {
			// Process opening bracket
			//push to stack
			Bracket brac(next, position + 1);
			opening_brackets_stack.push(brac);
		}

		if (next == ')' || next == ']' || next == '}') {
			// Process closing bracket			
			//if stack==empty
			if (opening_brackets_stack.empty())
			{
				return position + 1;//return closing bracket position
			}
			
			//else pop
			else {
				Bracket top = opening_brackets_stack.top();
				opening_brackets_stack.pop();
				//if no match return closing bracket 
				if (!top.Matchc(next))
					return (position + 1);

			}
			

		}
	}
	//if stack not empty return positoon of top
	if (!opening_brackets_stack.empty())
	{
		Bracket top = opening_brackets_stack.top();
		return top.position;
	}
	else { return 0; }		//else return 0;
}

int main() {
	std::string text;
	/*std::ifstream infile("49.txt");
		
	if (infile.is_open())
	{
		infile >> text;
		infile.close();

	}
	else
		std::cout << "fail \n";
	
	*/
	getline(std::cin, text);

	
	std::stack <Bracket>
		opening_brackets_stack;
	int x=ismatched(text, opening_brackets_stack);
	if (x== 0)
	{		std::cout << "Success";
}
	else {
		std::cout << x;

	}
	
	// Printing answer, write your code here
	
	return 0;
}

