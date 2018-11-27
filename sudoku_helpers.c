#include <stdio.h>
#include <math.h>

/* Each of the n elements of array elements, is the address of an
 * array of n integers.
 * Return 0 if every integer is between 1 and n^2 and all
 * n^2 integers are unique, otherwise return 1.
 */
int check_group(int **elements, int n) {
	// Concatenate the n arrays into one array
	int count = 0;
	int full_size = (int) pow(n, 2);
    int *whole_array[full_size];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			whole_array[count] = &elements[i][j];
			count++;
		}
	}

	// Check if elements are between 1 and n^2
	for (int k = 0; k < (full_size); k++){
		if (*whole_array[k] < 1 || *whole_array[k] > (full_size)){

		    //printf("%s\n", "NOT IN RANGE");
			return 1;
		}
	}

	// Check if elements are unique in whole_array
	for (int l = 0; l < (full_size); l++){
		for (int m = l + 1; m < (full_size); m++){

            //printf("l: %d --- m %d\n", *whole_array[l], *whole_array[m]);

			if (*whole_array[l] == *whole_array[m]){

                //printf("%s\n", "DUPLICATE NUMBERS");
				return 1;
			}
		}
	}

	return 0;
}

/* puzzle is a 9x9 sudoku, represented as a 1D array of 9 pointers
 * each of which points to a 1D array of 9 integers.
 * Return 0 if puzzle is a valid sudoku and 1 otherwise. You must
 * only use check_group to determine this by calling it on
 * each row, each column and each of the 9 inner 3x3 squares
 */

int check_regular_sudoku(int **puzzle) {

    // Check Rows
    for (int i = 0; i < 9; i++) {
        int *set_row[3];
        int small_set_num = 0;
        for (int j = 0; j < 9; j += 3) {
            int *small_set[3] = {&puzzle[i][j], &puzzle[i][j + 1], &puzzle[i][j + 2]};

//            //FOR TESTING NUMBERS IN SET (IN THE FOR LOOP)
//            for(int x = 0; x < 3; x++) {
//                printf("%d\n", *small_set[x]);
//            }
//            printf("=======\n");

            set_row[small_set_num] = *small_set;

//            //FOR TESTING SET_ROW OUTSIDE OF FOR-LOOP
//            printf("%d\n", set_row[small_set_num][0]);
//            printf("%d\n", set_row[small_set_num][1]);
//            printf("%d\n", set_row[small_set_num][2]);
//            printf("========================\n");

//            //FOR TESTING NUMBERS IN SET (IN THE FOR LOOP)
//            for(int x = 0; x < 3; x++) {
//                printf("%d\n", set_row[small_set_num][x]);
//            }

            small_set_num++;
        }

//        //FOR TESTING NUMBERS IN SET (OUTSIDE OF FOR LOOP)
//        for(int x = 0; x < 3; x++) {
//            for(int y = 0; y < 3; y++){
//                printf("%d\n", set_row[x][y]);
//            }
//        }

        if (check_group(set_row, 3) == 1){
            return 1;
        }
    }

//// CHECK COLUMNS
    for(int i = 0; i < 9; i++){
        int *set[3];

        int small_set1[3];
        int small_set2[3];
        int small_set3[3];

        small_set1[0] = puzzle[0][i];
        small_set1[1] = puzzle[1][i];
        small_set1[2] = puzzle[2][i];

        small_set2[0] = puzzle[3][i];
        small_set2[1] = puzzle[4][i];
        small_set2[2] = puzzle[5][i];


        small_set3[0] = puzzle[6][i];
        small_set3[1] = puzzle[7][i];
        small_set3[2] = puzzle[8][i];

        set[0] = small_set1;
        set[1] = small_set2;
        set[2] = small_set3;

        if (check_group(set, 3) == 1){
            return 1;
        }
    }


//// CHECK SQUARES
for (int i = 0; i < 9; i += 3){
    for (int k = 0; k < 9; k += 3) {
        int *set[3];
        int small_set1[3];
        int small_set2[3];
        int small_set3[3];

        small_set1[0] = puzzle[i][k];
        small_set1[1] = puzzle[i + 1][k];
        small_set1[2] = puzzle[i + 2][k];

        small_set2[0] = puzzle[i][k + 1];
        small_set2[1] = puzzle[i + 1][k + 1];
        small_set2[2] = puzzle[i + 2][k + 1];

        small_set3[0] = puzzle[i][k + 2];
        small_set3[1] = puzzle[i + 1][k + 2];
        small_set3[2] = puzzle[i + 2][k + 2];

        set[0] = small_set1;
        set[1] = small_set2;
        set[2] = small_set3;

        if (check_group(set, 3) == 1) {
            return 1;
        }
    }
}

    return 0;
}





