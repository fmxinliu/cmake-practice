#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <QDateTime>
#include <QThread>
#include <QThreadStorage>
#include <stdlib.h>

class RandomGenerator
{
public:
    static quint32 bounded(quint32 lowest, quint32 highest)
    {
        if (lowest >= highest)
            return lowest;

        quint32 range = highest - lowest;
        quint32 scaled = generate64() >> 32;
        return lowest + scaled % range;
    }

    static quint64 generate64()
    {// 伪随机数生成器（线性同余法）
        static QThreadStorage<quint64 *> seedStorage;
        if (!seedStorage.hasLocalData())
        {// 初始化线程的 seed
            quint64 timestamp = QDateTime::currentMSecsSinceEpoch();
            quintptr threadId = quintptr(QThread::currentThreadId());
            quint64 randomValue = (quint64(rand()) << 32) | rand();

            quint64 seed = timestamp ^ (threadId << 16) ^ randomValue;
            seedStorage.setLocalData(new quint64(seed));
        }

        quint64 &seed = *seedStorage.localData();
        seed = 1664525 * seed + 1013904223;
        return seed;
    }
};

#endif // RANDOMGENERATOR_H
