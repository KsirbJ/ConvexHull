#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>




int main(int argc, char const *argv[], char *envp[]){
	const int MAXINT = 1000000;
	const int MININT = 1;
	int *rand_ints = NULL;

	int num_of_nums = 100; // how many numbers to expect
	int min_int = MININT; //  lowest allowed number
	int max_int = 255; // highest allowed number
	char *out_file = NULL;
	bool out_file_ex = false;

	struct timespec tim;
	clock_gettime(CLOCK_REALTIME, &tim);
	unsigned long seed = tim.tv_nsec;

	// Go through argv and get args
	int i;
	for(i = 0; i < argc; ++i){
		
		// check for -u
		if(!strcmp(argv[i], "-u")){

			fprintf(stderr, "%s\n","Here's how to use this program:\n ./prog1sorter [-u] [-n <num-integers>] [-m <min-int>] [-M <max-int>] [-i <input-file-name>] [-o <output-file-name>] [-c <count-file-name>]\n" );
			exit(0);

		// check for -n
		}else if(!strcmp(argv[i], "-n")){

			int j;
			for(j = 0; j < strlen(argv[i+1]); ++j){
				if(!isdigit(argv[i+1][j])){
					fprintf(stderr, "Invalid input. Expected number after -n\n");
					exit(1);
				}
			}
			assert(num_of_nums == 100 && atoi(argv[i+1]) >= 0 && atoi(argv[i+1]) <= MAXINT && " Invalid number for -n");
			num_of_nums = atoi(argv[i+1]);


		// check for -m
		}else if(!strcmp(argv[i], "-m")){

			int j;
			for(j = 0; j < strlen(argv[i+1]); ++j){

				if(!isdigit(argv[i+1][j])){
					fprintf(stderr, "Invalid input. Expected number after -m\n");
					exit(1);
				}
			}
			if(min_int == MININT && atoi(argv[i+1]) >= MININT && atoi(argv[i+1]) <= MAXINT){
				min_int = atoi(argv[i+1]);
			}else{
				fprintf(stderr, "Invalid argument for -m\n" );
				exit(1);
			}

		// check for -M
		}else if(!strcmp(argv[i], "-M")){

			int j;
			for(j = 0; j < strlen(argv[i+1]); ++j){
				if(!isdigit(argv[i+1][j])){
					fprintf(stderr, "Invalid input. Expected number after -M\n");
					exit(1);
				}
			}
			if(max_int == 255 && atoi(argv[i+1]) <= MAXINT && atoi(argv[i+1]) >= min_int){
				max_int = atoi(argv[i+1]);
			}else{
				fprintf(stderr, "Invalid argument for -M\n" );
				exit(1);
			}

		// -o
		}else if(!strcmp(argv[i], "-o")){

			if(out_file_ex == false){
				int len = strlen(argv[i+1]);
				if(len > 4){
					out_file = (char *)malloc(len * sizeof(char));
					assert(out_file != NULL && " Couldn't allocate space for filename");
					strcpy(out_file, argv[i+1]); 
					out_file_ex = true;
				}else{
					fprintf(stderr, "%s\n", "Invalid argument for -o" );
					exit(1);
				}
			}

		// -s
		}else if(!strcmp(argv[i], "-s")){

			seed = strtoul(argv[i+1], NULL, 10);

		// invalid option
		}else if(argv[i][0] == '-'){
			fprintf(stderr, "Invalid command %s\n", argv[i]);
			exit(1);
		}
	}

	rand_ints = (int*)malloc(num_of_nums * sizeof(int));
	assert(rand_ints != NULL && " Couldn't generate numbers");
	int j;
	srand(seed);
	for(j = 0; j < num_of_nums; ++j){
		rand_ints[j] = ( rand() % max_int + min_int);
	}

	if(out_file_ex){
		FILE *f;
		f = fopen(out_file, "w+");
		int k = 0;
		fprintf(f, "%d\n", num_of_nums);
		while(k < num_of_nums){
			fprintf(f, "%d\n", rand_ints[k] );
			++k;
		}
		fclose(f);
	}else{
		fprintf(stderr, "%d\n", num_of_nums);
		int k = 0;
		while(k < num_of_nums){
			fprintf(stdout, "%d\n", rand_ints[k] );
			++k;
		}
	}

	free(out_file);
	free(rand_ints);
	return 0;
}