// JUST TEST THIS OUT AND SEE

int	append_to_stash(char **stash, char *buffer)
{
	char	*new_stash;
	size_t	total_len;

	total_len = ft_strlen(buffer);
	if (*stash)
		total_len += ft_strlen(*stash);
	new_stash = (char *)malloc(total_len + 1);
	if (!new_stash)
		return (-1); // Indicate failure
	new_stash[0] = '\0';
	if (*stash)
		ft_strlcpy(new_stash, *stash, ft_strlen(*stash) + 1);
	ft_strlcat(new_stash, buffer, total_len + 1);
	free(*stash);
	*stash = new_stash;
	return (0); // Indicate success
}

char	*extract_line(char **stash)
{
	char	*line;
	char	*new_stash;
	int		newline_index;

	newline_index = get_newline(*stash);
	if (newline_index != -1)
	{
		line = ft_substr(*stash, 0, newline_index + 1);
		new_stash = ft_substr(*stash, newline_index + 1, ft_strlen(*stash)
				- newline_index - 1);
		if (!new_stash)
		{
			free(line);
			free(*stash);
			*stash = NULL;
			return (NULL);
		}
		free(*stash);
		*stash = new_stash;
	}
	else
	{
		line = ft_substr(*stash, 0, ft_strlen(*stash));
		free(*stash);
		*stash = NULL;
	}
	return (line);
}

int	get_newline(char *buffer)
{
	int	i;

	if (!buffer)
		return (-1); // Handle NULL buffer
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	read_and_append(int fd, char **stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		if (append_to_stash(stash, buffer) == -1)
		{
			free(buffer);
			return (-1); // Handle append failure
		}
		if (get_newline(*stash) != -1)
			break ;
	}
	free(buffer);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char *stash;
	int bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read_and_append(fd, &stash);
	if (bytes_read < 0 || !stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (ft_strlen(stash) == 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	return (extract_line(&stash));
}