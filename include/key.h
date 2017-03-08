/**
 * key.h -- Key library
 *
 * Copyright (C) 2017 Jordi Sánchez, jorsanpe@gmail.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#pragma once

typedef struct key Key;

Key *Key_Create(void);

void Key_Destroy(Key *self);
