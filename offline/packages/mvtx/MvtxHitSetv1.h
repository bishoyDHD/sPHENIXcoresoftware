#ifndef __MvtxHitSetv1_H__
#define __MvtxHitSetv1_H__

#include <trackbase/TrkrHitSetv1.h>

#include <map>
#include <utility>

class MvtxHitSetv1 : public TrkrHitSetv1
{
public:

  typedef std::multimap<uint16_t, uint16_t> HitMap;
  typedef HitMap::iterator Iterator;
  typedef HitMap::const_iterator ConstIterator;
  typedef std::pair<Iterator, Iterator> Range;
  typedef std::pair<ConstIterator, ConstIterator> ConstRange;

  /// ctor
  MvtxHitSetv1();

  /// dtor
  virtual ~MvtxHitSetv1() {}

  virtual void identify(std::ostream& os = std::cout) const;
  virtual void Reset();
  void print() const;

  /// add a pixel hit
  void addHit(const uint16_t col, const uint16_t row);

  /// get all hits
  ConstRange getHits( void );

  /// get all hits in a given column (useful?)
  ConstRange getHits(const uint16_t col);

private:

  HitMap m_hits; ///< Hit storage object

  ClassDef(MvtxHitSetv1, 1);
};


#endif //__MvtxHitSetv1_H__
