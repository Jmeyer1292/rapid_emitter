#include "rapid_emitter/rapid_emitter.h"

#include <iostream>
#include <fstream>

bool rapid_emitter::emitRapidFile(const std::string& filename,
                                 const std::vector<TrajectoryPt>& points,
                                 size_t lengthFreeMotion,
                                 const ProcessParams& params)
{
  // Write header
  // Emit all of the joint points
  // Write beginning of procedure
  // For 0 to lengthFreeMotion, emit free moves
  // for lengthFreeMotion to end of points, emit grind moves
  // write any footers including main procedure calling the above
  return false;
}