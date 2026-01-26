#include "push_swap.h"


typedef struct s_config
{
	int simple;
	int medium;
	int complex;
	int adaptative;
	int bench;
} t_config;

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] )
		i++;
	return (s1[i] - s2[i]);
}

void set_flags(char *flag,t_config *config)
{
	if (ft_strcmp(flag,"--simple") == 0)
	{
		if (config->adaptative + config->complex + config->medium + config->simple > 1)
		{
			write(2,"Error",5);
			exit(1);
		}
		config->simple = 1;
		printf("test simple algo\n");
		
	}
	else if (ft_strcmp(flag,"--medium") == 0)
	{
		if (config->adaptative + config->complex + config->medium + config->simple > 1)
		{
			write(2,"Error",5);
			exit(1);
		}
		config->medium = 1;
		printf(" medium alogtest\n");
	}
	else if (ft_strcmp(flag,"--complex") == 0)
	{
		if (config->adaptative + config->complex + config->medium + config->simple > 1)
		{
			write(2,"Error",5);
			exit(1);
		}
		config->complex = 1;
		printf("hard test\n");
	}
	else if (ft_strcmp(flag,"--adaptive") == 0)
	{
		if (config->adaptative + config->complex + config->medium + config->simple > 1)
		{
			write(2,"Error",5);
			exit(1);
		}
		config->adaptative = 1;
		printf("hard test\n");
	}
	else if (ft_strcmp(flag,"--bench") == 0)
	{
		printf("bench\n");
		config->bench = 1;
	}
	else
	{
		write(2,"Error",5);
		return ();
	}
}

int check_flags(char **av,t_config *config)
{
	int i;

	i = 1;
	while (av[i] && av[i][0] == '-' && av[i][1] == '-')
	{
		set_flags(av[i],config);
		i++;
	}
	return (i);
}
void parser(char **av)
{
	int i;
	t_config config;
	i = check_flags(av,&config);
	while (av[i])
	{
		
		i++;
	}
	
}