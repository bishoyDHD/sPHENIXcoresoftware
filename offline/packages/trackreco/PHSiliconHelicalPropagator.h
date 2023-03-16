#include <trackreco/PHTrackPropagating.h>
#include <trackbase/ActsGeometry.h>
#include <trackbase_historic/TrackSeedContainer.h>
#include <trackermillepedealignment/HelicalFitter.h>
#include <trackbase_historic/SvtxTrackMap.h>

class PHSiliconHelicalPropagator : public SubsysReco
{
public:

  PHSiliconHelicalPropagator(std::string name = "PHSiliconHelicalPropagator");
  ~PHSiliconHelicalPropagator();

  int InitRun(PHCompositeNode *topNode) override;
  int process_event(PHCompositeNode *topNode) override;
  int End(PHCompositeNode *topNode) override;

  void set_track_map_name(std::string name){ _track_map_name = name; }
private:
  ActsGeometry* _tgeometry = nullptr;
  TrackSeedContainer* _si_seeds = nullptr;
  HelicalFitter* _fitter = nullptr;
  TrkrClusterContainer* _cluster_map = nullptr;
  SvtxTrackMap* _track_map = nullptr;
  std::string _track_map_name = "SvtxTrackMap";
};
