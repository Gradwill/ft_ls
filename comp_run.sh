# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    comp_run.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 11:36:29 by gngobeni          #+#    #+#              #
#    Updated: 2019/07/22 18:06:24 by gngobeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

gcc -o ft_ls ft_ls.c -I ft_printf  -I ft_printf/libft libftls.a -L ft_printf -lftprintf \
	-L ft_printf/libft -lft
