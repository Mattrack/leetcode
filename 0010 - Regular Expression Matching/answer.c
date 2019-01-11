#include <stdbool.h>
#include <string.h>

bool isMatch(char* s, char* p)
{
	bool first_match = (s[0] && (p[0] == s[0] || p[0] == '.'));

	if (!p[0])
		return (s[0] == 0);

	if (strlen(p) >= 2 && p[1] == '*')
		return (isMatch(s, p + 2) || (first_match && isMatch(s + 1, p)));
	else
		return first_match && isMatch(s + 1, p + 1);
}
