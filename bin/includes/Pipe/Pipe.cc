/*
 * Copyright 2005 X-Istence.com. All rights  reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and  documentation are
 * those of the authors and should not be  interpreted as representing official
 * policies, either expressed  or implied, of X-Istence.com or the bsdPanel
 * project.
 *
 * $Id$
 */

#include "Pipe.h"

int bsdPanel::Pipe::doPipe() {
	if ( pipe(to) == -1) {
		std::cerr << "Creating pipe failed. Resource exhaustion?";
		bsdPanel::exit_program();
	}

	if ( pipe(from) == -1) {
		std::cerr << "Creating pipe failed. Resource exhaustion?";
		bsdPanel::exit_program();
	}

	switch ( doFork() ) {
		case 0:
			close(to[1]);
			close(from[0]);
			dup2(to[0], 0);
			dup2(from[1], 1);
			return 0;
		case 1:
			close(to[0]);
			close(from[1]);
                        writer.attach(to[1]);
                        reader.attach(from[0]);
			return 1;
		default:
			bsdPanel::exit_program();
	}
	return 0; // We should never get here!
} 

int bsdPanel::Pipe::write(const std::string& sendOver) {
        writer << sendOver;
        writer.flush();
        return sendOver.length();
}

int bsdPanel::Pipe::read(std::string& readOver) {
        reader >> readOver;
        return readOver.length();
}
