#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

// 1D Linear Convection
void exercise_1() {
	int nx, nt;
	float dx, dt, c, *u, *u_prev;

	// defining constants
	nx = 41;
	dx = 2.0 / (nx - 1);
	nt = 25;
	dt = nt / 1000.0;
	c = 1.0;

	// defining u according to ICs
	u = malloc(nx * sizeof(float));

	for (int i = 0; i < nx; i++) {
		if ((i * dx < 0.5) || (i * dx > 1.0)) u[i] = 1.0;			// u = 1 on [0, 0.5)U(1, 2]
		else u[i] = 2.0;											// u = 2 on [0.5, 1]
	}

	// copy u into u_prev
	u_prev = malloc(sizeof(*u));


	// finite difference method
	for (int n = 0; n < nt; n++) {
		for (int i = 0; i < nx; i++) u_prev[i] = u[i]; 	// subroutine to copy u into u_prev
		for (int i = 1; i < nx; i++) {
			u[i] = u_prev[i] - c * dt / dx * (u_prev[i] - u_prev[i - 1]);
		}
	}
	plot_1d(0.0, dx, nx, u, "exercise1.dat");
}

// 1D Nonlinear Convection... most code copied directly from exercise 1
void exercise_2() {
	int nx, nt;
	float dx, dt, c, * u, * u_prev;

	nx = 41;
	dx = 2.0 / (nx - 1);
	nt = 25;
	dt = nt / 1000.0;
	c = 1.0;

	u = malloc(nx * sizeof(float));

	for (int i = 0; i < nx; i++) {
		if ((i * dx < 0.5) || (i * dx > 1.0)) u[i] = 1.0;
		else u[i] = 2.0;
	}
	u_prev = malloc(sizeof(*u));

	for (int n = 0; n < nt; n++) {
		for (int i = 0; i < nx; i++) u_prev[i] = u[i]; 
		for (int i = 1; i < nx; i++) {
			u[i] = u_prev[i] - u_prev[i] * dt / dx * (u_prev[i] - u_prev[i - 1]);	// changed constant c to nonlinear term
		}
	}
	plot_1d(0.0, dx, nx, u, "exercise2.dat");
}

// 1D Diffusion
void exercise_3() {


	// PROBLEMS WITH THSI EXERCISE... example does not trail off at RHS. One too many DOF? Left point is fixed according to BC?
	// Consult lesson 4 on Laura Barba's YT

	int nx, nt;
	float dx, dt, nu, sigma, * u, * u_prev;

	nx = 41;
	dx = 2.0 / (nx - 1);
	nt = 20;
	nu = 0.3;			// viscosity value
	sigma = 0.2;		// another parameter for the equation, used to define dt
	dt = sigma * dx * dx / nu;
	
	u = malloc(nx * sizeof(float));

	for (int i = 0; i < nx; i++) {
		if ((i * dx < 0.5) || (i * dx > 1.0)) u[i] = 1.0;
		else u[i] = 2.0;
	}
	
	u_prev = malloc(sizeof(*u));

	for (int n = 0; n < nt; n++) {
		for (int i = 0; i < nx; i++) u_prev[i] = u[i];
		for (int i = 1; i < nx; i++) {
			// u[i] = un[i] + nu * dt / dx**2 * (un[i+1] - 2 * un[i] + un[i-1])
			u[i] = u_prev[i] + nu * dt / dx / dx * (u_prev[i + 1] - 2 * u_prev[i] + u_prev[i - 1]); // central difference method due to second order partial derivatives
		}
	}
	plot_1d(0.0, dx, nx, u, "exercise3.dat");

}
