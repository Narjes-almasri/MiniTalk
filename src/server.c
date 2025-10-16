#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stddef.h>
#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*n;
	size_t	i;

	i = 0;
	n = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (n == NULL)
		return (NULL);
	while (s[i])
	{
		n[i] = s[i];
		i++;
	}
	n[i] = '\0';
	return (n);
}

char	*ft_strjoin(char const *s1, char *s2)
{
	size_t	i;
	size_t	len_s1;
	char	*p;

	if (!s1)
		return (NULL);
	len_s1 = ft_strlen(s1);
	p = (char *)malloc((len_s1 + 2) * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = *s2;
	i++;
	p[i] = '\0';
	return (p);
}

void	recivesig(int sig)
{
	static int	count = 0;
	static int	result = 0;
	static char	*message = NULL;
	char		c[2];

	if (!message)
		message = ft_strdup("");
	result |= (sig == SIGUSR2) << (7 - count);
	count++;
	if (count == 8)
	{
		c[0] = (char)result;
		c[1] = '\0';
		if (result == 0)
		{
			ft_printf(message);
            ft_printf("\n");
			free(message);
			message = NULL;
		}
		else
			message = ft_strjoin(message, c);
		count = 0;
		result = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID:%d\n", pid);
	signal(SIGUSR1, recivesig);
	signal(SIGUSR2, recivesig);
	while (1)
	{
		pause();
		usleep(100);
	}
	return (0);
}
