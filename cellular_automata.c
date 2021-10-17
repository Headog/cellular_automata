/** 
 * Copyright (c) 2021 Headog
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See LICENSE for details.
 */

#include <cellular_automata.h>

#ifdef __cplusplus
extern "C" {
#endif

struct cellular_map
{
    int32_t width;
    int32_t height;
    bool* cells;
};

#ifdef __cplusplus
}
#endif
