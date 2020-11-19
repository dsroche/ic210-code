/* gps.c: header file for GPS coordinates functions
 * You MAY NOT CHANGE this file.
 */

#ifndef GPS_H
#define GPS_H

// mean radius of the earth in miles
#define EARTH_RADIUS (3958.7613)

// stores a GPS coordinate as latitude and longitude in radians
struct gpsco {
  double latrad;
  double lonrad;
};

// you can just say "gpsco" with this typedef.
typedef struct gpsco gpsco;

// creates a gpsco from latitude and longitude in degrees
gpsco make_gps(double latdeg, double londeg);

// gets the latitude in degrees from the given gpsco struct
double gps_latdeg(gpsco pt);

// gets the longitude in degrees from the given gpsco struct
double gps_londeg(gpsco pt);

// returns the distance in miles between two GPS points
double gps_dist(gpsco p1, gpsco p2);

#endif // GPS_H
