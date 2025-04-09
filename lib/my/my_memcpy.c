/*
** EPITECH PROJECT, 2025
** my_memcpy
** File description:
** my_memcpy
*/

#include "my.h"

void *my_memcpy(void *dest, void *src, int len)
{
    if (!dest || !src)
        return NULL;
    for (int i = 0; i < len; i++) {
        ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
    }
    return dest;
}
