

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14

int nx = 3;
int ny = 3;
int nz = 3;


void computeAndCopy(double ***pDouble, double ***pDouble1);

int main() {

    int interations = 5;

    double ***v, ***u;

    v = malloc(nz * sizeof *v);
    u = malloc(nz * sizeof *u);


    v[0] = malloc(nz * ny * sizeof *v[0]);
    u[0] = malloc(nz * ny * sizeof *u[0]);

    v[0][0] = malloc(nz * ny * nx * sizeof *v[0][0]);
    u[0][0] = malloc(nz * ny * nx * sizeof *u[0][0]);

    for (int i = 1; i < nz; i++) {
        v[i] = &v[0][i * ny];
    }

    for (int j = 1; j < nz*ny; j++) {
        v[0][j] = &v[0][0][j * nx];
    }

    for (int i = 0; i < nz; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nx; k++) {
                double frac = (i * j * k * PI)/((nx - 1) * (ny - 1) * (nz - 1));
                v[i][j][k] = 2.0 + sin(frac );
                u[i][j][k] = 0;
            }
        }
    }

    computeAndCopy(v, u);

    free(v[0][0]);
    free(v[0]);
    free(v);

    free(u[0][0]);
    free(u[0]);
    free(u);

}

void computeAndCopy(double ***u, double ***v) {

    for (int i = 1; i < nx-1; i++) {
        for (int j = 1; j < ny-1; j++) {
            for (int k = 1; k < nz-1; k++) {

                u[i][j][k] = v[i][j][k] + ( (v[i-1][j][k] + v[i][j-1][k] + v[i][j][k-1] - (6 * v[i][j][k]) + v[i+1][j][k] + v[i][j+1][k] + v[i][j][k+1]) / 6 );

                v[i][j][k] = u[i][j][k];

            }
        }
    }



}

