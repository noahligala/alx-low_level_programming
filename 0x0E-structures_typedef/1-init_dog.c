#include "dog.h"
#include <stddef.h>
/**
 * init_dog - Initiates the dog structure
 * @d: A dog structure
 * @name: The name of the dog.
 * @age: the age of the dog.
 * @owner: the owner of the dog.
 *
 * Return: Nothing.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
