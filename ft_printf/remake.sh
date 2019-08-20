# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    remake.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 12:31:54 by gngobeni          #+#    #+#              #
#    Updated: 2019/07/09 12:34:08 by gngobeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bish/bash
#Script to re make current and libft/ lib.a

make re && make clean && make -C libft re && make -C libft clean

