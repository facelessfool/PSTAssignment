#include <stdio.h>
#include <assert.h>

int filter_initial(char *infile, char *outfile, char letter) {

    int occ = 0;//occ is used for count

    //fp_in is for opening the file to read
    //fp_out is for opening the file to write
    FILE *fp_in, *fp_out;  

    //checking if the file to read exist 
    if ((fp_in = fopen(infile, "r")) == NULL) {
        printf("Error opening infile!");
        return -1;
    }



    //if output file exists, open it. 
    if (outfile != NULL)
        fp_out = fopen(outfile, "w");

    //line is used to store the names from names.txt
    char line[256];


    //fgets fetches the read file fp_in and stores in on line

    while (fgets(line, sizeof(line), fp_in)) {


        //checking if the First letter matches 
        if (line[0] == letter) {
            occ++;

            //if there is no output file, then print in on the standard output using printf
            if (outfile == NULL)
                printf("%s", line); 
            else

                //if there exists an output file, print it on the output file using fprintf
                fprintf(fp_out, "%s", line);
        }
    }


    //close the input file 

    fclose(fp_in);

    //if there is an output file, close it.
    if (outfile != NULL)
        fclose(fp_out);

    return occ;
}
    

/********************************************************************/
/*    DO NOT ALTER ANY OF THE THE DRIVER CODE BELOW                 */
/********************************************************************/
int main(){
    printf("\n\t=========Test#1: Filter Initial Letter===========\n\n");
    assert(29 == filter_initial("names.txt", "filtered.txt", 'A'));
    assert(23 == filter_initial("names.txt", "filtered.txt", 'B'));
    assert(30 == filter_initial("names.txt", "filtered.txt", 'C'));
    printf("\n\t=========Test#1 Passed===========\n\n");
    printf("\n\t=========Test#2: Verify Output File===========\n\n");
    assert(30 == filter_initial("filtered.txt", NULL, 'C'));
    printf("\n\t=========Test#2 passed if names are printed above.===========\n\n");
    printf("\n\t=========Please remember to check with Valgrind.===========\n\n");
}