/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigsegv_guard.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:28:23 by smontuor          #+#    #+#             */
/*   Updated: 2024/07/23 13:44:00 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_GUARD_H
# define SIG_GUARD_H

# include <execinfo.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	sig_guard(char *exec_name);

#endif