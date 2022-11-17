compile:
	python3 scripts/compile.py smart

compile-all:
	python3 scripts/compile.py all

run:
	build/stoopid stpd/test.stpd
