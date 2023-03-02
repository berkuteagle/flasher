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

#include "flasher-ihex.h"

static void
flasher_ihex_extension_iface_init (FlasherExtensionInterface *iface)
{
}

static void
flasher_ihex_file_extension_iface_init (FlasherFileExtensionInterface *iface)
{
  iface->load_file      = NULL;
  iface->get_mime_types = flasher_ihex_file_extension_get_mime_types;
}

G_DEFINE_FINAL_TYPE_WITH_CODE (FlasherIHex,
                               flasher_ihex,
                               PEAS_TYPE_EXTENSION_BASE,
                               G_IMPLEMENT_INTERFACE (FLASHER_TYPE_EXTENSION, flasher_ihex_extension_iface_init)
                                   G_IMPLEMENT_INTERFACE (FLASHER_TYPE_FILE_EXTENSION, flasher_ihex_file_extension_iface_init))

static void
flasher_ihex_set_property (GObject *object, guint prop_id, const GValue *value, GParamSpec *pspec)
{
  FlasherIHex *plugin;

  g_return_if_fail (FLASHER_IS_IHEX (object));

  plugin = FLASHER_IHEX (object);

  switch (prop_id)
    {
    case PROP_FLASHER:
      plugin->flasher = FLASHER_OBJECT (g_value_dup_object (value));
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
    }
}

static void
flasher_ihex_get_property (GObject *object, guint prop_id, GValue *value, GParamSpec *pspec)
{
  FlasherIHex *plugin;

  g_return_if_fail (FLASHER_IS_IHEX (object));

  plugin = FLASHER_IHEX (object);

  switch (prop_id)
    {
    case PROP_FLASHER:
      g_value_set_object (value, plugin->flasher);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
    }
}

static void
flasher_ihex_init (FlasherIHex *extension)
{
  g_message ("iHEX init");
}

static void
flasher_ihex_class_init (FlasherIHexClass *klass)
{
  GObjectClass *object_class;

  g_message ("iHEX class init");

  object_class               = G_OBJECT_CLASS (klass);
  object_class->set_property = flasher_ihex_set_property;
  object_class->get_property = flasher_ihex_get_property;

  g_object_class_override_property (object_class, PROP_FLASHER, "flasher");
}

GArray *
flasher_ihex_file_extension_get_mime_types (FlasherFileExtension *extension)
{
  GArray *a = g_array_new (FALSE, FALSE, sizeof (char *));
  g_array_append_val (a, "bin");

  g_assert (FLASHER_IS_IHEX (extension));

  if (FLASHER_IHEX (extension)->flasher != NULL)
    g_message ("Flasher object property is defined");

  return a;
}

G_MODULE_EXPORT void
peas_register_types (PeasObjectModule *module)
{
  g_message ("Register peas types: iHEX");

  // flasher_plugin_ihex_register_type (G_TYPE_MODULE (module));
  peas_object_module_register_extension_type (module, FLASHER_TYPE_FILE_EXTENSION, FLASHER_TYPE_IHEX);
}
