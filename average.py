import sys
from io import StringIO


def average(values):
    values = list(values)
    aver = 0.0
    for i in range(10):
        aver += values[i]
    aver = round(aver / 10)
    return aver

T = int(input())
for test_case in range(1, T + 1):
    values = map(int, input().split())
    print(f"#{test_case} {average(values)}")