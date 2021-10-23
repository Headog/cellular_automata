/** 
 * Copyright (c) 2021 Headog
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See LICENSE for details.
 */

#ifndef _CELLUAR_AUTOMATA_H_
#define _CELLUAR_AUTOMATA_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

    struct celluar_map;
    typedef struct cellular_map *cellular_map_t;
    typedef bool *cellular_rule_t;

    cellular_rule_t create_random_rule();
    cellular_rule_t read_rule(FILE *input);
    void save_rule(FILE *output, const cellular_rule_t rule);
    cellular_map_t create_random_map(const int32_t height, const int32_t width);
    void save_map(FILE *output, const cellular_map_t map);
    void update_map(const cellular_map_t map, const cellular_rule_t rule);

    cellular_map_t read_model(const FILE *input);
    int32_t get_fitness(const cellular_map_t map, const cellular_map_t model);
    cellular_rule_t mix_rules(const cellular_rule_t rule1, const cellular_rule_t rule2);

#ifdef __cplusplus
}
#endif

#endif /* _CELLUAR_AUTOMATA_H_ */
