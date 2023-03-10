/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:57:35 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/10 16:57:40 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_error_msg_and_exit(char *error_msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(1);
}
