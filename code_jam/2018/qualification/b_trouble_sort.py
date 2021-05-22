from array import array


def test_trouble_sort(prob_num, v):
    done = False
    while not done:
        done = True
        for i in range(0, len(v)-2):
            if v[i] > v[i+2]:
                done = False
                # Swap two values
                temp = v[i]
                v[i] = v[i+2]
                v[i+2] = temp

    # Verify after sort
    for j in range(0, len(v)-1):
        if v[j] > v[j+1]:
            print('Case #{}: {}'.format(prob_num, j))
            return

    print('Case #{}: OK'.format(prob_num))


t = int(input())

for i in range(1, t+1):
    n = int(input())
    v = array('i', [int(x) for x in input().split(' ')])

    test_trouble_sort(i, v)



