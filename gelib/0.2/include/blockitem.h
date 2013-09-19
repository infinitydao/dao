/*              blockitem.h
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#ifndef __BLOCKITEM_H__
#define __BLOCKITEM_H__

//=========================================================================
namespace gelib
{

class BlockItem : public IStaticItem
{
public:
  explicit BlockItem( int x, int y, int width, int height );
  explicit BlockItem( const QPoint& p, const QSize& size );
  explicit BlockItem( const BlockItem& other );
  ~BlockItem();
  BlockItem& operator=( const BlockItem& other );
};

} //namespace glib

//=========================================================================

#endif //__BLOCKITEM_H__
