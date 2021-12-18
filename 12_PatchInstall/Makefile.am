bin_PROGRAMS=binsearch
pkgdata_DATA=ru/LC_MESSAGES/binsearch.mo
pkgdatadir=$(localedir)/ru/LC_MESSAGES
AM_CFLAGS = -D LOCALEDIR='"$(localedir)"'
man1_MANS = binsearch.1

ru/LC_MESSAGES/binsearch.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po: messages.pot
	msgmerge -U $@ $<

messages.pot: binsearch.pot binsearch.c
	xgettext -k_ -c binsearch.c -o messages.new.pot
	cp binsearch.pot messages.pot
	msgmerge -U messages.pot messages.new.pot

binsearch.1:
	help2man --no-info --output="binsearch.1" --name='@PACKAGE_NAME@' ./binsearch

clean:
	git clean -fd
