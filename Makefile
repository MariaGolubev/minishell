NAME = minishell

CC = cc
CFLAGS = -Wextra -Werror -Wall #-g3 -fsanitize=address,undefined,leak
LIBFLAGS = -lreadline -ltinfo

INCLUDE = include

HEADERSFILE = token.h lexer.h libft.h minishell.h parser.h executer.h

HEADERS = $(HEADERSFILE:%=$(INCLUDE)/%)

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

SRCDIR = src
OBJDIR = objs

SRCDIR_TOKEN = $(SRCDIR)/token
OBJDIR_TOKEN = objs_token

SRCDIR_LEXER = $(SRCDIR)/lexer
OBJDIR_LEXER = objs_lexer

SRCDIR_AST = $(SRCDIR)/ast
OBJDIR_AST = objs_ast

SRCDIR_PARSER = $(SRCDIR)/parser
OBJDIR_PARSER = objs_parser

SRCDIR_ENV = $(SRCDIR)/env
OBJDIR_ENV = objs_env

SRCDIR_EXECUTER = $(SRCDIR)/executer
OBJDIR_EXECUTER = objs_executer

SRC = main.c fn_mshell_executer.c \
	fn_mshell_lexer.c fn_mshell_parser.c fn_mshell_redline.c \
	fn_mshell_start.c fn_mshell_clean.c mshell_utils.c

SRC_TOKEN = fn_token_add.c fn_tokens_foreach.c fn_tokens_clean.c \
	fn_token_last.c fn_token_new.c

SRC_LEXER = fn_lexer.c fn_lexer_start.c fn_lexer_word.c \
	fn_lexer_redirect.c fn_lexer_pipe_or.c fn_lexer_semicolon.c \
	fn_lexer_quote.c fn_lexer_escape.c \
	fn_lexer_variable.c fn_lexer_comment.c fn_lexer_next_state.c \
	fn_lexer_and_background.c fn_lexer_assign.c fn_lexer_nl.c

SRC_AST = fn_ast_value_new.c fn_ast_value_append.c fn_ast_value_free.c \
	fn_ast_node_new.c fn_ast_node_free.c \
	fn_ast_node_redin_new.c fn_ast_node_redout_new.c \
	fn_ast_node_append_new.c fn_ast_node_argument_new.c \
	fn_ast_node_setvar_new.c fn_ast_node_foreach.c \
	fn_ast_node_append.c fn_ast_node_command_new.c \
	fn_ast_node_pipe_new.c fn_ast_node_and_new.c \
	fn_ast_node_or_new.c fn_ast_node_heredoc_new.c \
	fn_ast_node_depth.c fn_ast_node_semicolon_new.c

SRC_PARSER = fn_parser.c fn_parse_cmdline.c fn_parse_cmdline_next_state.c \
	fn_parse_cmdline_cmd.c fn_parse_cmdline_redirect.c \
	fn_parse_cmdline_heredoc.c fn_parse_cmdline_arg.c \
	fn_parse_cmdline_setenv.c fn_parser_utils.c fn_parse_and_or.c \
	fn_parse_pipe.c fn_parse_semicolon.c

SRC_ENV = fn_env_node_init.c fn_env_node_set.c fn_env_to_array.c fn_envs_clean.c \
	fn_env_node_append.c fn_env_node_free.c fn_env_node_get_value.c fn_env_node_new.c \
	fn_envs_new.c fn_envs_to_array.c fn_envs_get_value.c fn_envs_set_status.c \
	fn_envs_export.c

SRC_EXECUTER = executer_utils.c fn_exec_and.c fn_exec_append.c fn_exec_cmd.c \
	fn_exec_heredoc.c fn_exec_or.c fn_exec_pipe.c fn_exec_recursive.c \
	fn_exec_redin.c fn_exec_redout.c fn_exec_setvar.c fn_execute.c \
	fn_executer_clean.c fn_executer_init.c fn_exec_semicolon.c \
	fn_exec_builtins_or_cmd.c fn_builtin_exit.c fn_builtin_pwd.c \
	fn_builtin_export.c fn_ast_values_to_str.c fn_builtin_cd.c \
	cd_utils.c fn_builtin_env.c fn_builtin_unset.c fn_builtin_echo.c \
	signals.c fn_double_quote_to_str.c fn_builtin_export_print.c

OBJ = $(SRC:%.c=$(OBJDIR)/%.o) \
	$(SRC_TOKEN:%.c=$(OBJDIR_TOKEN)/%.o) \
	$(SRC_LEXER:%.c=$(OBJDIR_LEXER)/%.o) \
	$(SRC_AST:%.c=$(OBJDIR_AST)/%.o) \
	$(SRC_PARSER:%.c=$(OBJDIR_PARSER)/%.o) \
	$(SRC_ENV:%.c=$(OBJDIR_ENV)/%.o) \
	$(SRC_EXECUTER:%.c=$(OBJDIR_EXECUTER)/%.o)

all: $(NAME) print_ascii

COLOR_RED   = \033[31m
COLOR_GREEN = \033[32m
COLOR_END   = \033[0m
CURSOR_HIDE   = \033[?25l
CURSOR_SHOW   = \033[?25h

$(NAME): $(OBJ) $(LIBFT)
	@printf "$(CURSOR_HIDE)$@"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFLAGS) $(LIBFT) -o $@ && \
	printf "\r$(COLOR_GREEN)$@$(COLOUR_END)\n$(CURSOR_SHOW)" || \
	printf "\r$(COLOR_RED)$@$(COLOUR_END)\n$(CURSOR_SHOW)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) Makefile | $(OBJDIR)
	@printf "$(CURSOR_HIDE)$@"
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@ && \
	printf "\r$(COLOR_GREEN)$@$(COLOUR_END)\n$(CURSOR_SHOW)" || \
	printf "\r$(COLOR_RED)$@$(COLOUR_END)\n$(CURSOR_SHOW)"

$(OBJDIR_TOKEN)/%.o: $(SRCDIR_TOKEN)/%.c $(HEADERS) Makefile | $(OBJDIR_TOKEN)
	@printf "$(CURSOR_HIDE)$@"
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@ && \
	printf "\r$(COLOR_GREEN)$@$(COLOUR_END)\n$(CURSOR_SHOW)" || \
	printf "\r$(COLOR_RED)$@$(COLOUR_END)\n$(CURSOR_SHOW)"

$(OBJDIR_LEXER)/%.o: $(SRCDIR_LEXER)/%.c $(HEADERS) Makefile | $(OBJDIR_LEXER)
	@printf "$(CURSOR_HIDE)$@"
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@ && \
	printf "\r$(COLOR_GREEN)$@$(COLOUR_END)\n$(CURSOR_SHOW)" || \
	printf "\r$(COLOR_RED)$@$(COLOUR_END)\n$(CURSOR_SHOW)"

$(OBJDIR_AST)/%.o: $(SRCDIR_AST)/%.c $(HEADERS) Makefile | $(OBJDIR_AST)
	@printf "$(CURSOR_HIDE)$@"
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@ && \
	printf "\r$(COLOR_GREEN)$@$(COLOUR_END)\n$(CURSOR_SHOW)" || \
	printf "\r$(COLOR_RED)$@$(COLOUR_END)\n$(CURSOR_SHOW)"

$(OBJDIR_PARSER)/%.o: $(SRCDIR_PARSER)/%.c $(HEADERS) Makefile | $(OBJDIR_PARSER)
	@printf "$(CURSOR_HIDE)$@"
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@ && \
	printf "\r$(COLOR_GREEN)$@$(COLOUR_END)\n$(CURSOR_SHOW)" || \
	printf "\r$(COLOR_RED)$@$(COLOUR_END)\n$(CURSOR_SHOW)"

$(OBJDIR_ENV)/%.o: $(SRCDIR_ENV)/%.c $(HEADERS) Makefile | $(OBJDIR_ENV)
	@printf "$(CURSOR_HIDE)$@"
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@ && \
	printf "\r$(COLOR_GREEN)$@$(COLOUR_END)\n$(CURSOR_SHOW)" || \
	printf "\r$(COLOR_RED)$@$(COLOUR_END)\n$(CURSOR_SHOW)"

$(OBJDIR_EXECUTER)/%.o: $(SRCDIR_EXECUTER)/%.c $(HEADERS) Makefile | $(OBJDIR_EXECUTER)
	@printf "$(CURSOR_HIDE)$@"
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@ && \
	printf "\r$(COLOR_GREEN)$@$(COLOUR_END)\n$(CURSOR_SHOW)" || \
	printf "\r$(COLOR_RED)$@$(COLOUR_END)\n$(CURSOR_SHOW)"

$(LIBFT):
	@$(MAKE) -s -C $(LIBFTDIR)

$(OBJDIR):
	@mkdir -p $@

$(OBJDIR_TOKEN):
	@mkdir -p $@

$(OBJDIR_LEXER):
	@mkdir -p $@

$(OBJDIR_AST):
	@mkdir -p $@

$(OBJDIR_PARSER):
	@mkdir -p $@

$(OBJDIR_ENV):
	@mkdir -p $@

$(OBJDIR_EXECUTER):
	@mkdir -p $@

clean:
	@rm -rf obj*
	@$(MAKE) -s -C $(LIBFTDIR) clean
	@printf "Object files are removed\n"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFTDIR) fclean
	@printf "$(NAME) is removed\n"

COLOUR_RED = \033[38;5;196m
COLOUR_ORANGE = \033[38;5;214m
COLOUR_YELLOW = \033[38;5;226m
COLOUR_GREEN = \033[38;5;46m
COLOUR_BLUE = \033[38;5;21m
COLOUR_PURPLE = \033[38;5;201m
COLOUR_END = \033[0m

print_ascii:
	@printf "$(COLOUR_RED) __  __ ___ _   _ ___ ____  _   _ _____ _     _ \n"
	@printf "$(COLOUR_ORANGE)|  \/  |_ _| \ | |_ _/ ___|| | | | ____| |   | | \n"
	@printf "$(COLOUR_YELLOW)| |\/| || ||  \| || |\___ \| |_| |  _| | |   | | \n"
	@printf "$(COLOUR_GREEN)| |  | || || |\  || | ___| |  _  | |___| |___| |___\n"
	@printf "$(COLOUR_BLUE)|_|  |_|___|_| \_|___|____/|_| |_|_____|_____|_____|\n"
	@printf "$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re
