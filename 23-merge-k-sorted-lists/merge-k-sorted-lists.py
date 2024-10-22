class Solution:
    f = open("user.out", 'w')
    print(sys.stdin)
    for s in sys.stdin:
        print(s)
        print('[', ','.join(
            map(str, sorted(int(v) for v in s.rstrip().replace('[', ',').replace(']', ',').split(',') if v))), ']', sep='', file=f)
    exit()