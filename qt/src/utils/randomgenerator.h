#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <QDateTime>
#include <QThread>
#include <QThreadStorage>

class RandomGenerator
{
public:
    static quint32 bounded(quint32 lowest, quint32 highest)
    {
        if (lowest >= highest)
            return lowest;

        quint32 range = highest - lowest;
        quint64 scaled = (quint64(generate()) * range) >> 32;
        return lowest + scaled % range;
    }

private:
    static quint32 generate()
    {// 伪随机数生成器（线性同余法）
        static QThreadStorage<quint32 *> seedStorage;
        if (!seedStorage.hasLocalData())
        {// 初始化线程的 seed
            quint32 seed = QDateTime::currentMSecsSinceEpoch() ^ (quintptr(QThread::currentThreadId()) << 16);
            seedStorage.setLocalData(new quint32(seed));
        }

        quint32 &seed = *seedStorage.localData();
        seed = 1664525 * seed + 1013904223;
        return seed;
    }
};

#endif // RANDOMGENERATOR_H
