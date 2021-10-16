/** 
 * Copyright (c) 2021 Headog
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See LICENSE for details.
 */

#ifndef _CELLUAR_AUTOMATA_H_
#define _CELLUAR_AUTOMATA_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <map.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef bool* celluar_map_t;
typedef map_bool_t celluar_rule_t;

celluar_rule_t create_random_rule();
celluar_rule_t read_rule(FILE file);
void save_rule(FILE file, celluar_rule_t rule);
celluar_map_t create_map(int32_t height, int32_t width);
void output_map(FILE file, celluar_map_t map);
void update_map(celluar_map_t map, celluar_rule_t rule);

#ifdef __cplusplus
}
#endif

#endif /* _CELLUAR_AUTOMATA_H_ */
