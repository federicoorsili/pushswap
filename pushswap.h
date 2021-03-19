#ifndef H_PUSHSWAP
# define H_PUSHSWAP

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"

# define FBLACK      "\033[30m"
# define FRED        "\033[31m"
# define FGREEN      "\033[32m"
# define FYELLOW     "\033[33m"
# define FBLUE       "\033[34m"
# define FPURPLE     "\033[35m"
# define D_FGREEN    "\033[6m"
# define FWHITE      "\033[7m"
# define BBLACK      "\e[40m"
# define BRED        "\e[41m"
# define BGREEN      "\e[42m"
# define BYELLOW     "\e[43m"
# define BBLUE       "\e[44m"
# define BPURPLE     "\e[45m"
# define D_BGREEN    "\e[46m"
# define BWHITE      "\e[47m"
# define FCYAN       "\x1b[36m"
# define NONE        "\033[0m"
# define MIN_INT -2147483648
# define MAX_INT 2147483647
# define MOVES_SIZE 11

typedef struct		s_stack
{
	int				len;
	int				*stack;
	int				*indexed;
}					t_stack;

typedef struct		s_h
{
	int				*solution[10000];
	char			mov[11][3];
}					t_h;

void				do_sasb(t_stack *stack);
void				do_ss(t_stack *stack_a, t_stack *stack_b);
void				shift_stack(t_stack *stack, int mod);
void				shift_rev_stack(t_stack *stack, int mod);
void				do_push(t_stack *stack_a, t_stack *stack_b);
void				rotate_one_stack(t_stack *stack);
void				rotate_two_stack(t_stack *stack_a, t_stack *stack_b);
void				rotate_rev_one_stack(t_stack *stack);
void				rotate_rev_two_stack(t_stack *stack_a, t_stack *stack_b);
char				**define_moves(void);
void				move(t_stack *stack_a, t_stack *stack_b, char *move);
void				print_stack(t_stack *stack_a, t_stack *stack_b);
void				algorithm(t_stack *stack_a, t_stack *stack_b);

#endif