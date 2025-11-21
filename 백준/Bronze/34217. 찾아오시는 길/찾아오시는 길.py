# Python 3 - BOJ 34217
import sys

def main():
    input = sys.stdin.readline
    A, B = map(int, input().split())
    C, D = map(int, input().split())

    time_hanyang = A + C
    time_yongdap = B + D

    if time_hanyang < time_yongdap:
        print("Hanyang Univ.")
    elif time_hanyang > time_yongdap:
        print("Yongdap")
    else:
        print("Either")

if __name__ == "__main__":
    main()
