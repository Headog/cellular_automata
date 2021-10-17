/** 
 * Copyright (c) 2021 Headog
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See LICENSE for details.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <cellular_automata.h>

struct cellular_map
{
    int32_t width;
    int32_t height;
    bool* cells;
};

#ifdef __cplusplus
}
#endif
