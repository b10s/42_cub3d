NAME = libft
CC = cc
INC_DIR = include
LIBFT_DIR = ./
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)

LST_DIR = ./ft_lst/
PRINTF_DIR = ./ft_printf/

SRCS_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c  ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c  ft_putnbr_fd.c \
ft_atoi_with_error.c \
#ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c\
ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
ft_lstiter_bonus.c ft_lstmap_bonus.c 

LST_FILES = ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c\
ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
ft_lstiter_bonus.c ft_lstmap_bonus.c 

PRINTF_FILES = ft_printf.c ft_print_string.c ft_print_hex.c 
#ft_printf_itoa.c \


SRCS = $(SRCS_FILES)
LST_SRCS = $(addprefix $(LST_DIR), $(LST_FILES))
PRINTF_SRCS = $(addprefix $(PRINTF_DIR), $(PRINTF_FILES))
OBJS = $(SRCS:.c=.o) $(LST_SRCS:.c=.o) $(PRINTF_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $@

$(LIBFT_DIR)%.o: $(LIBFT_DIR)%.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@

$(LST_DIR)%.o: $(LST_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF_DIR)%.o: $(PRINTF_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
#del /Q $(subst /,\,$(NAME))
	rm -f $(NAME)

re: fclean all

bonus:
	make WITH_BONUS=1 all

.PHONY: all clean fclean re bonus