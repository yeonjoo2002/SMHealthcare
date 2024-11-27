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


/*
	typedef struct 
	{	char food_name[MAX_FOOD_NAME_LEN]; 	// the name of food
    	int calories_intake;   				// calorie intake
	} 	Diet;
*/

static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;


void loadDiets(const char* DIETFILEPATH) {
    FILE *file = fopen(DIETFILEPATH, "r");   // open diets.txt
    if (file == NULL) 
	{
        printf("There is no file for diets!\n");
        return;
    }
    
    // ToCode: to read a list of the diets from the given file
    // read data from diets.txt and save at diet_list
    while (fscanf(file, "%49s %d", 
                  diet_list[diet_list_size].food_name, 
                  &diet_list[diet_list_size].calories_intake) == 2) 
	{
        diet_list_size++;	// increament diet_list_size when the loop begin

        if (diet_list_size >= MAX_DIETS)	// break the loop when the diet_list_size >= MAX_DIETS
		{
            break; 
        }
    }
    fclose(file); // close diets.txt
}

void inputDiet(HealthData* health_data) {
    int choice,i;

    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    
    // display diets.txt using diet_list
    for (i = 0; i < diet_list_size; i++) {
        printf("%d. %s (%d kcal)\n", i + 1, diet_list[i].food_name, diet_list[i].calories_intake);
    }
    
    // ToCode: to enter the diet to be chosen with exit option
    printf("%d. Exit\n", diet_list_size + 1);

    printf("Choose (1-%d): ", diet_list_size + 1); 	
    scanf("%d", &choice);	// choose diet what the user wants
	
	if (choice == diet_list_size + 1)
    	return 0;
		
	// ToCode: to enter the selected diet in the health data
    if (choice >= 1 && choice <= diet_list_size)	// the number of provided diets is diet_list_size
	{
        if (health_data->diet_count < MAX_DIETS) 
		{
            health_data->diet[health_data->diet_count] = diet_list[choice-1]; // save selected diets (that user enters) at health_data
            health_data->diet_count++;	// sice user enters diets once, increment diet_count and save at health_data
            
			// ToCode: to enter the total calories intake in the health data
            health_data->total_calories_intake += diet_list[choice-1].calories_intake;	// update total intaken calories 
        } 
        
    } 
}



/*void test_HealthData(const HealthData* health_data) {
    printf("\n---- Health Data ----\n");
    printf("Total Calories Intake: %d kcal\n", health_data->total_calories_intake);

    if (health_data->diet_count > 0) {
        printf("\nDiet History (%d items):\n", health_data->diet_count);
        for (int i = 0; i < health_data->diet_count; i++) {
            printf("%d. Food: %s, Calories: %d kcal\n",
                   i + 1,
                   health_data->diet[i].food_name,
                   health_data->diet[i].calories_intake);
        }
    } else {
        printf("\nDiet History: No diets recorded yet.\n");
    }

    printf("----------------------\n");
}

int main() {
    HealthData health_data = {0};

    loadDiets("C:\\Users\\a\\Desktop\\Final Project\\diets.txt");

    while (1) {
        printf("\n---- Diet Input ----\n");
        inputDiet(&health_data);
        test_HealthData(&health_data);
    }

    return 0;
}
*/





/*
    description : read the information in "diets.txt"
*/

/*void loadDiets(const char* DIETFILEPATH) {
    FILE *file = fopen(DIETFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for diets! \n");
        return;
    }

     // ToCode: to read a list of the diets from the given file
    while () {
    	
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

/*
void inputDiet(HealthData* health_data) {
    int choice, i;
    
    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    
    
	// ToCode: to enter the diet to be chosen with exit option
    

    // ToCode: to enter the selected diet in the health data
    

    // ToCode: to enter the total calories intake in the health data


}
*/