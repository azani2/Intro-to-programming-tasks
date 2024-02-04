#include <iostream>
#include <stack>

bool readLetter(std::stack<char>& letters, char letter, std::stack<char>& store) {
	while (!letters.empty()) {
		char top = letters.top();
		letters.pop();
		if (top != letter) store.push(top);
		else return true;
	}
	return false;
}

template<typename T>
void pushAll(std::stack<T>& destination, std::stack<T> source) {
	while (!source.empty()) {
		destination.push(source.top());
		source.pop();
	}
}

bool readAndDelete(std::stack<char>& letters, std::string word) {
	int length = word.length();
	std::stack<char> toKeep;
	for (int i = 0; i < length; i++)
	{
		if (!readLetter(letters, word[i], toKeep)) {
			pushAll(letters, toKeep);
			return false;
		}
	}
	
	pushAll(letters, toKeep);
	return true;
}

template<typename T>
void print(std::stack<T> stack) {
	while (!stack.empty()) {
		std::cout << stack.top() << " ";
		stack.pop();
	}
}

int main() {
	std::stack<char> letters1;
	letters1.push('o');
	letters1.push('m');
	letters1.push('o');
	letters1.push('o');
	letters1.push('f');
	letters1.push('m');
	std::cout << readAndDelete(letters1, "mom") << " | ";
	print(letters1);
	std::cout << std::endl;

	std::stack<char> letters2;
	letters2.push('y');
	letters2.push('a');
	letters2.push('d');
	letters2.push('c');
	letters2.push('c');
	std::cout << readAndDelete(letters2, "car") << " | ";
	print(letters2);
	std::cout << std::endl;
}