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

UTSBASE	= ../..
include $(UTSBASE)/intel/Makefile.intel

FETCH=	$(SRC)/tools/userland-fetch

GFXP_URL=https://github.com/gwr/illumos-gate/raw/gfxp4/gfxp.tar
GFXP_HASH=sha256:abffa1d6664508660ddd327b19d5359338051ffb398c0d3c9688746c88d87453

def all: gfxp.tar

gfxp.tar: Makefile
	$(FETCH) -u $(GFXP_URL) -h $(GFXP_HASH)

clean:

clobber:
	$(RM) gfxp.tar

lint:

modlintlib:

clean.lint:

# Install gfx_private.h
install_h : ../../common/sys/gfx_private.h

../../common/sys/gfx_private.h : install
	$(CP) -p $(ROOT)/usr/include/sys/gfx_private.h $@

# Install gfx_private kmods
install: $(ROOT)/usr/include/sys/gfx_private.h \
	$(ROOT)/platform/i86pc/kernel/misc/gfx_private \
	$(ROOT)/platform/i86pc/kernel/misc/amd64/gfx_private

$(ROOT)/usr/include/sys/gfx_private.h \
$(ROOT)/platform/i86pc/kernel/misc/gfx_private \
$(ROOT)/platform/i86pc/kernel/misc/amd64/gfx_private : gfxp.tar
	(cd $(ROOT) && tar xvf -) < gfxp.tar
