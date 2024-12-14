#!/usr/bin/env python

import sys
 
from random import randint, random

def random_number(ndigs, prob_pos):

    if random() <= 1 - prob_pos:
        print('-', end='')

    print(randint(1, 9), end='')
    for i in range(ndigs - 1):
        print(randint(0, 9), end='')
    print()

def random_number_str(ndigs, prob_pos):

    v = []

    if random() <= 1 - prob_pos:
        v.append("-")

    v.append(str(randint(1, 9)))
    for i in range(ndigs - 1):
        v.append(str(randint(0, 9)))

    return "".join(v)


def random_set_random_op(nmin, nmax, n):

    op = ['+', '-', '*', '/']
    i = 0
    while i < n:
        random_number(randint(nmin, nmax), .5)
        random_number(randint(nmin, nmax), .5)
        j = randint(0, len(op) - 1)

        print(op[j])
        i += 1

random_set_random_op(4, 1000, 1000)
