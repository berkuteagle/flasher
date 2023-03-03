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

#include "flasher-file-extension.h"

G_DEFINE_INTERFACE (FlasherFileExtension, flasher_file_extension, FLASHER_TYPE_EXTENSION)

static void
flasher_file_extension_default_init (FlasherFileExtensionInterface *iface)
{
}

void
flasher_file_extension_load_file (FlasherFileExtension *extension)
{
  FlasherFileExtensionInterface *iface;

  g_return_if_fail (FLASHER_IS_FILE_EXTENSION (extension));

  iface = FLASHER_FILE_EXTENSION_GET_IFACE (extension);

  g_return_if_fail (iface->load_file != NULL);

  iface->load_file (extension);
}

GArray *
flasher_file_extension_get_mime_types (FlasherFileExtension *extension)
{
  FlasherFileExtensionInterface *iface;

  g_return_val_if_fail (FLASHER_IS_FILE_EXTENSION (extension), NULL);

  iface = FLASHER_FILE_EXTENSION_GET_IFACE (extension);

  g_return_val_if_fail (iface->get_mime_types != NULL, NULL);

  return iface->get_mime_types (extension);
}
