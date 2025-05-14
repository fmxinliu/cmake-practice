#include "randomstringthread.h"
#include "common.h"
#include <QSet>
#include <QMutex>
#include <QStringList>

QMutex mutex;
QStringList generatedStrings;

RandomStringThread::RandomStringThread(int iterations, int length, bool lock)
    : m_iterations(iterations), m_length(length), lock(lock) {}

void RandomStringThread::run()
{
    for (int i = 0; i < m_iterations; ++i)
    {
        QString str = Common::generateRandomStr(m_length);
        if (lock)
        {
            QMutexLocker locker(&mutex);
            generatedStrings.push_back(str);
        }
        else
        {
            generatedStrings.push_back(str);
        }
    }
}

int RandomStringThread::startTest(int numThreads, int numIterationsPerThread)
{
    const int stringLength = 100;

    QList<QThread *> threads;

    // 清空结果集
    generatedStrings.clear();

    // 启动多个线程
    for (int i = 0; i < numThreads; ++i)
    {
        QThread* thread = new RandomStringThread(numIterationsPerThread, stringLength, numThreads > 1);
        threads.push_back(thread);
        thread->start();
    }

    // 等待所有线程完成
    Q_FOREACH(QThread *thread, threads)
    {
        thread->wait();
        delete thread;
    }

    // 检查是否有重复的字符串
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    QSet<QString> uniqueStrings(generatedStrings.begin(), generatedStrings.end());
#else
    QSet<QString> uniqueStrings = generatedStrings.toSet();
#endif
    return uniqueStrings.size();
}
