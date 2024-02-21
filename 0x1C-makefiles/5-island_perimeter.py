#!/usr/bin/python3
"""To Define island perimeter measuring the function"""


def island_perimeter(grid):
    """Return -> perimiter of island
     Grid represent water -> 0 and land -> 1
    Args:
        grid (list): The  list of list of ints representing island
    Returns:
        Perimeter of island defined in grid
    """
    wth = len(grid[0])
    hght = len(grid)
    edgs = 0
    sz = 0

    for ix in range(hght):
        for ji in range(wth):
            if grid[ix][ji] == 1:
                sz += 1
                if (ji > 0 and grid[ix][ji - 1] == 1):
                    edgs += 1
                if (ix > 0 and grid[ix - 1][ji] == 1):
                    edgs += 1
    return sz * 4 - edgs * 2
