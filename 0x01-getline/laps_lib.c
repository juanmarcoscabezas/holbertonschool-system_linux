#include "laps.h"

/**
 * print_cars - Prints the cars list
 * @cars_list: List of cars
 * Return:
 */
void print_cars(Cars_t *cars_list)
{
	printf("Race state:\n");
	for (; cars_list != NULL;)
	{
		printf("Car %d [%d laps]\n", cars_list->id, cars_list->laps);
		cars_list = cars_list->next;
	}
}

/**
 * remove_cars - Removes all cars
 * @cars_list: List of cars
 * Return:
 */
void remove_cars(Cars_t *cars_list)
{
	Cars_t *aux;

	for (; cars_list != NULL;)
	{
		aux = cars_list;
		cars_list = cars_list->next;
		free(aux);
	}
}
