# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avelandr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 12:30:28 by avelandr          #+#    #+#              #
#    Updated: 2025/03/07 20:19:10 by avelandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiladador y sus flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Libreria
NAME = get_next_line.a

# Lista de funciones a compilar
FUNCTIONS = get_next_line.c \
	get_next_line_utils.c

OBJS = $(FUNCTIONS:%.c=%.o)

# Default target
all: $(NAME)

# Rule to create the static library
$(NAME): $(OBJS)
	ar rcs $(NAME) $^

# Rule to compile .c files into .o files
$(OBJS): %.o: %.c get_next_line.h Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BOBJS): %.o: %.c get_next_line.h
	$(CC) -c $(CFLAGS) $< -o $@

# Rule to run Valgrind for memory leak checks
valgrind: $(NAME)
	valgrind --leak-check=full --track-fds=yes ./$(NAME)

# Clean up the object files
clean:
	rm -f $(OBJS)
# Clean up the object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild the library from scratch
re: fclean all

# Print the list of functions (for debugging purposes)
info:
	$(info $(FUNCTIONS))

# Declare these rules as phony (they are not actual files)
.PHONY: all clean fclean re info valgrind
