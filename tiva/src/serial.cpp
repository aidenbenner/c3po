/*
 * Serial helpers
 */

#include <Energia.h>
#include <string.h>
#include <stdlib.h>
#include "serial.h"
#include "utils.h"

void serial_init ()
{
  Serial.begin (9600);
}

char * serial_readline (size_t serial_size)
{
  char *buffer = (char *) malloc (sizeof (char) * serial_size);
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
