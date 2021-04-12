from sys import stdin, stdout
# 식의 값을 최소로 만들기 위해서는 결국 a - b에서 b의 값이 최대가 되어야 한다

poly = stdin.readline()
operand = []
operator = ['+']
tmp = ""

for c in poly:
    if c == "+" or c == "-":
        operand.append(tmp)
        operator.append(c)
        tmp = ""
    else:
        tmp += c
operand.append(tmp[:-1]) # 줄변환 문자 처리(\n이 같이 저장됨)
operand = list(map(int, operand))

# 뒤쪽부터 계산하면서 +는 모두 더해주고, -가 나오면 해당 값을 음수로
res = tmp = 0
num = len(operator)-1

for idx in range(num, -1, -1):
    op = operator[idx]
    if op == '+':
        tmp += operand[idx]
    else:
        res -= (tmp+operand[idx])
        tmp = 0

res += tmp
print(res)