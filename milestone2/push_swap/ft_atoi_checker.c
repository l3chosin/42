int	ft_atoi_ok(const char *str,	int	*ok)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	*ok = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		if ((str[i + 1] == '-' || str[i + 1] == '+'))
			return (*ok = 0, 0);
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (*ok = 0, 0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (*ok = 0, 0);
	return (result * sign);
}
