from os import popen
popen('g++ -w generator.cpp -o generator')
popen('g++ -w  a.cpp -o a')
popen('g++ -w a_good.cpp -o a_good')
for i in range(1,1001):
    print i
    f = open('test.txt', 'w')

    test = popen('./generator').read();
    f.write(test)
    f.close()

    v1 = popen('./a_good < test.txt').read()
    v2 = popen('./a < test.txt').read()
    if v1 != v2:
        print "TEST"
        print test
        print "GOOD"
        print v1
        print "BAD"
        print v2
        break
