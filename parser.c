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
	else if (ft_strcmp(flag,"--adaptive") == 0)
	{
		config->adaptative = 1;
		check_config(config);
	}
	else if (ft_strcmp(flag,"--bench") == 0)
	{
		config->bench = 1;
	}
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
t_config parser(char **av,t_stack *a)
{
	int i;
	int j;
	t_config config;
	long value;
	config.simple = 0;
	config.medium = 0;
	config.complex = 0;
	config.adaptative = 0;
	config.bench = 0;
	i = check_flags(av,&config);
	j = i;
	while (av[j])
		j++;
	a->data = malloc(sizeof(int) * (j - i));

	if (!a->data)
		error_exit();
	
	a->size = 0;
	if (!config.simple && !config.medium &&!config.complex && !config.adaptative)
		config.adaptative = 1;
	while (av[i])
	{
		if (!is_valid_num(av[i]))
			error_exit();
		value = ft_atol(av[i]);
		if (value < INT_MIN || value > INT_MAX )
			error_exit();
		if (is_dup(a,(int)value))
			error_exit();
		push_value_to_a(a,(int)value);
		i++;
	}
	return (config);
}
