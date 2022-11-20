python = python3

compile:
	${python} scripts/compile.py smart

compile-all:
	${python} scripts/compile.py all

run:
	build/stoopid stpd/errorHunting.stpd
