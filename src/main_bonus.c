
#include "pipex.h"

int	main(int argc, char **argv)
{
	if (argc < 5)
		exit_print_usage();
	return (pipex(argv));
}

static int	pipex()
{
	int		pre_pipefd[2];
	int		pipefd[2];
	size_t	cmd_cnt;
	size_t	i;

	cmd_cnt = get_cmd_cnt();
	i = 0;
	while (i < cmd_cnt)
	{
		if (i == 0)

		else if (i == cmd_cnt - 1)
		else
	}
}
