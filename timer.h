#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>

#define INTERVAL_MS 1000

class Timer : public QObject {
    Q_OBJECT

public:
    Timer(unsigned workSeconds, unsigned restSeconds, QObject *parent = nullptr);
    void start();
    void stop();
    void reset();
    void skipPhase();
    bool isRunning();
    bool isResting();
    QString getWorkSeconds();

private slots:
    void onTimeout();

signals:
    void timeUpdated(const QString& timeString);
    void phaseChanged(bool isResting);
    void timerStopped();
    void timerStarted();

private:
    QTimer timer;
    bool running;
    bool resting;
    unsigned workSeconds;
    unsigned restSeconds;
    unsigned remainingSeconds;
    QString formatTime(unsigned seconds);

};

#endif // TIMER_H
