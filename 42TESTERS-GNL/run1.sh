gcc -Wall -Werror -Wextra srcs/gnl_tester.c ../get_next_line.c ../get_next_line_utils.c -I ../ -D BUFFER_SIZE=1 -fsanitize=address && ./a.out
