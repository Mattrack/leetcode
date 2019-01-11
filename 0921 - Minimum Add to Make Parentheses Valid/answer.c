int minAddToMakeValid(char const *s)
{
	int total = 0;
	int depth = 0;
	int index;

	for (index = 0; s && s[index]; index++)
	{
		if (s[index] == '(')
			depth++;
		else
		{
			if (depth == 0)
				total++;
			else
				depth--;
		}
	}

	return (total + depth);
}
