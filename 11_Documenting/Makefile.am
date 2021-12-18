bin_PROGRAMS=binsearch
pkgdata_DATA=ru/LC_MESSAGES/binsearch.mo

@DX_RULES@

all-local: doxygen-doc

ru/LC_MESSAGES/binsearch.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po: messages.pot
	msgmerge -U $@ $<

messages.pot: binsearch.pot binsearch.c
	xgettext -k_ -c binsearch.c -o messages.new.pot
	cp binsearch.pot messages.pot
	msgmerge -U messages.pot messages.new.pot

man:
	help2man --no-info --output=$@ --name='@PACKAGE_NAME@' ./binsearch

clean:
	git clean -fd

