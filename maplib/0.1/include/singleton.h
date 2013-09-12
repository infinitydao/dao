/*
          singleton.h
Created by infinitydao@gmail.com 
            09/2013
 General Publing License v 2.0
*/

#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <memory>

//=========================================================================
namespace maplib
{

template <class T>
class Singleton
{
public:
  static T* instance()
  {
    if( &*_inst == 0 )
      return _inst.reset( new T );
    return &*_inst;
  }

  static T* release()
  {
    return _inst.release();
  }

  static void reset( T *const ptr = 0 )
  {
    _inst.reset(ptr);
  }

private:
  static std::auto_ptr<T> _inst;
  Singleton();
};

}

//=========================================================================

#endif //__SINGLETON_H__