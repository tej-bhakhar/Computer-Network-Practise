
def redbits(m):

    for i in range(m):
        if (2**i >= m + i + 1):
            return i


def posbits(num, r):

    j = 0
    k = 1
    m = len(num)
    ress = ''

    for i in range(1, m + r+1):
        if (i == 2**j):
            ress = ress + '0'
            j += 1
        else:
            ress = ress + num[-1 * k]
            k += 1

    return ress[::-1]


def paritybits(a, r):
    n = len(a)

    for i in range(r):
        value = 0
        for j in range(1, n + 1):

            if (j & (2**i) == (2**i)):
                value = value ^ int(a[-1 * j])

        a = a[:n-(2**i)] + str(value) + a[n-(2**i)+1:]
    return a


def error(a, nor):
    n = len(a)
    ress = 0

    for i in range(nor):
        value = 0
        for j in range(1, n + 1):
            if (j & (2**i) == (2**i)):
                value = value ^ int(a[-1 * j])

        ress = ress + value*(10**i)

    return int(str(ress), 2)


num = '11010110011'

m = len(num)
r = redbits(m)
a = posbits(num, r)
a = paritybits(a, r)

print("num transferred is " + a)

a = '10111011110'
print("Error num is " + a)

corr = error(a, r)
if (corr == 0):
    print("There is no error in the received message.")
else:
    print("Position of the error is ", len(a)-corr+1, "from the left")
