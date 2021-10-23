/** 
 * Copyright (c) 2021 Headog
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See LICENSE for details.
 */

#include "cellular_automata.h"
#include <stdio.h>

int main(void)
{
    printf("Start");
    cellular_map_t map =  create_random_map(10, 10);
    cellular_rule_t rule = create_random_rule();
    update_map(map, rule);
    return 0;
}
