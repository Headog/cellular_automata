/** 
 * Copyright (c) 2021 Headog
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See LICENSE for details.
 */

#include "cellular_automata.h"
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

struct cellular_map
{
    int32_t height;
    int32_t width;
    bool *cells;
};

cellular_rule_t create_random_rule()
{
    cellular_rule_t result = (cellular_rule_t)malloc(0b1000000000);
    srand((unsigned int)time(NULL));
    for (int_fast8_t i = 0b0; i <= 0b111111111; i++)
    {
        *(result + i) = rand() % 2;
    }
    return result;
}

cellular_rule_t read_rule(FILE *input)
{
    cellular_rule_t result = (cellular_rule_t)malloc(0b1000000000);
    fread(result, 0b1000000000, sizeof(bool), input);
    return result;
}

void save_rule(FILE *output, const cellular_rule_t rule)
{
    fwrite(rule, 0b1000000000, sizeof(bool), output);
}

cellular_map_t create_random_map(const int32_t height, const int32_t width)
{
    const cellular_map_t result = (cellular_map_t)malloc(sizeof(cellular_map_t));
    result->height = height;
    result->width = width;
    bool *cells = (bool *)malloc(sizeof(height * width));
    srand((unsigned int)time(NULL));
    for (int_fast8_t i = 0b0; i <= 0b111111111; i++)
    {
        *(cells + i) = rand() % 2;
    }
    result->cells = cells;
    return result;
}

void save_map(FILE *output, const cellular_map_t map)
{
    for (int_fast8_t i = 0b0; i <= 0b111111111; i++)
    {
        fprintf(output, "%d", *(map->cells + i));
        if ((i + 1) % map->width == 0)
        {
            fprintf(output, "\n");
        }
    }
}

void update_map(const cellular_map_t map, const cellular_rule_t rule)
{
    const int32_t map_size = map->height * map->width;
    for (int_fast32_t i = 0; i < map->height; i++)
    {
        for (int_fast32_t j = 0; j < map->width; j++)
        {
            int_fast8_t condition = 0b0;
            bool *cell = map->cells + i * map->width + j;
            static bool *current_cell;

            //left-up
            current_cell = cell - map->width - 1;
            if (i == 0)
            {
                current_cell += map_size;
            }
            if (j == 0)
            {
                current_cell += map->width;
            }
            condition += *current_cell;
            condition <<= 1;

            //up
            if (i == 0)
            {
                condition += *(cell + map->width * (map->height - 1));
            }
            else
            {
                condition += *(cell - map->width);
            }
            condition <<= 1;

            //right-up
            current_cell = cell - map->width + 1;
            if (i == 0)
            {
                current_cell += map_size;
            }
            if (j == map->width - 1)
            {
                current_cell -= map->width;
            }
            condition += *current_cell;
            condition <<= 1;

            //left
            if (j == 0)
            {
                condition += *(cell + map->width - 1);
            }
            else
            {
                condition += *(cell - 1);
            }
            condition <<= 1;

            //center
            condition += *cell;
            condition <<= 1;

            //right
            if (j == map->width - 1)
            {
                condition += *(cell - map->width + 1);
            }
            else
            {
                condition += *(cell + 1);
            }
            condition <<= 1;

            //left-down
            current_cell = cell + map->width - 1;
            if (i == map->height - 1)
            {
                current_cell -= map_size;
            }
            if (j == 0)
            {
                current_cell += map->width;
            }
            condition += *current_cell;
            condition <<= 1;

            //down
            if (i == map->height - 1)
            {
                condition += *(cell - map->width * (map->height - 1));
            }
            else
            {
                condition += *(cell + map->width);
            }
            condition <<= 1;

            //right-down
            current_cell = cell + map->width - 1;
            if (i == map->height - 1)
            {
                current_cell -= map_size;
            }
            if (j == map->width - 1)
            {
                current_cell -= map->width;
            }
            condition += *current_cell;
            condition <<= 1;

            *(cell) = *(rule + condition);
        }
    }
}

//Not Supported yet.
cellular_map_t read_model(const FILE *input)
{
    return NULL;
}

int32_t get_fitness(const cellular_map_t map, const cellular_map_t model)
{
    if (map->height != model->height || map->width != model->width)
    {
        return 0;
    }
    register int32_t result = 0;
    for (int_fast32_t i = 0; i < map->height * map->width; i++)
    {
        if (*(map->cells + i) == *(model->cells + i))
        {
            result++;
        }
    }
    return result;
}

cellular_rule_t mix_rules(const cellular_rule_t rule1, const cellular_rule_t rule2)
{
    srand((unsigned int)time(NULL));
    int split = rand() % 0b111111111;
    for (int i = split + 1; i < 0b1000000000; i++)
    {
        *(rule1 + i) = *(rule2 + i);
    }
    return rule1;
}
