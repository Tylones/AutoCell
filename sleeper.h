#ifndef SLEEPER_H
#define SLEEPER_H
#include <QThread>

/*!
 * \brief Cette classe est utilisée pour attendre un certain temps entre deux générations
 */
class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};

#endif // SLEEPER_H
