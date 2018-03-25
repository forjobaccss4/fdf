#include "fdf.h"
 
void line(t_lst *win, int *xytxtywhc, int x2, int y2)
{
      int dx = (x2 - xytxtywhc[0] >= 0 ? 1 : -1);
      int dy = (y2 - xytxtywhc[1] >= 0 ? 1 : -1);
 
      int lengthX = abs(x2 - xytxtywhc[0]);
      int lengthY = abs(y2 - xytxtywhc[1]);
 
      int length = fmax(lengthX, lengthY);
 
      if (length == 0)
      {
            mlx_pixel_put(win->mlx_ptr, win->win_prt, xytxtywhc[0], xytxtywhc[1], 0x00ffae);
      }
 
      if (lengthY <= lengthX)
      {
            // Начальные значения
            int x = xytxtywhc[0];
            int y = xytxtywhc[1];
            int d = -lengthX;
 
            // Основной цикл
            length++;
            while(length--)
            {
                  mlx_pixel_put(win->mlx_ptr, win->win_prt, x, y, 0x00ffae);
                  x += dx;
                  d += 2 * lengthY;
                  if (d > 0) {
                        d -= 2 * lengthX;
                        y += dy;
                  }
            }
      }
      else
      {
            // Начальные значения
            int x = xytxtywhc[0];
            int y = xytxtywhc[1];
            int d = - lengthY;
 
            // Основной цикл
            length++;
            while(length--)
            {
                  mlx_pixel_put(win->mlx_ptr, win->win_prt, x, y, 0x00ffae);
                  y += dy;
                  d += 2 * lengthX;
                  if (d > 0) {
                        d -= 2 * lengthY;
                        x += dx;
                  }
            }
      }
}
