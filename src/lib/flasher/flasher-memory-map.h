/* MIT License
 *
 * Copyright (c) 2023 Anton Snigirev
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <glib-object.h>

G_BEGIN_DECLS

typedef enum
{
  DATA_BYTES,
  CONFIG_BITS
} FlasherMemoryMapSectionType;

typedef struct
{
  char                       *name;
  guint                       size;
  guint                       address;
  FlasherMemoryMapSectionType type;
} FlasherMemoryMapSection;

#define FLASHER_TYPE_MEMORY_MAP (flasher_memory_map_get_type ())

G_DECLARE_FINAL_TYPE (FlasherMemoryMap, flasher_memory_map, FLASHER, MEMORY_MAP, GObject)

FlasherMemoryMap *flasher_memory_map_new (void);
void              flasher_memory_map_add_section (FlasherMemoryMap *self, FlasherMemoryMapSection *section);
FlasherMemoryMapSection *flasher_memory_map_section_new (char *name, guint size, guint address, FlasherMemoryMapSectionType type);

G_END_DECLS

