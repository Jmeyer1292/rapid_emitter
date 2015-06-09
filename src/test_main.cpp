#include "rapid_emitter/rapid_emitter.h"
#include <iostream>

std::vector<TrajectoryPt> makeFakeTrajectory()
{
  std::vector<TrajectoryPt> points;
  std::vector<double> dummy(6, 0.0);
  TrajectoryPt pt (dummy);
  for (std::size_t i = 0; i < 10; i ++)
  {
    points.push_back(pt);
  }
  return points;
}

ProcessParams makeFakeParams()
{
  ProcessParams params;
  params.spindle_speed = 2000.0;
  params.tcp_speed = 100.0;
  params.slide_force = 10;
  params.output_name = "doTestOutput";
  params.wolf = false;
  return params;
}
int main()
{
  std::vector<TrajectoryPt> pts = makeFakeTrajectory();
  ProcessParams params = makeFakeParams();
  size_t startProcessMotion = 2;
  size_t endProcessMotion = 6;

  rapid_emitter::emitRapidFile(std::cout, pts, startProcessMotion, endProcessMotion, params);
}