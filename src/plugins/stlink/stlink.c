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

#include "stlink.h"

static void
flasher_stlink_extension_iface_init (FlasherExtensionInterface *iface)
{
}

static void
flasher_stlink_device_extension_iface_init (FlasherDeviceExtensionInterface *iface)
{
  iface->activate = flasher_stlink_device_extension_activate;
}

G_DEFINE_FINAL_TYPE_WITH_CODE (FlasherSTLink,
                               flasher_stlink,
                               PEAS_TYPE_EXTENSION_BASE,
                               G_IMPLEMENT_INTERFACE (FLASHER_TYPE_EXTENSION, flasher_stlink_extension_iface_init)
                                   G_IMPLEMENT_INTERFACE (FLASHER_TYPE_DEVICE_EXTENSION, flasher_stlink_device_extension_iface_init))

static void
flasher_stlink_set_property (GObject *object, guint prop_id, const GValue *value, GParamSpec *pspec)
{
  FlasherSTLink *plugin;

  g_return_if_fail (FLASHER_IS_STLINK (object));

  plugin = FLASHER_STLINK (object);

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
flasher_stlink_get_property (GObject *object, guint prop_id, GValue *value, GParamSpec *pspec)
{
  FlasherSTLink *plugin;

  g_return_if_fail (FLASHER_IS_STLINK (object));

  plugin = FLASHER_STLINK (object);

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
flasher_stlink_init (FlasherSTLink *extension)
{
}

static void
flasher_stlink_class_init (FlasherSTLinkClass *klass)
{
  GObjectClass *object_class;

  object_class               = G_OBJECT_CLASS (klass);
  object_class->set_property = flasher_stlink_set_property;
  object_class->get_property = flasher_stlink_get_property;

  g_object_class_override_property (object_class, PROP_FLASHER, "flasher");
}

void
flasher_stlink_device_extension_activate (FlasherDeviceExtension *extension)
{
  g_assert (FLASHER_IS_STLINK (extension));
}

G_MODULE_EXPORT void
peas_register_types (PeasObjectModule *module)
{
  peas_object_module_register_extension_type (module, FLASHER_TYPE_DEVICE_EXTENSION, FLASHER_TYPE_STLINK);
}

