///////////////////////////////////////
/// V. Hunter Adams
/// vha3@cornell.edu
/// 5/23/2023
///
/// Compile with:
/// gcc lb.c -o gr -O2 -lm
///
///////////////////////////////////////


///////////////////////////////////////
///////////// INCLUDES ////////////////
///////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> 
#include <math.h>


///////////////////////////////////////
////// FIXED-POINT MACROS, ETC ////////
///////////////////////////////////////
// s3.17 format (FPGA memory size)
typedef signed int Fix ;
#define two18 131072.0
#define mFix(a,b) ((Fix)((((signed long long)(a))*((signed long long)(b)))>>17)) 
#define f2Fix(a) ((Fix)((a)*two18)) // 
#define Fix2f(a) ((float)(a)/two18)
#define i2Fix(a) ((Fix)((a)<<17)) // 
#define Fix2i(a) ((int)(a)>>17)
#define absFix(a) abs(a) 
#define divFix(a,b) ((Fix)(((((signed long long)(a))<<17)/(b)))) 

// some multiply macros 
#define m3(a) ((a)+((a)<<1))
#define m1_5(a) ((a)+((a)>>1))
#define m4_5(a) (((a)<<2)+((a)>>1))

// min and max
#define min(X,Y) ((X) < (Y) ? (X) : (Y))
#define max(X,Y) ((X) > (Y) ? (X) : (Y))


///////////////////////////////////////
////// LB PARAMS AND CONSTANTS ////////
///////////////////////////////////////
#define height 50 					// grid height
#define width 50 					// grid width
Fix omega = f2Fix(1./((3*0.002) + 0.5)) ;	// Relaxation parameter (funct. of viscosity)
Fix u0 = f2Fix(0);				// Initial speed
Fix four9ths = f2Fix(4./9.);		// 4/9
Fix one9th   = f2Fix(1./9.);		// 1/9
Fix one36th  = f2Fix(1./36.);		// 1/36
Fix fixone   = f2Fix(1.0) ;

#define times_omega(a) ((a<<1) - (a>>5))



///////////////////////////////////////
////// LATTICE-BOLTZMANN GLOBALS //////
///////////////////////////////////////
// Microscopic densities
Fix n0[height*width]  = {0} ;
Fix nN[height*width]  = {0} ;
Fix nS[height*width]  = {0} ;
Fix nE[height*width]  = {0} ;
Fix nW[height*width]  = {0} ;
Fix nNW[height*width] = {0} ;
Fix nNE[height*width] = {0} ;
Fix nSE[height*width] = {0} ;
Fix nSW[height*width] = {0} ;
// Barriers
Fix bar[height*width] = {0} ;

// measure time
struct timeval t1, t2;
double elapsedTime;
char num_string[20], time_string[20] ;


void initialize(unsigned int xtop, unsigned int ytop, unsigned int yheight, Fix u0) {
	
	// Iterating variables
	unsigned int xcoord = 0 ;
	unsigned int ycoord = 0 ;

	// Total number of cells
	int num_cells = (height*width) ;

	// Useful pre-computed contants
	Fix u0sq 		= mFix(u0, u0) ;
	Fix u0sq_1_5	= m1_5(u0sq) ;
	Fix u0sq_4_5 	= m4_5(u0sq) ;
	Fix u0_3 		= m3(u0) ;

	// Iterating variable
	int i ;

	// Loop through the cells, initialize densities
	for (i=0; i<num_cells; i++) {
		*(n0 + i)  = mFix(four9ths, fixone - u0sq_1_5) ;
		*(nN + i)  = mFix(one9th,   fixone - u0sq_1_5) ;
		*(nS + i)  = mFix(one9th,   fixone - u0sq_1_5) ;
		*(nE + i)  = mFix(one9th,   fixone + u0_3 + u0sq_4_5 - u0sq_1_5) ;
		*(nW + i)  = mFix(one9th,   fixone - u0_3 + u0sq_4_5 - u0sq_1_5) ;
		*(nNW + i) = mFix(one36th,  fixone - u0_3 + u0sq_4_5 - u0sq_1_5) ;
		*(nNE + i) = mFix(one36th,  fixone + u0_3 + u0sq_4_5 - u0sq_1_5) ;
		*(nSW + i) = mFix(one36th,  fixone - u0_3 + u0sq_4_5 - u0sq_1_5) ;
		*(nSE + i) = mFix(one36th,  fixone + u0_3 + u0sq_4_5 - u0sq_1_5) ;

		// And initialize the barrier
		// if (xcoord == xtop) {
		// 	if (ycoord >= ytop) {
		// 		if (ycoord < (ytop+yheight)) {
		// 			*(bar + ycoord*width + xcoord) = 1 ;
		// 		}
		// 	}
		// }

		xcoord = (xcoord < (width-1)) ? (xcoord+1) : 0 ;
		ycoord = (xcoord != 0) ? ycoord : (ycoord+1) ;
	}
}


void stream() {
	// Stream all internal cells
    int x ;
    int y ;
    for (x=0; x<(width-1); x++) {
    	for (y=0; y<(height-1); y++) {
            // # Movement north (Northwest corner)
            *(nN+(y*width) + x) = *(nN + (y*width) + x + width) ;
            // # Movement northwest (Northwest corner)
            *(nNW + y*width + x) = *(nNW + y*width + x + width + 1) ;
            // # Movement west (Northwest corner)
            *(nW + y*width + x) = *(nW + y*width + x + 1) ;
            // # Movement south (Southwest corner)
            *(nS + (height-y-1)*width + x) = *(nS + (height-y-2)*width + x) ;
            // # Movement southwest (Southwest corner)
            *(nSW + (height-y-1)*width + x) = *(nSW + (height-y-2)*width + x + 1) ;
            // # Movement east (Northeast corner)
            *(nE + y*width + (width-x-1)) = *(nE + y*width + (width-x-2)) ;
            // # Movement northeast (Northeast corner)
            *(nNE + y*width + (width-x-1)) = *(nNE + y*width + width + (width-x-2)) ;
            // # Movement southeast (Southeast corner)
            *(nSE + (height-y-1)*width + (width-x-1)) = *(nSE + (height-y-2)*width + (width-x-2)) ;
        }
    }
            
    // Tidy up the edges
    x += 1 ;
    for (y=1; y<(height-1); y++) {
        // Movement north on right boundary (Northwest corner)
        *(nN + y*width + x) = *(nN + y*width + x + width) ;
        // Movement south on right boundary (Southwest corner)
        *(nS + (height-y-1)*width + x) = *(nS + (height-y-1-1)*width + x) ;
    }
}

void bounce() {
	int x ;
	int y ;
	int cellnum ;
	// # Loop through all interior cells
	for (x=2; x<(width-2); x++) {
		for (y=2; y<(height-2); y++) {

			// Compute the cellnum
			cellnum = y*width + x ;
            
            // # If the cell contains a boundary . . .
            if (*(bar+cellnum)){
                
                // # Push densities back from whence they came, then clear the cell
                *(nN + cellnum - width) = *(nS+cellnum) 		; *(nS+cellnum)  = 0 ;
                *(nS + cellnum + width) = *(nN + cellnum) 		; *(nN+cellnum)  = 0 ;
                *(nE + cellnum + 1) = *(nW + cellnum) 			; *(nW+cellnum)  = 0 ;
                *(nW + cellnum - 1) = *(nE + cellnum) 			; *(nE+cellnum)  = 0 ;
                *(nNE + cellnum - width + 1) = *(nSW + cellnum) ; *(nSW+cellnum) = 0 ;
                *(nNW + cellnum - width - 1) = *(nSE + cellnum) ; *(nSE+cellnum) = 0 ;
                *(nSE + cellnum + width + 1) = *(nNW + cellnum) ; *(nNW+cellnum) = 0 ;
                *(nSW + cellnum + width - 1) = *(nNE + cellnum) ; *(nNE+cellnum) = 0 ;

                // Clear zero density
                *(n0+cellnum) = 0 ;
            }
        }
    }
}


void collide() {

	// Iterating/indexing variables
	int x, y, i ;

	// Local variables for density updates
	Fix rho, rho_m_one_sq, rho_inv ;
	Fix ux, uy ;
	Fix vx3, vy3 ;
	Fix one9th_rho, one36th_rho ;
	Fix vx2, vy2, v2 ;
	Fix vxvy2, v215 ;

	Fix nNm, nEm, nWm, nSm, nNEm, nNWm, nSEm, nSWm ;
	Fix vx2_4_5, vy2_4_5 ;
	Fix v2_m_2vxvy_4_5, v2_p_2vyvy_4_5 ;

	// Do not touch cells on top, bottom, left, or right
    for (x=1; x<(width-1); x++) {
        for(y=1; y<(height-1); y++) {
            
            // # What's our current index?
            i = y * width + x;
            
            // # Skip over cells containing barriers                
            if (*(bar+i)==0) {

                // # Compute the macroscopic density
                rho = (*(n0+i) + *(nN+i) + *(nE+i) + *(nS+i) + *(nW+i) +
                	   *(nNE+i) + *(nSE+i) + *(nSW+i) + *(nNW+i) ) ;

                // printf("%f\n", Fix2f(rho)) ;

                // # Compute some convenient constants
                one9th_rho 	= mFix(one9th, rho) ;	// 1/9 times rho
                one36th_rho = mFix(one36th, rho) ;	// 1/36 times rho

                // Taylor expand inverse of rho
                rho_m_one_sq = mFix((rho-fixone), (rho-fixone)) ;
                rho_inv = (fixone-(rho-fixone)+rho_m_one_sq) ;

                // # Compute the macroscopic velocities (vx and vy)
                if (rho > 0){
                    ux  = mFix((*(nE+i) + *(nNE+i) + *(nSE+i) - *(nW+i) - *(nNW+i) - nSW[i]), rho_inv) ;
					uy  = mFix((*(nN+i) + *(nNE+i) + *(nNW+i) - *(nS+i) - *(nSE+i) - nSW[i]), rho_inv) ;
                }

                // # Compute 3x those velocities
                vx3 		= m3(ux) ;				// 3*vx
                vy3 		= m3(uy) ;				// 3*vy
                
                // # Compute squares of velocities, and velocity cross-term
                vx2 		= mFix(ux, ux) ;		// vx^2
                vy2 		= mFix(uy, uy) ;		// vy^2
                vxvy2 		= (mFix(ux, uy)) << 1 ;	// 2*vx*vy
                
                // # Compute convenient constants
                v2 				= vx2 + vy2 ;		// (vx^2 + vy^2)
                v215 			= m1_5(v2) ;		// 1.5*(vx^2 + vy^2)
                vx2_4_5 		= m4_5(vx2) ; 		// 4.5*(vx^2)
                vy2_4_5 		= m4_5(vy2) ; 		// 4.5*(vy^2)
                v2_m_2vxvy_4_5 	= m4_5(v2-vxvy2) ; 	// 4.5*((vx^2 + vy^2) - 2*vx*vy)
                v2_p_2vyvy_4_5 	= m4_5(v2+vxvy2) ;	// 4.5*((vx^2 + vy^2) + 2*vx*vy)
             
                // # Perform collision multiplies
                nEm 	= mFix(one9th_rho,  (fixone + vx3 + vx2_4_5 - v215) ) ;
                nWm 	= mFix(one9th_rho,  (fixone - vx3 + vx2_4_5 - v215) ) ;
                nNm 	= mFix(one9th_rho,  (fixone + vy3 + vy2_4_5 - v215) ) ;
                nSm 	= mFix(one9th_rho,  (fixone - vy3 + vy2_4_5 - v215) ) ;
                nNEm 	= mFix(one36th_rho, (fixone + vx3 + vy3 + v2_p_2vyvy_4_5 - v215) ) ;
                nNWm 	= mFix(one36th_rho, (fixone - vx3 + vy3 + v2_m_2vxvy_4_5 - v215) ) ;
                nSEm 	= mFix(one36th_rho, (fixone + vx3 - vy3 + v2_m_2vxvy_4_5 - v215) ) ;
                nSWm 	= mFix(one36th_rho, (fixone - vx3 - vy3 + v2_p_2vyvy_4_5 - v215) ) ;
                
                // # Update densities
                *(nE+i)  += times_omega((   nEm - *(nE+i)))  ;
                *(nW+i)  += times_omega((   nWm - *(nW+i)))  ;
                *(nN+i)  += times_omega((   nNm - *(nN+i)))  ;
                *(nS+i)  += times_omega((   nSm - *(nS+i)))  ;
                *(nNE+i) += times_omega((  nNEm - *(nNE+i)))  ;
                *(nNW+i) += times_omega((  nNWm - *(nNW+i)))  ;
                *(nSE+i) += times_omega((  nSEm - *(nSE+i)))  ;
                *(nSW+i) += times_omega((  nSWm - *(nSW+i)))  ;
                
                // # Conserve mass
                *(n0+i)   = rho - (*(nE+i) + *(nW+i) + *(nN+i) + *(nS+i) + *(nNE+i) + *(nSE+i) + *(nNW+i) + *(nSW+i));

                // Draw the pixel
                // VGA_PIXEL(x+50,y+100,((v2>>7) & 0x3F) << 5) ;

            }
        }
    }
}

	
// int main(void)
// {   
  

// 	// Initialize the simulation
// 	initialize(25, 11, 10, u0) ;

// 	printf("Fixone: %08x\n", fixone) ;
// 	printf("1/9: %08x\n", one9th) ;
// 	printf("1/36: %08x\n", one36th) ;
// 	printf("Naught: %08x\n", *(n0 + 1000)) ;
// 	printf("North: %08x\n", *(nN + 1000)) ;
// 	printf("South: %08x\n", *(nS + 1000)) ;
// 	printf("East: %08x\n", *(nE + 1000)) ;
// 	printf("West: %08x\n", *(nW + 1000)) ;
// 	printf("Northwest: %08x\n", *(nNW + 1000)) ;
// 	printf("Northeast: %08x\n", *(nNE + 1000)) ;
// 	printf("Southwest: %08x\n", *(nSW + 1000)) ;
// 	printf("Southeast: %08x\n\n", *(nSE + 1000)) ;

// 	int j ;
// 	char junk[8] ;

	
// 	while(1) 
// 	{

// 		// Start timer
// 		gettimeofday(&t1, NULL);

// 		// Update all cells
// 		stream() ;
// 		bounce() ;
// 		collide() ;
	
// 		// stop timer, display time
// 		gettimeofday(&t2, NULL);
// 		elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000000.0;      // sec to us
// 		elapsedTime += (t2.tv_usec - t1.tv_usec) ;   // us 
// 		printf("T = %6.0f uSec  ", elapsedTime);	
		
// 	} // end while(1)
// } // end main

// ADD AT THE BOTTOM OF FILE
void dump_rho_to_file(const char *filename) {
    FILE *f = fopen(filename, "w");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int i = y * width + x;
            Fix rho = n0[i] + nN[i] + nE[i] + nS[i] + nW[i] +
                      nNE[i] + nSE[i] + nSW[i] + nNW[i];
            fprintf(f, "%f ", Fix2f(rho));
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void dump_speed2_to_file(const char *filename) {
    FILE *f = fopen(filename, "w");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int i = y * width + x;
            if (bar[i]) {
                fprintf(f, "0 ");
                continue;
            }
            Fix rho = n0[i] + nN[i] + nE[i] + nS[i] + nW[i] +
                      nNE[i] + nSE[i] + nSW[i] + nNW[i];
            Fix rho_m1 = rho - fixone;
            Fix rho_inv = fixone - rho_m1 + mFix(rho_m1, rho_m1);
            Fix ux = mFix(nE[i] + nNE[i] + nSE[i] - nW[i] - nNW[i] - nSW[i], rho_inv);
            Fix uy = mFix(nN[i] + nNE[i] + nNW[i] - nS[i] - nSE[i] - nSW[i], rho_inv);
            Fix speed2 = mFix(ux, ux) + mFix(uy, uy);
            fprintf(f, "%f ", Fix2f(speed2));
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

// MODIFY main()
int main(void)
{   
    initialize(25, 11, 10, u0);

    char fname[64];
    int max_frames = 9;

    for (int frame = 0; frame < max_frames; frame++) {
        stream();
        bounce();
        collide();

        sprintf(fname, "frames/speed2_frame_%04d.txt", frame);
        dump_speed2_to_file(fname);
    }

    printf("Frames written to 'frames/' folder.\n");
    return 0;
}
