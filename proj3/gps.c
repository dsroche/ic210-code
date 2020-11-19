/* gps.c: Function implementations for GPS coordinates.
 * You MAY NOT CHANGE this file.
 */

#include "gps.h"
#include <math.h>

// helper functions to convert between degrees and radians
double deg2rad(double deg) {
  return deg * M_PI / 180.0;
}

double rad2deg(double rad) {
  return rad * 180.0 / M_PI;
}

// creates a gpsco from latitude and longitude in degrees
gpsco make_gps(double latdeg, double londeg) {
  gpsco pt;
  pt.latrad = deg2rad(latdeg);
  pt.lonrad = deg2rad(londeg);
  return pt;
}

// gets the latitude in degrees from the given gpsco struct
double gps_latdeg(gpsco pt) {
  return rad2deg(pt.latrad);
}

// gets the longitude in degrees from the given gpsco struct
double gps_londeg(gpsco pt) {
  return rad2deg(pt.lonrad);
}

// the haversine of theta = (sin(theta/2))^2
double hav(double rads) {
  double s = sin(rads/2);
  return s*s;
}

// returns the distance in miles between two GPS points
double gps_dist(gpsco p1, gpsco p2) {
  // haversine formula: https://en.wikipedia.org/wiki/Haversine_formula
  double h = hav(p2.latrad - p1.latrad)
             + cos(p1.latrad) * cos(p2.latrad)
               * hav(p2.lonrad - p1.lonrad);
  return EARTH_RADIUS * 2 * atan2(sqrt(h), sqrt(1.0-h));
}
