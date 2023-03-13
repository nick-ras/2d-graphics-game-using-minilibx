# so_long
2d graphics game, where have to collect items and find an exit.
see the subject pdf for  requirements.
Program can be run in WSL2 or mac. If you use WSL2 then you have to have x11 forwarding.


To make library and x11forwarding work, you have to follow instructions from here: https://github.com/42Paris/minilibx-linux.
After following this tutorial then you can try running the tests in the minilibx*/test folder, to see if graphics is working.
When this is done, you can run my code with makefile by typing "make re && ./so_long maps/map4.ber" or other map if you prefer.
There is no memoryleaks to my knowledge. The project has been thoroughly tested by 3 of my peers.
