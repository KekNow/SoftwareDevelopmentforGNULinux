bin_PROGRAMS=binsearch
pkgdata_DATA=ru/LC_MESSAGES/binsearch.mo

@DX_RULES@

all-local: doxygen-doc
	help2man --no-info --output="binsearch.1" --name='@PACKAGE_NAME@' ./binsearch

ru/LC_MESSAGES/binsearch.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po: messages.pot
	msgmerge -U $@ $<

messages.pot: binsearch.pot binsearch.c
	xgettext -k_ -c binsearch.c -o messages.new.pot
	cp binsearch.pot messages.pot
	msgmerge -U messages.pot messages.new.pot

clean:
	git clean -fd

