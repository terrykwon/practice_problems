from random import randint
import math


def get_optimal_spot(plot):
    most_empties = 0
    optimal_spot = (2, 2)

    for c in range(2, 67):
        empty_count = 0

        # Count number of empty spots in enveloping
        # 3-by-3 grid.
        for i in range(1, 4):
            for j in range(c - 1, c + 2):
                if plot[i][j] == 0:
                    empty_count += 1

        if empty_count == 9:
            return 2, c

        if empty_count > most_empties:
            most_empties = empty_count
            optimal_spot = (2, c)

    return optimal_spot


def prepare_plot():
    a = int(input())

    plot = [[0] * 70 for k in range(5)]

    x, y = get_optimal_spot(plot)

    print('{} {}'.format(x, y), flush=True)

    while True:
        x_in, y_in = [int(c) for c in input().split(' ')]
        plot[x_in][y_in] = 1

        if x_in == 0 and y_in == 0:
            return

        if x_in == -1 and y_in == -1:
            exit(-1)

        x, y = get_optimal_spot(plot)
        print('{} {}'.format(x, y), flush=True)


t = int(input())

for i in range(1, t+1):
    prepare_plot()

