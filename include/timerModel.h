#ifndef TIMERMODEL_H
#define TIMERMODEL_H

#include <QObject>
#include <QTimer>

#define INTERVAL_MS 1000

class TimerModel : public QObject {
    Q_OBJECT

public:
    TimerModel(unsigned workSeconds, unsigned restSeconds, QObject *parent = nullptr);
    void start();
    void stop();
    void reset();
    void skip();
    bool isRunning() const;
    bool isResting() const;
    unsigned remainingTime() const;

signals:
    void timeUpdated(unsigned seconds);
    void phaseChanged(bool resting);
    void started();
    void stopped();

private slots:
    void onTimeout();

private:
    QTimer timer;
    bool running;
    bool resting;
    unsigned workDuration;
    unsigned restDuration;
    unsigned remaining;
};

#endif // TIMERMODEL_H
