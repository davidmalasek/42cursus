/*
MAP:

0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position.

Valid map checklist:
- map must contain 1 exit, at least 1 collectible,
	and 1 starting position to be valid
- map must be rectangular
- map must be closed/surrounded by walls, if it’s not,
	the program must return an error
- map must have a valid path

If any misconfiguration of any kind is encountered in the file, the program must
exit in a clean way,
	and return "Error\n" followed by an explicit error message of
your choice.

Valid map:

1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
*/

#include "../include/so_long.h"

int	main(void)
{
	char	*file_content;

	file_content = read_from_file("./maps/map2.ber");
	printf("%s\n", file_content);
	printf("\n---\n");
	printf("%d\n", is_map_valid(file_content));
}
