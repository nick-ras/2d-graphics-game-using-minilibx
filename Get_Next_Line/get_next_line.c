/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:55:19 by nickras           #+#    #+#             */
/*   Updated: 2022/06/17 18:55:23 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//if static buffer contains newline character. It copies everyting until newline
//into a new string and return it to the calling function.
//the static buffer is being modified so that everyting after the newline overwrites
//what was being copied to the buffer. So the character after first newline character is 
//at index 0, and therefor overwritting everything everything until and including the first newline.
char	*put_s_str_leftover_in_buf(char *s_str)
{
	char	*buf;
	int		i;
	int		j;

	i = 0;
	j = 0;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (s_str[i] != '\n' && s_str[i] != '\0')
	{
		buf[i] = s_str[i];
		i++;
	}
	if (s_str[i] == '\n')
		buf[i++] = '\n';
	buf[i] = '\0';
	while (s_str[i] != '\0')
		s_str[j++] = s_str[i++];
	s_str[j] = '\0';
	return (buf);
}

//Adds the characters after the newline character to
//the static variable. This function is used when the readcall 
//contain a newline
void	edit_buf_and_s_str(char *s_str, char *buf)
{
	int		i;
	int		j;

	i = 0;
	if (!buf)
		return ;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	j = 0;
	if (buf[i] == '\n')
		i++;
	while (buf[i] != '\0')
	{
		s_str[j++] = buf[i];
		buf[i] = '\0';
		i++;
	}
	s_str[j] = '\0';
}

//This mallocs space to save the output from a read call. It read until it 
//it find a newline or null character. Everytime it makes a read call it adds that string to
//the current string, if any.
char	*read_lines(int fd, char *s_str, char *buf, char *temp)
{
	int		read_count;
	char	*char_ptr;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!ft_strchr(buf, '\n'))
	{
		read_count = read(fd, temp, BUFFER_SIZE);
		if (read_count <= 0)
		{
			free(temp);
			if (read_count == -1 || buf[0] == '\0')
			{
				free(buf);
				return (NULL);
			}
			return (buf);
		}
		temp[read_count] = '\0';
		char_ptr = buf;
		buf = ft_strjoin(buf, temp);
		free(char_ptr);
	}
	free(temp);
	edit_buf_and_s_str(s_str, buf);
	return (buf);
}

//This is the starting function. This function takes a filedescriptor for the file
//that it needs to read from. The buffer size of the static variable can be altered
// depending on how many bytes you want the function to read from the file at a time.
char	*get_next_line(int fd)
{
	static char	s_str[BUFFER_SIZE];
	char		*buf;

	if (!s_str[0])
		s_str[0] = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= __INT_MAX__)
	{
		return (NULL);
	}
	if (ft_strchr(s_str, '\n'))
		return (put_s_str_leftover_in_buf(s_str));
	else
	{
		buf = put_s_str_leftover_in_buf(s_str);
		buf = read_lines(fd, s_str, buf, NULL);
		return (buf);
	}
}
