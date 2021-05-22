from array import array


def calc_score(p):
    score = 0
    curr_dmg = 1

    for c in p:
        if c == 'S':
            score += curr_dmg
        else:
            curr_dmg *= 2

    return score


def min_swaps(d, p):

    count = 0

    if len(p) == 1:
        if calc_score(p) <= d:
            print('Case #{}: {}'.format(i, count))
        else:
            print('Case #{}: {}'.format(i, 'IMPOSSIBLE'))
        return

    # Initial state
    if calc_score(p) <= d:
        print('Case #{}: {}'.format(i, count))
        return

    while 1:
        swapped = False

        for j in range(len(p)-1, 0, -1): # Traverse from rightmost end

            if p[j] == 'S' and p[j-1] == 'C':
                p[j] = 'C'
                p[j-1] = 'S'
                count += 1
                swapped = True

                if calc_score(p) <= d:
                    print('Case #{}: {}'.format(i, count))
                    return

        if not swapped:
            # Currently in optimal state
            if calc_score(p) <= d:
                print('Case #{}: {}'.format(i, count))
            else:
                print('Case #{}: {}'.format(i, 'IMPOSSIBLE'))
            return


t = int(input())

for i in range(1, t+1):

    input_list = input().split(' ')

    d = int(input_list[0])
    p = array('u', input_list[1])

    min_swaps(d, p)


