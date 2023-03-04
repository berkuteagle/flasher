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

#include "flasher-memory-map.h"

struct _FlasherMemoryMap
{
  GObject parent_instance;
  GSList *sections;
};

G_DEFINE_FINAL_TYPE (FlasherMemoryMap, flasher_memory_map, G_TYPE_OBJECT)

static void
flasher_memory_map_init (FlasherMemoryMap *self)
{
  self->sections = NULL;
}

static void
flasher_memory_map_dispose (GObject *object)
{
  FlasherMemoryMap *memory_map;

  memory_map = FLASHER_MEMORY_MAP (object);

  g_slist_free_full (memory_map->sections, (GDestroyNotify) g_free);

  G_OBJECT_CLASS (flasher_memory_map_parent_class)->dispose (object);
}

static void
flasher_memory_map_class_init (FlasherMemoryMapClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->dispose = flasher_memory_map_dispose;
}

FlasherMemoryMap *
flasher_memory_map_new (void)
{
  return g_object_new (FLASHER_TYPE_MEMORY_MAP, NULL);
}

FlasherMemoryMapSection *
flasher_memory_map_section_new (char *name, guint size, guint address, FlasherMemoryMapSectionType type)
{

  FlasherMemoryMapSection *section = g_new (FlasherMemoryMapSection, 1);

  section->name    = name;
  section->size    = size;
  section->address = address;
  section->type    = type;

  return section;
}

void
flasher_memory_map_add_section (FlasherMemoryMap *self, FlasherMemoryMapSection *section)
{
  self->sections = g_slist_append (self->sections, section);
}

