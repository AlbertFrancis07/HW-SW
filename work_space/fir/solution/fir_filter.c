/*
 * fir_filter.c
 */


#include "fir_filter.h"
#include "fir_data.h"


/* 
 * FIR filter implementation
 * with 8 coefficients
 * 
 * in:	pointer to input array
 * out:	pointer to output array
 * len:	#input values
 */
void fir_C(short *in, int *out, int len)
{
	int i, j;
	
	for (i = 0; i < len+7; i++)
	{
		for (j = 0; j < 8; j++) out[i] += in[i+7-j]*coeff[j];
	}
}



int main()
{
	FILE *inpFile, *outFile;
	
	short *inpArr;
	int *firOut_C;
	int i, j, len=0;
	char error = 0;
	
	
	//open input file
	inpFile = fopen ("input","r");
	if (inpFile!=NULL)
	{
		// get # of integers to read from the file
		while(!fscanf(inpFile,"%*[^\n]%*c")) len++;
		
		fseek(inpFile,0,SEEK_SET);
		
		inpArr = (short*)calloc((len+14),sizeof(short));
		
		// check allocation
		if(!inpArr)
		{
			printf("ERROR: Could not allocate memory for 'inpArr'!");
			fclose (inpFile);
			return 1;
		}
		
		// read file content to inpArr
		for (i = 7; i < len+7; i++) fscanf (inpFile, "%hd", &inpArr[i]);
		
		// close input file
		fclose (inpFile);
	}
  
	printf("len: %d\n", len);
	
	// alloc memory
	firOut_C = (int*)calloc((len+7), sizeof(int));
	
	// check allocation
	if(!firOut_C)
	{
		printf("ERROR: Could not allocate memory for 'firOut_C'!\n");
		return 1;
	}
	
	// without TIE extensions
	fir_C(inpArr, firOut_C, len);
	

#if FIR_TIE==0
	// MAC fusion
	fir_macTIE(inpArr, firOut_TIE, len);
#endif
	
#if FIR_TIE==1
	// SIMD extension
	fir_simdTIE(inpArr, firOut_TIE, len);
#endif

#if FIR_TIE==2
	//advanced FIR
	FIR_advancedTIE(inpArr, firOut_TIE, len);
#endif
	
	//check input and output
	for (i = 0; i < len+7; i++)
	{
		if(firOut_C[i] != firOut_TIE[i])
		{
			error = 1;
			break;
		}
	}
	if(error) printf("ERROR!\nERROR!\nERROR!\n");
	else printf("No errors!\n");
	
	// open output file
	outFile = fopen ("output","w");
	if (outFile!=NULL)
	{
		fprintf(outFile, "C:\tTIE:\n");
		
		// write FIR filter output contained in array firOut
		for (i = 0; i < len+7; i++) fprintf (outFile, "%d\t%d\n", firOut_C[i], firOut_TIE[i]);
    }
    // close output file
    fclose (outFile);
    
    return 0;
}
