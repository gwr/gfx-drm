#
# This file and its contents are supplied under the terms of the
# Common Development and Distribution License ("CDDL"), version 1.0.
# You may only use this file in accordance with the terms of version
# 1.0 of the CDDL.
#
# A full copy of the text of the CDDL should have accompanied this
# source.  A copy of the CDDL is also available via the Internet at
# http://www.illumos.org/license/CDDL.
#

#
# Copyright 2016 Gordon W. Ross
#

#
#	Include common rules.
#

include $(SRC)/Makefile.master

FETCH=	$(SRC)/tools/userland-fetch

LIBDRM_DIR=libdrm-2.4.67
LIBDRM_ARCHIVE=$(LIBDRM_DIR).tar.bz2
LIBDRM_URL=http://dri.freedesktop.org/libdrm/$(LIBDRM_ARCHIVE)
LIBDRM_HASH=sha256:ee5b71e1113be37544d0752681c12f040c01f782e2933df7d7bc21fd0d10cebe

# These headers MUST come from the kernel, so
# remove the copies from the libdrm unpack.
KDRM_HDRS= drm.h drm_fourcc.h drm_mode.h drm_sarea.h i915_drm.h

def all: $(LIBDRM_ARCHIVE)

$(LIBDRM_ARCHIVE) :
	$(FETCH) -u $(LIBDRM_URL) -h $(LIBDRM_HASH)

clobber: clean
	$(RM) $(LIBDRM_ARCHIVE)

install_h: .patched

# Install gfx_private kmods
install: .patched

patched: .patched

.patched: .unpacked
	(cd $(LIBDRM_DIR) && \
	for p in ../patches/* ; do \
	patch -N -p 1 -i $$p ; done )
	(cd $(LIBDRM_DIR)/include/drm && \
	for h in $(KDRM_HDRS) ; do \
	$(MV) $$h $$h.orig ; done)
	touch $@

unpacked: .unpacked

.unpacked: $(LIBDRM_ARCHIVE)
	tar xvfjo $(LIBDRM_ARCHIVE)
	touch $@

clean: FRC
	$(RM) -rf $(LIBDRM_DIR)
	$(RM) .unpacked .patched

lint:

FRC:
