/**
 * map.h -- Map library
 *
 * Copyright (C) 2017 Jordi Sánchez, jorsanpe@gmail.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#pragma once

#include <key.h>

typedef struct map Map;

Map *Map_Create(void);

void Map_Destroy(Map *self);

_Bool Map_isEmpty(Map *self);

int Map_Insert(Map *self, Key *key, void *value);

void *Map_Find(Map *self, Key *key);
