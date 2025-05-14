#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <QDateTime>
#include <QThread>

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
    static qint32 generate()
    {// 伪随机数生成器（线性同余法）
        static quint32 seed = QDateTime::currentMSecsSinceEpoch() ^ (quint32(QThread::currentThreadId()) << 16);
        seed = 1664525 * seed + 1013904223;
        return seed;
    }
};

#endif // RANDOMGENERATOR_H
