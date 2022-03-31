# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 11:03:19 by msoler-e          #+#    #+#              #
#    Updated: 2022/03/29 12:59:43 by msoler-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
INCLUDE_DIR := include
SRC_DIR := src
LIBS_DIR := libft
OBJS_DIR := objs
PROGRAM_LOCATION := $(BIN_DIR)/$(NAME)


LIBS := $(LIBS_DIR)/libft.a

LIBS_HEADERS := -I $(LIBS_DIR)/libft
			
INC := -I $(INCLUDE_DIR) $(LIBS_HEADERS)

SRCS := fractol.c ft_error.c fractalmandelbrot.c

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))


CC = gcc
CFLAGS = -Wall -Werror -Wextra -g $(INC)


objs/%.o:src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $^
	@echo "🔨 Compiling: $^"
	
all: $(NAME)

$(NAME):$(OBJS) $(LIBS)
	$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "✅ Built $(NAME)"

$(LIBS_DIR)/libft.a:
	@make -C $(LIBS_DIR)

run: $(NAME)
	./$(NAME)

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make fclean -C $(LIBS_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all re run clean fclean
