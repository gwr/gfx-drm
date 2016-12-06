/*
 * Copyright (c) 2006, 2012, Oracle and/or its affiliates. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

/*
 * Copyright (c) 2012 Intel Corporation.  All rights reserved.
 */

#ifndef _I915_IO32_H_
#define _I915_IO32_H_

#ifdef _MULTI_DATAMODEL

typedef struct drm_i915_batchbuffer32 {
	int start;		/* agp offset */
	int used;		/* nr bytes in use */
	int DR1;		/* hw flags for GFX_OP_DRAWRECT_INFO */
	int DR4;		/* window origin for GFX_OP_DRAWRECT_INFO */
	int num_cliprects;	/* mulitpass with multiple cliprects? */
	caddr32_t cliprects;	/* pointer to userspace cliprects */
} drm_i915_batchbuffer32_t;

typedef struct drm_i915_cmdbuffer32 {
	caddr32_t buf;	/* pointer to userspace command buffer */
	int sz;			/* nr bytes in buf */
	int DR1;		/* hw flags for GFX_OP_DRAWRECT_INFO */
	int DR4;		/* window origin for GFX_OP_DRAWRECT_INFO */
	int num_cliprects;	/* mulitpass with multiple cliprects? */
	caddr32_t cliprects;	/* pointer to userspace cliprects */
} drm_i915_cmdbuffer32_t;

typedef struct drm_i915_irq_emit32 {
	caddr32_t irq_seq;
} drm_i915_irq_emit32_t;

typedef struct drm_i915_getparam32 {
	int param;
	caddr32_t value;
} drm_i915_getparam32_t;

typedef struct drm_i915_mem_alloc32 {
	int region;
	int alignment;
	int size;
	caddr32_t region_offset;	/* offset from start of fb or agp */
} drm_i915_mem_alloc32_t;

extern int copyin32_i915_mem_alloc(void *dest, void *src);
extern int copyin32_i915_irq_emit(void *dest, void *src);
extern int copyin32_i915_getparam(void *dest, void *src);
extern int copyin32_i915_cmdbuffer(void * dest, void * src);
extern int copyin32_i915_batchbuffer(void * dest, void * src);

#endif /* _MULTI_DATAMODEL */

#endif /* _I915_IO32_H_ */
