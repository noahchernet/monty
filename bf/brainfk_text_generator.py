#!/usr/bin/python3
import sys

'''
 This program takes the string provided in the argument
 and prints the Brainf*ck equivalent for printing the string
'''


def main():
    text = sys.argv[1]

    for i in text:
        for j in range(ord(i)):
            print('+', end="")
        print(".>")
    print("++++++++++.")


if __name__ == '__main__':
    main()
