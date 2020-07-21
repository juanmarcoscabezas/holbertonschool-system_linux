#include "laps.h"

/**
 * race_state - State of the race
 * @id: List of cars id
 * @size: Size of the incoming cars
 * Return:
 */
void race_state(int *id, size_t size)
{
	size_t iterator;
	static Cars_t *cars_list_head;

	if (size == 0)
	{
		remove_cars(cars_list_head);
		return;
	}

	for (iterator = 0; iterator < size; iterator++)
	{
		insert_car(&cars_list_head, id[iterator]);
	}

	print_cars(cars_list_head);
}

/**
 * insert_car - Insert a new car
 * @cars_list: List of cars
 * @id: Id to insert
 * Return:
 */
void insert_car(Cars_t **cars_list, int id)
{
	Cars_t *cars_iterator;
	Cars_t *new_car;

	if (*cars_list == NULL || id < (*cars_list)->id)
	{
		append_car(cars_list, id);
		return;
	}

	cars_iterator = (*cars_list);

	while (cars_iterator)
	{
		if (cars_iterator->id == id)
		{
			cars_iterator->laps = cars_iterator->laps + 1;
			return;
		}
		if (id < cars_iterator->id)
		{
			new_car = malloc(sizeof(Cars_t));
			new_car->id = id;
			new_car->laps = 0;
			new_car->next = cars_iterator;
			new_car->prev = cars_iterator->prev;
			cars_iterator->prev->next = new_car;
			cars_iterator->prev = new_car;
			printf("Car %d joined the race\n", new_car->id);
			return;
		}
		if (!cars_iterator->next)
			break;
		cars_iterator = cars_iterator->next;
	}
	push_car(cars_iterator, id);
}

/**
 * append_car - Append a new car
 * @cars_list: List of cars
 * @id: Id to insert
 * Return:
 */
void append_car(Cars_t **cars_list, int id)
{
	Cars_t *new_car;

	new_car = malloc(sizeof(Cars_t));
	new_car->id = id;
	new_car->laps = 0;
	new_car->prev = NULL;
	printf("Car %d joined the race\n", new_car->id);

	if ((*cars_list))
	{
		new_car->next = (*cars_list);
		(*cars_list)->prev = new_car;
	}
	else
		new_car->next = NULL;

	*cars_list = new_car;
}

/**
 * push_car - Push a new car
 * @cars_iterator: Actual position inc ars list
 * @id: Id to insert
 * Return:
 */
void push_car(Cars_t *cars_iterator, int id)
{
	Cars_t *new_car;

	new_car = malloc(sizeof(Cars_t));
	new_car->id = id;
	new_car->laps = 0;
	new_car->next = NULL;
	new_car->prev = cars_iterator;
	cars_iterator->next = new_car;
	printf("Car %d joined the race\n", new_car->id);
}
