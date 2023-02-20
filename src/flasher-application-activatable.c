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

#include "flasher-application-activatable.h"
#include "flasher-application.h"

G_DEFINE_INTERFACE(FlasherApplicationActivatable, flasher_application_activatable, G_TYPE_OBJECT)

static void
flasher_application_activatable_default_init (FlasherApplicationActivatableInterface *iface)
{
  g_object_interface_install_property(iface,
                                      g_param_spec_object("application",
                                                          "Application",
                                                          "Flasher application",
                                                          FLASHER_TYPE_APPLICATION,
                                                          G_PARAM_READWRITE|
                                                          G_PARAM_CONSTRUCT_ONLY|
                                                          G_PARAM_STATIC_STRINGS));
}

void
flasher_application_activatable_activate (FlasherApplicationActivatable *activatable)
{
  FlasherApplicationActivatableInterface *iface;

  g_return_if_fail(FLASHER_IS_APPLICATION_ACTIVATABLE(activatable));

  iface = FLASHER_APPLICATION_ACTIVATABLE_GET_IFACE(activatable);

  if (iface->activate != NULL)
    iface->activate(activatable);
}

void
flasher_application_activatable_deactivate (FlasherApplicationActivatable *activatable)
{
  FlasherApplicationActivatableInterface *iface;

  g_return_if_fail(FLASHER_IS_APPLICATION_ACTIVATABLE(activatable));

  iface = FLASHER_APPLICATION_ACTIVATABLE_GET_IFACE(activatable);

  if (iface->deactivate != NULL)
    iface->deactivate(activatable);
}

