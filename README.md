inilibX Project
Description:
The MinilibX project involves creating a simple graphics library that allows you to open a window, draw basic shapes, and handle user input in a graphical environment. The goal of the project is to understand the fundamentals of graphics programming in C and learn how to interact with the X11 window system on Unix-like systems. MinilibX simplifies drawing pixels, handling window events, and providing an interface for graphical output.

In this project, you'll implement basic graphical functions such as creating a window, drawing images, and handling keyboard or mouse inputs. This is a foundational project for understanding how graphical user interfaces (GUIs) work at a low level and how they interact with hardware and operating systems.

Project Requirements:
Window Management:
You need to create a window on the screen where graphics can be rendered. This window should respond to events like resizing or closing.

Drawing Basic Graphics:
The library should allow drawing basic shapes such as pixels, lines, and rectangles in the window.

Event Handling:
Handle events like mouse clicks, mouse movements, and key presses to allow interaction with the graphical content displayed in the window.

Graphics Manipulation:
You should provide functionality to change the color of pixels, draw images, and manage layers of graphics on the screen.

Key Restrictions & Challenges:
X11 and Low-Level Graphics:
MinilibX requires interacting with the X11 system, which is a low-level window system on Unix-based systems. This means you need to understand how X11 works, including its event loop, window management, and graphics context. The project forces you to handle the intricacies of working with an external system and library for graphics.

Event Handling:
Event handling in MinilibX is typically done in a loop, where the program constantly checks for user inputs like keyboard presses or mouse movements. Handling these inputs in a real-time event-driven manner can be tricky, especially if you have multiple events happening simultaneously.

Graphics Rendering:
Rendering graphics involves using low-level functions to manipulate the display buffer. The challenge lies in understanding how to manipulate pixel data and manage graphical output in an efficient manner.

Memory Management:
MinilibX requires efficient memory handling to store and manage images or graphical objects. Ensuring that memory is properly allocated, freed, and that no memory leaks occur while manipulating graphics is an essential part of the project.

Limited Functionality:
Unlike full-featured graphics libraries like OpenGL or SDL, MinilibX is designed to be minimalist, which means you need to implement many features manually. You don’t have access to advanced graphical techniques, so it pushes you to use basic methods and algorithms to handle render



Requirements for running it:
Program can be run in WSL2 or mac. If you use WSL2 then you have to have x11 forwarding.
See the en.subject.pdf for project description
To make minilibx library and x11forwarding work, you have to follow instructions from here: https://github.com/42Paris/minilibx-linux.
After following this tutorial then you can try running the tests in the minilibx*/test folder, to see if graphics is working.
When this is done, you can run my code with makefile by typing "make re && ./so_long maps/map4.ber" or other map if you prefer.
There is no memoryleaks to my knowledge. The project has been thoroughly tested by 3 of my peers.

How to run
Command--> "make; ./so_long maps/map1.ber" (orname of map you want to run)
