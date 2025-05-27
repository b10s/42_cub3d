#include <fcntl.h>
#include <libc.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*joined;
	ssize_t	read_bytes;
	char	*line;
	int		i;

	static char *save; // NULL
	if (save == NULL)
		joined = strdup("");
	else
		joined = strdup(save);
	read_bytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (read_bytes > 0 && !strchr(joined, '\n'))
		// read関数からの読み込みが成功　かつ　joinedに改行文字が含まれていないとき
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		joined = strjoin(joined, buffer);
	}
	if (read_bytes == 0 && strlen(joined) == 0)
		return (NULL);
	if (strchr(joined, '\n') == NULL)
	{
		line = strdup(joined);
		return (line);
	}
	else
	{
		i = 0;
		while (joined[i] != '\n')
			i++;
		line = substr(joined, 0, i + 1);
		save = strdup(joined + i + 1);
		return (line);
	}
}
// }

// int	main(void)
// {
// 	int fd;
// 	char *line;

// 	// テキストファイルを開く
// 	fd = open("test1.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Failed to open file");
// 		return (1);
// 	}

// 	// ファイルの内容を1行ずつ読み込む
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}

// 	// ファイルを閉じる
// 	close(fd);

// 	return (0);
// }
