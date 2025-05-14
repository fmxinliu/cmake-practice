#ifndef RANDOMSTRINGTHREAD_H
#define RANDOMSTRINGTHREAD_H

#include <QThread>

class RandomStringThread : public QThread
{
    Q_OBJECT

public:
    static int startTest(int numThreads, int numIterationsPerThread);

protected:
    void run();

private:
    int m_iterations;
    int m_length;
    bool lock;
    RandomStringThread(int iterations, int length, bool lock);
};

#endif // RANDOMSTRINGTHREAD_H
