#include "map.h"

#define MAP_M 25
#define MAP_N 25

int main( int argc, char *argv[] )
{
  maplib::Map map( MAP_M, MAP_N );
  for( int i = 0; i < MAP_M; i++ ){
    for( int j = 0; j < MAP_N; j++ ){
      if( i != 0 && i != MAP_M - 1 && j != 0 && j != MAP_N - 1 ){
        map.m_map[i][j]->setType( maplib::RegionItem::Free );
        maplib::MapConsole( map.m_map[i][j]->type(), i, j );
      }
      else{
        maplib::MapConsole( map.m_map[i][j]->type(), i, j );
      }
    }
  }
  return 0;
}
