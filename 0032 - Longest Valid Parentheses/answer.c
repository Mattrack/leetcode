int longestValidParentheses(char const *s)
{
	int depth = 0;
	int i;
	int max = 0;
	int next = 0;

	if (!s || !s[0] || !s[1])
		return (0);

	for (i = 0; s && s[i]; i++)
	{
		if (s[i] == ')')
			depth--;
		if (s[i] == '(')
			depth++;

		if (depth < 0)
			break;
		if (depth == 0)
			max = i + 1;
	}
	next = longestValidParentheses(s + 1);

	return (next > max ? next : max);
}
