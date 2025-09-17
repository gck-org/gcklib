TEXI = gcklib.texi
INFO = gcklib.info
PDF  = gcklib.pdf
HTML = gcklib.html

all: info pdf man

info: $(TEXI)
	makeinfo $(TEXI)

pdf: $(TEXI)
	texi2pdf $(TEXI)

html: $(HTML)
	texi2html

clean:
	rm -f $(INFO) $(PDF) $(HTML) *.aux *.log *.toc *.cp *.fn *.ky *.pg *.tp *.vr *.cps

.PHONY: all info pdf html clean
