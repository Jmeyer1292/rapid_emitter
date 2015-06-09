#ifndef TEST_DATA_STRUCTURES_H
#define TEST_DATA_STRUCTURES_H

#include <vector>
#include <string>

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
  std::string output_name;
  bool wolf;
  double slide_force;
};

#endif
