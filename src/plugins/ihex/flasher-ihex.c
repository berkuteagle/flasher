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

struct _FlasherPluginIHex
{
  PeasExtensionBase parent_instance;
};

static void flasher_ihex_plugin_iface_init (FlasherFileExtensionInterface *iface);

G_DEFINE_FINAL_TYPE_WITH_CODE (FlasherPluginIHex,
                               flasher_plugin_ihex,
                               PEAS_TYPE_EXTENSION_BASE,
                               G_IMPLEMENT_INTERFACE (FLASHER_TYPE_FILE_EXTENSION, flasher_ihex_plugin_iface_init))

static void
flasher_ihex_plugin_iface_init (FlasherFileExtensionInterface *iface)
{
  iface->load_file      = NULL;
  iface->get_mime_types = flasher_file_extension_ihex_get_mime_types;
}

static void
flasher_plugin_ihex_init (FlasherPluginIHex *plugin)
{
}

static void
flasher_plugin_ihex_class_init (FlasherPluginIHexClass *klass)
{
}

void
flasher_file_extension_ihex_get_mime_types (FlasherFileExtension *extension)
{
  g_warn_message ("iHEX Plugin", "f", 1, "activate", "1");
}
