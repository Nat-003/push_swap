#include "push_swap.h"




int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] )
		i++;
	return (s1[i] - s2[i]);
}
void error_exit()
{
	write(2,"Error\n",6);
	exit(1);
}

void check_config(t_config *config)
{
	if (config->adaptative + config->complex + config->medium + config->simple > 1)
			error_exit();

}

void set_flags(char *flag,t_config *config)
{
	if (ft_strcmp(flag,"--simple") == 0)
	{
		config->simple = 1;
		check_config(config);
	}
	else if (ft_strcmp(flag,"--medium") == 0)
	{
		config->medium = 1;
		check_config(config);
	}
	else if (ft_strcmp(flag,"--complex") == 0)
	{
		config->complex = 1;
		check_config(config);
	}
	else if (ft_strcmp(flag,"--adaptative") == 0)
	{
		config->adaptative = 1;
		check_config(config);
	}
	else if (ft_strcmp(flag,"--bench") == 0)
		config->bench = 1;
	else
		error_exit();
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

int is_valid_num(char *s)
{
	int i;

	i = 0;

	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
long ft_atol(char *s)
{
	long result;
	int sign;
	int i;

	result = 0;
	sign = 1;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		result = result * 10 +(s[i] -'0');
		i++;
	}
	return (result * sign);
}
int is_dup(t_stack *a, int value)
{
	int i;

	i = 0;
	while (i < a->size)
	{
		if (a->data[i] == value)
			return (1);
		i++;
	}
	return (0);
}
void push_value_to_a(t_stack *a,int value)
{
	a->data[a->size] = value;
	a->size = a->size + 1;

}

void free_split(char **s)
{
	int j = 0;
		while (s[j])
		{
			free(s[j]);
			j++;
		}
		free(s);
}
t_config parser(char **av,t_stack *a)
{
	int i;
	int k;
	int total;
	char **split;
	char **split2;
	int count;
	t_config config;
	long value;
	config.simple = 0;
	config.medium = 0;
	config.complex = 0;
	config.adaptative = 0;
	config.bench = 0;
	i = check_flags(av,&config);
	k = i;
	total = 0;
	while (av[k])
	{
		count = 0;
		split = ft_split(av[k],' ');
		if (!split)
			error_exit(); 
		while (split[count])
			count++;
		total += count;
		free_split(split);
		k++;
	}
	if (total == 0)
    	error_exit();
	a->data = malloc(sizeof(int) * total);
	if (!a->data)
		error_exit();
	
	a->size = 0;
	if (!config.simple && !config.medium &&!config.complex && !config.adaptative)
		config.adaptative = 1;
	while (av[i])
	{
		split2 = ft_split(av[i], ' ');
		if (!split2)
			error_exit();
		
		count = 0;
		while (split2[count])
		{
			if (!is_valid_num(split2[count]))
				error_exit();
			value = ft_atol(split2[count]);
			if (value < INT_MIN || value > INT_MAX )
				error_exit();
			if (is_dup(a,(int)value))
				error_exit();
			push_value_to_a(a,(int)value);
			count++;
		}
		free_split(split2);
		i++;
	}
	return (config);
}
