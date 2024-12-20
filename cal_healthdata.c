//
//  cal_healthdata.c
//  Diets for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

/*
    description : enter the exercise and diet history in "health_data.txt" 
    input parameters : health_data - data object in which the selected exercise and diet is stored
    return value : No
    
    operation : 1. save the chosen exercise and total calories burned 
    			2. save the chosen diet and total calories intake 
    			3. save the total remaining calrories
*/

int remained_calories = -1300;	// calculate remaining calories, initial value is -1300

void saveData(const char* HEALTHFILEPATH, const HealthData* health_data) {
	int i;
	
	// calculate remaining calroies using structure HealthData and pointer health_data
	// women basal metabolic rate : 1300 kcal (constant)
	remained_calories = (health_data->total_calories_intake) - 1300 - (health_data->total_calories_burned);	
	
    FILE* file = fopen(HEALTHFILEPATH, "w");
    if (file == NULL) {
        printf("There is no file for health data.\n");
        return;
    }

    // ToCode: to save the chosen exercise and total calories burned 
    fprintf(file, "[Exercises] \n");
    for (i = 0; i < health_data->exercise_count; i++) 
	{
        fprintf(file, "%s - %d kcal \n", 								// save selected exercises and burned calories through exercising
        	    health_data->exercises[i].exercise_name, 
                health_data->exercises[i].calories_burned_per_minute); 
    }
    fprintf(file, "Total calories burned - %d kcal", health_data->total_calories_burned);	// save total burned calories through HealthData (structure) and health_data (pointer)
    
    // adjust line spacing
	fprintf(file, "\n");
    fprintf(file, "\n");
    
    // ToCode: to save the chosen diet and total calories intake 
    fprintf(file, "\n[Diets] \n");
	for (i = 0; i < health_data->diet_count; i++) 
	{
        fprintf(file, "%s - %d kcal intake\n", 						// save selected diets and intaken calories through eating
            	health_data->diet[i].food_name, 
            	health_data->diet[i].calories_intake); 
    }
	fprintf(file, "Total calories intake - %d kcal", health_data->total_calories_intake);	// save total intaken calories through HealthData (structure) and health_data (pointer)
	
	// adjust line spacing
	fprintf(file, "\n");
	fprintf(file, "\n");
	
    // ToCode: to save the total remaining calrories
    fprintf(file, "\n[Total] \n");
    
    fprintf(file, "Basal metabolic rate - 1300 kcal\n");	
    fprintf(file, "The remaining calories - %d kcal\n", remained_calories);		// save remaining calories through remained_calories
    
    
}

/*
    description : print the history of exercised and diets
    input parameters : health_data - data object in which the history of the exercise and diet is to be printed
    return value : No
    
    operation : 1. print out the saved history of exercises
    			2. print out the saved history of diets
    			3. print out the saved history of calories
*/

void printHealthData(const HealthData* health_data) {
	int i;
	
	// ToCode: to print out the saved history of exercises
	printf("=========================== History of Exercise =======================\n");
	
	// print history of exercise using exercise (structure) and health_data (pointer)
	for (i = 0; i < health_data->exercise_count; i++) 	
	{
        printf("Exercise: %s, Calories burned : %d kcal \n", 								
        	    health_data->exercises[i].exercise_name, 
                health_data->exercises[i].calories_burned_per_minute); 
    }
    printf("=======================================================================\n");

	

    // ToCode: to print out the saved history of diets
    printf("============================= History of Diet =========================\n");
	
	// print history of diets using diet (structure) and health_data (pointer)
	for (i = 0; i < health_data->diet_count; i++) 
	{
        printf("Food: %s, Calories intake: %d kcal \n", 						
            	health_data->diet[i].food_name, 
            	health_data->diet[i].calories_intake); 
    }
    printf("=======================================================================\n");


	// ToCode: to print out the saved history of calories including basal metabolic rate, 
	// total calories burned, total calories intake, and the remaining calories
	printf("============================== Total Calories =========================\n");
 	printf("Basal Metabolic Rate: 1300 kcal\n");
 	printf("Total calories burned: %d kcal\n", health_data->total_calories_burned);			// print total burned calories using HealthData (structure) and health_data (pointer)
 	printf("Total calories intake: %d kcal\n", health_data->total_calories_intake);			// print total intaken calories using HealthData (structure) and health_data (pointer)
 	printf("The remaining ccalories: %d kcal\n", remained_calories);
    printf("=======================================================================\n \n");
    
	
	// ToCode: to print out the recommendtaion depending on the current total calories burned and intake    
    
    // check remained calories and print recomment
    if (remained_calories == 0)
    	printf("You have consumed all your calories for today!\n");
    	// need to plus break the system
    	
    else if (remained_calories <0)
    	 {
    	 	printf("[Warning] Too few calories!\n");
    	 	
    	 	// check total intaken calories and print recomment
    	 	if (health_data->total_calories_intake == 1300)
    	 		printf("Your total calorie intake for today has reached your goal!\n");
    	 	else if (health_data->total_calories_intake < 1300 )
    	 		printf("Your total calorie intake for today has not reached your goal, remember to eat more!!\n");
    	 	else if (health_data->total_calories_intake > 1300 )
    	 		printf("You have eaten more calories than planned today, but you exercised too much!\n");
    	 		
		 }
	else if (remained_calories >0)
		{
			printf("Please exercise for your health!\n");
			
			// check total intaken calories and print recomment
			if (health_data->total_calories_intake == 1300)
    	 		printf("Your total calorie intake for today has reached your goal!\n");
    	 	else if (health_data->total_calories_intake >= 1300 )
    	 		printf("Your total calorie intake for today has not reached your goal, remember to eat more!!\n");
		}
	printf("=======================================================================\n");
}




/*
    description : enter the exercise and diet history in "health_data.txt" 
    input parameters : health_data - data object in which the selected exercise and diet is stored
    return value : No
    
    operation : 1. save the chosen exercise and total calories burned 
    			2. save the chosen diet and total calories intake 
    			3. save the total remaining calrories
*/

/*void saveData(const char* HEALTHFILEPATH, const HealthData* health_data) {
	int i;
    FILE* file = fopen(HEALTHFILEPATH, "w");
    if (file == NULL) {
        printf("There is no file for health data.\n");
        return;
    }

    // ToCode: to save the chosen exercise and total calories burned 
    fprintf(file, "[Exercises] \n");
    
    
    // ToCode: to save the chosen diet and total calories intake 
    fprintf(file, "\n[Diets] \n");



    // ToCode: to save the total remaining calrories
    fprintf(file, "\n[Total] \n");
    
    
}
*/

/*
    description : print the history of exercised and diets
    input parameters : health_data - data object in which the history of the exercise and diet is to be printed
    return value : No
    
    operation : 1. print out the saved history of exercises
    			2. print out the saved history of diets
    			3. print out the saved history of calories
*/

/*void printHealthData(const HealthData* health_data) {
	int i;
	
	// ToCode: to print out the saved history of exercises
	printf("=========================== History of Exercise =======================\n");
  
  
    printf("=======================================================================\n");

    // ToCode: to print out the saved history of diets
    printf("============================= History of Diet =========================\n");


    printf("=======================================================================\n");


	// ToCode: to print out the saved history of calories including basal metabolic rate, 
	// total calories burned, total calories intake, and the remaining calories
	printf("============================== Total Calories =========================\n");
 
 
    printf("=======================================================================\n \n");
    
	
	// ToCode: to print out the recommendtaion depending on the current total calories burned and intake    
    
    
	 printf("=======================================================================\n");
}
*/