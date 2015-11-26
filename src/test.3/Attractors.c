/* 
 * Copyright 2015 Eugenio Parodi <ceccopierangiolieugenio at googlemail>.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Based on the article:
 *    Attractors and Fractals 
 *    Grant Schindler, 2008
 *    http://www.cc.gatech.edu/~phlosoft/attractors/
 *
 *    References:
 *    Scott Draves. Fractal Flames (http://flam3.com/). 1992.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#define X_RES ( 256 * 2 )
#define Y_RES ( 256 * 2 )

#define N_SAMPLES 5000000

/**
 * # accumulate_points
 *
 * Generate sample points (N_SAMPLES)
 * and populate the Image Array
 * looping through:
 *     xn+1 = sin(ca*yn) - cos(cb*xn)
 *     yn+1 = sin(cc*xn) - cos(cd*yn)
 *
 * @param[in]	a	Image Array
 * @param[in]	cX	Noise to Coefficients
 */
static void accumulate_points(float (*a)[Y_RES][4],float ca, float cb, float cc, float cd){
	float ce = 0.7f, cf = -1.1f;
	float x = 0, y = 0, z = 0;
	int loop = N_SAMPLES;
	while(loop--){
		float x1 = sin(ca*y) - cos(cb*x);
		float y1 = sin(cc*x) - cos(cd*y);
		/* z coefficient used to improve the imge result */
		float z1 = sin(ce*x) - cos(cf*z);
		x = x1, y = y1, z = z1;

		/* -2 <= (x,y) <= +2 */
		int xa = (int)((x+2.2f)/4.5f*X_RES);
		int ya = (int)((y+2.2f)/4.5f*Y_RES);
		/* Map Z-Coordinate to Color */
		a[xa][ya][0]+= z * 0.9 + (1.0-z) * 0.6;
		a[xa][ya][1]+= z * 0.2 + (1.0-z) * 0.4;
		a[xa][ya][2]+= z * 0.5 + (1.0-z) * 0.9;
		a[xa][ya][3]++;
	}
}

/**
 * # get_max
 *
 * Return the max value in the input array
 *
 * @param[in]	a	Image Array
 */
static float get_max(float (*a)[Y_RES][4]){
	float max = 0;
	for (int i=X_RES; i--;)
		for (int ii=Y_RES; ii--;)
			max = max<a[i][ii][3]?a[i][ii][3]:max;
	return max;
}

/**
 * # main
 */
int main(int argc, char** argv) {
	float (*points)[Y_RES][4];
	int max;

	/* SDL init */
	SDL_Init(SDL_INIT_VIDEO);
	printf("(Ticks) Start: %d ms\n",SDL_GetTicks());

	SDL_Surface *screen = SDL_SetVideoMode(X_RES, Y_RES, 32, SDL_SWSURFACE);

	/* Allocate the 2D points array */
	points = (float (*)[Y_RES][4])calloc(1,sizeof(points));
	if (NULL == points){
		printf("calloc error\n");
		return -1;
	}

	/* Accumulate Samples */
	accumulate_points(points, 1.5f, 2.5f, 3.5f, 3.5f);
	max = get_max(points);

	/* Drawing to SDL */
	if (SDL_MUSTLOCK(screen)) SDL_LockSurface(screen);
	for (int i=X_RES; i--;){
		for (int ii=Y_RES; ii--;){
			int alpha = 255;
			/* Postproces colors */
			float c = log(max); c*=c/255.0f;
			float r = log(points[i][ii][0]); r*=r/c;
			float g = log(points[i][ii][1]); g*=g/c;
			float b = log(points[i][ii][2]); b*=b/c;
			/* Populate pixel map */
			*((Uint32*)screen->pixels+i*X_RES+ii) = SDL_MapRGBA(screen->format, r, g, b, alpha);
		}
	}
	if (SDL_MUSTLOCK(screen)) SDL_UnlockSurface(screen);
	SDL_Flip(screen); 

	printf("(Ticks) End: %d ms\n",SDL_GetTicks());
	SDL_Quit();
	return 0;
}

