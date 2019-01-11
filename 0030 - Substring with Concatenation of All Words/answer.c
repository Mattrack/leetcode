#include <stdlib.h>
#include <string.h>

typedef struct node_s
{
	char const	*word;
	struct node_s	*prev;
	struct node_s	*next;
} node_t;

int find_all_words(char const *s, char const **words, int wordsSize)
{
	int i;
	node_t *lwords = NULL;

	for (i = 0; i < wordsSize; i++)
	{
		node_t *node = malloc(sizeof(*node));

		node->word = words[i];
		node->prev = NULL;
		node->next = lwords;
		if (node->next)
			node->next->prev = node;
		lwords = node;
	}

	while (lwords && s && *s)
	{
		node_t *node;
		int changed = 0;

		for (node = lwords; node; node = node->next)
		{
			if (strncmp(s, node->word, strlen(node->word)) == 0)
			{
				s += strlen(node->word);
				if (node->prev)
					node->prev->next = node->next;
				if (node->next)
					node->next->prev = node->prev;
				if (node == lwords)
					lwords = node->next;
				free(node);
				changed = 1;
			}
		}

		if (!changed)
			break;
	}

	return (!lwords);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findSubstring(char const *s, char const **words, int wordsSize, int *returnSize)
{
	int *indices = NULL;
	int i;

	*returnSize = 0;
	if (wordsSize == 0)
		return (NULL);
	for (i = 0; s && s[i]; i++)
	{
		if (find_all_words(s + i, words, wordsSize))
		{
			indices = realloc(indices, sizeof(*indices) * (*returnSize + 1));
			indices[*returnSize] = i;
			*returnSize += 1;
		}
	}

	return (indices);
}
