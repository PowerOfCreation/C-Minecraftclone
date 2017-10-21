#!/bin/sh

CMAKE_GENERATOR="Unix Makefiles"

if [ -n "${MINGW_PACKAGE_PREFIX}" ]; then
	if [ $(command -v pacman) ]; then
		GLEW_PKG="${MINGW_PACKAGE_PREFIX}-glew"
		CMAKE_PKG="${MINGW_PACKAGE_PREFIX}-cmake"
		pacman -Q ${GLEW_PKG} || pacman -S ${GLEW_PKG} || exit -1
		pacman -Q ${CMAKE_PKG} || pacman -S ${CMAKE_PKG} || exit -1
	fi
	if [ -n "${MSYSTEM}" ]; then
		CMAKE_GENERATOR="MSYS Makefiles"
	else
		CMAKE_GENERATOR="MinGW Makefiles"
	fi
fi

git submodule init && git submodule update || exit -2

if [ ! -d build ]; then
	mkdir build || exit -3
fi
cd build

cmake -G "${CMAKE_GENERATOR}" .. || exit -4
exec make -j$(nproc)
