# Makefile for gcklib manual

TEXI = gcklib.texi
INFO = gcklib.info
PDF  = gcklib.pdf
HTML = gcklib.html

all: $(INFO) $(PDF) $(HTML)

$(INFO): $(TEXI)
	makeinfo --force --no-split -o $@ $<

$(PDF): $(TEXI)
	texi2pdf --batch $< -o $@

$(HTML): $(TEXI)
	makeinfo --html --no-split -o $@ $<

clean:
	$(RM) $(INFO) $(PDF) $(HTML) *.aux *.log *.toc *.cp *.fn *.ky *.pg *.tp *.vr *.cps *.fns
