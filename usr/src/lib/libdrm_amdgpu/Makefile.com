#
# CDDL HEADER START
#
# The contents of this file are subject to the terms of the
# Common Development and Distribution License (the "License").
# You may not use this file except in compliance with the License.
#
# You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
# or http://www.opensolaris.org/os/licensing.
# See the License for the specific language governing permissions
# and limitations under the License.
#
# When distributing Covered Code, include this CDDL HEADER in each
# file and include the License file at usr/src/OPENSOLARIS.LICENSE.
# If applicable, add the following below this CDDL HEADER, with the
# fields enclosed by brackets "[]" replaced with your own identifying
# information: Portions Copyright [yyyy] [name of copyright owner]
#
# CDDL HEADER END
#
#
# Copyright 2008 Sun Microsystems, Inc.  All rights reserved.
# Use is subject to license terms.
#
# Copyright 2011 Nexenta Systems, Inc.  All rights reserved.
#

LIBRARY=	libdrm_amdgpu.a
VERS=		.1

# See common/libdrm/libdrm-*/amdgpu/Makefile.in am__objects
OBJECTS= \
	amdgpu_bo.o amdgpu_cs.o amdgpu_device.o \
	amdgpu_gpu_info.o amdgpu_vamgr.o util_hash.o \
	util_hash_table.o

include ../../Makefile.lib
include $(SRC)/common/libdrm/Makefile.lib

LIBS =		$(DYNLIB)
PCS =		$(LIBRARY:.a=.pc)

MAPFILES=
SRCDIR =	$(LIBDRM_CMN_DIR)/amdgpu
SRCS =		$(OBJECTS:%.o=$(SRCDIR)/%.c)

CPPFLAGS +=	-I$(LIBDRM_CMN_DIR)
CPPFLAGS +=	-I$(LIBDRM_CMN_DIR)/amdgpu

LDLIBS32 +=	-L$(ROOT)/usr/lib/xorg
LDLIBS64 +=	-L$(ROOT)/usr/lib/xorg/$(MACH64)

LDLIBS += -lpciaccess -ldrm -lc

all : $(LIBS) $(PCS)

lint :

include ../../libdrm/Makefile.pc
include ../../Makefile.targ

.KEEP_STATE:
