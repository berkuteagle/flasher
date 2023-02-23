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

#include "flasher-device-extension.h"
#include "flasher-object.h"

G_DEFINE_INTERFACE (FlasherDeviceExtension, flasher_device_extension, G_TYPE_OBJECT)

static void
flasher_device_extension_default_init (FlasherDeviceExtensionInterface *iface)
{
  g_object_interface_install_property (iface, g_param_spec_object ("flasher", "Flasher", "Flasher Object", FLASHER_TYPE_OBJECT,
                                                                   G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY | G_PARAM_STATIC_STRINGS));
}

void
flasher_device_extension_activate (FlasherDeviceExtension *extension)
{
  FlasherDeviceExtensionInterface *iface;

  g_return_if_fail (FLASHER_IS_DEVICE_EXTENSION (extension));

  iface = FLASHER_DEVICE_EXTENSION_GET_IFACE (extension);

  if (iface->activate != NULL)
    iface->activate (extension);
}

void
flasher_device_extension_deactivate (FlasherDeviceExtension *extension)
{
  FlasherDeviceExtensionInterface *iface;

  g_return_if_fail (FLASHER_IS_DEVICE_EXTENSION (extension));

  iface = FLASHER_DEVICE_EXTENSION_GET_IFACE (extension);

  if (iface->deactivate != NULL)
    iface->deactivate (extension);
}
