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

#include <libpeas/peas.h>

#include "flasher-file-extension.h"
#include "flasher-object.h"
#include "flasher-plugins-engine.h"

struct _FlasherObjectPrivate
{
  GArray *mime_types;
};

struct _FlasherObject
{
  GObject               parent_instance;
  FlasherPluginsEngine *engine;
};

G_DEFINE_FINAL_TYPE_WITH_PRIVATE (FlasherObject, flasher_object, G_TYPE_OBJECT)

static void
flasher_object_init (FlasherObject *self)
{
  FlasherObjectPrivate *priv;

  self->engine = flasher_plugins_engine_get_default ();

  priv             = flasher_object_get_instance_private (self);
  priv->mime_types = NULL;

  flasher_object_get_mime_types (self);
}

static void
flasher_object_class_init (FlasherObjectClass *klass)
{
}

FlasherObject *
flasher_object_new (void)
{
  return g_object_new (FLASHER_TYPE_OBJECT, NULL);
}

static void
on_extension_check (PeasExtensionSet *set, PeasPluginInfo *info, FlasherFileExtension *exten, GArray *mime_types)
{
  GArray *types;

  g_message ("Check extension %s", peas_plugin_info_get_name (info));

  types = flasher_file_extension_get_mime_types (exten);

  if (types != NULL)
    {
      g_array_append_vals (mime_types, types, types->len);
      g_array_free (types, FALSE);
    }
}

void
flasher_object_get_mime_types (FlasherObject *self)
{
  FlasherObjectPrivate *priv;

  priv = flasher_object_get_instance_private (self);

  if (priv->mime_types == NULL)
    priv->mime_types = g_array_new (FALSE, FALSE, sizeof (char *));

  if (priv->mime_types->len == 0)
    {
      PeasExtensionSet *set;
      g_message ("Load extensions...");

      set = peas_extension_set_new (PEAS_ENGINE (self->engine), FLASHER_TYPE_FILE_EXTENSION, "flasher", self, NULL);

      peas_extension_set_foreach (set, (PeasExtensionSetForeachFunc) on_extension_check, priv->mime_types);
    }

  g_message ("Number of registered mime types: %d", priv->mime_types->len);
}
