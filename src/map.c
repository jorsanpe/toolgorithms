/**
 * map.h -- Map library
 *
 * Copyright (C) 2017 Jordi Sánchez, jorsanpe@gmail.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#include <map.h>

struct map_node {
	Key *key;
	void *value;
};

struct map {
	struct map_node *map_node;
};


Map *Map_Create(void)
{
	return calloc(1, sizeof(Map));
}


void Map_Destroy(Map *self)
{
	free(self);
}


_Bool Map_isEmpty(Map *self)
{
	if (self->map_node != NULL) {
		return false;
	}
	return true;
}


int Map_Insert(Map *self, Key *key, void *value)
{
	if (self->map_node != NULL) {
		return -1;
	}
	self->map_node = malloc(sizeof(struct map_node));
	self->map_node->key = key;
	self->map_node->value = value;
	return 0;
}


void *Map_Find(Map *self, Key *key)
{
	if (self->map_node != NULL) {
		return self->map_node->value;
	}
	return NULL;
}


void Map_Delete(Map *self, Key *key)
{
	if (self->map_node != NULL) {
		free(self->map_node);
		self->map_node = NULL;
	}
}
