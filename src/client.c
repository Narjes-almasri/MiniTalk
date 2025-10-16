#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "ft_printf.h"

int ft_atoi(const char *nptr)
{
    int res;
    int s;
    int i;

    res = 0;
    s = 1;
    i = 0;
    while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
        i++;
    if (nptr[i] == '-' || nptr[i] == '+')
    {
        if (nptr[i] == '-')
            s = -1;
        i++;
    }
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        res *= 10;
        res += nptr[i] - '0';
        i++;
    }
    return (res * s);
}

void send_signal(int server_pid, char c)
{
    int i;
    unsigned char bit;

    i = 7;
    while (i >= 0)
    {
        bit = (c >> i) & 1;
        if (bit == 0)
        {
            kill(server_pid, SIGUSR1);
           // write(1, "SIGUSR1 ", 8);
        }
        else
        {
            kill(server_pid, SIGUSR2);
            //write(1, "SIGUSR2 ", 8);
        }
        usleep(500);
        i--;
    }
}

int is_digit(int i)
{
    if (i >= '0' && i <= '9')
        return (1);
    else
        return (0);
}

int checkpid(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (!is_digit(s[i]))
            return (0);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int server_pid;
    int i;

    if (argc != 3)
    {
        write(1, "ya 3amo you have to put the [PID] & [message]\n", 47);
        return (1);
    }
    if (checkpid(argv[1]) == 0)
    {
        ft_printf("ERROR\n");
        return (1);
    }
    server_pid = ft_atoi(argv[1]);
    i = 0;
    while (argv[2][i] != '\0')
    {
        send_signal(server_pid, argv[2][i]);
        i++;
    }
    send_signal(server_pid, '\0'); // bonus
    return (0);
}
