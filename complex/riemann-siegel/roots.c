/*************************************************************************
 * *
 *Program to verify the Riemann hypothesis up to Gram point END. The *
 *main routine uses the Riemann-Siegel formula for fast evaluation of *
 *the zeta function. *
 * *
 *This program counts the number of zeros of the Riemann zeta function *
 *between Gram points BEGIN and END. The program establishes the *
 *existence of a zero with complete certainty, and thus produces a lower *
 *bound on the number of zeros in the search range. There is the *
 *possibility that a zero will be missed in the case where |Z(t)| is *
 *less than the error tolerance, and hence the sign of Z(t) cannot be *
 *determined with certainty. In these situations, a warning is written *
 *to the RESULTFILE indicating that the questionable region should be *
 *examined with more accuracy. *
 * *
 *Output to the RESULTFILE consists of the count of roots found, the *
 *number of Gram blocks found, the total number of roots within these *
 *Gram blocks, and the longest and shortest Gram blocks found. *
 **
 *************************************************************************/

#include <stdio.h>
#include <math.h>

#define BEGIN - 1 /*initial Gram point */ 
#define END 12193873 /*final Gram point */ 
#define RESULTFILE "results.txt" /*output file for results */

/************************************************************************/

int main()
{
	FILE * results_file; /*output file for results */
	long double Z(long double, int); /*Riemann-Siegel Z(t) function */
	long double gram(int); /*Gram point location function */
	int gramblock(int, int, FILE *); /*Gram block root count function */
	int even(int); /*-1,+1 parity function */
	int gpt_final; /*index of final Gram point */
	int gpt_indx; /*index of current Gram point */
	int tot_roots; /*root counter */
	int gblock_start; /*current Gram block lower index */
	int gblock_end; /*current Gram block upper index */
	int gblock_roots; /*roots in current Gram block */
	int tot_gblocks; /*total Gram blocks found */
	int tot_gblock_roots; /*total Gram block roots found */
	int l_gblock_start; /*longest Gram block left index */
	int l_gblock_end; /*longest Gram block right index */
	gpt_indx = BEGIN; /*initializations */
	gpt_final = END; /**/
	tot_roots = 0; /**/
	gblock_roots = 0; /**/
	tot_gblocks = 0; /**/
	tot_gblock_roots = 0; /**/
	l_gblock_start = -1; /**/
	l_gblock_end = -1; /**/
	results_file = fopen(RESULTFILE, "w"); /*open output file */
	while (gpt_indx < gpt_final) /*while not at last */
	{ /*Gram point... */
		++gpt_indx; /*go to next one */
		if (even(gpt_indx) *Z(gram(gpt_indx), 1) /*if Gram’s Law */ >
			0.053 L / powl(gram(gpt_indx), 1.25 L)) /*satified, */
			++tot_roots; /*increment total */
		/*number of roots... */
		else /*otherwise, try */
			if (even(gpt_indx) *Z(gram(gpt_indx), 4) /*more precise */ >
				0.053 L / powl(gram(gpt_indx), 1.25 L)) /*calculation of */
				++tot_roots; /*Z(t)... */
			else /*still not */
			{ /*satisfied? then we */
				/*have a Gram */
				/*block... */
				gblock_start = gpt_indx - 1; /*identify left */
				/*index of block... */
				while (even(gpt_indx) /*test succeeding */ *
					Z(gram(gpt_indx), 1) /*Gram points */<=
					/*until Gram’s Law */
					0.053 L / powl(gram(gpt_indx), /*once again */
						1.25 L)) /*satisfied... */
					++gpt_indx; /**/
				gblock_end = gpt_indx; /*identify right */
				/*index of block */
				gblock_roots = /*determine number */
					gramblock(gblock_start, gblock_end, /*of roots inside */
						results_file); /*the Gram block... */
				++tot_gblocks; /*increment root and */
				tot_gblock_roots += gblock_roots; /*Gram block */
				tot_roots += gblock_roots; /*counters */
				if (gblock_end - gblock_start /*determine if the */ >
					l_gblock_end - l_gblock_start) /*new Gram block */
				{ /*is longest so far */
					l_gblock_start = gblock_start; /**/
					l_gblock_end = gblock_end; /* */
				} /**/
			}
		if (gpt_indx % 1000 == 0) /*write progress */
			printf("%d roots located to Gram point" /*message to screen */
				" %d\n", /**/
				tot_roots, gpt_indx); /**/
	}
	fprintf(results_file, "Number of roots to" /*write results to */
		" Gram point N = %d is %d\n", /*output file: */
		gpt_indx, tot_roots); /*...total roots, */
	fprintf(results_file, "Number of Gram" /**/
		" blocks found is %d\n", /*...total Gram */
		tot_gblocks); /*blocks, */
	fprintf(results_file, "Total number of roots" /**/
		" in these %d Gram blocks is %d\n", /*...total roots in */
		tot_gblocks, tot_gblock_roots); /*Gram blocks, */
	fprintf(results_file, "Longest Gram block" /**/
		" found is[%d, %d]\n", /*...longest Gram */
		l_gblock_start, l_gblock_end); /*block */
	fclose(results_file); /*close output file */
	return (0);
}
