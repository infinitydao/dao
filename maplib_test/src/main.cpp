#include "maplib.h"

#define MAP_M 25
#define MAP_N 25

int main( int argc, char *argv[] )
{
  maplib::Map map;
  maplib::MapFile file( map, "first.map" );
  if( file.Open() ){
    file.Load();
  }

  //maplib::Map map( MAP_M, MAP_N );
  for( int i = 0; i < map.m(); i++ ){
    for( int j = 0; j < map.n(); j++ ){
      if( i != 0 && i != map.m() - 1 && j != 0 && j != map.n() - 1 ){
        map.m_map[i][j]->setType( maplib::RegionItem::Free );
        maplib::MapConsole( map.m_map[i][j]->type(), i, j );
      }
      else{
        maplib::MapConsole( map.m_map[i][j]->type(), i, j );
      }
    }
  }

// testing for saving in the file
//   maplib::MapFile file( map, "first.map" );
//   if( file.Open() )
//     file.Save();

  return 0;
}
