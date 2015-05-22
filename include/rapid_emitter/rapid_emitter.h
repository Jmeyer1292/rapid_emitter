#ifndef RAPID_EMITTER_H
#define RAPID_EMITTER_H

#include "test_data_structures.h"

#include <iosfwd>
#include <string>

namespace rapid_emitter
{
  bool emitJointPosition(std::ostream& os, const TrajectoryPt& pt, size_t n);
  bool emitGrindMotion(std::ostream& os, const ProcessParams& params, size_t n);
  bool emitFreeMotion(std::ostream& os, const ProcessParams& params, size_t n);

  bool emitRapidFile(std::ostream& os,
                     const std::vector<TrajectoryPt>& points,
                     size_t lengthFreeMotion,
                     const ProcessParams& params);
}

#endif
