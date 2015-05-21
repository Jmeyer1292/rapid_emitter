#ifndef TEST_DATA_STRUCTURES_H
#define TEST_DATA_STRUCTURES_H

#include <vector>

struct TrajectoryPt
{
  typedef std::vector<double> value_type;

  TrajectoryPt(const std::vector<double>& positions)
    : positions_(positions)
  {}

  value_type positions_;
};

struct ProcessParams
{
  double spindle_speed;
  double tcp_speed;
  double force;
};

#endif
