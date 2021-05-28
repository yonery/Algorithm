# 1224 - 계산기 - https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14tDX6AFgCFAYD&categoryId=AV14tDX6AFgCFAYD&categoryType=CODE&problemTitle=1224&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1
# eval 이면 끝나는데 금지된 라이브러리라네요
from collections import deque

prec = {
    '*': 3,
    '+': 2,
    '(': 1
}
for test_case in range(1, 2):
    N = int(input())
    st = input()

    # 중위표기법 -> 후위표기법 (stack)
    dq = deque()
    ans = deque()
    for c in st:
        if c not in '()*+':
            ans.append(c)
        elif c == '(':
            dq.append('(')
        elif c == ')':
            while dq[-1] != '(':
                ans.append(dq.pop())
            dq.pop()
        elif dq and prec[c] <= prec[dq[-1]]:
            ans.append(dq.pop())
            dq.append(c)
        else:
            dq.append(c)
    while dq:
        ans.append(dq.pop())

    # 후위표기법 계산
    sq = deque()
    while ans:
        a = ans.popleft()
        if a == '*':
            sq.append(sq.pop()*sq.pop())
        elif a == '+':
            sq.append(sq.pop()+sq.pop())
        else:
            sq.append(int(a))

    print("#{} {}".format(test_case, sq.pop()))
