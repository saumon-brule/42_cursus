/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:45:51 by ebini             #+#    #+#             */
/*   Updated: 2025/01/13 22:34:49 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# include <defs.h>

/*************************************************/
/*                   CONVERTER                   */
/*************************************************/

/**
 * @brief Will parse a string into an int
 * @param nptr Pointer of the first character of the string to parse
 * @note This function will accept one '+' or '-' optional character for the 
 * sign before the number and as many whitespaces as you want before the
 * sign. It will also stop to parse at the first non-digit character found
 * after the sign.
 * @warning Any trying to parse a number bigger than INT_MAX or smaller than
 * INT_MIN will result in a overflow.
 * @return An int corresponding to the string passed in parameter.
 */
int			ft_atoi(const char *nptr);

/**
 * @brief Will convert an int into a allocated string.
 * @param n The number converted
 * @return An allocated string corresponding to the number passed in parameter.
 */
char		*ft_itoa(int n);

/*************************************************/
/*                  IDENTIFIERS                  */
/*************************************************/

/**
 * @brief Identify if a character is alphanumeric.
 * @param c the character to identify
 */
bool		ft_isalnum(int c);

/**
 * @brief Identify if a character is in the alphabet.
 * @param c the character to identify
 */
bool		ft_isalpha(int c);

/**
 * @brief Identify if a character is in the ascii table.
 * @param c the character to identify
 */
bool		ft_isascii(int c);

/**
 * @brief Identify if a character is a digit.
 * @param c the character to identify
 */
bool		ft_isdigit(int c);

/**
 * @brief Identify if a character is a lowercase letter.
 * @param c the character to identify
 */
bool		ft_islower(int c);

/**
 * @brief Identify if a character is printable.
 * @param c the character to identify
 */
bool		ft_isprint(int c);

/**
 * @brief Identify if a character is an uppercase letter.
 * @param c the character to identify
 */
bool		ft_isupper(int c);

/*************************************************/
/*                     LIST                      */
/*************************************************/

/**
 * @brief Will add a new t_list struct at the back of the list pointed by the
 * double pointer lst.
 * @param lst A double pointer to the first element of a list made of t_list
 * @param new A pointer to the first element of a list made of t_list
 * @note The parameter lst is a double pointer because in the case where it is
 * NULL, it will be replaced by the new pointer.
 */
void		ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Will add a new t_list struct at the front of the list pointed by the
 * double pointer lst.
 * @param lst A double pointer to the first element of a list made of t_list
 * @param new A pointer to a t_list element added at the front of lst
 * @note The parameter lst is a double pointer because the first element of the
 * list lst will be replaced by the first element of the list new
 */
void		ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Will free all element composing a list made of t_list.
 * @param lst A double pointer to the list that needs to be freed
 * @param del A function that will free the element stored in each list node
 * @note The value of *lst will be replaced by NULL
 */
void		ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Delete and free the content of one node of a list.
 * @param lst The node to delete
 * @param del The function to free the content of the node
 */
void		ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Apply the function f to the content of every node of the list lst.
 * @param lst The first node of a listto iter through
 * @param f The funciton to call with the content of every node
 */
void		ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Duplicate the list lst and update the content of every node with the
 * function f.
 * @param lst The first node of the list to map
 * @param f The function to apply on the content of every node
 * @param del The function used to free the content of nodes if a malloc fails
 * @note Every memory allocation of this function is secure meaning that if one
 * of the many malloc returns NULL, all the new created list will be freed
 * @return The same list as lst but updated by the function f.
 */
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Creates a new node of t_list.
 * @param content The the content that will be contained by the list node
 * @return A pointer on a new node of a list.
 */
t_list		*ft_lstnew(void *content);

/**
 * @brief Calculate the length of a list made of t_list nodes.
 * @param lst A pointer on the first element of a list
 * @return The length of the list starting by lst.
 */
size_t		ft_lstsize(t_list *lst);

/*************************************************/
/*                     MATH                      */
/*************************************************/

// "Maths" is maybe a bit presomptuous

/**
 * @brief Give you the biggest number of an array arr of n element.
 * @param arr An array of int
 * @param n The length of the array
 * @return The biggest int of the array.
 */
int			arrmax(int *arr, size_t n);

/**
 * @brief Give you the smallest number of an array arr of n element.
 * @param arr An array of int
 * @param n The length of the array
 * @return The smallest int of the array.
 */
int			arrmin(int *arr, size_t n);

/**
 * @brief Returns the biggest number between a and b.
 * @param a An int
 * @param b An other int
 * @return The biggest int.
 */
int			max(int a, int b);

/**
 * @brief returns the smallest number between a and b
 * @param a an int
 * @param b an other int
 * @return the smallest int
 */
int			min(int a, int b);

/*************************************************/
/*                    MEMORY                     */
/*************************************************/

/**
 * @brief set n bytes of the the memory to 0 starting at the location pointed
 * by s.
 * @param s Pointer of the first element of the memory to erase
 * @param n The number of bytes set to 0
 */
void		ft_bzero(void *s, size_t n);

/**
 * @brief Allocate nmemb followed area of size size in the memory
 * (basically nmemb * size) and set them to 0.
 * @param nmemb The number of element to allocate
 * @param size The size of the elements
 * @return A void pointer on the first element allocated in the memory.
 */
void		*ft_calloc(size_t nmemb, size_t size);

/**		
 * @brief Look in the memory starting at the adress pointed by s of size n for
 * a byte of value c.
 * @param s A pointer to an area of the memory where we will search a value
 * @param c The value to search
 * @param n The size of the memory
 * @return A void pointer on the first byte corresponding to c (or NULL if
 * nothing was found).
 */
void		*ft_memchr(const void *s, int c, size_t n);

/**		
 * @brief Gives the difference between 2 memory areas
 * @param s1 A pointer to an area of the memory where we will search a value
 * @param s2 The value to search
 * @param n The size to compare
 * @return The difference between the first different bytes between in s1 and
 * s2 or 0 if the n bytes of s1 and s2 are identicals.
 */
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Copy n bytes of the memory from src to dest.
 * @param src A pointer to the first byte of the source memory area
 * @param dest A pointer to the first byte of the destination memory area
 * @param n The number of bytes to copy
 * @note If the src and dest are overlapping use ft_memmove instead
 * @return dest
 */
void		*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Move n bytes of the memory from src to dest (overlapping safe).
 * @param src A pointer to the first of the source memory area
 * @param dest A pointer to the first of the destination memory area
 * @param n The number of bytes to move
 * @note This function handle memory overlapping meaning that src might be
 * modified but dest will always contain what was in src.
 * @return dest
 */
void		*ft_memmove(const void *src, void *dest, size_t n);

/**
 * @brief Set n bytes of the memory from s to the value c.
 * @param s A pointer to the first of the memory area to set
 * @param c The value to set in the memory
 * @param n The number of bytes to set
 * @return s
 */
void		*ft_memset(void *s, int c, size_t n);

/*************************************************/
/*                    STRING                     */
/*************************************************/

char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_strcpy(const char *src, char *dest);
void		ft_strncpy(const char *src, char *dest, size_t n);
char		*ft_strdup(const char *s);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
int			ft_tolower(int c);
int			ft_toupper(int c);

/**
 * @brief Will try to behave as a simple printf, handling flags csuihHp%
 */
int			ft_printf(const char *arg, ...) __attribute__((format(printf, 1, 2)));

char		*get_next_line(int fd);

# define LIBFT_H
#endif