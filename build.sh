#!/bin/sh
git submodule init && git submodule update || exit -1

CMAKE_GENERATOR="Unix Makefiles"

if [ -n ${MINGW_PACKAGE_PREFIX} ]; then
	GLEW_PKG="${MINGW_PACKAGE_PREFIX}-glew"
	if [ $(command -v pacman) ]; then
		pacman -Q ${GLEW_PKG} || pacman -S ${GLEW_PKG} || exit -2
	fi
	if [ -n ${MSYSTEM} ]; then
		CMAKE_GENERATOR="MSYS Makefiles"
	else
		CMAKE_GENERATOR="MinGW Makefiles"
	fi
fi

if [ ! -d build ]; then
	mkdir build || exit -3
fi
cd build

cmake -G "${CMAKE_GENERATOR}" .. || exit -4
exec make -j$(nproc)
