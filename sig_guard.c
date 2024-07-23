/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_guard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:29:21 by smontuor          #+#    #+#             */
/*   Updated: 2024/07/23 13:53:40 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sig_guard.h"

char	*g_executable_name;

static void	print_stack_trace()
{
	void *buffer[100];	// change this value if you need more or less stack frames
	int nptrs = backtrace(buffer, 100);
	char **strings = backtrace_symbols(buffer, nptrs);

	if (strings == NULL)
	{
		perror("backtrace_symbols");
		exit(EXIT_FAILURE);
	}

	printf("Stack trace:\n");
	/*print in reverse*/
	for (int i = nptrs - 1; i >= 2; i--) // last 2 frames are sigsegv_handler and print_stack_trace
	{
		char command[256];
		FILE *fp;
		snprintf(command, sizeof(command), "addr2line -e %s %p", g_executable_name, buffer[i]);
		fp = popen(command, "r");
		if (fp == NULL)
		{
			perror("popen");
			exit(EXIT_FAILURE);
		}
		char result[256];
		while (fgets(result, sizeof(result), fp) != NULL)
		{
			if (strstr(result, "??") == NULL && strstr(result, "sigsegv_guard") == NULL)
				printf("%s", result);
		}
		pclose(fp);
	}
	free(strings);
}

static void	sigsegv_handler(int sig)
{
	printf("Caught signal %d (%s)\n", sig, strsignal(sig));
	print_stack_trace();
	exit(EXIT_FAILURE);
}

void sig_guard(char *exec_name)
{
	struct sigaction sa;
	g_executable_name = exec_name;
	sa.sa_handler = sigsegv_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;

	if (sigaction(SIGSEGV, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
// 	it could be used to catch other signals
/*	if (sigaction(SIGABRT, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGBUS, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGILL, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGFPE, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGTERM, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGPIPE, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	} */
}

// backtrace:
// backtrace() is a GNU C Library function that provides a way to obtain a backtrace (a snapshot of the call stack).
// It fills the buffer array with the return addresses of the current call stack up to the size specified by size.
// The function returns the number of addresses returned, which can be used to print a stack trace or for debugging purposes.

// backtrace_symbols:
// backtrace_symbols() is a GNU C Library function that translates the addresses obtained from backtrace() into an array of strings.
// Each string in the array describes the corresponding frame in the backtrace buffer.
// This function returns a pointer to an array of strings that need to be freed by the caller using free().
// If the function fails, it returns NULL.

// snprintf:
// snprintf() is a variant of sprintf() that allows you to specify the size of the output buffer.
// It writes formatted data to a string and ensures that the resulting string does not exceed the specified buffer size.
// This function is used to prevent buffer overflow vulnerabilities by limiting the number of characters written to the buffer.

// popen:
// popen() is a function that creates a pipe, forking the current process, and invokes the shell to execute a specified command.
// The command's output can be read from the returned file pointer, or input can be written to the command.
// popen() returns a FILE pointer associated with the pipe, or NULL if an error occurs.

// fgets:
// fgets() is a standard library function that reads a line from the specified file pointer into a buffer.
// It stops reading after an EOF or a newline character, or when the specified number of characters have been read.
// The newline character (if read) is retained in the buffer, and a null character is appended at the end of the string.

// pclose:
// pclose() is a function that closes a stream opened by popen().
// It waits for the associated process to terminate and returns the exit status of the command.
// If an error occurs, pclose() returns -1.
