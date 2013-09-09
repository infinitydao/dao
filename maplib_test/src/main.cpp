#include "map.h"

#define MAP_M 6
#define MAP_N 5

int main( int argc, char *argv[] )
{
  maplib::Map map( MAP_M, MAP_N );
  for( int i = 0; i < MAP_M; i++ ){
    for( int j = 0; j < MAP_N; j++ ){
      if( i != 0 && i != MAP_M && j != 0 && j != MAP_N )
        map.m_map[i][j]->setType( maplib::RegionItem::Free );
    }
  }
  return 0;
}
