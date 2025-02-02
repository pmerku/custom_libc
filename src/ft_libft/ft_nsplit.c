/* ************************************************************************** */
/*                                                                            */
/*   Project: custom_libc                                 ::::::::            */
/*   Members: dvoort, prmerku                           :+:    :+:            */
/*   Copyright: 2020                                   +:+                    */
/*                                                    +#+                     */
/*                                                   +#+                      */
/*                                                  #+#    #+#                */
/*   while (!(succeed = try()));                   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <ft_memory.h>

static int	count_words(const char *str, char delim, int max) {
	int		n = 0;
	char	in_word = 0;

	while (*str != '\0') {
		if (*str != delim && !in_word) {
			n++;
			in_word = 1;
		}
		if (*str == delim && in_word) {
			in_word = 0;
		}
		str++;
	}
	return (n > max ? max : n);
}

static char	read_word(const char *str, char delim, char **arr, int last) {
	size_t	len = 0;
	while (str[len] != '\0' && (str[len] != delim || last)) {
		len++;
	}
	char *word = ft_calloc(sizeof(char), (len + 1));
	if (!word) {
		return (0);
	}
	while (len > 0) {
		word[len - 1] = str[len - 1];
		len--;
	}
	arr[0] = word;
	return (1);
}

/*
 * Split a character array based on a delimiter, until the
 * end of the array or max number of splits.
 *
 * @param1  const char * array to split
 * @param2  char         delimiter to split on
 * @param3  int          max number of splits
 * @return  char **      2d sized array
 */
char		**ft_nsplit(const char *str, char delim, int max) {
	if (!str) {
		return (NULL);
	}
	int 	word_count = count_words(str, delim, max);
	char	**arr = ft_calloc(sizeof(char *), (word_count + 1));
	if (!arr) {
		return (NULL);
	}
	int n = 0;
	while (n < word_count) {
		while (*str == delim && *str != '\0') {
			str++;
		}
		if (!read_word(str, delim, arr + n, n == max - 1)) {
			return (ft_free_array(arr));
		}
		while (*str != delim && *str != '\0') {
			str++;
		}
		n++;
	}
	return (arr);
}
