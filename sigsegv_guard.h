/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigsegv_guard.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:28:23 by smontuor          #+#    #+#             */
/*   Updated: 2024/05/27 22:28:59 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGSEGV_GUARD_H
# define SIGSEGV_GUARD_H

# include <execinfo.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	sigsegv_guard();

#endif