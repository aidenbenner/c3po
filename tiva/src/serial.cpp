/*
 * Serial helpers
 */

#include <Energia.h>
#include <string.h> 
#include <stdlib.h>
#include "serial.h"
#include "utils.h"

static const int BUFFER_MAX = 1028;

void serial_init ()
{
  Serial.begin (9600);
}

char * serial_readline (void)
{
  char *buffer = (char *) malloc (sizeof (char) * BUFFER_MAX);
  memset (buffer, '\0', BUFFER_MAX);

  char c;
  int count = 0;

  while (count < BUFFER_MAX - 1)
  {
    if (Serial.available ())
    {
      c = Serial.read();

      if (c == '\n')
        break;

      buffer[count] = c;
      count ++;
    }
  }

  return buffer;
}
