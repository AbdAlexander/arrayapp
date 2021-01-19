// Az array_appender már korábban létrehozott hagyományos, C int tömbök logikai
// egymásután fűzését támogatja, azaz az elemek indexeléssel elérhetőek, de
// ténylegesen ott maradnak az eredeti tömbben. Az append művelettel egy
// tömböt lehet az eddigiek végéhez fűzni, a size()-zal lekérdezhető az
// elemszám, az at és indexelés egyaránt a tömb elemeit kérdezi le és engedi
// felülírni.

#include <iostream>
#include "arrapp.h"
#include "arrapp.h"

bool check()
{
  int a[] = { 3, 8, 1, 2 };
  int b[] = { 1, 7, 2, 5, 4 };
  int c[] = { 5, 1, 2 };
  array_appender s;
  s.append( a, sizeof( a ) / sizeof( a[ 0 ] ) );
  s.append( b, sizeof( b ) / sizeof( b[ 0 ] ) );
  s.append( c, sizeof( c ) / sizeof( c[ 0 ] ) );

  int d[] = { 1, 8, 5 };
  int e[] = { 8, 2, 1 };
  int f[] = { 7, 1 };
  int g[] = { 2, 5 };
  array_appender t;

  t.append( g, sizeof( g ) / sizeof( g[ 0 ] ) );
  t.append( f, sizeof( f ) / sizeof( f[ 0 ] ) );
  t.append( e, sizeof( e ) / sizeof( e[ 0 ] ) );
  t.append( d, sizeof( d ) / sizeof( d[ 0 ] ) );

  if ( 10 != t.size() )
  {
    return false;
  }
  
  t.at( 5 ) = 3;
  s.at( 5 ) = 8;
  ++s.at( 4 );

  if ( 8 != b[ 1 ] || 2 != t.at( 0 ) || 2 != b[ 0 ] )
  {
    return false;
  }
  
  t[ 9 ]--;
  s[ 2 ] = 3;

  return ( 3 == a[ 2 ] );
}

int main()
{
  std::cout
    << "Your solution is " << (check() ? "" : "not ")
    << "ready for submission.\n";
}
