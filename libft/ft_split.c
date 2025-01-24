/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:10:44 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/06 00:32:19 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	ft_words_counter(const char *s, char c)
{
	unsigned int	i;
	unsigned int	in_word;
	unsigned int	counter;

	i = 0;
	in_word = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			in_word = 1;
			counter++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (counter);
}

static unsigned int	ft_get_word_len(const char *s, char c)
{
	unsigned int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*ft_get_next_word(const char *s, char c, unsigned int *i)
{
	unsigned int	len;
	char			*word;

	while (s[*i] && s[*i] == c)
		(*i)++;
	if (!s[*i])
		return (NULL);
	len = ft_get_word_len(&s[*i], c);
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, &s[*i], len + 1);
	*i += len;
	return (word);
}

static int	ft_check_word(char *word, char **words, unsigned int index)
{
	if (!word)
	{
		while (index > 0)
			free(words[--index]);
		free(words);
		return (0);
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	unsigned int	i;
	unsigned int	index;
	unsigned int	wc;
	char			**words;
	char			*word;

	if (!s)
		return (NULL);
	wc = ft_words_counter(s, c);
	words = ft_calloc(wc + 1, sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	index = 0;
	while (index < wc)
	{
		word = ft_get_next_word(s, c, &i);
		if (!ft_check_word(word, words, index))
			return (NULL);
		words[index++] = word;
	}
	words[index] = NULL;
	return (words);
}
