#!/usr/bin/python

def car(fn):
    def getFirst(a, b):
        return a
    return fn(getFirst)

def cdr(fn):
    def getLast(a, b):
        return b
    return fn(getLast)

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

def main():
    test1 = cons(3, 4)
    test2 = cons(1, 10)

    print('For cons(3, 4), ')
    print('car: {}, should be 3'.format(car(test1)))
    print('cdr: {}, should be 4'.format(cdr(test1)))

    print('')

    print('For cons(1, 10), ')
    print('car: {}, should be 1'.format(car(test2)))
    print('cdr: {}, should be 10'.format(cdr(test2)))


if __name__ == '__main__':
    main()
