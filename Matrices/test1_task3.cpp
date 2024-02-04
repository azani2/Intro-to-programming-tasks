#include <iostream>
using namespace std;

void concatChar_s(char* s1, const size_t MAX_SIZE, char* s2) {
	while (*s1)
	{
		s1++;
	}
	while (*s2)
	{
		if (*s2 >= 'a' && *s2 <= 'z' || *s2 >= 'A' && *s2 <= 'Z')
		{
			*s1 = *s2;
			s1++;
		}
		s2++;
	}
	*s1 = '\0';
}

int main()
{
	const size_t MAX_SIZE = 1024;
	char s1[MAX_SIZE];
	char s2[MAX_SIZE];
	cout << "String 1: ";
	cin >> s1;
	cout << "String 2: ";
	cin >> s2;

	int s1len = strlen(s1);
	int s2len = strlen(s2);
	if (s2len > (1024 - s1len))
		return -1;
	concatChar_s(s1, MAX_SIZE, s2);
	cout << s1;
}