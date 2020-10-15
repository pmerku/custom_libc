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

#ifdef __cplusplus
extern "C" {
#endif
#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>

/*
 * Get size of string
 *
 * @param   const char * string to calculate size
 * @return  size_t       calculated size
 */
extern size_t	ft_strlen(const char *s);

/*
 * Copy n bytes from src into dst
 *
 * @param1  void *       dst memory area
 * @param2  const void * src memory area
 * @param3  size_t       number of bytes to copy
 * @return  void *       pointer to dst
 */
extern void		*ft_memcpy(void *dst, const void *src, size_t n);

/*
 * Duplicate and allocate a new string
 *
 * @param   const char * string to duplicate
 * @return  char *       pointer to new allocated string
 */
extern char		*ft_strdup(const char *s);

/*
 * Compare two string
 *
 * @param1  const char * first string to compare
 * @param2  const char * second string to compare
 * @return  int          comparison difference
 */
extern int		ft_strcmp(const char *s1, const char *s2);

/*
 * Copy src string to dst buffer
 *
 * @param1  char *       string where to copy
 * @param2  const char * string to copy
 * @return  char *       pointer to dst string
 */
extern char 	*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
size_t 			ft_strlcpy(char *dst, const char *src, size_t size);

/*
 * Append src string to dst string
 *
 * @param1  char *       string where to append
 * @param2  const char * string to append
 * @return  char *       pointer to dst
 */
extern char		*ft_strcat(char *dst, const char *src);
char			*ft_strncat(char *dst, const char *src, size_t n);
size_t 			ft_strlcat(char *dst, const char *src, size_t size);

/*
 * Find first occurrence of c in s
 *
 * @param1  const char * string to search
 * @param2  int          character to find
 * @return  char *       pointer to the matched character
 */
extern char		*ft_strchr(const char *s, int c);

void			*ft_memset(void *s, int c, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);

/*
 * Find occurance of character c in no more than n bytes
 * in the memory pointer
 *
 * @param1  const void * pointer to memory to search
 * @param2  size_t       max bytes to search
 * @return  void *       pointer
 */
extern void		*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const	void *s1, const	void *s2, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strnlen(const char *s, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);

#endif
#ifdef __cplusplus
}
#endif
