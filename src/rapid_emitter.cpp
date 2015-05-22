#include "rapid_emitter/rapid_emitter.h"

#include <iostream>
#include <fstream>

bool rapid_emitter::emitRapidFile(const std::string& filename,
                                 const std::vector<TrajectoryPt>& points,
                                 size_t lengthFreeMotion,
                                 const ProcessParams& params)
{
  // Write header
  std::cout << "MODULE mGodel_Blend\n\n";
  // Emit all of the joint points
  for (std::size_t i = 0; i < points.size(); ++i)
  {
    emitJointPosition(std::cout, points[i], i);
  }
  // Write beginning of procedure
  std::cout << "\nPROC TestProc()\n";
  // For 0 to lengthFreeMotion, emit free moves
  for (std::size_t i = 0; i < lengthFreeMotion; ++i)
  {
    emitFreeMotion(std::cout, params, i);
  }
  // for lengthFreeMotion to end of points, emit grind moves
  for (std::size_t i = lengthFreeMotion; i < points.size(); ++i)
  {
    emitGrindMotion(std::cout, params, i);
  }
  std::cout << "EndProc\n";
  // write any footers including main procedure calling the above
  std::cout << "ENDMODULE";
  return true;
}

bool rapid_emitter::emitGrindMotion(std::ostream& os, const ProcessParams& params, size_t n)
{
  os << "GrindL CalcRobT(jTarget_" << n << ",tool0), v100, z40, tool0;\n";
  return os.good();
}

bool rapid_emitter::emitFreeMotion(std::ostream& os, const ProcessParams& params, size_t n)
{
  os << "MoveL CalcRobT(jTarget_" << n << ",tool0), v100, z40, tool0;\n";
  return os.good();
}
bool rapid_emitter::emitJointPosition(std::ostream& os, const TrajectoryPt& pt, size_t n)
{
  os << "TASK PERS jointtarget jTarget_" << n << ":=[[";
    for (size_t i = 0; i < pt.positions_.size() ; i++)
    {
      os << pt.positions_[i];
      if (i < pt.positions_.size()-1)
      {
        os << ",";
      }
    }
    
  os << "],[9E9,9E9,9E9,9E9,9E9,9E9]];\n";
  return true;
} 
