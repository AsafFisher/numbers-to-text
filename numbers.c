/*

  numbers.c
  MMN13

  Created by Asaf Fisher on 6/16/16.
  Copyright © 2016 Asaf Fisher. All rights reserved.
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Question 1:
int*(*table())[30];stdout                     <-----------------
 *table() return a pointer.                  <-----------------
 (*table())[30] return a pointer to an array of 30 pointers. <----------------------
 int*(*table())[30]; = return a pointer to a 30 length array of pointers to int. <-------------------------
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Question 2:
	THIS CODE IS USING ONLY 22 key words for the translation of digits to text ("" is not included).
*/

#include <stdio.h>
#include <stdlib.h>
enum{NO_ARGS = 1,ONE_ARG,TWO_ARG, TENS = 15};

const char * strings[] = {"zero","one","two","three","four",
"five","six","seven","eight","nine","ten","eleven","twelve","thirteen",
"forteen","fifteen","teen","twenty","thirty","forty","fifty","ty",""};

int buff[1000];
/*GET TWO FILES (input and output) translate the input from digits to language*/
int translateFromFile(FILE *input, FILE *output);

int main(int argc, const char * argv[]) {
	FILE *fi;
	FILE *fo;
    /*fprintf(stdout,"%s",buff);*/

    switch (argc) {
    	/*default IO*/
        case NO_ARGS:
        	fi = stdin;
        	fo = stdout;
		fprintf(stdout,"PLEASE USE ctl+d (EOF) flag when done with input.\n");
            if(!translateFromFile(fi,fo))
        	{
        		fprintf(stderr,"ERROR\n");
        		exit(0);
        	}
            break;
            /*one arg*/
        case ONE_ARG:
        	if(!(fi = fopen(argv[ONE_ARG-1], "r"))){
        		fprintf(stdout,"ERROR\n");
        		exit(0);
        		
        	}
        	fo = stdout;
        	if(!translateFromFile(fi,fo))
        	{
        		fprintf(stderr,"ERROR\n");
        		exit(0);
        	}
            
            break;
            /*two args*/
        case TWO_ARG:
        	/*inputfile*/
        	if(!(fi = fopen(argv[ONE_ARG-1], "r"))){
        		fprintf(stdout,"ERROR\n");
        		exit(0);
        		
        	}
        	/*outputfile*/
        	if(!(fo = fopen(argv[TWO_ARG-1], "w"))){
        		fprintf(stdout,"ERROR\n");
        		exit(0);
        		
        	}
        	if(!translateFromFile(fi,fo))
        	{
        		fprintf(stderr,"ERROR\n");
        		exit(0);
        	}
            
            break;
            
        default:
            break;
    }
   
fprintf(stdout,"Done.\n");
return 0;

}
/*GET TWO FILES (input and output) translate the input from digits to language*/
int translateFromFile(FILE *input, FILE *output){
    	int count = 0;
    	int amount=0;
    	/*GET VALUES*/
    	while(fscanf(input, "%d",&buff[amount])!= EOF){
    		amount++;
    	}
    	fprintf(output,"\n");
    	/*TRANSLATION*/
    	for(count = 0;count<amount;count++){
    		int number =  buff[count];
    		if(number>15){
    			int tens;
    			int units;
    			tens = number/10;
    			units = number%10;
    			if(tens == 1){
    				fprintf(output, "%s%s\n", strings[units],strings[TENS+tens]);
    			}else{
    				if(units == 0)
    				units = 22;/*wont write zero such as: "Twenty-zero"...*/
    				if(tens>5){
    					                                                   /*TENS+6 - Is "ty"*/
    					fprintf(output, "%s%s %s\n", strings[tens],strings[TENS+6],strings[units]);
    				}else{
    					fprintf(output, "%s %s\n", strings[TENS+tens],strings[units]);
    					
    				}
    				
			}
    			
    		}else if(number>=0){
    			fprintf(output,"%s\n",strings[number]);
    		}else{
    			return 0;
    		}
    		
    		
    	}
    	return 1;
  }






