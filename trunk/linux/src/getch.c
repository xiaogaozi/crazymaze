/*
 * Behavior like getch() function in Window$.
 */

/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

int getch()
{
  int c = 0;
  struct termios org_opts, new_opts;
  int res = 0;

  /*
   * Store old settings.
   */
  res = tcgetattr(STDIN_FILENO, &org_opts);
  assert(res == 0);

  /*
   * Set new terminal parms.
   */
  memcpy(&new_opts, &org_opts, sizeof(new_opts));
  new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
  tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
  c = getchar();

  /*
   * Restore old settings.
   */
  res = tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
  assert(res == 0);

  return c;
}
