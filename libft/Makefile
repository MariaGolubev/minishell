NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3

OBJDIR = objs

AR = ar rcs

INC = libft.h

SRCS = ft_strlen.c ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
	ft_striteri.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_strcmp.c ft_atof.c ft_atoc.c ft_isspace.c ft_islower.c ft_isupper.c \
	ft_strtod.c ft_strtol.c ft_strjoin_with.c

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

COLOR_RED   = \033[31m
COLOR_GREEN = \033[32m
COLOR_END   = \033[0m
CURSOR_HIDE   = \033[?25l
CURSOR_SHOW   = \033[?25h

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(CURSOR_HIDE)$@"
	@$(AR) $(NAME) $(OBJS) && \
	printf "\r$(COLOR_GREEN)$@$(COLOUR_END)\n$(CURSOR_SHOW)" || \
	printf "\r$(COLOR_RED)$@$(COLOUR_END)\n$(CURSOR_SHOW)"

$(OBJDIR)/%.o: %.c $(INC) | $(OBJDIR)
	@printf "$(CURSOR_HIDE)$@"
	@$(CC) $(CFLAGS) -c $< -o $@ && \
	printf "\r$(COLOR_GREEN)$@$(COLOUR_END)\n$(CURSOR_SHOW)" || \
	printf "\r$(COLOR_RED)$@$(COLOUR_END)\n$(CURSOR_SHOW)"
$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -fr $(OBJDIR)

fclean: clean
	rm -f $(NAME) libft.so

re : fclean all

.PHONY: all clean fclean re
