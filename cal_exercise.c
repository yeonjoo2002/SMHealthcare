//
//  cal_exercise.c
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise

/*typedef struct {
    char exercise_name[MAX_EXERCISE_NAME_LEN];	// the name of the exercise
    int calories_burned_per_minute;   			// calory burned per minute
} Exercise;
*/

// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES];
int exercise_list_size = 0;

void loadExercises(const char* EXERCISEFILEPATH) {
    FILE *file = fopen(EXERCISEFILEPATH, "r");	// open exercises.txt
    if (file == NULL) 
	{
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
   	// read data from exercises.txt and save at diet_list
    while (fscanf(file, "%49s %d", 
                  exercise_list[exercise_list_size].exercise_name, 
                  &exercise_list[exercise_list_size].calories_burned_per_minute) == 2) 
	{
        exercise_list_size++;	// increament exercise_list_size when the loop begin

        if (exercise_list_size >= MAX_EXERCISES)	// break the loop when the exercise_list_size >= MAX_EXERCISES
		{
        	break;
		}
    }

    fclose(file);	// close exercises.txt
}


void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    int calories_burned;	// since user enters duration, we need new variables that indicates total caloreis burned through exercise
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    
    // display exercises.txt using exercise_list
	for (i = 0; i < exercise_list_size; i++) {
        printf("%d. %s (%d kcal burned per min.)\n", i + 1, exercise_list[i].exercise_name, exercise_list[i].calories_burned_per_minute);
    }
    
    // ToCode: to enter the exercise to be chosen with exit option
	printf("%d. Exit\n", exercise_list_size + 1);

    printf("Choose (1-%d): ", exercise_list_size + 1);
    scanf("%d", &choice); 	// choose exercise what the user wants
	
	if (choice == exercise_list_size + 1)
    	return 0;
    	
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);	// choose duration what the user wants
    
    // ToCode: to enter the selected exercise and total calcories burned in the health data 
    if (choice >= 1 && choice <= exercise_list_size)	// the number of provided exercises is exercise_list_size
	{
        calories_burned = exercise_list[choice - 1].calories_burned_per_minute * duration;	// calculate calories through exercise
        
        if (health_data->exercise_count < MAX_EXERCISES) 
		{
        health_data->exercises[health_data->exercise_count] = exercise_list[choice - 1];  // save selected exercises (that user enters) at health_data
		health_data->exercises[health_data->exercise_count].calories_burned_per_minute = calories_burned;	// since we need to save calories_burned, not calories_burned_per_miniute, so save burned calories through selected exercise and duration

		health_data->exercise_count++;	// since user enters exercises once, increment exercise_count and save at health_data
        
        health_data->total_calories_burned += calories_burned; 	// update total burned calories 
    	}
        
    } 

}


/*void test_HealthData(const HealthData* health_data) {
    printf("\n---- Health Data ----\n");
    printf("Total Calories Intake: %d kcal\n", health_data->total_calories_intake);

    if (health_data->exercise_count > 0) {
        printf("\nExercise History (%d items):\n", health_data->exercise_count);
        for (int i = 0; i < health_data->exercise_count; i++) {
            printf("%d. exercise: %s, Calories: %d kcal\n",
                   i + 1,
                   health_data->exercises[i].exercise_name,
                   health_data->exercises[i].calories_burned_per_minute);
        }
    } else {
        printf("\nDiet History: No diets recorded yet.\n");
    }

    printf("----------------------\n");
}

int main() {
    HealthData health_data = {0};

    loadExercises("C:\\Users\\a\\Desktop\\Final Project\\exercises.txt");

    while (1) {
        printf("\n---- Exerciese Input ----\n");
        inputExercise(&health_data);
        test_HealthData(&health_data);
    }

    return 0;
}
*/


/*
    description : read the information in "excercises.txt"
*/

/*void loadExercises(const char* EXERCISEFILEPATH) {
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    while ( ) {
    	
        if (exercise_list_size >= MAX_EXERCISES){
        	break;
		}
    }

    fclose(file);
}


/*
    description : to enter the selected exercise and the total calories burned in the health data
    input parameters : health_data - data object to which the selected exercise and its calories are added 
    return value : No
    
    operation : 1. provide the options for the exercises to be selected
    			2. enter the duration of the exercise
    			3. enter the selected exercise and the total calories burned in the health data
*/

/*void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");


    // ToCode: to enter the exercise to be chosen with exit option

 
    
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);

    // ToCode: to enter the selected exercise and total calcories burned in the health data
    

}
*/
