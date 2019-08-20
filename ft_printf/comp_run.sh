# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    comp_run.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 12:19:16 by gngobeni          #+#    #+#              #
#    Updated: 2019/07/16 09:40:24 by gngobeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
#Compile and run main test function

gcc -o main main.c -I libft -L. -L libft -lftprintf -lft
./main $1
