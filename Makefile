# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 11:26:33 by vimazuro          #+#    #+#              #
#    Updated: 2025/04/09 09:56:19 by vimazuro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=thread
HEADER = philo.h

SRC_FILES = main.c ft_atoi.c ft_check_fill_arg.c ft_routine.c \
			ft_current_time_ms.c ft_fill_philos.c \
			ft_free_philos.c ft_check_death.c \
			ft_safe_usleep.c ft_monitoring.c ft_check_eat_count.c \
			ft_one_philo.c ft_print_status.c

OBJS = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
