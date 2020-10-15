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

#include <ft_errno.h>
#include <stddef.h>

/*
 * Error value
 */
int		g_errno = DEFAULT;

/*
 * Set g_errno value
 *
 * @param  int  error value
 * @return void no return
 */
void	set_errno(int errno_value) {
	g_errno = errno_value;
}

/*
 * Get value of g_errno
 *
 * @param  void
 * @return int  value of g_errno
 */
int		get_errno(void) {
	return (g_errno);
}

/*
 * List of error strings
 */
static t_error_list	g_error_list[] = {
	{PIPE_ERROR, "Can't create pipe"},
	{CLOSE_ERROR, "Can't close file or file doesn't exist"},
	{DUP_ERROR, "Can't create new file descriptor"},
	{DUP2_ERROR, "Can't create new file descriptor"},
	{MALLOC_ERROR, "Can't allocate memory"},
	{SIGNAL_ERROR, "Can't catch user signal"}
};

/*
 * Get error string message
 *
 * @param  int    error value
 * @return char * message string
 */
char	*ft_strerror(int errno_value) {
	size_t j = 0;

	while (j < sizeof(g_error_list) / sizeof(g_error_list[0])) {
		if (errno_value == g_error_list[j].index) {
			return (g_error_list[j].error_str);
		}
		j++;
	}
	return ("Unknown error");
}
