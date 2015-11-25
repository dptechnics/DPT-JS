/*
 * Project: DPT-JS javascript interpreter for DPT-Board and OpenWRT. 
 * 
 * Author: Daan Pape
 * Company: DPTechnics
 * Date: Sunday 4 october 2015
 * 
 * Based on: duktape.org and dukluv.io
 * 
 * License: The MIT License (MIT)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef DPTJS_H
#define	DPTJS_H

#include <assert.h>
#include <unistd.h>

#include "uv.h"
#include "duktape.h"

#define DPTJS_VERSION   "0.0.1"

#ifndef PATH_MAX
#define PATH_MAX (8096)
#endif

#ifndef MAX_TITLE_LENGTH
#define MAX_TITLE_LENGTH (8192)
#endif

// There are two slots for holding callbacks.  One is for the CLOSED event.
// The other slot is for all others since they never conflict in practice.
#define duv_callback_id int
#define DUV_CLOSED 0
#define DUV_TIMEOUT 1
#define DUV_PREPARE 1
#define DUV_IDLE 1
#define DUV_CHECK 1
#define DUV_ASYNC 1
#define DUV_POLL 1
#define DUV_SIGNAL 1
#define DUV_EXIT 1
#define DUV_CONNECTION 1
#define DUV_READ 1
#define DUV_RECV 1
#define DUV_FS_EVENT 1
#define DUV_FS_POLL 1

// Ref for userdata and event callbacks
typedef struct {
  int ref;
  int context;
  int callbacks[2];
} duv_handle_t;

typedef struct {
  int req_ref; // ref for uv_req_t's userdata
  int context;
  int callback_ref; // ref for callback
  void* data; // extra data
} duv_req_t;

duk_ret_t dukopen_uv(duk_context *ctx);

#include "refs.h"
#include "utils.h"
#include "schema.h"
#include "uv_schema.h"
#include "callbacks.h"
#endif