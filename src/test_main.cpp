#include "rapid_emitter/rapid_emitter.h"

std::vector<TrajectoryPt> makeFakeTrajectory()
{
  std::vector<TrajectoryPt> points;
  return points;
}

ProcessParams makeFakeParams()
{
  ProcessParams params;
  params.spindle_speed = 1.0;
  params.tcp_speed = 100.0;
  return params;
}
int main()
{
  std::vector<TrajectoryPt> pts = makeFakeTrajectory();
  ProcessParams params = makeFakeParams();
  size_t lengthFreeMotion = 10;

  rapid_emitter::emitRapidFile("testfile.rapid", pts, lengthFreeMotion, params);
}