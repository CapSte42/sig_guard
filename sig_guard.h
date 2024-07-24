/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_guard.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:28:23 by smontuor          #+#    #+#             */
/*   Updated: 2024/07/24 03:46:22 by smontuor42       ###   ########.fr       */
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


# define MAX_LINE_LENGTH	1024
# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_RESET	"\x1b[0m"
# define ANSI_BOLD_ON		"\x1b[1m"
# define ANSI_BOLD_OFF		"\x1b[22m"
# define CONTEXT_LINES		5

void	sig_guard(char *exec_name);

#endif
