TEXI = gcklib.texi
INFO = gcklib.info
PDF  = gcklib.pdf

all: info pdf man

info: $(TEXI)
	makeinfo $(TEXI)

pdf: $(TEXI)
	texi2pdf $(TEXI)

man:

clean:
	rm -f $(INFO) $(PDF) *.aux *.log *.toc *.cp *.fn *.ky *.pg *.tp *.vr *.cps

.PHONY: all info pdf clean
