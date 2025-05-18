#include "include/timerPresenter.h"

QString TimerPresenter::formatTime(unsigned seconds) {
  unsigned minutes = seconds / 60;
  unsigned secs = seconds % 60;
  std::ostringstream oss;
  oss << std::setw(2) << std::setfill('0') << minutes << ":" << std::setw(2)
      << std::setfill('0') << secs;
  return QString::fromStdString(oss.str());
}

QString TimerPresenter::phaseText(bool resting) {
  return resting ? QStringLiteral("Отдых") : QStringLiteral("Работа");
}
