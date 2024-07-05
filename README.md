# NavierStokes
C implementation for each exercise of Lorena Barba's "12 Steps to Navier Stokes".

Files are arranged by modules:

<samp>1d.c</samp> includes one-dimensional exercises:
1. Linear convection: $\frac{\partial u}{\partial t} + c \frac{\partial u}{\partial x} = 0,\ u=2$ for $x\in [0.5,\ 1]$ and $u=1$ on $[0,2]$ for $x\notin [0.5, 1]$.
2. Nonlinear convection: $\frac{\partial u}{\partial t} + u \frac{\partial u}{\partial x}$ with same conditions as (1).
3. Diffusion Equation: $\frac{\partial u}{\partial t} = \nu \frac{\partial^2 u}{\partial^2 x}$ with same conditions as (1).
4. Burger's Equation: $\frac{\partial u}{\partial t} + u \frac{\partial u}{\partial x} = \nu \frac{\partial^2 u}{\partial^2 x}$
