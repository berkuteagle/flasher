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
#include <glib.h>

G_BEGIN_DECLS

#define FLASHER_TYPE_DEVICE_EXTENSION (flasher_device_extension_get_type ())

G_DECLARE_INTERFACE (FlasherDeviceExtension, flasher_device_extension, FLASHER, DEVICE_EXTENSION, GObject)

struct _FlasherDeviceExtensionInterface
{
  GTypeInterface g_iface;

  void (*activate) (FlasherDeviceExtension *extension);
  void (*deactivate) (FlasherDeviceExtension *extension);
};

void flasher_device_extension_activate (FlasherDeviceExtension *extension);
void flasher_device_extension_deactivate (FlasherDeviceExtension *extension);

G_END_DECLS
