import sys


def is_promising(i, j):
    promising = list(range(1, 10))  # 세연이가 알려준 방법

    # 1~9별로 조건을 확인하기 보다 가능한 숫자를 남겨두는 것이 더 빠름
    for k in range(9):
        if sudoku[i][k] in promising:
            promising.remove(sudoku[i][k])
        if sudoku[k][j] in promising:
            promising.remove(sudoku[k][j])

    # 3x3 박스 검사
    i -= i % 3
    j -= j % 3

    # 마찬가지로 9개칸 안에 있는 숫자는 후보군에서 제외
    for p in range(i, i+3):
        for q in range(j, j+3):
            if sudoku[p][q] in promising:
                promising.remove(sudoku[p][q])

    return promising


def dfs(x):
    if x == len(zeros):  # 마지막 0 까지 다 채웠을 경우
        for row in sudoku:
            print(*row)  # 리스트 양 옆 [] 빼고 출력 가능
        sys.exit(0)

    else:  # 계속 계산한다
        (i, j) = zeros[x]
        promising = is_promising(i, j)  # 현재 빈칸에서 가능한 후보군 받기

        for num in promising:
            sudoku[i][j] = num  # 후보군 중 하나 선택
            dfs(x+1)  # 다음 0으로 넘어감
            sudoku[i][j] = 0  # 초기화


sudoku = [list(map(int, sys.stdin.readline().split())) for _ in range(9)]
zeros = [(i, j) for i in range(9) for j in range(9) if sudoku[i][j] == 0]
# 0인 위치만 튜플의 리스트로 저장! 이중 for문과 조건문을 한 줄로 쓰는게 아직 어색하다

dfs(0)