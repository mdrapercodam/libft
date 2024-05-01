/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 11:24:37 by mdraper       #+#    #+#                 */
/*   Updated: 2024/05/01 16:09:33 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdbool.h>
# include <signal.h>
# include <sys/types.h>

/* *****************||***************** */
/* 			   	  LIBFT					*/
/* *****************||***************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*				  FT_IS					*/
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_iscntrl(int c);
int		ft_isdigit(int c);
int		ft_isgraph(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_ispunct(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_isxdigit(int c);

/*				  FT_LIS				*/
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

/*				  FT_MEM				*/
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

/*				  FT_PUT				*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*				  FT_STR				*/
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*				  FT_TO					*/
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		ft_numlen(long nbr, int base);
int		ft_tolower(int c);
int		ft_toupper(int c);

/* *****************||***************** */
/* 			    FT_PRINTF				*/
/* *****************||***************** */

int		ft_printf(const char *str, ...);
int		ft_printchar(char c);
int		ft_printstring(char *str);
int		ft_printdigit(int n);
int		ft_printunsigned(unsigned int n);
int		ft_printhexadecimal(unsigned long n, int hex);
int		ft_printpointer(unsigned long nptr);

/* *****************||***************** */
/* 			   GET_NEXT_LINE			*/
/* *****************||***************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
void	ft_fn(char **ptr);
int		ft_pos(char *str, int c);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_strdup(char *buf);
char	*ft_read_file(int fd, char **line, char **rem, char *buf);

/* *****************||***************** */
/* 			   	 PUSH_SWAP				*/
/* *****************||***************** */

typedef struct s_pslist
{
	int				data;
	struct s_pslist	*next;
	struct s_pslist	*prev;
}	t_pslst;

/*				  ALGORITHM				*/
void	ft_algorithm(t_pslst **stk_a, t_pslst **stk_b);
void	ft_sort_small(t_pslst **stk_a, t_pslst **stk_b, int nds_a, int nds_b);
int		ft_count_moves(t_pslst **stk_a, t_pslst **stk_b, int pos, int idx_a);
int		ft_cheapest(t_pslst **stk_a, t_pslst **stk_b, t_pslst **push_node);
int		ft_multiple_ops(t_pslst **stk_a, t_pslst **stk_b, int nmbr, char *ops);
int		ft_find_rotate(t_pslst **stk_a, t_pslst **stk_b, int idx_a, int idx_b);
void	ft_push_b(t_pslst **stk_a, t_pslst **stk_b, t_pslst *push, int moves);
void	ft_push_a(t_pslst **stk_a, t_pslst **stk_b);
void	ft_sort_two(t_pslst **stk_a, t_pslst **stk_b, int stack);
void	ft_sort_three(t_pslst **stk_a, t_pslst **stk_b, int stack);
void	ft_rotate_sort(t_pslst **stk_a, t_pslst **stk_b, bool ascending);

/*				    INPUT				*/
int		ft_check_string(const char *str);
int		ft_check_spaces(const char *str);
int		ft_check_valid_int(const char *str);
int		ft_check_value(t_pslst **head, int data);
void	ft_free_lists(t_pslst **stk_a, t_pslst **stk_b, int err);
void	ft_free_split(char **split, t_pslst **stk_a, t_pslst **stk_b, int err);
int		ft_make_list(t_pslst **stk_a, int data);
void	ft_split_string(t_pslst **stk_a, t_pslst **stk_b, const char *str);
void	ft_handle_input(t_pslst **stk_a, t_pslst **stk_b, const char *str);

/*				  OPERATIONS			*/
int		ft_pa(t_pslst **stk_a, t_pslst **stk_b, int print);
int		ft_pb(t_pslst **stk_a, t_pslst **stk_b, int print);
int		ft_rra(t_pslst **stk_a, int print);
int		ft_rrb(t_pslst **stk_b, int print);
int		ft_rrr(t_pslst **stk_a, t_pslst **stk_b, int print);
int		ft_ra(t_pslst **stk_a, int print);
int		ft_rb(t_pslst **stk_b, int print);
int		ft_rr(t_pslst **stk_a, t_pslst **stk_b, int print);
int		ft_sa(t_pslst **stk_a, int print);
int		ft_sb(t_pslst **stk_b, int print);
int		ft_ss(t_pslst **stk_a, t_pslst **stk_b, int print);

/*				   UTILS				*/
int		ft_count_nodes(t_pslst *stack);
int		ft_count_n_nodes(t_pslst *stack, int n);
t_pslst	*ft_find_max_or_min(t_pslst *stack, bool max);
int		ft_find_position(t_pslst *stack, int nmbr, bool asc);
int		ft_find_index(t_pslst *stack, t_pslst *node);
int		ft_issorted(t_pslst *stack, bool ascending);
int		ft_check_issorted(t_pslst *stack, bool ascending);

/*			    VISUALISATION			*/
void	ft_print_stack(t_pslst *head);
void	ft_print_stacks(t_pslst *stk_a, t_pslst *stk_b);

/*			     EXECUTABLES			*/
int		ft_checker_push_swap(int argc, char const *argv[]);
int		ft_push_swap(int argc, char const *argv[]);

/* *****************||***************** */
/* 				 Minitalk				*/
/* *****************||***************** */

/*				  SERVER				*/
void	ft_print_bits(char recieved_char, int bit_index);
void	ft_send_signal_to_client(pid_t client_pid, int signal);
char	ft_signal_to_bit(int sig);
void	ft_signal_handler(int sig, siginfo_t *info, void *context);
int		ft_server_minitalk(void);

/*				  CLIENT				*/
void	ft_signal_server_received(int sig);
void	ft_waiting_for_signal(void);
void	ft_send_bit(pid_t server_pid, int bit);
void	ft_send_character(pid_t server_pid, char c);
int		ft_client_minitalk(int argc, char *argv[]);

/*				  ERROR				*/
void	ft_minitalk_errors(int error_nmbr);

#endif
