//
//  cal_diets.c
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

#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food


// list of diets 
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;


void loadDiets(const char* DIETFILEPATH) {
    FILE *file = fopen(DIETFILEPATH, "r");   // open diets.txt
    if (file == NULL) 
	{
        printf("There is no file for diets!\n");
        return;
    }

    // read data from diets.txt and save at diet_list
    while (fscanf(file, "%49s %d", 
                  diet_list[diet_list_size].food_name, 
                  &diet_list[diet_list_size].calories_intake) == 2) 
	{
        diet_list_size++;

        if (diet_list_size >= MAX_DIETS) 
		{
            printf("Maximum number of diets reached.\n");
            break; 
        }
    }
    fclose(file); // close diets.txt
}

void inputDiet(HealthData* health_data) {
    if (diet_list_size == 0) {
        printf("No diets available. Please load diets first.\n");
        return;
    }

    int choice;

    // print diet_list 
    printf("The list of diets:\n");
    for (int i = 0; i < diet_list_size; i++) {
        printf("%d. %s (%d kcal)\n", i + 1, diet_list[i].food_name, diet_list[i].calories_intake);
    }
    printf("%d. Exit\n", diet_list_size + 1);

    // input number from user
    printf("Choose (1-%d): ", diet_list_size + 1);
    scanf("%d", &choice);

    if (choice >= 1 && choice <= diet_list_size) 
	{
        // save selected diet at health_data
        Diet selected_diet = diet_list[choice - 1];
        if (health_data->diet_count < MAX_DIETS) 
		{
            health_data->diet[health_data->diet_count] = selected_diet; // save diets
            health_data->diet_count++;
            health_data->total_calories_intake += selected_diet.calories_intake; // update total calories
        } 
        
    } 
}

/*
    description : read the information in "diets.txt"
*/

//loadDiets("C:\\Users\\a\\Desktop\\SMHealthcare\\Project\\diets.txt");

/*void loadDiets(const char* DIETFILEPATH) {
    
	
	FILE *file = fopen(DIETFILEPATH, "r");	
    if (file == NULL) {
        printf("There is no file for diets! \n");
        return;
    }
    
	// ToCode: to read a list of the diets from the given file
    while ()	
	
        if (diet_list_size >= MAX_DIETS){
			break;
		}
    }
    fclose(file);
    
  
}


/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
*/

/*void inputDiet(HealthData* health_data) {
    int choice, i;
    
    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    
    
	// ToCode: to enter the diet to be chosen with exit option
    

    // ToCode: to enter the selected diet in the health data
    

    // ToCode: to enter the total calories intake in the health data


}
*/
