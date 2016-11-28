#include <Energia.h>
#include <stdlib.h>
#include "sensors/sensors.h"
#include "sensors/accel.h"
#include "oled.h"
#include "serial.h"
#include "Wire_Util.h"
#include "menu.h"
#include "parser.h"
#include "state.h"

void device_init ()
{
  serial_init ();
  WireInit ();
  oled_init ();
  accel_init ();
  init_sensors (); 
  refresh_all ();
  menu_init (); 
  led_left_right (255, true);
  led_left_right (255, false);
}

void setup ()
{
  device_init ();
}

void loop ()
{
  display_menu (); 
  delay(5);
}
